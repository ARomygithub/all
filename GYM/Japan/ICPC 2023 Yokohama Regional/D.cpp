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
string s;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

void solve() {
    cin >>s;
    n = s.length();
    vector dp(n,vector<string>(n));
    HashInterval hi(s);
    rep(ji,0,n) {
        rep(i,0,n) {
            int j = i+ji;
            if(j>=n) break;
            if(j-i<=2) {
                dp[i][j] = s.substr(i,j-i+1);
                continue;
            }
            dp[i][j] =s.substr(i,j-i+1);
            per(k,j,i) {
                int leni = j-k+1;
                int m = 1;
                while(k-leni*(m-1)>=i) {
                    int kl = k-leni*(m-1);
                    if(hi.hashInterval(kl,kl+leni) == hi.hashInterval(k,j+1)) {
                        string temp = (i<kl?dp[i][kl-1]:"");
                        if(m>1) {
                            rep(ct,2,10) {
                                if((m%ct)==0) {
                                    string temp2 = temp + (char)(ct+'0');
                                    temp2 += '(';
                                    temp2 += dp[kl][kl+(m/ct)*leni-1];
                                    temp2 += ')';
                                    if(sz(temp2)<sz(dp[i][j])) {
                                        dp[i][j] = temp2;
                                    }
                                }
                            }
                        } else {
                            string temp2 = temp + dp[kl][j];
                            if(sz(temp2)<sz(dp[i][j])) {
                                dp[i][j] = temp2;
                            }
                        }
                        m++;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout <<dp[0][n-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}