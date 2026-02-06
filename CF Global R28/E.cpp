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

const int mxn=1e3;
int n,m,t;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve() {
    cin >>n >>m;
    if(m>=n*2) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
        vector ans(n*2, vi(m,-1));
        // rep(i,0,n) {
        //     rep(k,0,m) {
        //         int cur = (i+k)%n + 1;
        //         ans[i][k] = cur;
        //     }
        // }
        rep(i,0,n*2) {
            rep(k,0,m) {
                int cur = ((i+k)/2)%n + 1;
                ans[i][k] = cur;
            }
        }
        // rep(i,0,n) {
        //     rep(j,0,2) {
        //         rep(k,0,min(n,m)) {
        //             int cur = (i+k)%n + 1;
        //             ans[i*2+j][k] = cur;
        //         }
        //     }
        // }
        // if(n<m) {
        //     rep(i,0,n) {
        //         rep(j,0,m-n) {
        //             int cur = (i+j)%n + 1;
        //             ans[i][n+j] = cur;
        //             ans[n*2-1-i][n+j] = cur;
        //         }
        //     }
        // }
        // tes
        // rep(i,1,n+1) {
        //     UF uf(n*2+m);
        //     rep(j,0,n*2) {
        //         rep(k,0,m) {
        //             assert(ans[j][k]>0);
        //             if(ans[j][k]==i) {
        //                 if(!uf.join(j,n*2+k)) {
        //                     assert(false);
        //                     // debug() <<imie(j) imie(k);
        //                 }
        //             }
        //         }
        //     }
        // }
        rep(i,0,n*2) {
            rep(j,0,m) {
                cout <<ans[i][j] <<" \n"[j==m-1];
            }
        }
    }
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