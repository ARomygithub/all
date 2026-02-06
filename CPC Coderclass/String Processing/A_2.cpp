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

const int mxn=300;
string s,t,x;

vi pi(const string& s) {
    vi p(sz(s));
    rep(i,1,sz(s)) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

void solve() {
    cin >>s;
    cin >>t;
    cin >>x;
    auto pix = pi(x);
    vector dp(sz(s), vector(sz(t), vector(sz(x), 0)));
    vector par(sz(s), vector(sz(t), vector(sz(x), -1)));
    rep(i,0,sz(s)) {
        rep(j,0,sz(t)) {
            if(s[i]==t[j]) {
                auto& temp =  dp[i][j][(s[i]==x[0])];
                if(temp<1) {
                    temp = 1;
                    par[i][j][(s[i]==x[0])] = 0;
                }
            }
            rep(k,0,sz(x)) {
                if(dp[i][j][k]) {
                    if(i+1<sz(s)) {
                        if(dp[i+1][j][k]< dp[i][j][k]) {
                            dp[i+1][j][k] = dp[i][j][k];
                            par[i+1][j][k] = 1;
                        }
                    }
                    if(j+1<sz(t)) {
                        if(dp[i][j+1][k] < dp[i][j][k]) {
                            dp[i][j+1][k] = dp[i][j][k];
                            par[i][j+1][k] = 2;
                        }
                    }
                    if(i+1<sz(s) && j+1<sz(t)) {
                        if(s[i+1]==t[j+1]) {
                            int g = k;
                            while(g && s[i+1]!=x[g]) g = pix[g-1];
                            int k_new = g + (s[i+1]==x[g]);
                            if(k_new==sz(x)) continue;
                            if(dp[i+1][j+1][k_new] < dp[i][j][k]+1) {
                                dp[i+1][j+1][k_new] = dp[i][j][k]+1;
                                par[i+1][j+1][k_new] = 3+k;
                            }
                        }
                    }
                }
            }
        }
    }
    int mx = 0, mxk=-1;
    rep(k,0,sz(x)) {
        if(mx < dp[sz(s)-1][sz(t)-1][k]) {
            mx = dp[sz(s)-1][sz(t)-1][k];
            mxk = k;
        }
    }
    // debug() <<imie(dp);
    // debug() <<imie(par);
    if(mx) {
        string ans = "";
        int ui = sz(s)-1, uj=sz(t)-1, uk=mxk;
        while(true) {
            int paru = par[ui][uj][uk];
            if(paru==1) {
                ui--;
            } else if(paru==2) {
                uj--;
            } else {
                ans += s[ui];
                if(paru==0) break;
                uk = paru-3;
                ui--,uj--;
            }
        }
        reverse(ans.begin(),ans.end());
        cout <<ans <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}