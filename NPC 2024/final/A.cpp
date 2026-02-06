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

const int mxn=1e5;
ll n,s,k,h;
ll p[mxn],t[mxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>p[i];
    }
    rep(i,0,n) {
        cin >>t[i];
    }
    cin >>s >>k >>h;
    ll l=0,r=0;
    rep(i,0,n) {
        max_self(r, p[i]+t[i]*h);
    }
    ll ans = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        vector<ll> y(n);
        rep(i,0,n) {
            ll dif = (p[i]+t[i]*h)-mid;
            y[i] = max(0ll, (dif+s-1)/s);
        }
        ll sy = 0;
        rep(i,0,n) {
            sy += y[i];
        }
        bool ok = 1;
        if(sy>k*h) {
            ok = 0;
        }
        if(ok) {
            multiset<ll> ms;
            rep(i,0,h) {
                rep(j,0,k) {
                    ms.insert(i);
                }
            }
            rep(i,0,n) {
                rep(j,1,y[i]+1) {
                    // s*j <= p+t*mini
                    ll mini = (s*j-p[i] + t[i]-1)/t[i];
                    auto it = ms.lower_bound(mini);
                    if(it==ms.end()) {
                        ok = 0;
                        break;
                    } else {
                        ms.erase(it);
                    }
                }
                if(!ok) break;
            }
        }
        if(ok) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    // [..,ans]
    {
        ll mid = ans;
        vector<ll> y(n);
        rep(i,0,n) {
            ll dif = (p[i]+t[i]*h)-mid;
            y[i] = max(0ll, (dif+s-1)/s);
        }
        ll sy = 0;
        rep(i,0,n) {
            sy += y[i];
        }
        bool ok = 1;
        if(sy>k*h) {
            ok = 0;
        }
        if(ok) {
            multiset<ll> ms;
            rep(i,0,h) {
                rep(j,0,k) {
                    ms.insert(i);
                }
            }
            vector pd(n, vi());
            rep(i,0,n) {
                rep(j,1,y[i]+1) {
                    // s*j <= p+t*mini
                    ll mini = (s*j-p[i] + t[i]-1)/t[i];
                    auto it = ms.lower_bound(mini);
                    if(it==ms.end()) {
                        ok = 0;
                        break;
                    } else {
                        pd[i].push_back(*it);
                        ms.erase(it);
                    }
                }
                if(!ok) break;
            }
            // while(sz(ms)) {
            //     auto it = ms.begin();
            //     pd[rng()%n].push_back(*it);
            //     ms.erase(it);
            // }
            ll cur = 0;
            rep(i,0,n) {
                sort(all(pd[i]));
                ll tmp = p[i], hx = 0;
                for(auto px : pd[i]) {
                    if(px>hx) {
                        tmp += t[i]*(px-hx);
                        hx = px;
                    }
                    tmp = max(0ll,tmp-s);
                }
                if(h>hx) {
                    tmp += t[i]*(h-hx);
                    hx = h;
                }
                max_self(cur, tmp);
            }
            ans = cur;
        }        
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}