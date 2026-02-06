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
int n,q;
int a[mxn];
bool vis[mxn+1];
pii ans[mxn+1];
vector<pii> v;

pii get_ans(int u) {
    if(vis[u]) {
        return ans[u];
    }
    vis[u] = 1;
    ans[u] = {0,0};
    for(int i=0;i<n;) {
        auto it = upper_bound(v.begin(),v.end(),make_pair(i,(int)(1e9)));
        it--;
        int j;
        if(i==it->se) {
            j = i;
            it++;
            if(it!=v.end()) {
                if(a[it->fi]<=a[it->se] && a[j]<=a[j+1]) {
                    j = it->se;
                } else if(a[it->fi]>a[it->se] && a[j]>a[j+1]) {
                    j = it->se;
                } else {
                    j++;
                }
            }
        } else {
            j = it->se;
        }
        ans[u].fi++;
        int butuh = max(min(u,n-i)-(j-i+1),0);
        ans[u].se += butuh;
        j +=butuh;
        i = j+1;
    }
    return ans[u];
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    for(int i=0;i<n;) {
        int j=i;
        if(j+1<n) {
            if(a[j+1]>=a[j]) {
                while(j+1<n && a[j+1]>=a[j]) {
                    j++;
                }
            } else {
                while(j+1<n && a[j+1]<a[j]) {
                    j++;
                }
            }
        }
        v.push_back({i,j});
        i = j+1;
    }
    cin >>q;
    while(q--) {
        int qi; cin >>qi;
        auto [ct, bad] = get_ans(qi);
        cout <<ct <<" " <<bad <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}