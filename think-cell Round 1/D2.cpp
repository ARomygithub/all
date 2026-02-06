#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    ll ans = 0;
    vector<vector<int>> v;
    vector<int> temp;
    rep(i,0,n) {
        if(s[i]=='1') {
            ans += 1ll*(i+1)*(n-i);
            if(sz(temp)) {
                if(temp.back()>=i-2) {
                    temp.push_back(i);
                } else {
                    if(sz(temp)>=2) v.push_back(temp);
                    temp.clear();
                    temp.push_back(i);
                }
            } else {
                temp.push_back(i);
            }
        }
    }
    if(sz(temp)>=2) v.push_back(temp);
    ll mines = 0;
    for(auto v2 : v) {
        // debug() <<imie(v2);
        // ll ct_0 = v2[0]+1;
        // ll ct_1 = 0;
        map<int,ll> ct;
        ct[v2[0]+1] = v2[0]+1;
        rep(i,1,sz(v2)) {
            ll temp2 = ct[v2[i]-1]+ct[v2[i]];
            mines += (temp2)*(n-v2[i]);
            ct[v2[i]+1] += v2[i]+1-temp2;
            // if(i%2) {
            //     mines += (ct_0)*(n-v2[i]);
            //     debug() <<imie((ct_0)*(n-v2[i]));
            //     ct_1 += v2[i]-v2[i-1];
            // } else {
            //     mines += ct_1*(n-v2[i]);
            //     debug() <<imie(ct_1*(n-v2[i]));
            //     ct_0 += v2[i]-v2[i-1];
            // }
        }
        // debug() <<imie(mines);
    }
    // debug() <<imie(ans);
    cout <<ans-mines <<"\n";
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