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

const int mxn=1e5;
int n;
string s,t;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
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

void solve() {
    cin >>s >>t;
    n = s.length();
    vector<int> cta(26,0),ctb(26,0);
    rep(i,0,n) {
        cta[s[i]-'a']++;
        ctb[t[i]-'a']++;
    }
    vector<char> ans(n,'?');
    int la=-1,lb=-1;
    Tree sta(n),stb(n);
    rep(i,0,n) {
        if(i%2) {
            per(j,25,-1) {
                if(ctb[j]) {
                    int udh = stb.query(la+1,n);
                    int ctk=0;
                    rep(k,0,j+1) {
                        ctk += cta[k];
                    }
                    if(ctk==0) {
                        rep(k,j+1,26) {
                            ctk += cta[k];
                        }
                    } else {
                        ctk = 0;
                    }
                    min_self(ctk, (n-udh-la-1)/2);
                    if(abs(la-lb)>1) {
                        lb = min(la,lb)+ctk+udh+1;
                    } else {
                        lb = max(la,lb)+ctk+udh+1;
                    }
                    // cout <<lb <<"\n" <<flush;
                    ans[lb] = (char)('a'+j);
                    ctb[j]--;
                    stb.update(lb, 1);
                    break;
                }
            }
        } else {
            rep(j,0,26) {
                if(cta[j]) {
                    int udh = sta.query(lb+1,n);
                    int ctk=0;
                    per(k,25,j-1) {
                        ctk += ctb[k];
                    } 
                    if(ctk==0) {
                        per(k,j-1,-1) {
                            ctk += ctb[k];
                        }
                    } else {
                        ctk = 0;
                    }
                    min_self(ctk, (n-udh-lb-1)/2);
                    if(abs(la-lb)>1) {
                        la = min(la,lb)+ctk+udh+1;
                    } else {
                        la = max(la,lb)+ctk+udh+1;
                    }
                    // cout <<la <<"\n" <<flush;
                    ans[la] = (char)('a'+j);
                    cta[j]--;
                    sta.update(la, 1);
                    break;
                }
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i];
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}