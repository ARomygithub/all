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

const int mxn=40;
int n,ks,t;

void solve() {
    cin >>n >>ks;
    vector val(n+1, vector<int>());
    vector<int> mink(n+1,n*2);
    per(i,n,0) {
        val[i].resize(i);
        if(i>ks) continue;
        int l = 0,r=i-1;
        int ct = 0;
        bool odd = 1;
        while(l<=r) {
            if(odd) {
                val[i][l] = ct++;
                if(r!=l) {
                    val[i][r] = ct++;
                    r--;
                }
                l++;
            } else {
                val[i][r] = ct++;
                if(l!=r) {
                    val[i][l] = ct++;
                    l++;
                }
                r--;
            }
            // odd = !odd;
        }
        int temp = 0;
        rep(j,0,i) {
            rep(k,j+1,i) {
                max_self(temp, abs(k-j)+abs(val[i][k]-val[i][j]));
            }
        }
        mink[i] = temp;
    }
    mink[0] = 0;
    auto it = --upper_bound(mink.begin(),mink.end(),ks);
    int mx = it-mink.begin();
    int q = (n+mx-1)/mx;
    vector<int> ans(n), vali(n);
    int cti=1;
    for(int i=0;i<n;) {
        int j = min(n-1, i+mx-1);
        int len = j-i+1;
        rep(k,0,len) {
            ans[i+k] = val[len][k] + i;
            vali[i+k] = cti;
        }
        cti++;
        i = j+1;
    }
    rep(i,0,n) {
        cout <<ans[i]+1 <<" \n"[i==n-1];
    }
    cout <<q <<"\n";
    rep(i,0,n) {
        cout <<vali[i] <<" \n"[i==n-1];
    }
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