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
int n,q;

struct UF {
	vi e, ct, cl;
	UF(int n) : e(n, -1), ct(n,1), cl(n) {
        iota(all(cl),0);
    }
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
    void ch(int x, int c) {
        x = find(x);
        ct[cl[x]] -= size(x);
        cl[x] = c;
        ct[cl[x]] += size(x);
        int l=0, r = x-1;
        int le = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(sameSet(mid,x)) {
                r = mid-1;
            } else {
                l = mid+1;
                le = mid;
            }
        }
        l = x+1,r=sz(e)-1;
        int ri = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(sameSet(mid,x)) {
                l = mid+1;
            } else {
                ri = mid;
                r = mid-1;
            }
        }
        if(le!=-1 && cl[find(le)]==c) {
            join(le,x);
        }
        if(ri!=-1 && cl[find(ri)]==c) {
            join(ri,x);
        }
    }
};

void solve() {
    cin >>n >>q;
    UF uf(n);
    while(q--) {
        int qt; cin >>qt;
        if(qt==1) {
            int x,c; cin >>x >>c; x--,c--;
            uf.ch(x,c);
        } else {
            int c; cin >>c; c--;
            cout <<uf.ct[c] <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}