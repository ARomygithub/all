#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] %= m;
    }
    sort(a, a+n);
    if(n==1){
        cout << 0 << "\n";
    }
    else{
        ll ans = a[n-1]-a[0];
        for(int i=0; i<=n-2; i++){
            ans = min(ans,m-a[i+1]+a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}