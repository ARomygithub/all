#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        ll a[n];
        ll sum = 0;
        ll suf[n+1];
        suf[n] = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a+n);
        for(int i=n-1; i>=0; i--){
            suf[i] = suf[i+1] + a[i];
        }
        // cout << sum << " " << x << "\n";
        if(sum <= x){
            cout << 0 << "\n";
            continue;
        }
        ll p[n];
        ll ans = sum-x;
        for(int i=1; i<n; i++){
            ll px = x-sum+suf[i]+a[0];
            p[i] = 1LL*(px)/(n-i+1); // p[i]*(n-i+1)<=px.  p[i] sedekat mungkin sama a[0]. p[i] fix <a[0]. kalo p[i]>a[0], 0 in aja.
            if(px<0&&(px%(n-i+1)!=0)){
                p[i]--;
            }
            ans = min(ans, max(a[0]-p[i],0ll)+n-i);
        }
        // cout << "\n";
        cout << ans << "\n";
        // cout << -1/3 << "\n";
    }

    return 0;
}