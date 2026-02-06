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

const int mxn=1e5,sq=316;
int n,q,t;
int a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
        assert(a[i]<=n);
    }
    // sort(a,a+n);
    vi ans;
    vi p(n+1,0);
    rep(i,0,n) {
        p[a[i]]++;
    }
    rep(i,1,n+1) {
        p[i] += p[i-1];
    }
    map<int,int> mp;
    rep(j,0,q) {
        int x; cin >>x;
        assert(x<=n);
        if(!mp.count(x)) {
            // if(x<=sq) {
            //     vi v;
            //     rep(i,0,n) {
            //         v.push_back(a[i]%x);
            //     }
            //     sort(all(v));
            //     mp[x] = v[n/2];
            // } else {
                int ansi = x-1;
                int l = 0, r = x-1;
                while(l<=r) {
                    int mid = (l+r)/2;
                    int cur = 0;
                    int ct = 0;
                    while(cur<=n) {
                        ct += p[min(cur+mid,n)]-(cur>0?p[cur-1]:0);
                        cur += x;
                    }
                    if(ct>(n/2)) {
                        ansi = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                mp[x] = ansi;
            // }
        }
        ans.push_back(mp[x]);
    }
    // cout <<"tes" <<endl;
    rep(i,0,q) {
        cout <<ans[i] <<" \n"[i==q-1];
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