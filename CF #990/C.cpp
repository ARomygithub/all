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
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int mxn=2e5;
int n,t;
using piii = pair<pii,int>;

void solve() {
    cin >>n;
    vector<piii> v;
    rep(i,0,n) {
        int x,y; cin >>x >>y;
        v.push_back({{x,y},i});
    }
    sort(all(v));
    int ans = 0;
    pii pa = {0,0};
    int l = 1, r= (n/4);
    while(l<=r) {
        int mid = (l+r)/2;
        Tree<pii> loset, roset;
        rep(i,0,n) {
            roset.insert({v[i].fi.se,i});
        }
        bool ok = 0;
        pii pai = {-1,-1};
        for(int i=0;i<n;) {
            int j = i;
            while(j<n && v[j].fi.fi==v[i].fi.fi) {
                roset.erase({v[j].fi.se,j});
                loset.insert({v[j].fi.se,j});
                j++;
            }
            int xa = v[i].fi.fi+1;
            if(sz(loset)>=mid*2 && sz(roset)>=mid*2) {
                int lal = (*loset.find_by_order(mid-1)).fi;
                int ral = (*loset.find_by_order(sz(loset)-mid)).fi;
                int lar = (*roset.find_by_order(mid-1)).fi;
                int rar = (*roset.find_by_order(sz(roset)-mid)).fi;
                max_self(lar, lal);
                min_self(rar, ral);
                if(lar<rar) {
                    ok = 1;
                    pai = {xa, lar+1};
                    break;
                }
            }
            i = j;
        }
        if(ok) {
            ans = mid;
            pa = pai;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout <<ans <<"\n";
    cout <<pa.fi <<" " <<pa.se <<"\n";
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