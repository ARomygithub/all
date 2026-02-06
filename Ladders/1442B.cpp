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

const int mxn=2e5;
const ll mod = 998244353;
int n,k,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    map<int,int> mp;
    rep(i,0,k) {
        cin >>b[i];
        mp[b[i]] = (i+1)*(-1);
    }
    int l = 0;
    while(l<n) {
        if(mp[a[l]]>=0) break;
        l++;
    }
    rep(i,0,l-1) {
        if(mp[a[i]] > mp[a[i+1]]) {
            cout <<"0\n";
            return;
        }
    }
    int r = n-1;
    while(r>=0) {
        if(mp[a[r]]>=0) break;
        r--;
    }
    per(i,n-1,r+1) {
        if(mp[a[i]] > mp[a[i-1]]) {
            cout <<"0\n";
            return;
        }
    }
    ll ans = 1;
    for(int i = l; i<r; ) {
        if(mp[a[i]]<0) {
            int j = i;
            while(j<r && mp[a[j]]<0) {
                j++;
            }
            // cout <<j <<endl;
            int val = 0;
            int li = i, ri = j-1;
            bool ok = 1;
            while(li<=ri && ok) {
                if(mp[a[li]]>mp[a[ri]]) {
                    ok = mp[a[li]]< val;
                    val = mp[a[li]];
                    li++;
                } else {
                    ok = mp[a[ri]]< val;
                    val = mp[a[ri]];
                    ri--;
                }
            }
            if(!ok) {
                cout <<"0\n";
                return;
            }
            ans =ans*2%mod;
            i = j;
        } else {
            i++;
        }
    }
    cout <<ans <<"\n";
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