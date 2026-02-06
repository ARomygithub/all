#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)

const int MOD = 1000000007;
//const int MOD = 998244353;

union ieee754
{
    float f;
    uint32_t u;
};

uint32_t ones(int x) {
    if (x == 32) return 0xFFFFFFFF;
    return (1 << x) - 1;
}

uint32_t mid(uint32_t c0, uint32_t x, uint32_t b) {
    return (c0 >> x) & ones(b);
}

ieee754 nand(ieee754 a, ieee754 b) {
    a.u &= b.u;
    a.u = ~a.u;
    return a;
}

string toHex(uint32_t x) {
    string ret = "";
    rep(i,0,8) {
        int cur = x%16;
        if(cur>9) {
            ret += (char)('a' + (cur-10));
        } else {
            ret += (char)('0' + cur);
        }
        x /= 16;
    }
    reverse(all(ret));
    return ret;
}

void solve() {
    // for (int i = 0; i <= 32; i++) cout << ones(i) << " "; cout << endl;
    ieee754 x;
    cin >> hex >> x.u >> dec;

    int l; cin >> l;
    vector<vector<ieee754>>lut(l);

    for (int i = 0; i < l; i++) {
        int sz; cin >> sz;

        for (int j = 0; j < sz; j++) {
            ieee754 y;
            cin >> hex >> y.u >> dec;
            lut[i].push_back(y);
        }
    }

    vector<ieee754> C;

    C.push_back(x);

    int q;
    cin >> q;
    forn(t, q) {
        char c;
        cin >> c;
        if (c == 'L') {
            int i, j, b; cin >> i >> j >> b;
            C.push_back(lut[i][mid(C[0].u, j, b)]);
        }
        if (c == 'N') {
            int u, v; cin >> u >> v;
            C.push_back(nand(C[u], C[v]));
        }
        if (c == 'F') {
            int u, v, w; cin >> u >> v >> w;
            ieee754 f; f.f = fma(C[u].f, C[v].f, C[w].f);
            C.push_back(f);
        }
        if (c == 'C') {
            ieee754 u; cin >> hex >> u.u >> dec;
            C.push_back(u);
        }
    }
    // uint32_t zr = 0;
    // if(C.back().u==zr) {
    //     cout <<"00000000\n";
    // } else {
    //     cout << hex << C.back().u << dec << endl;
    // }
    cout <<toHex(C.back().u) <<endl;

}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}