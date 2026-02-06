#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mxn = 2e6;
const int inf = 1e9;
vector<int> t(mxn*4);
vector<int> a(mxn);
int n, k, m, q, sz;
int combine(int x, int y) {
    if(x >= inf || y >= inf) {
        return inf;
    } else {
        if(x >= inf-y) {
            return inf;
        } else {
            return x+y;
        }
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

array<int, 6> sol(int u, int kiri, int tengah, int kanan) {
    array<int, 6> res = {inf, inf, inf, inf, inf, inf};
    int atas, bawah;
    if(u <= k) {
        atas = query(1, 0, sz-1, 0, u-2);
        bawah = query(1, 0, sz-1, u-1, k-2);
        res[1] = combine(atas, kiri);
        res[2] = combine(atas, tengah);
        res[4] = combine(bawah, kiri);
        res[5] = combine(bawah, tengah);
    } else if(u <= n) {
        atas = query(1, 0, sz-1, u-1, n-1);
        bawah = query(1, 0, sz-1, k-1, u-2);
        res[1] = combine(atas, kanan);
        res[2] = combine(atas, tengah);
        res[4] = combine(bawah, kanan);
        res[5] = combine(bawah, tengah);
    } else {
        atas = query(1, 0, sz-1, n, u-1);
        bawah = query(1, 0, sz-1, u, sz-1);
        res[1] = combine(atas, kiri);
        res[2] = combine(atas, kanan);
        res[4] = combine(bawah, kiri);
        res[5] = combine(bawah, kanan);
    }
    res[0] = bawah;
    res[3] = atas;
    return res;
}

// array<int, 3> sol2(int u, int kiri, int tengah, int kanan) {
//     array<int, 3> res = {inf, inf, inf};
//     if(u <= k) {
//         int atas = query(1, 0, sz-1, 0, u-2);
//         int bawah = query(1, 0, sz-1, u-1, k-2);
//         res[0] = bawah;
//         res[1] = atas + kiri;
//         res[2] = atas + tengah;
//     } else if(u <= n) {
//         int atas = query(1, 0, sz-1, u-1, n-1);
//         int bawah = query(1, 0, sz-1, k-1, u-2);
//         res[0] = bawah;
//         res[1] = atas + kanan;
//         res[2] = atas + tengah;
//     } else {
//         int atas = query(1, 0, sz-1, n, u-1);
//         int bawah = query(1, 0, sz-1, u, sz-1);
//         res[0] = bawah;
//         res[1] = atas + kiri;
//         res[2] = atas + kanan;
//     }
//     return res;
// }


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m >> q;
    sz = n+m+1;
    for(int i=0; i<n; i++) {
        cin >> a[i]; 
    }
    for(int i=n; i<=n+m; i++) {
        cin >> a[i];
    }
    // for(int i=0; )
    build(1, 0, sz-1);
    while(q--) {
        char ct;
        cin >> ct;
        if(ct == 'q') {
            // for(int i=0; i<sz; i++){
            //     cout << query(1, 0, sz-1, i, i) << " \n"[i==sz-1];
            // }
            int u, v;
            cin >> u >> v;
            if(u == v) {
                cout << 0 << "\n";
            } else {
                if(u > v) {
                    swap(u, v);
                }
                int ans = query(1, 0, sz-1, u-1, v-2);
                int kiri = query(1, 0, sz-1, k-1, n-1);
                int tengah = query(1, 0, sz-1, n, sz-1);
                int kanan = query(1, 0, sz-1, 0, k-2);
                // cout << kiri << " " << tengah << " " << kanan << "\n";
                array<int, 6> ax1 = sol(u, kiri, tengah, kanan);
                array<int, 6> ax2 = sol(v, kiri, tengah, kanan);
                for(int i=0; i<3; i++) {
                    // cout << ax1[i] << " \n"[i==2];
                    for(int j=0; j<3; j++) {
                        int as = combine(ax1[i], ax2[j]);
                        ans = min(ans, as);
                    }
                }
                for(int i=3; i<6; i++) {
                    for(int j=3; j<6; j++) {
                        int as = combine(ax1[i], ax2[j]);
                        ans = min(ans, as);
                    }
                }
                if(ans >= inf) {
                    cout << "impossible\n";
                } else {
                    cout << ans << "\n";
                }
            }
        } else {
            int x;
            cin >> x;
            if(ct == 'x') {
                x = x+n+1;
            }
            int qry = query(1, 0, sz-1, x-1, x-1);
            if(qry >= inf) {
                update(1, 0, sz-1, x-1, a[x-1]);
            } else {
                update(1, 0, sz-1, x-1, inf);
            }
        }
        
        // for(int i=0; i<sz; i++){
        //     cout << query(1, 0, sz-1, i, i) << " \n"[i==sz-1];
        // }
    }

    return 0;
}