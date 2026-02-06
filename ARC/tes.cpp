namespace atcoder {

namespace internal {

template <class mint, int g = internal::primitive_root<mint::mod()>,
          internal::is_static_modint_t<mint> * = nullptr>
struct fft_info {
    static constexpr int rank2 = bsf_constexpr(mint::mod() - 1);
    std::array<mint, rank2 + 1> root;  // root[i]^(2^i) == 1
    std::array<mint, rank2 + 1> iroot; // root[i] * iroot[i] == 1

    std::array<mint, std::max(0, rank2 - 2 + 1)> rate2;
    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;

    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;
    std::array<mint, std::max(0, rank2 - 3 + 1)> irate3;

    fft_info() {
        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }

        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 2; i++) {
                rate2[i] = root[i + 2] * prod;
                irate2[i] = iroot[i + 2] * iprod;
                prod *= iroot[i + 2];
                iprod *= root[i + 2];
            }
        }
        {
            mint prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 3; i++) {
                rate3[i] = root[i + 3] * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    }
};

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
void butterfly(std::vector<mint> &a) {
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static const fft_info<mint> info;

    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len < h) {
        if (h - len == 1) {
            int p = 1 << (h - len - 1);
            mint rot = 1;
            for (int s = 0; s < (1 << len); s++) {
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * rot;
                    a[i + offset] = l + r;
                    a[i + offset + p] = l - r;
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate2[bsf(~(unsigned int)(s))];
            }
            len++;
        } else {
            int p = 1 << (h - len - 2);
            mint rot = 1, imag = info.root[2];
            for (int s = 0; s < (1 << len); s++) {
                mint rot2 = rot * rot;
                mint rot3 = rot2 * rot;
                int offset = s << (h - len);
                for (int i = 0; i < p; i++) {
                    auto mod2 = 1ULL * mint::mod() * mint::mod();
                    auto a0 = 1ULL * a[i + offset].val();
                    auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
                    auto a1na3imag =
                        1ULL * mint(a1 + mod2 - a3).val() * imag.val();
                    auto na2 = mod2 - a2;
                    a[i + offset] = a0 + a2 + a1 + a3;
                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
                    a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
                }
                if (s + 1 != (1 << len))
                    rot *= info.rate3[bsf(~(unsigned int)(s))];
            }
            len += 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
void butterfly_inv(std::vector<mint> &a) {
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static const fft_info<mint> info;

    int len = h; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len) {
        if (len == 1) {
            int p = 1 << (h - len);
            mint irot = 1;
            for (int s = 0; s < (1 << (len - 1)); s++) {
                int offset = s << (h - len + 1);
                for (int i = 0; i < p; i++) {
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = l + r;
                    a[i + offset + p] =
                        (unsigned long long)(mint::mod() + l.val() - r.val()) *
                        irot.val();
                    ;
                }
                if (s + 1 != (1 << (len - 1)))
                    irot *= info.irate2[bsf(~(unsigned int)(s))];
            }
            len--;
        } else {
            int p = 1 << (h - len);
            mint irot = 1, iimag = info.iroot[2];
            for (int s = 0; s < (1 << (len - 2)); s++) {
                mint irot2 = irot * irot;
                mint irot3 = irot2 * irot;
                int offset = s << (h - len + 2);
                for (int i = 0; i < p; i++) {
                    auto a0 = 1ULL * a[i + offset + 0 * p].val();
                    auto a1 = 1ULL * a[i + offset + 1 * p].val();
                    auto a2 = 1ULL * a[i + offset + 2 * p].val();
                    auto a3 = 1ULL * a[i + offset + 3 * p].val();

                    auto a2na3iimag =
                        1ULL *
                        mint((mint::mod() + a2 - a3) * iimag.val()).val();

                    a[i + offset] = a0 + a1 + a2 + a3;
                    a[i + offset + 1 * p] =
                        (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();
                    a[i + offset + 2 * p] =
                        (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3)) *
                        irot2.val();
                    a[i + offset + 3 * p] =
                        (a0 + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) *
                        irot3.val();
                }
                if (s + 1 != (1 << (len - 2)))
                    irot *= info.irate3[bsf(~(unsigned int)(s))];
            }
            len -= 2;
        }
    }
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution_naive(const std::vector<mint> &a,
                                    const std::vector<mint> &b) {
    int n = int(a.size()), m = int(b.size());
    std::vector<mint> ans(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
    }
    return ans;
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution_fft(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    int z = 1 << internal::ceil_pow2(n + m - 1);
    a.resize(z);
    internal::butterfly(a);
    b.resize(z);
    internal::butterfly(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++)
        a[i] *= iz;
    return a;
}

} // namespace internal

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution(std::vector<mint> &&a, std::vector<mint> &&b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m)
        return {};
    if (std::min(n, m) <= 60)
        return convolution_naive(a, b);
    return internal::convolution_fft(a, b);
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution(const std::vector<mint> &a,
                              const std::vector<mint> &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m)
        return {};
    if (std::min(n, m) <= 60)
        return convolution_naive(a, b);
    return internal::convolution_fft(a, b);
}

template <unsigned int mod = 998244353, class T,
          std::enable_if_t<internal::is_integral<T>::value> * = nullptr>
std::vector<T> convolution(const std::vector<T> &a, const std::vector<T> &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m)
        return {};

    using mint = static_modint<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> convolution_ll(const std::vector<long long> &a,
                                      const std::vector<long long> &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m)
        return {};

    static constexpr unsigned long long MOD1 = 754974721; // 2^24
    static constexpr unsigned long long MOD2 = 167772161; // 2^25
    static constexpr unsigned long long MOD3 = 469762049; // 2^26
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::inv_gcd(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::inv_gcd(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::inv_gcd(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * M2M3;
        x += (c2[i] * i2) % MOD2 * M1M3;
        x += (c3[i] * i3) % MOD3 * M1M2;
        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0)
            diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

} // namespace atcoder

#line 2 "cpplib/math/poly.hpp"

using poly = vector<mint>;
int size(const poly &x) { return x.size(); }
poly shrink(poly x) {
    while (size(x) >= 1 && x.back().val() == 0)
        x.pop_back();
    return x;
}

poly pre(const poly &x, int n) {
    auto res = x;
    res.resize(n);
    return res;
}
poly operator+(const poly &x, const poly &y) {
    poly res(max(x.size(), y.size()));
    rep(i, 0, x.size()) res[i] += x[i];
    rep(i, 0, y.size()) res[i] += y[i];
    return res;
}
poly &operator*=(poly &x, const mint &y) {
    rep(i, 0, x.size()) x[i] *= y;
    return x;
}
poly operator*(poly x, const mint &y) { return x *= y; }

poly operator-(const poly &x) {
    poly res(x.size());
    rep(i, 0, x.size()) res[i] = -x[i];
    return res;
}
poly operator-(const poly &x, const poly &y) { return x + (-y); }

poly operator*(const poly &x, const poly &y) {
    // if(x.size()+y.size()<=20){
    //     poly res(x.size()+y.size()-1);
    //     rep(i,x.size())rep(j,y.size()){
    //         res[i+j]+=x[i]*y[j];
    //     }
    //     return res;
    // }
    return atcoder::convolution(x, y);
}

// poly operator*(const poly&x,const poly&y){
//     poly res(x.size()+y.size()-1);
//     for(int i=0;i<x.size();++i){
//         for(int j=0;j<y.size();++j){
//             res[i+j]+=x[i]*y[j];
//         }
//     }
//     return res;
// }

// poly operator*(const poly&x,const poly&y){
//     return convolution(x,y);
// }

poly &operator+=(poly &x, const poly &y) { return x = (x + y); }
poly &operator-=(poly &x, const poly &y) { return x = (x - y); }
poly &operator*=(poly &x, const poly &y) { return x = (x * y); }
istream &operator>>(istream &in, poly &y) {
    int n = size(y);
    rep(i, 0, n) in >> y[i];
    return in;
}
ostream &operator<<(ostream &out, const poly &y) {
    int n = size(y);
    rep(i, 0, n) {
        if (i)
            out << ' ';
        out << y[i].val();
    }
    return out;
}
poly diff(const poly &x) {
    int n = size(x);
    poly res(n - 1);
    rep(i, 0, n - 1) res[i] = x[i + 1] * (i + 1);
    return res;
}
poly integrate(const poly &x) {
    int n = size(x);
    poly res(n + 1);
    rep(i, 1, n + 1) res[i] = x[i - 1] / i;
    return res;
}

poly inv(const poly &x) {
    int n = size(x);
    if (n == 1)
        return poly{x[0].inv()};
    auto c = inv(pre(x, (n + 1) / 2));
    return pre(c * (poly{2} - c * x), n);
}

poly log(const poly &x) {
    int n = size(x);
    assert(x[0].val() == 1);
    return pre(integrate(diff(x) * inv(x)), n);
}

poly exp(const poly &x) {
    assert(x[0].val() == 0);
    int n = size(x);
    if (n == 1)
        return poly{1};
    auto c = exp(pre(x, (n + 1) / 2));
    return pre(c * (poly{1} - log(pre(c, n)) + x), n);
}

pair<poly, poly> divmod(const poly &a, const poly &b) {
    assert(!b.empty());
    if (b.back().val() == 0)
        return divmod(a, shrink(b));
    if (a.empty())
        return make_pair(poly{}, poly{});
    if (a.back().val() == 0)
        return divmod(shrink(a), b);
    int n = max(0, size(a) - size(b) + 1);
    if (n == 0)
        return make_pair(poly{}, a);
    auto c = a;
    auto d = b;
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    d.resize(n);
    c *= inv(d);
    c.resize(n);
    reverse(c.begin(), c.end());
    return make_pair(c, pre(a - c * b, (int)b.size() - 1));
}

poly shift(poly a, mint c) {
    const int n = a.size();
    poly e(n);
    mint tmp = 1;
    for (int i = 0; i < n; ++i) {
        e[n - 1 - i] = tmp * fact_inv(i);
        tmp *= c;
    }
    for (int i = 0; i < n; ++i) {
        a[i] *= fact(i);
    }
    a *= e;
    poly res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = a[i + n - 1] * fact_inv(i);
    }
    return res;
}

mint eval(const poly &a, const mint &x) {
    int n = a.size();
    mint ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans = ans * x + a[i];
    }
    return ans;
}

