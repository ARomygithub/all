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

const int mxn=1e5;
int n;
int a[mxn];
vector<int> adj[mxn];
ll ans=0;
ll ct[mxn][11];

void dfs(int u, int p=-1) {
    ct[u][a[u]]++;
    for(int v: adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        // ans +=2ll*ct[v][(11-a[u])%11];
        for(int i=0;i<11;i++) {
            ans +=2ll*ct[u][i]*ct[v][i];
            // if(2ll*ct[u][i]*ct[v][(11-i)%11] >0) {
            //     debug() <<"nambah " <<imie(2ll*ct[u][i]*ct[v][(11-i)%11]);
            // }
        }
        // debug() <<imie(u) <<imie(v);
        for(int i=0;i<11;i++) {
            ct[u][i] += ct[v][(11+a[u]-i)%11];
            // debug() <<imie(i) <<imie(ct[u][i]);
        }
    }
}

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        ans +=(a[i]==0);
    }
    for(int i=1;i<n;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}