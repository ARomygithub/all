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
int n,x,y,t;
int a[mxn];

void solve() {
    cin >>n >>x >>y;
    int ya = y;
    rep(i,0,x) {
        cin >>a[i];
    }
    sort(a,a+x);
    vector<int> odd,even;
    rep(i,1,x) {
        if((a[i]-a[i-1])%2) {
            odd.push_back(a[i]-a[i-1]);
        } else {
            even.push_back(a[i]-a[i-1]);
        }
    }
    int tn0 = n-a[x-1]+a[0];
    if(tn0%2) {
        odd.push_back(tn0);
    } else {
        even.push_back(tn0);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int ans = 0;
    rep(i,0,sz(even)) {
        int temp = min(y, even[i]/2 - 1);
        if(temp==even[i]/2 -1) {
            ans += temp+1;
            y -= temp;
        } else {
            ans += temp;
            y -=temp;
        }
    }
    rep(i,0,sz(odd)) {
        int temp = min(y,odd[i]/2);
        ans += temp;
        y -= temp;
    }
    // if(y>0) {
        
    // }
    ans += x+ya-y-2;
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