poly multipoint_evalution(const poly &a, const poly &b) {
    int n = b.size();
    vector<poly> v(n * 2);
    rep(i, 0, n) { v[i + n] = poly{-mint(b[i]), mint(1)}; }
    for (int i = n - 1; i >= 1; --i) {
        v[i] = v[i * 2] * v[i * 2 + 1];
    }
    poly ans(n);
    v[0] = a;
    rep(i, 1, n * 2) {
        v[i] = divmod(v[i / 2], v[i]).second;
        if (i >= n)
            ans[i - n] = v[i][0];
    }
    return ans;
}

mint difference_product(poly a) {
    reverse(a.begin(), a.end());
    int n = a.size();
    vector<poly> v(n * 2), tb2(n * 2);
    vector<poly> tb(n * 2);
    int sz = 1;
    while (sz < n)
        sz *= 2;
    rep(i, 0, n) { v[(i + sz - n) % n + n] = poly{-a[i], mint(1)}; }
    rep(i, 0, n) { tb[(i + sz - n) % n + n] = poly{a[i], -mint(1)}; }
    for (int i = n - 1; i >= 1; --i) {
        v[i] = v[i * 2] * v[i * 2 + 1];
    }
    for (int i = n - 1; i >= 1; --i) {
        tb[i] = tb[i * 2] * tb[i * 2 + 1];
    }
    mint ans = 1;
    tb2[1] = poly{1};
    auto dfs = [&](auto dfs, lint i) -> void {
        if (i >= n) {
            return;
        }
        tb2[i * 2] = divmod(tb2[i], v[i * 2]).second;
        dfs(dfs, i * 2);
        tb2[i * 2 + 1] = divmod(tb2[i] * tb[i * 2], v[i * 2 + 1]).second;
        dfs(dfs, i * 2 + 1);
    };
    dfs(dfs, 1);
    rep(i, 0, n) {
        // cerr<<tb2[i+n].size()<<endl;
        ans *= tb2[i + n].size() ? tb2[i + n][0] : mint(0);
    }

    return ans;
}

