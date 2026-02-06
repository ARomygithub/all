#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i< (b); ++i)
#define per(i, a, b) for(int i = a; i> (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

const int mxn = 2e5;
int n,s;
int w[mxn];

void solve() {
    cin >>n >>s;
    rep(i,0,n) {
        cin >>w[i];
    }
    sort(w,w+n);
    per(i,n-1,max(-1ll,n-3)) {
        w[i] = 3;
    }
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({w[i]/3, w[i]%3});
    }
    sort(all(v));
    int ans = 0;
    int l = 1, r = n;
    while(l<=r) {
        int mid = (l+r)/2;
        pii cur = {0,0};
        vector vc(3, vi());
        rep(i,0,mid) {
            vc[v[i].se].push_back(v[i].fi);
        }
        int sm = mid;
        while(sm>0) {
            int nx = (3-cur.se)%3;
            if(sz(vc[nx])) {
                cur.se += nx;
                cur.fi += vc[nx].back();
                if(cur.se>=3) {
                    cur.fi++;
                    cur.se -= 3;
                }
                vc[nx].pop_back();
            } else {
                rep(i,0,3) {
                    if(sz(vc[i])) {
                        if(cur.se>0 && cur.se+i <=3) {
                            cur.se += i;
                            cur.fi += vc[i].back();
                            if(cur.se > 0) {
                                cur.fi++;
                                cur.se = 0;
                            }
                        } else {
                            if(cur.se>0) cur.fi++;
                            cur.fi += vc[i].back();
                            cur.se = i;
                        }
                        vc[i].pop_back();                        
                        break;
                    }
                }
            }
            sm--;
        }
        if(cur <= pii{s,0}) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout <<ans <<"\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}