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
const ll mod = 998244353;
ll n;
int a[3];

void solve() {
    cin >>n;
    rep(i,0,3) {
        cin >>a[i];
    }
    int ct=0;
    while((1ll<<(ct+1))-1 < n) {
        ct++;
    }
    vector dp(ct+1, vector(a[0], vector(a[1], vector(a[2], vector(8, 0)))));
    vector<vector<int>> move = {{0,0,0},{0,1,1},{1,0,1},{1,1,0}};
    per(bit,ct,-1) {
        rep(i,1,4) {
            int state = 0;
            int t0 = move[i][0] && bit==ct;
            int t1 = move[i][1] && bit==ct;
            int t2 = move[i][2] && bit==ct;
            state = (t0<<2)+(t1<<1)+t2;
            int r0 = move[i][0]? (1ll<<bit)%a[0] : 0;
            int r1 = move[i][1]? (1ll<<bit)%a[1] : 0;
            int r2 = move[i][2]? (1ll<<bit)%a[2] : 0;
            dp[bit][r0][r1][r2][state] = (dp[bit][r0][r1][r2][state] + 1)%mod;
        }
        if(bit==0) continue;
        rep(s0,0,a[0]) {
            rep(s1,0,a[1]) {
                rep(s2,0,a[2]) {
                    rep(strict,0,8) {
                        int st0= (strict>>2);
                        int st1 = (strict>>1)&1;
                        int st2 = strict&1;
                        int bitn = bit-1;
                        int cur = (n>>bitn)&1;
                        if(dp[bit][s0][s1][s2][strict]==0) continue;
                        // debug() <<imie(bit) <<imie(s0) <<imie(s1) <<imie(s2) <<imie(strict);
                        // debug() <<imie(dp[bit][s0][s1][s2][strict]);
                        rep(i,0,4) {
                            if(cur==0 && move[i][0] && st0) continue;
                            int t0 = st0 && move[i][0]==cur;
                            if(cur==0 && move[i][1] && st1) continue;
                            int t1 = st1 && move[i][1]==cur;
                            if(cur==0 && move[i][2] && st2) continue;
                            int t2 = st2 && move[i][2]==cur;
                            int state = (t0<<2)+(t1<<1)+t2;
                            int r0 = (s0 + (move[i][0]?(1ll<<bitn)%a[0]:0))%a[0];
                            int r1 = (s1 + (move[i][1]?(1ll<<bitn)%a[1]:0))%a[1];
                            int r2 = (s2 + (move[i][2]?(1ll<<bitn)%a[2]:0))%a[2];
                            dp[bitn][r0][r1][r2][state] = (dp[bitn][r0][r1][r2][state] + dp[bit][s0][s1][s2][strict])%mod;
                            // cout <<"tes" <<endl;
                            // debug() <<imie(bitn) <<imie(r0) <<imie(r1) <<imie(r2) <<imie(state);
                            // debug() <<imie(dp[bitn][r0][r1][r2][state]);
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,8) {
        ans = (ans + dp[0][0][0][0][i])%mod;
    }
    ll one0 = 0;
    auto lcm = [&](int ai, int bi) -> int {
        return (ai/__gcd(ai,bi))*bi;
    };
    one0 = (one0 + n/lcm(a[0],a[1]))%mod;
    one0 = (one0 + n/lcm(a[0],a[2]))%mod;
    one0 = (one0 + n/lcm(a[1],a[2]))%mod;
    ans = (ans -one0 + mod)%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}