vector<mint> composition(vector<mint> f, vector<mint> g) {
    int n = f.size(), m = g.size();
    assert(n == m);
    vector<mint> res(n);
    int b = ceil(sqrt(n));
    vector<vector<mint>> g_pow(b + 1);
    g_pow[0] = vector<mint>{1};
    for (int i = 0; i < b; ++i) {
        g_pow[i + 1] = g_pow[i] * g;
        g_pow[i + 1].resize(n);
    }
    vector<mint> g_pow2 = vector<mint>{1};
    for (int i = 0; i < n; i += b) {
        vector<mint> tmp;
        for (int j = i; j < std::min(i + b, n); ++j) {
            tmp += g_pow[j - i] * f[j];
        }
        res += tmp * g_pow2;
        res.resize(n);
        g_pow2 *= g_pow[b];
        g_pow2.resize(n);
    }
    return res;
}
#line 5 "main.cpp"

void solve() {
    lint n;
    cin >> n;
    vector<vec> g(n);
    rep(i, n - 1) {
        lint s, t;
        cin >> s >> t;
        s--;
        t--;
        g[s].emplace_back(t);
        g[t].emplace_back(s);
    }
    mint ans = 1;
    auto dfs = [&](auto dfs, lint now, lint p) -> pair<mint, mint> {
        poly res = {1};
        for (auto to : g[now]) {
            if (to == p)
                continue;
            auto [r, c] = dfs(dfs, to, now);
            auto tmp = res;
            tmp.insert(tmp.begin(), mint());
            res = res * r + (tmp * c);
        }
        mint s = 0, t = 0;
        rep(i, res.size()) {
            s += res[i] * fact(i);
            t += res[i] * fact(i) * i;
        }
        // cerr<<s<<t<<endl;
        return make_pair(s, s + t);
    };
    cout << dfs(dfs, 0, -1).first << endl;
}

int main() { solve(); }