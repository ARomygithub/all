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

const int mxn=10;
int n,m,k;
string s[mxn];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>s[i];
    }
    // rep(i,0,n) {
    //     cout <<s[i] <<endl;
    // }
    int ans = n+m;
    rep(i,0,(1<<(n-1))) {
        vector<int> en;
        rep(j,0,n-1) {
            if((i>>j)&1) {
                en.push_back(j);
                // cout <<"i " <<i <<"\n";
            }
        }
        en.push_back(n-1);
        int temp = sz(en)-1;
        // cout <<"i " <<i <<endl;
        vector<vector<int>> vv;
        rep(j,0,sz(en)) {
            int st = j>0?en[j-1]+1:0;
            vector<int> v(m,0);
            rep(l,st,en[j]+1) {
                rep(o,0,m) {
                    v[o] += s[l][o]-'0';
                    // cout <<l <<" " <<o <<endl;
                    // cout <<"s l o" <<s[l][o] <<" m" <<m <<endl;
                }
            }
            vv.push_back(v);
        }
        vector<int> sum(sz(en),0);
        rep(j,0,m) {
            bool ok=1;
            rep(l,0,sz(en)) {
                if(sum[l]+vv[l][j]>k) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                rep(l,0,sz(en)) {
                    sum[l] += vv[l][j];
                }
            } else {
                temp++;
                rep(l,0,sz(en)) {
                    if(vv[l][j]<=k) {
                        sum[l] = vv[l][j];
                    } else {
                        temp = 1e9;
                        break;
                    }
                }
                if(temp>=1e9) break;
            }
        }
        // cout <<temp <<endl;
        min_self(ans,temp);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}