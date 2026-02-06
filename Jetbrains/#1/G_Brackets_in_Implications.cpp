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
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    if(a[n-1]==1) {
        cout <<"NO\n";
        return;
    }
    int suf = 0;
    pii ada = {-1,-1};
    per(i,n-1,-1) {
        if(a[i]==0) {
            suf++;
        } else {
            per(j,i-1,-1) {
                if(a[j]==0) {
                    int k = j;
                    while(k>0 && a[k-1]==0) {
                        k--;
                    }
                    ada = {k,j};
                    break;
                }
            }
            break;
        }
    }
    if(suf==2 && ada.fi==-1) {
        cout <<"NO\n";
        return;
    }
    cout <<"YES\n";
    vi op(n,0), cl(n,0);
    if(suf>=3) {
        op[n-3]++;
        cl[n-2]++;
    } else if(suf==2) {
        per(i,n-suf-1,ada.se) {
            op[i]++;
            cl[n-suf]++;
        }
        op[ada.se]++;
        cl[n-suf]++;
    }
    rep(i,0,n) {
        rep(j,0,op[i]) {
            cout <<"(";
        }
        cout <<a[i];
        rep(j,0,cl[i]) {
            cout <<")";
        }
        if(i+1<n) {
            cout <<"->";
        } else {
            cout <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}