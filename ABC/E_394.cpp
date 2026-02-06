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

const int mxn=100;
int n;
string ed[mxn];
using ipii = pair<int,pii>;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>ed[i];
    }
    vector ans(n, vi(n, 1e9));
    priority_queue<ipii,vector<ipii>,greater<ipii>> pq;
    rep(i,0,n) {
        ans[i][i] = 0;
        pq.push({0,{i,i}});
    }
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            if(ed[i][j]!='-') {
                ans[i][j] = 1;
                pq.push({1,{i,j}});
            }
        }
    }
    while(sz(pq)) {
        auto [d,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        if(ans[i][j]<d) continue;
        rep(i2,0,n) {
            rep(j2,0,n) {
                if(ed[i2][i]!='-' && ed[j][j2]!='-' && ed[i2][i]==ed[j][j2]) {
                    if(ans[i2][j2]> d+2) {
                        ans[i2][j2] = d+2;
                        pq.push({d+2,{i2,j2}});
                    }
                }
            }
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            int cur = ans[i][j];
            if(cur==1e9) {
                cur = -1;
            }
            cout <<cur <<" \n"[j==n-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}