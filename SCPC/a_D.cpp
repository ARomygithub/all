#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define eul 0.5772156649
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
const int mxn = 200005;
const int mxk = 300005;
int vr[mxn];
int hr[mxn];
int cntx[mxn];
int cnty[mxn];
vector<int> linex[mxn];
vector<int> liney[mxn];
 
void solve(){
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> vr[i];
    for(int i = 0; i < m; i++) cin >> hr[i];
    memset(cntx, 0, sizeof(int) * (m + 5));
    memset(cnty, 0, sizeof(int) * (n + 5));
    vector<pair<int,int>> v;
    set<int> used[2];
    for(int i = 0; i < k; i++){
        cin >> x >> y;
        v.push_back({x, y});
        int lbx = lower_bound(vr, vr + n, x) - vr;
        int ubx = upper_bound(vr, vr + n, x) - vr;
        int lby = lower_bound(hr, hr + m, y) - hr;
        int uby = upper_bound(hr, hr + m, y) - hr;
 
        if(ubx == lbx){
            cnty[lbx]++;
            liney[lby].pb(x);
            used[0].insert(lby);
        }else if(uby == lby){
            cntx[lby]++;
            linex[lbx].pb(y);
            used[1].insert(lbx);
        }
    }
    for(auto &a : used[0]) sort(liney[a].begin(), liney[a].end());
    for(auto &a : used[1]) sort(linex[a].begin(), linex[a].end());
 
    ll sum = 0;
    for(auto &[x, y] : v){
        int lbx = lower_bound(vr, vr + n, x) - vr;
        int ubx = upper_bound(vr, vr + n, x) - vr;
        int lby = lower_bound(hr, hr + m, y) - hr;
        int uby = upper_bound(hr, hr + m, y) - hr;
 
        int a, b;
        if(ubx == lbx){
            a = vr[lbx - 1];
            b = vr[lbx];
            sum += (ll)(cnty[lbx] - (lower_bound(liney[lby].begin(), liney[lby].end(), b) - upper_bound(liney[lby].begin(), liney[lby].end(), a)));
        }else if(uby == lby){
            a = hr[lby - 1];
            b = hr[lby];
            sum += (ll)(cntx[lby] - (lower_bound(linex[lbx].begin(), linex[lbx].end(), b) - upper_bound(linex[lbx].begin(), linex[lbx].end(), a)));
        }
    }
    cout << (sum>>1) << "\n";
 
    for(auto &a : used[0]) liney[a].clear();
    for(auto &a : used[1]) linex[a].clear();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
//        cout << "Case #" << i << ": ";
        solve();
    }
}