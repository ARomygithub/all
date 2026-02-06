#include <bits/stdc++.h>
using namespace std;

// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge { c b, e; };
// sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug {
// #ifdef LOCAL
// ~debug() { cerr << endl; }
// eni(!=) cerr << boolalpha << i; ris; }
// eni(==) ris << range(begin(i), end(i)); }
// sim, class b dor(pair < b, c > d) {
//     ris << "(" << d.first << ", " <<d.second <<")";
// }
// sim dor(rge<c> d) {
//     *this << "[";
//     for(auto it = d.b; it != d.e;++it)
//         *this <<", " + 2 * (it==d.b) <<*it;
//     ris << "]";
// }
// #else
// sim dor(const c&) { ris; }
// #endif
// };
// #define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]"

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
#define plll pair<pll,ll>

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
ll n;
ll a[mxn],d[mxn];

void solve() {
    cin >>n;
    ll mx = -1;
    ll sum = 0;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        max_self(mx, a[i]);
        sum +=a[i];
    }
    for(int i=0;i<n;i++) {
        cin >>d[i];
    }
    ll l = (sum+n-1)/n;
    ll r = mx;
    vector<plll> v;
    for(ll i=0;i<n;i++) {
        v.push_back({{max(0ll,i-d[i]),min(n-1,i+d[i])},a[i]});
    }
    sort(v.begin(),v.end());
    ll ans = 1e9;
    vector<ll> vl;
    vl.push_back(v[0].fi.fi);
    for(int i=1;i<n;i++) {
        if(v[i].fi.fi!=vl[sz(vl)-1]) {
            vl.push_back(v[i].fi.fi);
        }
    }
    // debug() <<imie(vl);
    // debug() <<imie(v);
    while(l<=r) {
        ll mid = (l+r)/2;
        // debug() <<imie(mid);
        vector<ll> ct(n,0);
        priority_queue<plll, vector<plll>, greater<plll>> pq;
        for(int i=0;i<n;i++) {
            pq.push(v[i]);
        }
        ll idx = 0;
        bool flag=true;
        while(sz(pq) && flag) {
            plll pqi = pq.top(); pq.pop();
            // debug() <<imie(pqi);
            ll rr = pqi.fi.se;
            auto it = upper_bound(vl.begin(),vl.end(),pqi.fi.fi);
            if(it!=vl.end()) {
                min_self(rr, (*it)-1);
            }
            max_self(idx, pqi.fi.fi);
            ll temp2 = 0;
            while(idx<=rr && pqi.se>temp2) {
                ll temp = min(mid-ct[idx], pqi.se-temp2);
                ct[idx] +=temp;
                temp2 +=temp;
                if(ct[idx]==mid) {
                    idx++;
                }
            } 
            if(pqi.se>temp2) {
                // ada sisa
                if(rr<pqi.fi.se) {
                    pq.push({{rr+1,pqi.fi.se},pqi.se-temp2});
                } else {
                    flag = false;
                }
            }
        }
        if(flag) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}