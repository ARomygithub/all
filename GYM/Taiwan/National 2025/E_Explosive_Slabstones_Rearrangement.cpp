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

const int mxn=500;
int n,m,k,t;
pii st, en;
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

void solve() {
    cin >>n >>m >>k;
    vector<pii> bl(k);
    rep(i,0,k) {
        cin >>bl[i].fi >>bl[i].se; bl[i].fi--, bl[i].se--;
    }
    cin >>st.fi >>st.se; st.fi--, st.se--;
    cin >>en.fi >>en.se; en.fi--, en.se--;
    int l = 0, r = k;
    per(i,k-1,-1) {
        if(bl[i].fi>=st.fi && bl[i].fi<=en.fi && bl[i].se>=st.se && bl[i].se<=en.se) {
            l = i+1;
            break;
        }
    }
    int ans = -1;
    while(l<=r) {
        int mid = (l+r)/2;
        queue<pii> q;
        vector udh(n, vector<bool>(m,0));
        int ctudh = 0;
        int blk = 0;
        vector stt(n, vector<bool>(m,0));
        rep(i,0,mid) {
            stt[bl[i].fi][bl[i].se] = 1;
        }
        rep(i,st.fi,en.fi+1) {
            rep(j,st.se,en.se+1) {
                udh[i][j] = 1;
                q.push({i,j});
            }
        }
        rep(i,mid,k) {
            udh[bl[i].fi][bl[i].se] = 1;
        }
        auto e = [&](int i, int j) -> bool {
            return i>=0&&i<n&&j>=0&&j<m&&(!udh[i][j]);
        };
        while(sz(q)) {
            auto [i,j] = q.front(); q.pop();
            ctudh++;
            blk += stt[i][j];
            rep(ki,0,4) {
                int ii=i+di[ki], jj=j+dj[ki];
                if(e(ii,jj)) {
                    udh[ii][jj] = 1;
                    q.push({ii,jj});
                }
            }
        }
        int larang = (en.fi-st.fi+1)*(en.se-st.se+1);
        if(ctudh-larang >= blk) {
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
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}