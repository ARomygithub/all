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

const int mxn=5555;
int n,k;
ll a[mxn+1];

void solve() {
    cin >>n >>k;
    vector<ll> v;
    rep(i,1,n+1) {
        cin >>a[i];
        if((a[i]%2)==0) {
            v.push_back(a[i]);
        }
    }
    if(sz(v)<=2) {
        cout <<sz(v) <<"\n";
        return;
    }
    int ans = 2;
    int i=1, j=0;
    while(i+1<sz(v)) {
        ll bts = (v[i]+v[j]+k-1)/k;
        int id = lower_bound(all(v),bts)-v.begin();
        max_self(id,i+1);
        if(id<sz(v)) {
            j = i;
            i = id;
            ans++;
        } else {
            break;
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