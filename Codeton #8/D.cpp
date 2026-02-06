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

const int mxn=1e3;
int n,k,t;

void solve() {
    cin >>n >>k;
    vector a(n, vector<int>());
    rep(i,0,n) {
        a[i].resize(n-i);
        rep(j,0,n-i) {
            cin >>a[i][j];
        }
    }
    vector ans(n, vector<int>());
    ans[0].push_back(max(0,a[0][0]));
    ans[0].push_back(min(0,a[0][0]));
    rep(i,1,n) {
        priority_queue<pii> pq;
        pq.push({ans[i-1][0],i-1});
        vector<int> idx(i,0);
        rep(j,0,i-1) {
            pq.push({ans[j][0]+ a[j+2][i-(j+2)],j});
        }
        pq.push({a[1][i-1],-1});
        pq.push({a[0][i],-2});
        while(sz(pq) && sz(ans[i])<k) {
            auto [ai, id] = pq.top(); pq.pop();
            ans[i].push_back(ai);
            if(id>=0) {
                idx[id]++;
                if(idx[id]<sz(ans[id])) {
                    int temp = ans[id][idx[id]];
                    if(id<i-1) {
                        temp += a[id+2][i-(id+2)];
                    }
                    pq.push({temp,id});
                }
            }
        }
    }
    rep(i,0,k) {
        cout <<ans[n-1][i] <<" \n"[i==k-1];
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