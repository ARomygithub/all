#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
 
typedef long long ll;
 
ll solve(vector<int> x, vector<pair<int, int>> p) {
    // q lies in y
    // sort by x-coordinate
 
    int n = x.size();
    int m = p.size();
 
    sort(p.begin(), p.end());
    map<int, int> cnt;
 
    ll count = 0;
    for (int l = 0, i = 0, k = 0, lst_x = 0; l < m; ++l) {
        while (k < n && x[k] <= p[l].first)
            lst_x = x[k++];
 
        while (i < l && p[i].first <= lst_x) {
            --cnt[p[i].second];
            ++i;
        }
        
        count += l - i - cnt[p[l].second];
        ++cnt[p[l].second];
    }
    return count;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> x(n), y(m);
        for (auto &a : x)
            cin >> a;
        for (auto &a : y)
            cin >> a;
 
        vector<pair<int, int>> p(k);
        for (auto &[a, b] : p)
            cin >> a >> b;
        
        vector<pair<int, int>> one, two;
        for (auto [a, b] : p) {
            if (binary_search(x.begin(), x.end(), a)) {
                if (binary_search(y.begin(), y.end(), b))
                    continue;
                one.emplace_back(b, a);
            }
            else {
                two.emplace_back(a, b);
            }
        }
        
        ll ans = solve(x, two) + solve(y, one);
 
        // rep(i, 0, k)
        //     rep(j, i + 1, k)
        //         if (p[i].first == p[j].first || p[i].second == p[j].second)
        //             --ans;
 
        cout << ans << '\n';
    }
}