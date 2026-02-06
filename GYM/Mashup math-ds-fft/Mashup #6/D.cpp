#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int mxn=80;
int n,k;
int d[mxn][mxn];
vector<pii> d2[mxn][mxn];
bool bad[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        rep(j,0,n) {
            cin >>d[i][j];
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            vector<pii> temp;
            rep(l,0,n) {
                if(l==i || l==j) continue;
                temp.push_back({d[i][l]+d[l][j],l});
            }
            sort(all(temp));
            rep(l,0,min(6,sz(temp))) {
                d2[i][j].push_back(temp[l]);
            }
        }
    }
    vi sp((k/2)+1,1);
    rep(i,1,sz(sp)) {
        sp[i] = sp[i-1]*n;
    }
    int ans = 2e9;
    rep(st,0,sp[sz(sp)-2]) {
        vi cur;
        rep(i,0,sz(sp)-1) {
            int tmp = (st%sp[i+1])/sp[i];
            cur.push_back(tmp);
            bad[tmp] = 1;
        }
        int now = 0;
        int mn = 0;
        rep(i,0,sz(cur)) {
            int nx = cur[(i+1)%sz(cur)];
            if(sz(d2[nx][cur[i]])) {
                mn += d2[nx][cur[i]][0].fi;
            } else {
                mn = 1e9;
            }
        }
        rep(i,0,sz(cur)) {
            int nx = cur[(i+1)%sz(cur)];
            auto& v2 = d2[nx][cur[i]];
            bool ok = 0;
            rep(j,0,sz(v2)) {
                auto [d2i,l] = v2[j];
                if(!bad[l]) {
                    now += d2i;
                    ok = 1;
                    break;
                }
            }
            if(!ok) {
                now = 2e9;
                break;
            }
            mn -= d2[nx][cur[i]][0].fi;
            if(now+mn>ans) break;
        }
        min_self(ans, now+mn);
        rep(i,0,sz(cur)) {
            bad[cur[i]] = 0;
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