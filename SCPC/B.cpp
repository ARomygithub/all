#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define ar array
typedef long long ll;
typedef pair<int, int> pii;
const int mxn=2e5;
int n;
ll m;
ar<ll,2> a[mxn];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll temp=0, freq=0;
    for(int i=0; i<n; i++){
        cin >> a[i][0];
        a[i][0] %=m;
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i][1];
        freq +=a[i][1];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        temp +=a[i][0]*a[i][1];
    }
    temp += freq*(m-1-a[n-1][0]);
    ans = max(ans,temp);
    for(int i=n-2;i>=0;i--) {
        temp += (freq-a[i+1][1])*(a[i+1][0]-a[i][0]);
        temp += a[i+1][1]*(a[i+1][0]-a[i][0]-m);
        ans = max(ans,temp);
    }
    cout <<ans;
    return 0;
}