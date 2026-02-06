#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, x;
    cin >> n >> x;
    vector<ll> inp;
    for (int i = 0;i < n;i++){
        ll wow; cin >> wow;
        inp.push_back(wow);
    }
    vector<vector<ll>> ans;
    queue<pair<ll,ll>> qw;
    sort(all(inp), greater<ll>());
    ans.push_back(vector<ll>({inp[0]}));
    qw.push({inp[0],0});
    for (int i = 1;i < n;i++){
        // cout << inp[i] << endl;
        auto f = qw.front(); 
        if (inp[i]+x > f.first) {
            // cout << "bikin baru\n";
            ans.push_back(vector<ll>({inp[i]}));
            qw.push({inp[i], ans.size()-1});
        }
        else {
            // cout << "tambah " << f.second <<"\n";
            ans[f.second].push_back(inp[i]);
            qw.pop();
            qw.push({inp[i],f.second});
        }
    }

    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++){
        cout << ans[i].size();
        for (auto& b : ans[i]) cout << " " << b;
        cout << endl;
    }
}