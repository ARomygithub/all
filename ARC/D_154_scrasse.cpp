#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
 
#define INF (ll)1e18
#define mod 998244353
#define maxn 110
 
mt19937 rng(19938);
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */
 
    ll n; cin >> n;
 
    auto rr = [&](ll l, ll r) {
        return uniform_int_distribution<ll>(l, r)(rng);
    };
 
    map<array<ll, 3>, ll> cache;
 
    /* for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cache[{i, j, i}] = 1; cache[{j, i, i}] = 1;
        }
    } */
 
    auto ask = [&](ll i, ll j, ll k) {
        if (i == k || j == k) return (ll)1;
        if (cache.count({i, j, k})) return cache[{i, j, k}];
 
        cout << "?" _ i _ j _ k << nf;
        string x; cin >> x;
        if (x == "-1") exit(0);
 
        ll ans = 0;
        if (x == "Yes") ans = 1;
 
        cache[{i, j, k}] = ans;
 
        // cout << "ask" _ i _ j _ k _ ans << nl;
        return ans;
    };
 
    function<ll(vector<ll>, ll, ll)> reduce = [&](vector<ll> cand, ll iter, ll start) {
        ll n = cand.size();
 
        /* if (n <= 10) { // tweak, it's klog(k) if randomized
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (ask(cand[i], cand[i], cand[j]) == 1) break;
                }
                if (j == n) return cand[i];
            }
        } */
 
        ll curr = start;
        if (curr == -1) curr = cand[rr(0, n - 1)];
        for (ll i = 1; i <= iter; i++) {
            // cout << "i, curr =" _ i _ curr << nl;
            ll k = rr(0, n - 1);
            ll y = ask(cand[k], cand[k], curr);
            // cout << "y =" _ y << nl;
            if (y == 0) {
                curr = cand[k];
                // cout << "new_curr =" _ cand[k] << nl;
            }
        }
 
        vector<ll> new_cand;
        for (auto u : cand) {
            if (ask(u, u, curr) == 0) new_cand.pb(u);
        }
 
        /* cout << "new_cand" << nl;
        for (auto u : new_cand) cout << u << ' ';
        cout << nl; */
 
        if (new_cand.empty()) return curr;
        else return reduce(new_cand, 10, curr); // 20?
    };
 
    vector<ll> start_v;
    for (ll i = 1; i <= n; i++) start_v.pb(i);
    ll one = reduce(start_v, 100, -1); // 100
 
    vector<ll> perm(n + 1, 0), ans(n + 1, 0);
    for (ll i = 1; i <= n; i++) perm[i] = i;
    stable_sort(perm.begin() + 1, perm.end(), [&](ll i, ll j) {
        return (ask(i, one, j) == 0);
    });
 
    for (ll i = 1; i <= n; i++) ans[perm[i]] = i;
 
    cout << "! ";
    for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << nl;
 
    return 0;
}