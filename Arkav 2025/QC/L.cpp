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

const int mxn=1e6;
const ll mod = 998244353;
int n,m;
vector vans(51, vector<ll>(8,0));

ll det(vector<vector<ll>>& a) {
	int n = sz(a); ll ans = 1;
	rep(i,0,n) {
		rep(j,i+1,n) {
			while (a[j][i] != 0) { // gcd step
				ll t = a[i][i] / a[j][i];
				if (t) rep(k,i,n)
					a[i][k] = (a[i][k] - a[j][k] * t) % mod;
				swap(a[i], a[j]);
				ans *= -1;
			}
		}
		ans = ans * a[i][i] % mod;
		if (!ans) return 0;
	}
	return (ans + mod) % mod;
}

void solve() {
    // cin >>n >>m;
    vector mat(n+m-1, vector<ll>(n+m-1,0));
    rep(i,0,n-1) {
        mat[i][i] = m;
    }
    rep(i,n-1,n+m-1) {
        mat[i][i] = n;
    }
    rep(i,0,n-1) {
        rep(j,n-1,n+m-1) {
            mat[i][j] = mod-1;
        }
    }
    rep(i,n-1,n+m-1) {
        rep(j,0,n-1) {
            mat[i][j] = mod-1;
        }
    }
    // debug() <<imie(mat);
    // debug() <<imie(n) imie(m);
    vans[n][m] = det(mat);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    rep(i,1,8) {
        rep(j,1,8) {
            n = i, m = j;
            solve();
        }
        debug() <<imie(vans[i]);
    }
    
    // solve();
}