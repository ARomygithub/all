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

const int mxn=500,inf=1e9;
int n;
string s;

void solve() {
    cin >>s;
    n = sz(s);
    vector dp(n+1, vector(n+1, inf));
    vector mv(n+1, vector<pii>(n+1));
    vector pr(n+1, vector<pii>(n+1));
    queue<pii> q;
    dp[0][0] = 0;
    q.push({0,0});
    while(sz(q)) {
        auto [l,r] = q.front(); q.pop();
        int len = dp[l][r];
        // debug() <<imie(l) imie(r) imie(len);
        rep(a,0,10) {
            rep(ct,0,10) {
                if(a==0) {
                    if(ct==0) {
                        int nl=l+1, nr=r+1;
                        if(nl<=n && nr<=n && s[nl-1]=='0' && s[n-nr]=='0') {
                            if(dp[nl][nr] > len+1) {
                                dp[nl][nr] = len+1;
                                q.push({nl,nr});
                                mv[nl][nr] = {a,ct};
                                pr[nl][nr] = {l,r};
                            }
                        }
                    } else {
                        int nl = l+1;
                        if(nl<=n && s[nl-1]-'0' == ct) {
                            if(dp[nl][r] > len+1) {
                                dp[nl][r] = len+1;
                                q.push({nl,r});
                                mv[nl][r] = {a,ct};
                                pr[nl][r] = {l,r};
                            }
                        }
                    }
                } else {
                    if(ct==0) {
                        int nr = r+1;
                        if(nr<=n && s[n-nr]-'0' == a) {
                            if(dp[l][nr] > len+1) {
                                dp[l][nr] = len+1;
                                q.push({l,nr});
                                mv[l][nr] = {a,ct};
                                pr[l][nr] = {l,r};
                            }
                        }
                    } else {
                        if(a>l || l+ct>n || n-r-a-ct<0 || n-r>n) continue;
                        if(s.substr(l-a, ct)==s.substr(l,ct)) {
                            if(s.substr(n-r-a-ct,a)==s.substr(n-r-a,a)) {
                                int nl = l+ct, nr = r+a;
                                if(dp[nl][nr]>len+1) {
                                    dp[nl][nr] = len+1;
                                    q.push({nl,nr});
                                    mv[nl][nr] = {a,ct};
                                    pr[nl][nr] = {l,r};
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    string ans = "";
    pii st = {n,n};
    while(st.fi || st.se) {
        pii par = pr[st.fi][st.se];
        pii mvi = mv[st.fi][st.se];
        ans += (char)(mvi.se+'0');
        ans += (char)(mvi.fi+'0');
        st = par;
    }
    reverse(all(ans));
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}