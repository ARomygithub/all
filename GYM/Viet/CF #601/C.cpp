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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n;
int ct[mxn+1];

void solve() {
    cin >>n;
    vector<vector<int>> v(n-2);
    vector<set<int>> vs(n+1);
    rep(i,0,n-2) {
        v[i].resize(3);
        cin >>v[i][0] >>v[i][1] >>v[i][2];
        rep(j,0,3) {
            ct[v[i][j]]++;
            vs[v[i][j]].insert(i);
        }
    }
    vector<int> ans;
    int u = -1, uv=-1;
    rep(i,1,n+1) {
        if(ct[i] == 1) {
            u = i;
            uv = *vs[u].begin();
            break;
        }
    }
    while(sz(ans)<n) {
        bool awal = sz(ans)==0;
        set<pii> st;
        for(int a: v[uv]) {
            vs[a].erase(uv);
            st.insert({sz(vs[a]), a});
            if(sz(vs[a])==1) {
                u = a;
            }
        }
        if(awal) {
            for(auto [sa, a]: st) {
                ans.push_back(a);
            }
        } else {
            for(auto [sa, a]: st) {
                if(a != ans[sz(ans)-1] && a != ans[sz(ans)-2]) {
                    ans.push_back(a);
                    break;
                }
            }
        }
        uv = *vs[u].begin();
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}