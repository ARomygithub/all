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

using pic = pair<int,char>;
const int mxn=1e5;
const ll mod=998244353;
int n,m;
pic pc[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    assert(b>=0);
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        cin >>pc[i].fi >>pc[i].se;
    }
    sort(pc,pc+m);
    vector<pic> pc1,pc2;
    rep(i,0,m) {
        if(pc[i].fi%2) {
            pc2.push_back(pc[i]);
        } else {
            pc1.push_back(pc[i]);
        }
    }
    ll ans1 = 0;
    {
        vector dp(2, vector<ll>(2,0));
        rep(i,0,sz(pc1)) {
            auto [p,c] = pc1[i];
            p = p/2;
            vector dp_new(2, vector<ll>(2,0));
            if(i==0) {
                int len = p;
                if(c=='G') {
                    ll ct = fastexpo(2,max(len-2,0)); // max(len-2,0)
                    dp_new[0][1] = ct;
                } else {
                    dp_new[1][0] = fastexpo(2ll,max(len-3,0));
                    if(len>2) {
                        dp_new[1][1] = (fastexpo(2ll,len-3) + 1)%mod;
                    } else if(len==2) {
                        dp_new[1][1] = 1;
                    }
                }
            } else {
                int len = p-(pc1[i-1].fi/2);
                rep(j,0,2) {
                    rep(k,0,2) {
                        if(j==0 && k==0) continue;
                        if(j==1 && k==0) {
                            if(len==1) {
                                if(c=='B') {
                                    dp_new[1][1] = (dp_new[1][1] + dp[1][0])%mod;
                                }
                                continue;
                            } else {
                                len--;
                            }
                        }
                        if(j==0) {
                            if(c=='G') {
                                ll ct0 = fastexpo(2,max(len-2,0));
                                dp_new[0][1] = (dp_new[0][1] + ct0*dp[j][k]%mod)%mod;
                            } else {
                                ll ct1 = fastexpo(2,max(len-3,0));
                                dp_new[1][0] = (dp_new[1][0] + ct1*dp[j][k]%mod)%mod;
                                ll ct2 = 0;
                                if(len>2) {
                                    ct2 = (fastexpo(2ll,len-3) + 1)%mod;
                                } else if(len==2) {
                                    ct2 = 1;
                                }
                                dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k]%mod)%mod;
                            }
                        } else {
                            if(c=='G') {
                                ll ct = 0;
                                if(len<3) {
                                    ct = len;
                                } else {
                                    ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                }
                                dp_new[0][1] = (dp_new[0][1] + ct*dp[j][k]%mod)%mod;
                            } else {
                                if(len>1) {
                                    ll ct = 0;
                                    len--;
                                    if(len<3) {
                                        ct = len;
                                    } else {
                                        ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                    }
                                    dp_new[1][0] = (dp_new[1][0] + ct*dp[j][k]%mod)%mod;
                                    ll ct2 = len;
                                    if(len>2) {
                                        ct2 = (ct2 + fastexpo(2,max(len-2,0)))%mod;
                                        ct2 = (ct2 -1)%mod;
                                    }
                                    dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k])%mod;
                                } else {
                                    dp_new[1][1] = (dp_new[1][1] + dp[j][k])%mod;
                                }
                            }
                        }
                    }
                }
            }
            dp.swap(dp_new);
            debug() <<"pc1 " <<imie(dp);
        }
        int ls = (n-(n%2))/2;
        int pls = sz(pc1)>0?pc1.back().fi/2:0;
        debug() <<imie(ls) imie(pls);
        if(sz(pc1)==0) {
            dp[0][1] = 1;
            dp[1][0] = 0;
            dp[1][1] = 0;
        }
        if(pls<ls) {
            char c = 'B';
            {
                int len = ls-pls;
                vector dp_new(2, vector<ll>(2,0));
                rep(j,0,2) {
                    rep(k,0,2) {
                        if(j==0 && k==0) continue;
                        if(j==1 && k==0) {
                            if(len==1) {
                                if(c=='B') {
                                    dp_new[1][1] = (dp_new[1][1] + dp[1][0])%mod;
                                }
                                continue;
                            } else {
                                len--;
                            }
                        }
                        if(j==0) {
                            if(c=='G') {
                                ll ct0 = fastexpo(2,max(len-2,0));
                                dp_new[0][1] = (dp_new[0][1] + ct0*dp[j][k]%mod)%mod;
                            } else {
                                ll ct1 = fastexpo(2,max(len-3,0));
                                dp_new[1][0] = (dp_new[1][0] + ct1*dp[j][k]%mod)%mod;
                                ll ct2 = 0;
                                if(len>2) {
                                    ct2 = (fastexpo(2ll,len-3) + 1)%mod;
                                } else if(len==2) {
                                    ct2 = 1;
                                }
                                dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k]%mod)%mod;
                            }
                        } else {
                            if(c=='G') {
                                ll ct = 0;
                                if(len<3) {
                                    ct = len;
                                } else {
                                    ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                }
                                dp_new[0][1] = (dp_new[0][1] + ct*dp[j][k]%mod)%mod;
                            } else {
                                if(len>1) {
                                    ll ct = 0;
                                    len--;
                                    if(len<3) {
                                        ct = len;
                                    } else {
                                        ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                    }
                                    dp_new[1][0] = (dp_new[1][0] + ct*dp[j][k]%mod)%mod;
                                    ll ct2 = len;
                                    if(len>2) {
                                        ct2 = (ct2 + fastexpo(2,max(len-2,0)))%mod;
                                        ct2 = (ct2 -1)%mod;
                                    }
                                    dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k])%mod;
                                } else {
                                    dp_new[1][1] = (dp_new[1][1] + dp[j][k])%mod;
                                }
                            }
                        }
                    }
                }
                ans1 = (ans1 + dp_new[0][1])%mod;
                ans1 = (ans1 + dp_new[1][1])%mod;
            }
            c = 'G';
            {
                int len = ls-pls;
                vector dp_new(2, vector<ll>(2,0));
                rep(j,0,2) {
                    rep(k,0,2) {
                        if(j==0 && k==0) continue;
                        if(j==1 && k==0) {
                            if(len==1) {
                                if(c=='B') {
                                    dp_new[1][1] = (dp_new[1][1] + dp[1][0])%mod;
                                }
                                continue;
                            } else {
                                len--;
                            }
                        }
                        if(j==0) {
                            if(c=='G') {
                                ll ct0 = fastexpo(2,max(len-2,0));
                                dp_new[0][1] = (dp_new[0][1] + ct0*dp[j][k]%mod)%mod;
                            } else {
                                ll ct1 = fastexpo(2,max(len-3,0));
                                dp_new[1][0] = (dp_new[1][0] + ct1*dp[j][k]%mod)%mod;
                                ll ct2 = 0;
                                if(len>2) {
                                    ct2 = (fastexpo(2ll,len-3) + 1)%mod;
                                } else if(len==2) {
                                    ct2 = 1;
                                }
                                dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k]%mod)%mod;
                            }
                        } else {
                            if(c=='G') {
                                ll ct = 0;
                                if(len<3) {
                                    ct = len;
                                } else {
                                    ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                }
                                dp_new[0][1] = (dp_new[0][1] + ct*dp[j][k]%mod)%mod;
                            } else {
                                if(len>1) {
                                    ll ct = 0;
                                    len--;
                                    if(len<3) {
                                        ct = len;
                                    } else {
                                        ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                    }
                                    dp_new[1][0] = (dp_new[1][0] + ct*dp[j][k]%mod)%mod;
                                    ll ct2 = len;
                                    if(len>2) {
                                        ct2 = (ct2 + fastexpo(2,max(len-2,0)))%mod;
                                        ct2 = (ct2 -1)%mod;
                                    }
                                    dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k])%mod;
                                } else {
                                    dp_new[1][1] = (dp_new[1][1] + dp[j][k])%mod;
                                }
                            }
                        }
                    }
                }
                ans1 = (ans1 + dp_new[0][1])%mod;
                ans1 = (ans1 + dp_new[1][1])%mod;
            }
        } else {
            ans1 = (dp[0][1] + dp[1][1])%mod;
        }
    }
    ll ans2 = 0;
    {
        vector dp(2, vector<ll>(2,0));
        rep(i,0,sz(pc2)) {
            auto [p,c] = pc2[i];
            p = (p+1)/2;
            vector dp_new(2, vector<ll>(2,0));
            if(i==0) {
                int len = p;
                if(c=='G') {
                    ll ct = fastexpo(2,max(len-2,0)); // max(len-2,0)
                    dp_new[0][1] = ct;
                } else {
                    dp_new[1][0] = fastexpo(2ll,max(len-3,0));
                    if(len>2) {
                        dp_new[1][1] = (fastexpo(2ll,len-3) + 1)%mod;
                    } else if(len==2) {
                        dp_new[1][1] = 1;
                    }
                }
            } else {
                int len = p-((pc2[i-1].fi+1))/2;
                rep(j,0,2) {
                    rep(k,0,2) {
                        if(j==0 && k==0) continue;
                        if(j==1 && k==0) {
                            if(len==1) {
                                if(c=='B') {
                                    dp_new[1][1] = (dp_new[1][1] + dp[1][0])%mod;
                                }
                                continue;
                            } else {
                                len--;
                            }
                        }
                        if(j==0) {
                            if(c=='G') {
                                ll ct0 = fastexpo(2,max(len-2,0));
                                dp_new[0][1] = (dp_new[0][1] + ct0*dp[j][k]%mod)%mod;
                            } else {
                                ll ct1 = fastexpo(2,max(len-3,0));
                                dp_new[1][0] = (dp_new[1][0] + ct1*dp[j][k]%mod)%mod;
                                ll ct2 = 0;
                                if(len>2) {
                                    ct2 = (fastexpo(2ll,len-3) + 1)%mod;
                                } else if(len==2) {
                                    ct2 = 1;
                                }
                                dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k]%mod)%mod;
                            }
                        } else {
                            if(c=='G') {
                                ll ct = 0;
                                if(len<3) {
                                    ct = len;
                                } else {
                                    ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                }
                                dp_new[0][1] = (dp_new[0][1] + ct*dp[j][k]%mod)%mod;
                            } else {
                                if(len>1) {
                                    ll ct = 0;
                                    len--;
                                    if(len<3) {
                                        ct = len;
                                    } else {
                                        ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                    }
                                    dp_new[1][0] = (dp_new[1][0] + ct*dp[j][k]%mod)%mod;
                                    ll ct2 = len;
                                    if(len>2) {
                                        ct2 = (ct2 + fastexpo(2,max(len-2,0)))%mod;
                                        ct2 = (ct2 -1)%mod;
                                    }
                                    dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k])%mod;
                                } else {
                                    dp_new[1][1] = (dp_new[1][1] + dp[j][k])%mod;
                                }
                            }
                        }
                    }
                }
            }
            dp.swap(dp_new);
            debug() <<"pc2 " <<imie(dp);            
        }
        int ls = n;
        if((n%2)==0) {
            ls--;
        }
        ls = (ls+1)/2;
        int pls = 0;
        if(sz(pc2)) {
            pls = pc2.back().fi;
            pls = (pls+1)/2;
        } else {
            dp[0][1] = 1;
            dp[1][0] = 0;
            dp[1][1] = 0;            
        }
        debug() <<imie(ls) imie(pls);
        if(pls<ls) {
                char c = 'B';
                {
                    int len = ls-pls;
                    debug() <<imie(len);
                    vector dp_new(2, vector<ll>(2,0));                    
                    rep(j,0,2) {
                        rep(k,0,2) {
                            if(j==0 && k==0) continue;
                            if(j==1 && k==0) {
                                if(len==1) {
                                    if(c=='B') {
                                        dp_new[1][1] = (dp_new[1][1] + dp[1][0])%mod;
                                    }
                                    continue;
                                } else {
                                    len--;
                                }
                            }
                            if(j==0) {
                                if(c=='G') {
                                    ll ct0 = fastexpo(2,max(len-2,0));
                                    dp_new[0][1] = (dp_new[0][1] + ct0*dp[j][k]%mod)%mod;
                                } else {
                                    ll ct1 = fastexpo(2,max(len-3,0));
                                    dp_new[1][0] = (dp_new[1][0] + ct1*dp[j][k]%mod)%mod;
                                    ll ct2 = 0;
                                    if(len>2) {
                                        ct2 = (fastexpo(2ll,len-3) + 1)%mod;
                                    } else if(len==2) {
                                        ct2 = 1;
                                    }
                                    dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k]%mod)%mod;
                                }
                            } else {
                                if(c=='G') {
                                    ll ct = 0;
                                    if(len<3) {
                                        ct = len;
                                    } else {
                                        ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                    }
                                    dp_new[0][1] = (dp_new[0][1] + ct*dp[j][k]%mod)%mod;
                                } else {
                                    if(len>1) {
                                        ll ct = 0;
                                        len--;
                                        if(len<3) {
                                            ct = len;
                                        } else {
                                            ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                        }
                                        dp_new[1][0] = (dp_new[1][0] + ct*dp[j][k]%mod)%mod;
                                        ll ct2 = len;
                                        if(len>2) {
                                            ct2 = (ct2 + fastexpo(2,max(len-2,0)))%mod;
                                            ct2 = (ct2 -1)%mod;
                                        }
                                        dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k])%mod;
                                    } else {
                                        dp_new[1][1] = (dp_new[1][1] + dp[j][k])%mod;
                                    }
                                }
                            }
                        }
                    }
                    ans2 = (ans2 + dp_new[0][1])%mod;
                    ans2 = (ans2 + dp_new[1][1])%mod;                    
                    debug() <<imie(dp_new);                
                }
                c = 'G';
                {
                    int len = ls-pls;
                    debug() <<imie(len);
                    vector dp_new(2, vector<ll>(2,0));
                    rep(j,0,2) {
                        rep(k,0,2) {
                            if(j==0 && k==0) continue;
                            if(j==1 && k==0) {
                                if(len==1) {
                                    if(c=='B') {
                                        dp_new[1][1] = (dp_new[1][1] + dp[1][0])%mod;
                                    }
                                    continue;
                                } else {
                                    len--;
                                }
                            }
                            if(j==0) {
                                if(c=='G') {
                                    ll ct0 = fastexpo(2,max(len-2,0));
                                    dp_new[0][1] = (dp_new[0][1] + ct0*dp[j][k]%mod)%mod;
                                } else {
                                    ll ct1 = fastexpo(2,max(len-3,0));
                                    dp_new[1][0] = (dp_new[1][0] + ct1*dp[j][k]%mod)%mod;
                                    ll ct2 = 0;
                                    if(len>2) {
                                        ct2 = (fastexpo(2ll,len-3) + 1)%mod;
                                    } else if(len==2) {
                                        ct2 = 1;
                                    }
                                    dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k]%mod)%mod;
                                }
                            } else {
                                if(c=='G') {
                                    ll ct = 0;
                                    if(len<3) {
                                        ct = len;
                                    } else {
                                        ct = (fastexpo(2,max(len-2,0))+1)%mod;
                                    }
                                    dp_new[0][1] = (dp_new[0][1] + ct*dp[j][k]%mod)%mod;
                                } else {
                                    if(len>1) {
                                        ll ct = 0;
                                        len--;
                                        if(len<3) {
                                            ct = len;
                                        } else {
                                            ct = (fastexpo(2,len-2)+1)%mod;
                                        }
                                        dp_new[1][0] = (dp_new[1][0] + ct*dp[j][k]%mod)%mod;
                                        ll ct2 = len;
                                        if(len>2) {
                                            ct2 = (ct2 + fastexpo(2,len-2))%mod;
                                            ct2 = (ct2 -1)%mod;
                                        }
                                        dp_new[1][1] = (dp_new[1][1] + ct2*dp[j][k])%mod;
                                    } else {
                                        dp_new[1][1] = (dp_new[1][1] + dp[j][k])%mod;
                                    }
                                }
                            }
                        }
                    }
                    ans2 = (ans2 + dp_new[0][1])%mod;
                    ans2 = (ans2 + dp_new[1][1])%mod;                    
                    debug() <<imie(dp_new);   
                }
        } else {
            ans2 = (dp[0][1] + dp[1][1])%mod;
        }
    }
    debug() <<imie(ans1) imie(ans2);
    ll ans = ans1*ans2%mod;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}