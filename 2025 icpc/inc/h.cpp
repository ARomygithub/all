#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
bool min_self(T& A, T B) {
    bool ret = A>B;
    A = min(A,B);
    return ret;
}
template<typename T>
bool umin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
bool umax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define pb push_back
#define len(a) (int)(a.size())

const int mxn=5e4;
int n,q,m,t;

const int inf = 1000111222;
struct node {
    int val, id, mask, high;
};


inline int get_high (int x) {
    if (x == 0) {
        return -1;
    }
    return 31 - __builtin_clz(x);
}

inline void swap_bits (int &x, int a, int b) {
    int x1 = bool(x & (1 << a));
    int x2 = bool(x & (1 << b));
    x ^= (x1 ^ x2) << a;
    x ^= (x1 ^ x2) << b;
}

struct xor_basis {
    vector <node> basis;

    inline bool add (int x, int id) {
        int mask = 0;
        for (auto &i : basis) {
            if (min_self(x, x ^ i.val)) {
                mask ^= i.mask;
            }
        }
        if (x) {
            mask |= 1 << sz(basis);
            for (auto &i : basis) {
                if (min_self(i.val, i.val ^ x)) {
                    i.mask ^= mask;
                }
            }
            basis.push_back(node{val: x, id: id, mask: mask, high: get_high(x)});
            return true;
        }
        return false;
    }



    inline int get_the_same_high_bit (int bits, const vector <int> &val) {
        for (auto &i : basis) {
            if (__builtin_popcount(val[i.id] & bits) & 1) {
                return i.id;
            }
        }
        return -1;
    }


    inline int rebuild_and_delete (int id) {
        int pos = 0, mn = inf, p2 = 0;
        for (int i = 0; i < sz(basis); i++) {
            if (basis[i].id == id) {
                pos = i;
            }
        }
        int bits = 0;
        for (int i = 0; i < sz(basis); i++) {
            if (basis[i].mask & (1 << pos)) {
                if (min_self(mn, basis[i].high)) {
                    p2 = i;
                }
                bits ^= 1 << basis[i].high;
            }
        }

        if (p2 != pos) {
            swap(basis[p2].id, basis[pos].id);
            for (auto &i : basis) {
                swap_bits(i.mask, pos, p2);
            }
            pos = p2;
        }
        for (int i = 0; i < sz(basis); i++) {
            if (i != pos) {
                if (basis[i].mask & (1 << pos)) {
                    basis[i].val ^= basis[pos].val;
                    basis[i].mask ^= basis[pos].mask;
                }
            }
        }
        int good = (1 << pos) - 1;
        int other = ((1 << sz(basis)) - 1) ^ (good | (1 << pos));
        basis.erase(basis.begin() + pos);
        for (auto &i : basis) {
            i.mask = ((i.mask & other) >> 1) | (i.mask & good);
        }
        return bits;
    }

};

template<int max_bit> // not inclusive
struct xor_basis_online {

    vector <xor_basis> basises[max_bit + 1];

    int mx;

    vector <pii> where;
    vector <int> val;

    xor_basis_online() : mx(0), cur_id(0) {}

    int cur_id;

    inline int add (int x) {
        // cout <<"add " <<x <<endl;
        val.pb(x);
        where.pb(make_pair(-1, -1));
        int id = cur_id++;
        if (x == 0) {
            return id;
        }
        for (int i = mx; i >= 0; i--) {
            if (basises[i].empty()) {
                continue;
            }
            if (basises[i].back().add(x, id)) {
                basises[i + 1].pb(basises[i].back());
                basises[i].pop_back();
                umax(mx, i + 1);
                for (auto &j : basises[i + 1].back().basis) {
                    where[j.id] = make_pair(i + 1, len(basises[i + 1]) - 1);
                }
                return id;
            }
        }
        basises[1].pb(xor_basis());
        basises[1].back().add(x, id);
        where.back() = make_pair(1, len(basises[1]) - 1);
        umax(mx, 1);
        return id;
    }

    inline int move_back (int sz, int pos) {
        int to = len(basises[sz]) - 1;
        if (to == pos) {
            return pos;
        }
        for (auto &i : basises[sz][pos].basis) {
            where[i.id].second = to;
        }
        for (auto &i : basises[sz][to].basis) {
            where[i.id].second = pos;
        }
        swap(basises[sz][pos], basises[sz][to]);
        return to;
    }

    inline void del (int id) {
        // cout <<"del " <<id <<endl;
        if (val[id] == 0) {
            return;
        }
        int sz, pos;
        tie(sz, pos) = where[id];
        pos = move_back(sz, pos);
        while (true) {
            int bits = basises[sz].back().rebuild_and_delete(id);
            int i = sz - 1;
            while (i > 0 && basises[i].empty()) {
                --i;
            }
            int new_id = -1;
            if (i > 0) {
                new_id = basises[i].back().get_the_same_high_bit(bits, val);
            }
            if (new_id == -1) {
                if (sz > 1) {
                    basises[sz - 1].pb(basises[sz].back());
                    for (auto &j : basises[sz - 1].back().basis) {
                        where[j.id] = make_pair(sz - 1, len(basises[sz - 1]) - 1);
                    }
                }
                basises[sz].pop_back();
                if (mx > 0 && basises[mx].empty()) {
                    --mx;
                }
                return;
            }
            int cur = val[new_id];
            assert(basises[sz].back().add(cur, new_id));
            int new_sz = i;
            int new_pos = len(basises[i]) - 1;
            where[new_id] = make_pair(sz, pos);
            id = new_id;
            sz = new_sz;
            pos = new_pos;
        }
    }

    inline int size () {
        return mx;
    }
};

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    cin >>n >>m >>q;
    xor_basis_online<30> xr;
    vi v;
    // cout <<"xr" <<endl;
    rep(i,0,n) {
        int cur = 0;
        int ki; cin >>ki;
        rep(j,0,ki) {
            int ai; cin >>ai; ai--;
            cur += (1<<ai);
        }
        v.push_back(cur);
    } 
    vi ri(n,n);
    // cout <<"ri" <<endl;
    int j = -1, i = 0;
    vi id(n,-1);
    auto cek = [&]() -> bool {
        int szi = xr.size();
        int ida = xr.add((1<<m)-1);
        int szi2 = xr.size();
        bool ok = (szi2-szi)==0;
        xr.del(ida);
        return ok;
    };
    while(i<n) {
        bool ok = 1;
        while(!cek()) {
            j++;
            if(j<n) {
                id[j] = xr.add(v[j]);
            } else {
                ok = 0;
                break;
            }
        }
        if(!ok) break;
        // cout <<i <<" " <<j <<endl;
        ri[i] = j;
        xr.del(id[i]);
        i++;
    }
    Tree st(n);
    rep(k,0,n) {
        st.update(k,ri[k]-k+1);
    }
    while(q--) {
        int l,r; cin >>l >>r; l--,r--;
        auto it = upper_bound(all(ri),r)-ri.begin();
        int qry = st.query(l,it);
        if(qry<=n) {
            cout <<qry <<"\n";
        } else {
            cout <<"-1\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}