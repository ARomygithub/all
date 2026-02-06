#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    int autolose = 0;
    for (int i = 0; i < n; i++)
    {
        string x, xx;
        cin >> x;
        if (x[0] == '=') xx = x.substr(3, 3);
        else xx = x.substr(0, 3);
        if (xx == "xxx") arr.push_back(2);
        else if (xx == "xx." or xx==".xx")arr.push_back(1);
        else if (xx == "..." or xx == "x.." or xx == "..x") autolose = 1;
    }
    if (autolose)
    {
        cout << "Polycarp\n";
        return;
    }

    int x = 0;
    for (auto e: arr) x ^= e;
    if (x == 0) cout << "Polycarp\n";
    else cout << "Monocarp\n";
    // int onecount = count(arr.begin(), arr.end(), 1);
    // int twocount = count(arr.begin(), arr.end(), 2);
    // int monocarp_win = twocount & 1;
    // if (onecount & 1) monocarp_win = !monocarp_win;
    // if (monocarp_win) cout << "Monocarp\n";
    // else cout << "Polycarp\n";
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}