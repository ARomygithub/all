#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,k,t;
int a[mxn];

// int tes() {

// }

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    rep(i,0,n) {
        s.insert(a[i]);
    }
    int x = 0,ct=0;
    auto it = s.begin();
    while(x < n) {
        while(x <n && x==(*it)) {
            x++;
            it++;
            if(it==s.end()) break;
        }
        if(it==s.end()) {
            ct += min(n,x+k)-x;
            x = min(n,x+k);
            k -= min(n,x+k)-x;
            break;
        } else {
            if(k>= ((*it)-x)) {
                k -= min((*it),n)-x;
                ct += min(*it,n)-x;
                x = min(*it,n);
            } else {
                ct += min(n,x+k)-x;
                x = min(n,x+k);
                break;
            }
        }
    }
    // debug() <<imie(x) imie(ct) imie(k);
    map<int,int> mp;
    rep(i,0,n) {
        if(a[i]>=x) {
            mp[a[i]]++;
        }
    }
    vector<pii> v;
    for(auto [ke,val]: mp) {
        v.push_back({val,ke});
    }
    sort(all(v));
    int ans = sz(mp);
    for(auto [cti,ai]: v) {
        if(cti<=ct) {
            ct -= cti;
            ans--;
        } else {
            break;
        }
    }
    // debug() <<imie(s);
    // debug() <<imie(lebih) imie(sz(s));
    // assert(x-ct == sz(s)-lebih);
    // int ans = max(lebih-ct,0); 
    // assert(ans=tes());
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}