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
const ll mxa = 1e18;
int n;
ll a[mxn],x;

void solve() {
    cin >>n >>x;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    ll mx = a[n-1], mx2 = a[n-2];
    vector<ll> cand;
    int bts = 0;
    per(i,n-2,-1) {
        if(a[i]*2 > mx2) {
            cand.push_back(a[i]*2);
            if(a[i]*2 >mx) {
                max_self(bts, sz(cand));
            }
        }
    }
    rep(i,1,sz(cand)) {
        cand[i] += cand[i-1];
    }
    ll ans = -1;
    ll l = 1, r= (mxa+mx-1)/mx;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll tmp = 0;
        tmp += mx*((mid)/2);
        tmp += mx*2;
        ll sisa = mid/2;
        if(sisa>0) {
            if(sz(cand)>0) {
                ll tmp2 = min(sisa,sz(cand)*1ll);
                tmp += cand[tmp2-1];
                sisa -= tmp2;
            }
            tmp += sisa*mx2;
        }
        if((sz(cand)+1)*2 >= mid) {
            ll tmp3 = 0;
            ll ct = mid;
            tmp3 += mx*2;
            ct--;
            if(ct>0 && sz(cand)>0) {
                if(bts>0) {
                    ll tmpb = min(1ll*bts, ct);
                    tmp3 += cand[tmpb-1];
                    ct -= tmpb;
                    ll tmp5 = min(ct, tmpb);
                    tmp3 += tmp5*mx;
                    ct -= tmp5;
                }
                ll ua = (ct+1)/2, ub = ct-ua;
                tmp3 += ua*mx;
                tmp3 += cand[bts+ub-1]-cand[bts-1]; 
                ct = 0;
            }
            tmp3 += ct*mx;
            max_self(tmp, tmp3);
        }

        if(tmp>=x) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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