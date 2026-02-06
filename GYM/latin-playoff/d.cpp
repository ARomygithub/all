#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;
#define sz(x) (int) (x).size()

const int MOD = 1000000007;
//const int MOD = 998244353;
 
 
bool alleven(vi &a) {
    for (int i = 0; i < sz(a); i++) {
        if (a[i] % 2) return false;
    }
    return true;
}
 
void solve() {
    int n; cin >> n;
    int nt = n;
    vi p;
    for (int i = 2; i * i <= n; i++) {
        int q = 0;
        while ((nt % i) == 0) {
            q++;
            nt/=i;
        }
        if(!q) continue;
        p.push_back(q);
    }
    if (nt >1){
        p.push_back(1);
    }
 
 
 
    if (sz(p) > 2 || alleven(p)) {
        cout << "N\n";
    }
    else {
        if(sz(p)==2) {
            if(p[0]==1 && p[1]==1) {
                cout << "Y\n";
            } else {
                cout <<"N\n";
            }
        } else {
            cout <<"Y\n";
        }
        // count needed to prevent win
        // int all_times = 1;
        // for (int q: p) {
        //     all_times *= (q + 1);
        // }
 
        // int tp = 0;
        // for (int q: p) {
        //     int none = all_times / (q+1);
        //     int atleastone = all_times - none;
 
        //     int prevent = all_times / 2 - atleastone + 1;
        //     prevent = max(prevent, 0LL);
        //     tp += prevent;
        // }
 
        // if (tp >= all_times / 2) {
        //     cout << "Y\n";
        // }
        // else {
        //     cout << "N\n";
        // }
 
    }
}
 
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}