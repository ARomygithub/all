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

const int mxn=1e5,mxa=1e5;
const ll mod = 998244353;
int n,k,t;
string s;

ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}

void solve() {
    cin >>n >>k;
    cin >>s;
    vector pr(2, vi(n+1,0));
    rep(c,0,2) {
        rep(i,1,n+1) {
            int cur = (s[i-1]-'0')==c;
            pr[c][i] = pr[c][i-1]+cur;
        }
    }
    vector<bool> ok(2,1);
    ll ans = 0;
    // rep(c,0,2) {
        per(i,n-k,-1) {
            debug() <<imie(i);
            // dominant
            vector<bool> ok_new(2,0);
            rep(c,0,2) {
                debug() <<imie(c);
                if(ok[c]) {
                    int j = i+k-1;
                    int le = n-k+1;
                    debug() <<imie(j) imie(le);
                    if((s[i]-'0')!=c) { 
                        if(i+k>=n || (s[i+k]-'0')!=1-c) {
                            ok_new[1-c] = 1; 
                        }
                    }
                    if(s[i]!='?' && (s[i]-'0')!=c) {
                        continue;
                    }
                    if(i==n-k) {
                        int ctc = pr[c][n] - pr[c][i+1];
                        int cte = pr[1-c][n] - pr[1-c][i+1];
                        int len = k-1;
                        if(pr[1-c][i]==0) {
                            for(int ctc2=(len/2)+1;ctc2<=len;ctc2++) {
                                ans = (ans + C(len-ctc-cte,ctc2-ctc))%mod;
                            }
                            if((len/2)-ctc>=0) {
                                ll cur = C(len-ctc-cte,(len/2)-ctc);
                                ans = (ans+cur)%mod;
                            }
                        }
                        continue;
                    }
                    if(le<=j) {
                        int len = j-le+1;
                        int idle = (le-(i+1))%2;
                        debug() <<imie(len) imie(idle);
                        if(idle%2) {
                            idle = 1-c;
                        } else {
                            idle = c;
                        }
                        int ctle = (len+1)/2;
                        int cta = len - (pr[0][j+1]-pr[0][le]) - (pr[1][j+1]-pr[1][j]);
                        int sisa = ctle - (pr[idle][j+1]-pr[idle][le]);
                        debug() <<imie(cta) imie(ctle) imie(sisa);
                        if(pr[1-c][i]==0) {
                            ans = (ans + C(cta,sisa))%mod;
                            debug() <<imie(ans);
                        }
                    } else {
                        if(pr[1-c][i]==0) {
                            ans = (ans + 1)%mod;
                        }
                        debug() <<imie(ans);
                    }
                    // wajib dominant, break
                }
            }
            ok.swap(ok_new);
        }
    // }
    rep(c,0,2) {
        if(ok[c]) {
            if((s[0]-'0')!=c) {
                ans = (ans+1)%mod;
            }
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init_fac();
    while(t--) {
        solve();
    }
}