#include <bits/stdc++.h>
using namespace std;

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

const int mxn=5e5;
int n;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

template<class T>
struct RXQ {
	vector<vector<T>> jmp;
	RXQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve() {
    cin >>n;
    vi s(n), t(n);
    rep(i,0,n) {
        cin >>s[i];
    }
    rep(i,0,n) {
        cin >>t[i];
    }
    RXQ<int> rx(s);
    RMQ<int> rm(t);
    ll ans = 0;
    rep(i,0,n) {
        int le = -1;
        int l = i, r = n-1;
        while(l<=r) {
            int mid = (l+r)/2;
            int mx = rx.query(i,mid+1);
            int mn = rm.query(i,mid+1);
            if(mx==mn) {
                le = mid;
                r = mid-1;
            } else if(mx<mn) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        if(le==-1) continue;
        int ri = -1;
        l = i, r = n-1;
        while(l<=r) {
            int mid = (l+r)/2;
            int mx = rx.query(i,mid+1);
            int mn = rm.query(i,mid+1);
            if(mx==mn) {
                ri = mid;
                l = mid+1;
            } else if(mx<mn) {
                l = mid+1;
            } else {
                r = mid-1;
            }            
        }
        ans += (ri-le+1);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}