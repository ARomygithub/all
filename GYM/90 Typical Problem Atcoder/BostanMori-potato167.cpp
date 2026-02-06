#line 1 "lib.cpp"
#include <bits/stdc++.h>
#line 3 "/Users/kaneshitakousuku/Desktop/AtCoder/code/library/po167_library/fps/FPS_Boston_Mori.hpp"
#include <atcoder/convolution>
#line 4 "/Users/kaneshitakousuku/Desktop/AtCoder/code/library/po167_library/fps/FPS_extend.hpp"

namespace po167{
// in  : DFT(v) (len(v) = z)
// out : DFT(v) (len(v) = 2 * z)
template<class T>
void FPS_extend(std::vector<T> &v){
    int z = v.size();
    T e = (T(atcoder::internal::primitive_root_constexpr(T::mod()))).pow(T::mod() / (2 * z));
    auto cp = v;
    atcoder::internal::butterfly_inv(cp);
    T tmp = (T)(1) / (T)(z);
    for (int i = 0; i < z; i++){
        cp[i] *= tmp;
        tmp *= e;
    }
    atcoder::internal::butterfly(cp);
    for (int i = 0; i < z; i++) v.push_back(cp[i]);
};
}
#line 1 "/Users/kaneshitakousuku/Desktop/AtCoder/code/library/po167_library/fps/FPS_pick_even_odd.hpp"
#pragma
#line 3 "/Users/kaneshitakousuku/Desktop/AtCoder/code/library/po167_library/fps/FPS_pick_even_odd.hpp"

namespace po167{
// s.t |v| = 2 ^ s (no assert)
template<class T>
void FPS_pick_even_odd(std::vector<T> &v, int odd){
    int z = v.size() / 2;
    T half = (T)(1) / (T)(2);
    if (odd == 0){
        for (int i = 0; i < z; i++){
            v[i] = (v[i * 2] + v[i * 2 + 1]) * half;
        }
        v.resize(z);
    } else {
        T e = (T(atcoder::internal::primitive_root_constexpr(T::mod()))).pow(T::mod() / (2 * z));
        T ie = T(1) / e;
        std::vector<T> es = {half};
        while ((int)es.size() != z){
            std::vector<T> n_es((int)es.size() * 2);
            for (int i = 0; i < (int)es.size(); i++){
                n_es[i * 2] = (es[i]);
                n_es[i * 2 + 1] = (es[i] * ie);
            }
            ie *= ie;
            std::swap(n_es, es);
        }
        for (int i = 0; i < z; i ++){
            v[i] = (v[i * 2] - v[i * 2 + 1]) * es[i];
        }
        v.resize(z);
    }
}
}
#line 7 "/Users/kaneshitakousuku/Desktop/AtCoder/code/library/po167_library/fps/FPS_Boston_Mori.hpp"

namespace po167{
// return [x^k] P(x) / Q(x)
template<class T>
T Boston_Mori(long long k, std::vector<T> P, std::vector<T> Q){
    assert(!Q.empty() && Q[0] != 0);
    int z = 1;
    while (z < (int)std::max(P.size(), Q.size())) z *= 2;
    P.resize(z * 2, 0);
    Q.resize(z * 2, 0);
    atcoder::internal::butterfly(P);
    atcoder::internal::butterfly(Q);

    // fast
    while (k){
        // Q(-x)
        std::vector<T> Q_n(z * 2);
        for (int i = 0; i < z; i++){
            Q_n[i * 2] = Q[i * 2 + 1];
            Q_n[i * 2 + 1] = Q[i * 2];
        }
        for (int i = 0; i < z * 2; i++){
            P[i] *= Q_n[i];
            Q[i] *= Q_n[i];
        }
        FPS_pick_even_odd(P, k & 1);
        FPS_pick_even_odd(Q, 0);
        k /= 2;
        if (k == 0) break;
        FPS_extend(P);
        FPS_extend(Q);
    }
    T SP = 0, SQ = 0;
    for (int i = 0; i < z; i++) SP += P[i], SQ += Q[i];
    return SP / SQ;
}

template<class T>
// 0 = a[i] * c[0] + a[i - 1] * c[1] + a[i - 2] * c[2] + ... + a[i - d] * c[d]
// a.size() + 1 == c.size()
// c[0] = - 1 ?
// return a[k]
T Kth_Linear(long long k, std::vector<T> a, std::vector<T> c){
    int d = a.size();
    assert(d + 1 == int(c.size()));
    std::vector<T> P = atcoder::convolution(a, c);
    P.resize(d);
    return Boston_Mori(k, P, c);
}
};
#line 4 "/Users/kaneshitakousuku/Desktop/AtCoder/code/library/po167_library/fps/FPS_inv.hpp"

namespace po167{
// return 1 / f
template <class T>
std::vector<T> FPS_inv(std::vector<T> f, int len = -1){
    if (len == -1) len = f.size();
    assert(f[0] != 0);
    std::vector<T> g = {1 / f[0]};
    int s = 1;
    while(s < len){
        // g = 2g_s - f(g_s)^2 (mod x ^ (2 * s))
        // g = g - (fg - 1)g
        // (fg - 1) = 0 (mod x ^ (s))
        std::vector<T> n_g(s * 2, 0);
        std::vector<T> f_s(s * 2, 0);
        g.resize(s * 2);
        for (int i = 0; i < s * 2; i++){
            if (int(f.size()) > i) f_s[i] = f[i];
            n_g[i] = g[i];
        }
        atcoder::internal::butterfly(g);
        atcoder::internal::butterfly(f_s);
        for (int i = 0; i < s * 2; i++){
            f_s[i] *= g[i];
        }
        atcoder::internal::butterfly_inv(f_s);
        T iz = 1 / (T)(s * 2);
        for (int i = s; i < s * 2; i++){
            f_s[i] *= iz;
        }
        for (int i = 0; i < s; i++){
            f_s[i] = 0;
        }
        atcoder::internal::butterfly(f_s);
        for (int i = 0; i < s * 2; i++){
            f_s[i] *= g[i];
        }
        atcoder::internal::butterfly_inv(f_s);
        for (int i = s; i < s * 2; i++){
            n_g[i] -= f_s[i] * iz;
        }
        std::swap(n_g, g);
        s *= 2;
    }
    g.resize(len);
    return g;
}
}
#line 4 "lib.cpp"
using mint = atcoder::modint998244353;
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;
    vector<int> p(K + 2);
    for (int i = 1; i <= K; i++) p[K / i]++;
    p[K + 1] = 1;
    vector<mint> base = {1};
    for (int i = 1; i <= K + 1; i++){
        if (p[i] == 0) continue;
        vector<mint> g(1 + (int)base.size());
        g[0] = 1;
        for (int j = 1; j <= (int)base.size(); j++){
            g[j] = base[j - 1] * -p[i];
        }
        if (i != K + 1){
            base = atcoder::convolution(base, po167::FPS_inv(g, i + 1));
            base.resize(i + 1);
        }
        else{
            cout << po167::Boston_Mori(N, base, g).val() << "\n";
        }
    }
}
\