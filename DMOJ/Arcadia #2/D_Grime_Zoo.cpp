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
int n,t;
string s;
ll x,y;

void solve() {
    cin >>s;
    n = sz(s);
    cin >>x >>y;
    int cty = count(all(s),'?');
    int ct1 = count(all(s), '1');
    int ct0 = count(all(s), '0');
    if(x<y) {
        swap(x,y);
        reverse(all(s));
    }
    if(x>=y) {
        vector<ll> suf(n,0);
        // 01
        vector<ll> ct(3,0);
        per(i,n-1,-1) {
            if(i+1<n) {
                suf[i] += suf[i+1];
            }
            if(s[i]!='1') {
                suf[i] += ct[1];
                ct[0]++;
            } else {
                ct[1]++;
            }
        }
        ll ans = 1e18;
        // debug() <<imie(suf);
        min_self(ans, y*ct1*(n-ct1) + (x-y)*suf[0]);
        ll pref = 0;
        ct[0] = 0, ct[1] = 0;
        rep(i,0,n) {

            if(s[i]!='0') {
                if(s[i]=='1') {
                    ct[1]++;
                } else {
                    ct[2]++;
                }
                pref += ct[0];
            } else {
                ct[0]++;
            }
            ll s01 = (i+1<n?suf[i+1]:0) + ct[0]*(ct1-ct[1]) + pref;
            // debug() <<imie(i) imie(s01);
            min_self(ans, y*(ct1+ct[2])*(n-ct1-ct[2]) + (x-y)*s01);
        }
        cout <<ans <<"\n";
    } else {
        // vector<ll> pref(n,0);
        // // 10
        // vector<ll> ct(3,0);
        // rep(i,0,n) {
        //     if(i) {
        //         pref[i] += pref[i-1];
        //     }
        //     if(s[i]!='1') {
        //         pref[i] += ct[1];
        //         ct[0]++;
        //     } else {
        //         ct[1]++;
        //     }
        // }
        // ll ans = 1e18;
        // min_self(ans, x*ct0*(n-ct0) + (y-x)*pref[n-1]);
        // ll suf = 0;
        // ct[0] = 0, ct[1] = 0;
        // per(i,n-1,-1) {
        //     if(s[i]!='0') {
        //         if(s[i]=='1') {
        //             ct[1]++;
        //         } else {
        //             ct[2]++;
        //         }
        //         suf += ct[0];
        //     } else {
        //         ct[0]++;
        //     }
        //     ll s10 = (i+1<)
        // }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}