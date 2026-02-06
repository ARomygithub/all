#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(n) for(int i = 0; i < (int)n; i++)
#define repi(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define all(x) x.begin(),x.end()
//#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>

template<typename T>
bool chmax(T &a, const T b) {if(a<b) {a=b; return true;} else {return false;}}
template<typename T>
bool chmin(T &a, const T b) {if(a>b) {a=b; return true;} else {return false;}}

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const ll INF = numeric_limits<long long>::max() / 2;
const ld pi = 3.1415926535897932384626433832795028;
const ll mod = 998244353;
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

#define int long long

template<long long MOD>
struct Modular_Int {
    using Mint_Type = Modular_Int<MOD>;
    long long x;

    Modular_Int() = default;
    Modular_Int(long long x_) : x(x_ >= 0? x_%MOD : (MOD-(-x_)%MOD)%MOD) {}

    long long val() const {
        return (x%MOD+MOD)%MOD;
    }
    static long long get_mod() {
        return MOD;
    }

    Mint_Type& operator^=(long long d)  {
        Mint_Type ret(1);
        long long nx = x;
        while(d) {
            if(d&1) ret *= nx;
            (nx *= nx) %= MOD;
            d >>= 1;
        }
        *this = ret;
        return *this;
    }
    Mint_Type operator^(long long d) const {return Mint_Type(*this) ^= d;}
    Mint_Type pow(long long d) const {return Mint_Type(*this) ^= d;}
    
    //use this basically
    Mint_Type inv() const {
        return Mint_Type(*this) ^ (MOD-2);
    }
    //only if the module number is not prime
    //Don't use. This is broken.
    // Mint_Type inv() const {
    //     long long a = (x%MOD+MOD)%MOD, b = MOD, u = 1, v = 0;
    //     while(b) {
    //         long long t = a/b;
    //         a -= t*b, swap(a, b);
    //         u -= t*v, swap(u, v);
    //     }
    //     return Mint_Type(u);
    // }

    Mint_Type& operator+=(const Mint_Type other) {
        if((x += other.x) >= MOD) x -= MOD;
        return *this;
    }
    Mint_Type& operator-=(const Mint_Type other) {
        if((x -= other.x) < 0) x += MOD;
        return *this;
    }
    Mint_Type& operator*=(const Mint_Type other) {
        long long z = x;
        z *= other.x;
        z %= MOD;
        x = z;
        if(x < 0) x += MOD;
        return *this;
    }
    Mint_Type& operator/=(const Mint_Type other) {
        return *this = *this * other.inv();
    }
    Mint_Type& operator++() {
        x++;
        if (x == MOD) x = 0;
        return *this;
    }
    Mint_Type& operator--() {
        if (x == 0) x = MOD;
        x--;
        return *this;
    }
    
    Mint_Type operator+(const Mint_Type other) const {return Mint_Type(*this) += other;}
    Mint_Type operator-(const Mint_Type other) const {return Mint_Type(*this) -= other;}
    Mint_Type operator*(const Mint_Type other) const {return Mint_Type(*this) *= other;}
    Mint_Type operator/(const Mint_Type other) const {return Mint_Type(*this) /= other;}
    
    Mint_Type& operator+=(const long long other) {Mint_Type other_(other); *this += other_; return *this;}
    Mint_Type& operator-=(const long long other) {Mint_Type other_(other); *this -= other_; return *this;}
    Mint_Type& operator*=(const long long other) {Mint_Type other_(other); *this *= other_; return *this;}
    Mint_Type& operator/=(const long long other) {Mint_Type other_(other); *this /= other_; return *this;}
    Mint_Type operator+(const long long other) const {return Mint_Type(*this) += other;}
    Mint_Type operator-(const long long other) const {return Mint_Type(*this) -= other;}
    Mint_Type operator*(const long long other) const {return Mint_Type(*this) *= other;}
    Mint_Type operator/(const long long other) const {return Mint_Type(*this) /= other;}

    bool operator==(const Mint_Type other) const {return (*this).val() == other.val();}
    bool operator!=(const Mint_Type other) const {return (*this).val() != other.val();}
    bool operator==(const long long other) const {return (*this).val() == other;}
    bool operator!=(const long long other) const {return (*this).val() != other;}

    Mint_Type operator-() const {return Mint_Type(0LL)-Mint_Type(*this);}

