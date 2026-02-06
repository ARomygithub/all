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
int n,q;
int a[mxn];
ll pref[mxn];

void solve() {
    cin >>n >>q;
    vector<int> v;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        pref[i] = (i>0?pref[i-1]:0ll)+a[i];
        if(a[i]==-1) {
            v.push_back(i);
        }
    }
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        int it = lower_bound(v.begin(),v.end(),l)-v.begin();
        ll ans=0;
        if(a[l]!=-1) {
            ans +=pref[min(v[it]-1,r)]-pref[l-1];
            int it2 = upper_bound(v.begin(),v.end(),r)-v.begin()-1;
            if(r>v[it] && r>v[it2]) {
                ans += pref[r]-pref[max(v[it2],l-1)];
            }
        } else {
            int it2 = upper_bound(v.begin(),v.end(),r)-v.begin()-1;
            if(r>v[it2]) {
                ans += pref[r]-pref[max(v[it2],l-1)];
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}