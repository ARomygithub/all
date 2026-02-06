#include <bits/stdc++.h>
using namespace std;

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
int n,m;
vector<int> adj[mxn];

void solve() {
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int u,v; cin >>u >>v; u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans1 = 0, ans2=0;
    for(int i=0;i<n;i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for(int i=0;i<n;i++) {
        int l = -1, r= n;
        if(sz(adj[i])>0) {
            auto it = lower_bound(adj[i].begin(), adj[i].end(), i);
            if(it != adj[i].end()) {
                min_self(r, *it);
            }
            if(it != adj[i].begin()) {
                it--;
                max_self(l, *it);
            }
            if(l!=-1) {
                auto it2 = lower_bound(adj[l].begin(), adj[l].end(), l);
                if(*it2 == i) {
                    int ll=-1, lr = r;
                    if(it != adj[i].begin()) {
                        it--;
                        max_self(ll, *it);
                    }
                    it2++;
                    if(it2 != adj[l].end()) {
                        min_self(lr, *it2);
                    }
                    it2--;
                    if(it2 != adj[l].begin()) {
                        it2--;
                        max_self(ll, *it2);
                    }
                    ans2 += 1ll*(l-ll)*(lr-i);
                }
            }
            if(r != n) {
                auto it2 = lower_bound(adj[r].begin(), adj[r].end(), r);
                it2--;
                if(*it2 == i) {
                    int rl = l, rr = n;
                    it = upper_bound(adj[i].begin(), adj[i].end(), r);
                    if(it != adj[i].end()) {
                        min_self(rr, *it);
                    }
                    it2++;
                    if(it2 != adj[r].end()) {
                        min_self(rr, *it2);
                    }
                    it2--;
                    if(it2 != adj[r].begin()) {
                        it2--;
                        max_self(rl, *it2);
                    }
                    ans2 += 1ll*(i-rl)*(rr-r);
                }
            }
        }
        ans1 += 1ll*(i-l)*(r-i);
    }
    ll ans = ans1+ans2;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}