#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
 
typedef long long li;
typedef pair<int, int> pt;
 
const int INF = int(1e9);
const int MOD = int(1e9) + 7;
 
int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}
 
namespace SuffixArray {
    string s;
    vector< array<int, 2> > classes;
    
    vector<int> build(const string &bs) {
        s = bs;
        s += '$';
        
        vector<int> c(all(s)), ord(sz(s));
        iota(all(ord), 0);
        classes.resize(sz(s));
 
        for (int len = 1; len < 2 * sz(s); len <<= 1) {
            int half = len >> 1;
            fore (i, 0, sz(s))
                classes[i] = {c[i], c[(i + half) % sz(s)]};
            
            sort(all(ord), [&](int i, int j) {
                return classes[i] < classes[j];
            });
            c[ord[0]] = 0;
            fore (i, 1, sz(ord))
                c[ord[i]] = c[ord[i - 1]] + (classes[ord[i - 1]] != classes[ord[i]]);
        }
        
        c.pop_back();
        for (int &cc : c)
            cc--;
        return c;
    }
};
 
int n, k;
string s;
 
inline bool read() {
    if(!(cin >> n >> k))
        return false;
    cin >> s;
    return true;
}
 
string calcZero(string s) {
    int rem = k;
    int pos = 0;
    for (int i = sz(s) - 1; rem > 0 && i >= 0; i--) {
        if (s[i] == '1')
            continue;
        
        while (pos < sz(s) && s[pos] == '0')
            pos++;
        if (pos >= i)
            break;
        
        swap(s[pos], s[i]);
        rem--;
    }
    return s.substr(s.find('1'));
}
 
string calcOne(string s) {
    reverse(all(s));
    
    auto c = SuffixArray::build(s);
    int cntOnes = count(all(s), '1');
    
    array<int, 3> mn = { 2 * sz(s), INF, -1 };
        
    int u = 0, curOnes = 0;
    fore (i, 0, n) {
        while (u < sz(s) && (u - i < cntOnes || cntOnes - curOnes > k - 1)) {
            curOnes += s[u] == '1';
            u++;
        }
        if (u - i < cntOnes || cntOnes - curOnes > k - 1)
            break;
        
        array<int, 3> curAns = { u - i, c[i], i };
        mn = min(mn, curAns);
        
        curOnes -= s[i] == '1';
    }
    assert(mn[2] >= 0);
    
    string res = s.substr(mn[2], mn[0]);
    int toAdd = cntOnes - count(all(res), '1');
    for (int i = sz(res) - 1; toAdd > 0 && i >= 0; i--) {
        if (res[i] == '0') {
            res[i] = '1';
            toAdd--;
        }
    }
    return res;
}
 
inline void solve() {
    auto s1 = calcZero(s);
    auto s2 = calcOne(s);
 
    if (sz(s1) > sz(s2) || (sz(s1) == sz(s2) && s1 > s2))
        swap(s1, s2);
    
    int res = 0;
    for (char c : s1)
        res = add(mul(res, 2), c - '0');
    cout << res << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}