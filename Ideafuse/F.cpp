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

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=200,mxm=20,mxk=500;
int n,m,k;
string s[mxn];
int powi[mxn][mxm];

void solve() {
    cin >>n >>m >>k;
    for(int i=0;i<n;i++) {
        cin >>s[i];
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m;j++) {
            int temp=0;
            for(int j1=0;j1<m;j1++) {
                temp +=(s[i][j1]==s[i+1][(j1+j)%m]);
            }
            powi[i][j] = temp*temp;
            // debug() <<imie(i) <<imie(j) <<imie(powi[i][j]);
        }
    }
    int ans=0;
    vector<vector<int>> dp(k+1,vector<int>(m,-1e9));
    for(int k1=0;k1<m;k1++) {
        dp[k1][k1] = 0;
    }
    for(int i=1;i<n;i++) {
        vector<vector<int>> dp_new(k+1,vector<int>(m,-1e9));
        for(int k1=0;k1<m;k1++) {
            dp_new[k1][k1] = 0;
        }
        for(int ki=0;ki<m;ki++) {
            for(int ki0=0;ki0+ki<=k;ki0++) {
                for(int last=0;last<m;last++) {
                    // if(ki0+ki<=k) {
                        max_self(dp_new[ki0+ki][ki], dp[ki0][last]+powi[i-1][(ki-last+m)%m]);
                    // }
                    // max_self(dp_new[ki0][last], dp[ki0][last]);
                }
            }
        }
        dp.swap(dp_new);
        // debug() <<imie(dp);
    }
    for(int ki=0;ki<=k;ki++) {
        for(int last=0;last<m;last++) {
            max_self(ans, dp[ki][last]);
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