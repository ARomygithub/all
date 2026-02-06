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

const int mxn=1e3;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector mp(n, map<int,int>());
    vector dp(n, set<pii>());
    int ats = 2;
    rep(i,1,n) {
        // int cur = 2;
        per(j,i-1,-1) {
            if(sz(dp[j])) {
                auto it = dp[j].end();
                do {
                    it--;
                    auto [len,xr] = *it;
                    int a1 = xr^a[j];
                    if(ats >= len + (n-i)) break;
                    // if(len+1 <= cur) break;
                    if(1ll*(a1^a[j]^a[i]) == 7ll*(a1&a[j]&a[i])) {
                        int xrn = a[j]^a[i];
                        int lenn = len+1;
                        if(mp[i].count(xrn)) {
                            int prv = mp[i][xrn]; 
                            if(prv < lenn) {
                                dp[i].erase({prv,xrn});
                                mp[i][xrn] = lenn;
                                dp[i].insert({lenn,xrn});
                            }
                        } else {
                            mp[i][xrn] = lenn;
                            dp[i].insert({lenn,xrn});
                        }
                        max_self(ats, lenn);
                        // max_self(cur, lenn);
                        break;
                    }
                } while(it !=dp[j].begin());
            }
        }
        if(ats >= 1+(n-i)) continue;
        rep(j,0,i) {
            int xr = a[j]^a[i];
            if(!mp[i].count(xr)) {
                mp[i][xr] = 2;
                dp[i].insert({2,xr});
            }
        }
    }
    if(ats<3) {
        ats = 0;
    }
    cout <<n-ats <<"\n";
    vi ans,ans2;
    int tg = -1;
    per(i,n-1,-1) {
        if(tg!=-1) {
            if(a[i]==tg) {
                if(ats==1) {
                    ans.push_back(a[i]);
                    ans2.push_back(i);
                    break;
                }
                for(auto [len,xr]: dp[i]) {
                    if(len==ats) {
                        ans.push_back(a[i]);
                        ans2.push_back(i);
                        tg = a[i]^(xr);
                        ats--;
                        break;
                    }
                }
            }
        } else {
            if(sz(dp[i])) {
                auto it = --dp[i].end();
                if(it->fi ==ats) {
                    ans.push_back(a[i]);
                    ans2.push_back(i);
                    tg = a[i]^(it->se);
                    ats--;    
                }
            }
        }
    }
    reverse(all(ans));
    reverse(all(ans2));
    debug() <<imie(ans);
    debug() <<imie(ans2);
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