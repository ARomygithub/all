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
typedef pair<int,pii> ipii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=500;
const int di[4]={-1,0,1,0}, dj[4]={0,1,0,-1};
int n;
string s[mxn];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<n;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector dp1(n, vector<int>(n, 1e9));
    dp1[0][0] = 0;
    priority_queue<ipii,vector<ipii>,greater<ipii>> pq;
    pq.push({0,{0,0}});
    while(sz(pq)) {
        auto [dpi,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        if(dpi>dp1[i][j]) continue;
        rep(k,0,4) {
            int ii = i+di[k], jj=j+dj[k];
            if(e(ii,jj)) {
                int nxt = dpi + (s[ii][jj]=='B');
                if(dp1[ii][jj] > nxt) {
                    dp1[ii][jj] = nxt;
                    pq.push({nxt,{ii,jj}});
                } 
            }
        }
    }
    vector dp2(n, vector<int>(n, 1e9));
    dp2[0][n-1] = 0;
    pq.push({0,{0,n-1}});
    while(sz(pq)) {
        auto [dpi,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        if(dpi>dp2[i][j]) continue;
        rep(k,0,4) {
            int ii = i+di[k], jj = j+dj[k];
            if(e(ii,jj)) {
                int nxt = dpi + (s[ii][jj]=='R');
                if(dp2[ii][jj] > nxt) {
                    dp2[ii][jj] = nxt;
                    pq.push({nxt,{ii,jj}});
                }
            }
        }
    }
    // rep(i,0,n) {
    //     debug() <<imie(dp1[i]);
    // }
    // rep(i,0,n) {
    //     debug() <<imie(dp2[i]);
    // }
    cout <<dp1[n-1][n-1]+dp2[n-1][0] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}