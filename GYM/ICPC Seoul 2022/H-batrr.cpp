#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
//#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

//const int N = 300500, inf = 1e9; mod = 998244353;
//const ll INF = 1e18;


//int bp(int a, int b) {
//    int res = 1;
//    while (b) {
//        if (b & 1)
//            res = mult(res, a);
//        a = mult(a, a);
//        b >>= 1;
//    }
//    return res;
//}

//int inv(int x) {
//    return bp(x, mod - 2);
//}
string s;
const int maxN = 5e4 + 10;
const int BUBEN = 300;
const int mod[2] = {(int)1e9 + 7, 998244353};
int sum(int a, int b, int mod) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b, int mod) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b, int mod) {
    return 1ll * a * b % mod;
}
const int pt = 239;
int pw[2][maxN];
int pref[2][maxN];
int id[maxN];
int cnt[maxN];
int lst[maxN];
pair<int,int> ans[maxN];
int cur[maxN];







const int maxM = (int)1e5 + 100;
map < char, int > to[maxM];
int link[maxM];
int len[maxM];
int last = 0;
int sz = 1;
vector<int> g[maxM];
vector<int> add[maxM];
void add_letter(char c, int pref) {
    int p = last;
    last = sz++;
    len[last] = len[p] + 1;
    for(; to[p][c] == 0; p = link[p]) {
        to[p][c] = last;
    }
    add[last].emplace_back(pref);
    if (to[p][c] == last) {
        link[last] = 0;
        return;
    }
    int q = to[p][c];
    if (len[q] == len[p] + 1) {
        link[last] = q;
        return;
    }
    int cl = sz++;
    to[cl] = to[q];
    link[cl] = link[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for (; to[p][c] == q; p = link[p]) {
        to[p][c] = cl;
    }
}
// все состояния [0; sz - 1]
// состояний не больше 2 * n, ребер не больше 3 * n => maxN = 2 * длина строки
// Любой путь из корня( = 0) это подстрока
// в одном состоянии находятся все строке, множество окончаний которых одинаковое
// link[p] - ссылка на минимальную вершину, которая имеет множество окончаний не меньше(но неверно, что link[p] < p -> нельзя считать динамики циклом, надо писать дфс)
// есть построить граф link[p] -> p, то получится дерево
// если насчитать f[v] = len[link[v]] + 1, то получим, что в одном состоянии лежат строки длины [f[v]; len[v]](и каждая из них входит в строку одинаковое число раз)

set<int> states[maxM];
void dfs(int v) {
    for (int to : add[v]) {
        states[v].insert(to);
    }
    for (int u : g[v]) {
        dfs(u);
        if ((int)states[u].size() > (int)states[v].size()) {
            swap(states[u], states[v]);
        }
        for (int x : states[u]) {
            states[v].insert(x);
        }
    }
    if (v == 0) return;
    int L = len[link[v]] + 1;
    int R = len[v];
    if (R <= BUBEN) return;
    if (L <= BUBEN) {
//        if (ans[states[v].size()].second != BUBEN) return;
    }
    L = max(L, BUBEN + 1);
    int his_len = states[v].size();
    auto get = [&](int l) {
        int cc = 0;
        int lst = -1e9;
        while (true) {
            auto it = states[v].lower_bound(lst + l);
            if (it == states[v].end()) break;
            cc++;
            lst = *it;
        }
        return cc;
    };
    int D = get(L);
    R++;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if ((s.size() / mid) + 1 >= D && get(mid) == D) {
            L = mid;
        }
        else {
            R = mid;
        }
    }
    ans[states[v].size()] = max(ans[states[v].size()], {D, L});
}








mt19937 rnd(228);
void solve() {
    cin >> s;
//    s = string(50000, 'a');
//    for (char& c : s) {
//        c = rnd() % 2 + 'b';
//    }
    int n = s.size();
    for (int i = 0; i < 2; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            pw[i][j] = mult(pw[i][j - 1], pt, mod[i]);
        }
    }
    for (int i = 0; i < 2; i++) {
        pref[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            pref[i][j] = sum(s[j - 1] - 'a' + 1, mult(pt, pref[i][j - 1], mod[i]), mod[i]);
        }
    }
    for (int i = 1; i <= n && i <= BUBEN; i++) {
        vector<pair<ll,int>> HSH;
        for (int j = 0; j + i - 1 <= n - 1; j++) {
            int F[2] = {0, 0};
            for (int z = 0; z < 2; z++) {
                F[z] = sub(pref[z][i + j], mult(pref[z][j], pw[z][i], mod[z]), mod[z]);
            }
            HSH.emplace_back(make_pair((ll)mod[1] * F[0] + F[1], j));
        }
        sort(HSH.begin(), HSH.end());
        for (int c = 0; c < HSH.size(); c++) {
            if (c == 0 || HSH[c].first != HSH[c - 1].first) {
                id[HSH[c].second] = c;
            }
            else {
                id[HSH[c].second] = id[HSH[c - 1].second];
            }
            lst[c] = -n - 100;
            cnt[c] = 0;
            cur[c] = 0;
        }
        for (int j = 0; j + i - 1 <= n - 1; j++) {
            cnt[id[j]]++;
            if (j - lst[id[j]] >= i) {
                cur[id[j]]++;
                lst[id[j]] = j;
            }
        }
        for (int c = 0; c < HSH.size(); c++) {
            ans[cnt[c]] = max(ans[cnt[c]], {cur[c], i});
        }
    }
    for (int i = 0; i < s.size(); i++) {
        add_letter(s[i], i);
    }
    for (int i = 1; i < sz; i++) {
        g[link[i]].emplace_back(i);
    }
    dfs(0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i].second << " ";
    }
    cout << '\n';

}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}