    //-1: sqrtが存在しない
    //複数存在する場合どれを返すかは不明
    long long get_sqrt() const {
        long long a = val(), p = get_mod();
        if(a == 0) return 0;
        if(p == 2) return a;
        if(Mint_Type(a).pow((p - 1) >> 1).val() != 1) return -1;
        long long b = 1;
        while(Mint_Type(b).pow((p - 1) >> 1).val() == 1) ++b;
        long long e = 0, m = p - 1;
        while(m % 2 == 0) m >>= 1, ++e;
        long long x = Mint_Type(a).pow((m - 1) >> 1).val();
        long long y = a * (x * x % p) % p;
        (x *= a) %= p;
        long long z = Mint_Type(b).pow(m).val();
        while(y != 1) {
            long long j = 0, t = y;
            while(t != 1) {
                j += 1;
                (t *= t) %= p;
            }
            z = Mint_Type(z).pow((long long)1 << (e - j - 1)).val();
            (x *= z) %= p;
            (z *= z) %= p;
            (y *= z) %= p;
            e = j;
        }
        return x;
    }

    template <typename T>
    friend Mint_Type operator+(T t, const Mint_Type& o) {
        return o + t;
    }
    template <typename T>
    friend Mint_Type operator-(T t, const Mint_Type& o) {
        return -o + t;
    }
    template <typename T>
    friend Mint_Type operator*(T t, const Mint_Type& o) {
        return o * t;
    }
    template <typename T>
    friend Mint_Type operator/(T t, const Mint_Type& o) {
        return o.inv() * t;
    }
};

// TODO: SELECT MOD_VAL
// const long long MOD_VAL = 1e9+7;
const long long MOD_VAL = 998244353;
using mint = Modular_Int<MOD_VAL>;

istream& operator>>(istream& is, mint& x) {
    long long X;
    is >> X;
    x = X;
    return is;
}
ostream& operator<<(ostream& os, mint& x) {
    os << x.val();
    return os;
}


// 1e9 + 7をmodとして使いたいときに注意！！！！特にCFやCCなどのAtCoder以外

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vpii> es(n);
    FOR(m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        es[c].emplace_back(a, b);
    }
    vi cnt(n, 0);
    vector<pair<int, vi>> regu(n);
    FOR(n) {
        if(es[i].size() == 0) continue;
        if(es[i].size() > i) {
            cout << 0 << endl;
            return;
        }
        int mx = 0, mxid = 0;
        for(auto e : es[i]) {
            ++cnt[e.first];
            ++cnt[e.second];
            if(chmax(mx, cnt[e.first])) mxid = e.first;
            if(chmax(mx, cnt[e.second])) mxid = e.second;
        }

        vi other;
        for(auto e : es[i]) {
            if(e.first != mxid) other.push_back(e.first);
            if(e.second != mxid) other.push_back(e.second);
        }
        sort(all(other));
        other.erase(unique(all(other)), other.end());

        regu[i] = make_pair(mxid, other);

        if(mx != es[i].size()) {
            cout << 0 << endl;
            return;
        }
        for(auto e : es[i]) {
            --cnt[e.first];
            --cnt[e.second];
        }
    }

    int rem = 0;
    mint ans = 1;

    vector<bool> seen(n, 0);

    FOR(n) {
        ++rem;
        if(regu[i].second.size() == 1) {
            if(seen[regu[i].first] && seen[regu[i].second[0]]) {
                cout << 0 << endl;
                return;
            }
            if(!seen[regu[i].first]) swap(regu[i].first, regu[i].second[0]);
            if(!seen[regu[i].first]) {
                ans *= 2;
                cout <<2 <<endl;
                if(!seen[regu[i].first]) {
                    seen[regu[i].first] = true;
                    --rem;
                }
                for(auto e : regu[i].second) if(!seen[e]) {
                    seen[e] = true;
                    ans *= rem;
                    cout <<rem <<endl;
                    --rem;
                }
            }else {
                seen[regu[i].second[0]] = true;
                --rem;
            }
        }
        if(regu[i].second.size() > 1) {
            if(seen[regu[i].first]) {
                cout << 0 << endl;
                return;
            }
            seen[regu[i].first] = true;
            --rem;
            for(auto e : regu[i].second) if(!seen[e]) {
                seen[e] = true;
                ans *= rem;
                cout <<rem <<endl;
                --rem;
            }
        }
    }
    while(rem > 0) {
        ans *= rem;
        cout <<rem <<endl;
        --rem;
    }

    cout << ans.val() << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
