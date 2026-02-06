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
#define all(x) (x).begin(),(x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
int n,k;
ll p;

ll qry(vector<vector<ll>>& pref, int x1, int y1, int x2, int y2) {
    ll ret = pref[x1][y1];
    if(x2>0) {
        ret -= pref[x2-1][y1];
    }
    if(y2>0) {
        ret -= pref[x1][y2-1];
    }
    if(x2>0 && y2>0) {
        ret += pref[x2-1][y2-1];
    }
    ret = ((ret%p) + p)%p; 
    return ret;
}

void solve() {
    cin >>n >>k >>p;
    vector dp(k+1, vector(1, vector<ll>(1,0ll)));
    dp[0][0][0] = 1ll;
    rep(len,2,n+1) {
        vector dp_new(k+1, vector(len, vector<ll>(len,0ll)));
        rep(ki,0,k+1) {
            rep(la,0,len) {
                rep(lb,0,len) {
                    ll temp = 0;
                    if(ki>0) {
                        int x2=la,y2=lb,x1=len-2,y1=len-2;
                        if(x1>=x2 && y1>=y2) {
                            temp = (temp + qry(dp[ki-1],x1,y1,x2,y2)) %p;
                        }
                        x1 = la-1,y1=lb-1, x2=0,y2=0;
                        if(x1>=x2 && y1>=y2) {
                            temp = (temp + qry(dp[ki-1],x1,y1,x2,y2))%p;
                        } 
                    }
                    int x1 = la-1,y1 = len-2, x2=0, y2 = lb;
                    if(x1>=x2 && y1>=y2) {
                        temp = (temp + qry(dp[ki],x1,y1,x2,y2)) %p;
                    }
                    x1 = len-2, y1=lb-1, x2=la, y2=0;
                    if(x1>=x2 && y1>=y2) {
                        temp = (temp + qry(dp[ki],x1,y1,x2,y2))%p;
                    }
                    // if(temp>0) {
                    //     cout <<"tes" <<endl;
                    // }
                    dp_new[ki][la][lb] = temp;
                }
            }
        }
        dp.swap(dp_new);
        rep(ki,0,k+1) {
            rep(la,0,len) {
                ll temp = 0;
                rep(lb,0,len) {
                    temp = (temp + dp[ki][la][lb])%p;
                    dp[ki][la][lb] = temp;
                    if(la>0) {
                        dp[ki][la][lb] = (dp[ki][la][lb] + dp[ki][la-1][lb])%p;
                    }
                }
            }
        }
    }
    ll ans = dp[k][n-1][n-1];
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}