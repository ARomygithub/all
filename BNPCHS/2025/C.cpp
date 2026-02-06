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
int n;

void solve() {
    cin >>n;
    vector<pii> v;
    rep(i,0,n) {
        int l,r; cin >>l >>r;
        v.push_back({l,r});
    }
    sort(all(v));
    vi ans(n+1,-1);
    multiset<int> ms;
    int ct = 0;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && v[j].fi == v[i].fi) {
            j++;
        }
        int awl = v[i].fi;
        rep(k,i,j) {
            while(sz(ms) && (*ms.begin())<awl) {
                int er = *ms.begin();
                while(sz(ms) && (*ms.begin()) == er) {
                    ms.erase(ms.begin());
                    ct--;
                }
                if(er+1 < awl) {
                    if(ans[ct]==-1) {
                        ans[ct] = er+1;
                    }
                }
            }
            ct++;
            ms.insert(v[k].se);
        }
        if(ans[ct]==-1) {
            ans[ct] = awl;
        }
        i = j;
    }
    while(sz(ms)) {
        int er = *ms.begin();
        while(sz(ms) && (*ms.begin()) == er) {
            ms.erase(ms.begin());
            ct--;
        }
        if(ans[ct]==-1) {
            ans[ct] = er+1;
        }        
    }
    rep(i,1,n+1) {
        cout <<ans[i] <<" \n"[i==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}