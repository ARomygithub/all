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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const ll mxn=1e18;
ll n,t;

void solve() {
    cin >>n;
    int ans = 0;
    rep(i,2,101) {
        ll ve = n;
        bool ok = 1;
        while(ve) {
            if((ve%i)!=0 && (ve%i)!=1) {
                ok = 0;
                break;
            }
            ve /=i;
        }
        if(ok) {
            if(i<=100) {
                ans++;
            }
            // ans2++;
            // assert(ok);
        } else {
            // assert(!ok);
        }
    }
    rep(bit,2,(1<<9)) {
        ll l=101, r = n;
        ll cur=-1;
        while(l<=r) {
            ll mid = (l+r)/2;
            ll temp = n;
            ll pow = 1;
            rep(j,0,9) {
                if((bit>>j)&1) {
                    temp -=pow;
                    if(temp<=0) {
                        if((bit>>(j+1))>0) {
                            temp = -1;
                        }
                        break;
                    } 
                }
                if(mid>(mxn/pow)) {
                    temp = (bit>>(j+1))>0?-1:1;
                    break;
                }
                pow *=mid;
            }
            if(temp==0) {
                cur = mid;
                break;
            } else if(temp>0) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        ans += (cur!=-1);
    }
    // cout <<"i " <<n <<"\n";
    cout <<ans <<"\n";
    // assert(ans==ans2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    // init();
    while(t--) {
        solve();
    }
    // rep(i,2,1001) {
    //     n = i;
    //     solve();
    // }
}