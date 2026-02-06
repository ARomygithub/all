#include<bits/stdc++.h>
using namespace std;

// #define rep(i,a,b) for(int i= a; i < (b);i++)
// #define per(i,a,b) for(int i= a; i > (b); i--)
// #define all(x) begin(x), end(x)
// #define sz(x) (int)(x).size()
// using ll = long long;
// using pii = pair<int,int>;
// using vi = vector<int>;
// #define fi first
// #define se second
#define what_is(x) cerr << #x <<": " <<x <<endl;


void solve() {
    string s; cin >> s;
    int size = (int) s.size();
    vector<int> vi;
    vector<vector<int>> vic, vicp, ans;
    for (int i = 0; i < size; i++) {
        char current = s[i];
        if (current == 'I') {
            vi.push_back(i + 1);
        } else if (current == 'P') {
            if (!vic.empty()) {
                vector<int> current = vic.back();
                current.push_back(i + 1);
                vic.pop_back();
                vicp.push_back(current);
            }
        } else {
            // C
            what_is(vicp.size())
            if (!vicp.empty()) {
                vector<int> current = vicp.back();
                current.push_back(i + 1);
                vicp.pop_back();
                ans.push_back(current);
            } else if (!vi.empty()) {
                vector<int> current = { vi.back() };
                current.push_back(i + 1);
                vi.pop_back();
                vic.push_back(current);
            }
        }
    }



    cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
        for (auto &el: ans[i]) {
            cout << el << ' ';
        }
        cout << endl;
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
}