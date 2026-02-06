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

const int mxn=4e5;
ll n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    ll ans1 = n*n/2 -1, ans2=n*n;
    {
        ll temp = 0;
        vector<int> v, v2(2);
        int id=0;
        rep(i,0,n) {
            if(a[i]==(n/2)) {
                v2[0] = i;
            } else if(a[i] == (n/2)+1) {
                v2[1] = i;
            } else {
                if(a[i]<=n/2) {
                    v.push_back(id);
                }
                id++;
            }
        }
        temp += v2[0]+(n-1-v2[1]);
        if(v2[0]>v2[1]) {
            temp--;
        }
        int idx = n-3;
        per(i,sz(v)-1,-1) {
            temp += abs(v[i]-idx);
            idx -=2;
        }
        min_self(ans2, temp);
    }
    {
        ll temp = 0;
        vector<int> v, v2(2);
        int id=0;
        rep(i,0,n) {
            if(a[i]==(n/2)) {
                v2[0] = i;
            } else if(a[i] == (n/2)+1) {
                v2[1] = i;
            } else {
                if(a[i]<=n/2) {
                    v.push_back(id);
                }
                id++;
            }
        }
        temp += v2[1]+(n-1-v2[0]);
        if(v2[1]>v2[0]) {
            temp--;
        }
        int idx = 0;
        rep(i,0,sz(v)) {
            temp += abs(v[i]-idx);
            idx +=2;
        }
        min_self(ans2, temp);        
    }
    cout <<ans1 <<" " <<ans2 <<"\n";
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