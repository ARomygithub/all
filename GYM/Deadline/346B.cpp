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
typedef pair<pair<char,int>,pii> pcpi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
string s1,s2, vrs;

typedef uint64_t ull;
static int C = 998244353; // initialized below
// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

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
    cin >>s1;
    cin >>s2 >>vrs;
    HashInterval hv(vrs);
    vector dp(sz(s1)+1, vector(sz(s2)+1, vector<int>(sz(vrs),0)));
    vector last(sz(s1)+1, vector(sz(s2)+1, vector<pcpi>(sz(vrs), {{'.',0},{0,0}})));
    rep(i,0,sz(s1)+1) {
        rep(j,0,sz(s2)+1) {
            rep(k,0,sz(vrs)) {
                if(min(i,j) < k) {
                    continue;
                }
                int cur = dp[i][j][k];
                if(i+1<=sz(s1) && dp[i+1][j][k]<cur) {
                    dp[i+1][j][k] = cur;
                    last[i+1][j][k] = {{'.',k},{i,j}};
                }
                if(j+1<=sz(s2) && dp[i][j+1][k]<cur) {
                    dp[i][j+1][k] = cur;
                    last[i][j+1][k] = {{'.',k},{i,j}};
                }
                if(i<sz(s1) && j<sz(s2) && s1[i] == s2[j]) {
                    if(dp[i+1][j+1][k] < cur) {
                        dp[i+1][j+1][k] = cur;
                        last[i+1][j+1][k] = {{'.',k},{i,j}};
                    }
                    if(k<sz(vrs)-1 || (k==sz(vrs)-1 && s1[i]!=vrs[sz(vrs)-1])) {
                        // debug() <<imie(i) <<imie(j) <<imie(k);
                        // debug() <<imie(cur);
                        string nxt = vrs.substr(0,k);
                        nxt += s1[i];
                        HashInterval hn(nxt);
                        int lenNxt = 0;
                        per(len,sz(nxt),0) {
                            // if(i==4 && j==4 && k==4) {
                            //     debug() <<imie(vrs.substr(0,len));
                            //     debug() <<imie(nxt.substr(sz(nxt)-len,len));
                            // }
                            if((ull) hv.hashInterval(0,len) == (ull) hn.hashInterval(sz(nxt)-len,sz(nxt))) {
                                lenNxt = len;
                                break;
                            }
                        }
                        // if(i==4 && j==4 && k==4) {
                        //     debug() <<imie(nxt);
                        //     debug() <<imie(lenNxt);
                        // }
                        if(dp[i+1][j+1][lenNxt] < cur+1) {
                            // cout <<lenNxt <<"\n";
                            dp[i+1][j+1][lenNxt] = cur+1;
                            last[i+1][j+1][lenNxt] = {{s1[i],k},{i,j}};
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    pcpi u = {{'.',0},{0,0}};
    string sans = "";
    rep(i,0,sz(vrs)) {
        if(ans < dp[sz(s1)][sz(s2)][i]) {
            ans = dp[sz(s1)][sz(s2)][i];
            u = last[sz(s1)][sz(s2)][i];
        }
    }
    if(ans==0) {
        cout <<ans <<"\n";
    } else {
        // cout <<u.fi.fi <<" " <<u.fi.se <<" " <<u.se.fi <<" " <<u.se.se <<"\n";
        while(!(u.fi.se==0 && u.se.fi==0 && u.se.se==0)) {
            if(u.fi.fi!='.') {
                sans += u.fi.fi;
            }
            u = last[u.se.fi][u.se.se][u.fi.se];
        }
        if(u.fi.fi !='.') {
            sans += u.fi.fi;
        }
        reverse(sans.begin(),sans.end());
        cout <<sans <<"\n";
        // cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}