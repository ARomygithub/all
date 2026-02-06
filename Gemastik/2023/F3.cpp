#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
    ris << "(" << d.first << ", " <<d.second <<")";
}
sim dor(rge<c> d) {
    *this << "[";
    for(auto it = d.b; it != d.e;++it)
        *this <<", " + 2 * (it==d.b) <<*it;
    ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]"

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string xs;
    getline(cin, xs);
    stringstream ss(xs);

    int p, n;
    ss >> p >> n;
    ll k;
    ss >> k;
    ll mn = 1e18;
    string ans = "";
    for(int ii=0; ii<p; ii++){
        string st;
        getline(cin, st);
        debug() <<imie(st);
        int sz1 = n/2;
        int sz2 = n-sz1;
        vector<ll> v;
        string sx;
        getline(cin, sx);
        stringstream sss(sx);
        for(int i=0; i<n; i++){
            ll x;
            sss >> x;
            v.pb(x);
        }
        debug() <<imie(v);
        vector<ll> v1, v2;
        for(int i=0; i<(1<<sz1); i++){
            ll sum = 0;
            for(int j=0; j<sz1; j++){
                if(i&(1<<j)){
                    sum+=v[j];
                }
            }
            v1.pb(sum);
        }
        for(int i=0; i<(1<<sz2); i++){
            ll sum = 0;
            for(int j=0; j<sz2; j++){
                if(i&(1<<j)){
                    sum+=v[sz1+j];
                }
            }
            v2.pb(sum);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i=0; i<(v1.size()); i++){
            ll x = k-v1[i];
            int id = lower_bound(v2.begin(), v2.end(), x)-v2.begin();
            int id2 = id;
            if(id > 0){
                id2 = id-1;
            }
            if(id < (v2.size())){
                if(mn > abs(k-v1[i]-v2[id])){
                    ans = st;
                    mn = abs(k-v1[i]-v2[id]);
                } else if(mn == abs(k-v1[i]-v2[id])){
                    ans = min(ans, st);
                }
            }
            if(id2 >= 0){
                if(mn > abs(k-v1[i]-v2[id2])){
                    ans = st;
                    mn = abs(k-v1[i]-v2[id2]);
                } else if(mn == abs(k-v1[i]-v2[id2])){
                    ans = min(ans, st);
                }
            }
        }
    }
    cout << ans << "\n";
    

    return 0;
}