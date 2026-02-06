#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int nextOne(int pos, vi& ones) {
    while(!ones.empty() && ones.back() < pos) ones.pop_back();
    if (ones.empty()) return -1;
    return ones.back();
}

void solve() {
    int n, k; cin >> n >> k;

    vector<pair<int, pii>> vec(n); // {floor, {count, weight}}
    rep(i, 0, n) {
        cin >> vec[i].second.first >> vec[i].second.second >> vec[i].first;
    }

    sort(all(vec), greater<pair<int, pii>>());

    vector<int> ones;
    rep(i, 0, n) {
        if (vec[i].second.second == 1) ones.push_back(i);
    }
    reverse(all(ones));

    int ans = 0;

    for (int i = 0; i < n;) {
        // try to pick all
        int nall = vec[i].second.first * vec[i].second.second / k;
        ans += nall * vec[i].first;
        vec[i].second.first -= nall * k / vec[i].second.second;

        // try to use remaining (if any)
        if (!vec[i].second.first) {
            i++;
            continue;
        }
        int cur_limit = k;
        int cost = vec[i].first;
        while (i < n && cur_limit > 0) {
            int use = min(cur_limit / vec[i].second.second, vec[i].second.first);
            cur_limit -= use * vec[i].second.second;
            vec[i].second.first -= use;

            if (vec[i].second.first == 0) {
                i++;
            }
            else {
                break;
            }
        }

        // try to use 1's (if any)
        if (cur_limit == 1) {
            int nO = nextOne(i, ones);
            if (nO != -1) {
                vec[nO].second.first -= 1;
            }
        }

        ans += cost;
        if (!vec[i].second.first) {
            i++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
}