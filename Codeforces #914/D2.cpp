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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,t;
int a[mxn],b[mxn];

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct TreeMin {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    Tree tA = Tree(n);
    rep(i,0,n) {
        tA.update(i,a[i]);
    }
    TreeMin tB = TreeMin(n);
    rep(i,0,n) {
        tB.update(i,b[i]);
    }
    bool flag=1;
    rep(i,0,n) {
        int atas=a[i],bwh=b[i];
        if(atas>b[i]) {
            flag=0;
            break;
        }
        int l=i,r=n-1;
        int ans=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            atas = tA.query(i,mid+1);
            bwh = tB.query(i,mid+1);
            if(atas==b[i] && bwh==b[i]) {
                ans = mid;
                break;
            } else if(bwh > b[i]) {
                r = mid-1;
            } else if(atas<b[i]) {
                l = mid+1;
            } else { //atas >b[i]
                r = mid-1;
            }
        }
        if(ans!=-1) {
            continue;
        }
        l = 0,r=i;
        while(l<=r) {
            int mid=(l+r)/2;
            atas = tA.query(mid,i+1);
            bwh = tB.query(mid,i+1);
            if(i==4) {
                // cout <<mid <<"\n";
                // cout <<atas <<" " <<bwh <<"\n";
            }
            if(atas==b[i] && bwh==b[i]) {
                ans = mid;
                break;
            } else if(bwh>b[i]) {
                l = mid+1;
            } else if(atas<b[i]) {
                r = mid-1;
            } else { //atas > b[i]
                l = mid+1;
            }
            // cout <<l <<" " <<r <<"\n";            
        }
        if(ans==-1) {
            // cout <<i <<"\n";
            flag = 0;
            break;
        }        
    }
    if(flag) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
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