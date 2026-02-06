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

const int mxn=2e3+1,mxa=2e3;
int n,m;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>m;
    int sa=0,sb=0;
    int amx = 0;
    rep(i,0,n) {
        cin >>a[i];
        max_self(amx, a[i]);
        sa += a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
        sb += b[i];
    }
    max_self(amx, sb);
    if(sb>=sa) {
        cout <<sb <<"\n";
        return;
    }
    vector<bitset<mxn>> bs(mxn);
    bs[0].set(0);
    rep(i,0,n) {
        per(j,mxn-1,-1) {
            bs[j] = bs[j] | (bs[j] << a[i]);
            if(j>=a[i]) {
                bs[j] = bs[j] | bs[j-a[i]];
            }
        }
    }
    bitset<mxn> bsm;
    bsm.set(0);
    rep(i,0,m) {
        bsm = bsm | (bsm << b[i]);
    }
    vi vml(mxn);
    rep(j,0,mxn) {
        if(bsm[j]) {
            vml[j] = j;
        } else {
            vml[j] = vml[j-1];
        }
    }
    int ans = -1;
    int l = max((sa+sb+2)/3, amx), r = max(sa,sb);
    while(l<=r) {
        int mid = (l+r)/2;
        int s1 = mid, s2 = mid-sb;
        bool ok = 0;
        rep(i,0,min(s2,sa)+1) {
            rep(j,i,min(s1,sa)+1) {
                if(bs[i][j]) {
                    auto it = vml[s1-j];
                    int sisa = sa+sb - i-j - (it);
                    if(sisa<=s1) {
                        ok = 1;
                        break;
                    }
                }
            }
            if(ok) break;
        }
        if(ok) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}