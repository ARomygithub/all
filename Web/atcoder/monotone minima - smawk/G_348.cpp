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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n;
constexpr ll inf = 1ll << 60;
vector<pair<ll, ll>> x; // x : (a, b)

template <class F>
vector<ll> monotone_maxima(F &f, int h, int w) {
    vector<ll> ret(h);
    auto sol = [&](auto &&self, const int l_i, const int r_i, const int l_j, const int r_j) -> void {
        const int m_i = (l_i + r_i) / 2;
        int max_j = l_j;
        ll max_val = -inf;
        for (int j = l_j; j <= r_j; ++j) {
            const ll v = f(m_i, j);
            if (v > max_val) {
                max_j = j;
                max_val = v;
            }
        }
        ret[m_i] = max_val;

        if (l_i <= m_i - 1) {
            self(self, l_i, m_i - 1, l_j, max_j);
        }
        if (m_i + 1 <= r_i) {
            self(self, m_i + 1, r_i, max_j, r_j);
        }
    };
    sol(sol, 0, h - 1, 0, w - 1);
    return ret;
}

vector<ll> max_plus_convolution(const vector<ll> &a, const vector<ll> &b) {
    const int n = (int)a.size(), m = (int)b.size();
    auto f = [&](int i, int j) {
        if (i < j or i - j >= m) {
            return -inf;
        }
        return a[j] + b[i - j];
    };

    return monotone_maxima(f, n + m - 1, n);
}

vector<ll> sol(const int l, const int r) {
    if (r - l == 1) {
        const vector<ll> ret = {-inf, x[l].first - x[l].second};
        return ret;
    }
    const int m = (l + r) / 2;
    const auto res_l = sol(l, m);
    const auto res_r = sol(m, r);

    vector<ll> sorted_l(m - l);
    for (int i = l; i < m; ++i) {
        sorted_l[i - l] = x[i].first;
    }
    sort(sorted_l.begin(), sorted_l.end(), greater());
    for (int i = 1; i < m - l; ++i) {
        sorted_l[i] += sorted_l[i - 1];
    }
    sorted_l.insert(sorted_l.begin(), -inf);

    auto res = max_plus_convolution(res_r, sorted_l);

    for (int i = 0; i < (int)res_l.size(); ++i) {
        res[i] = max(res[i], res_l[i]);
    }
    for (int i = 0; i < (int)res_r.size(); ++i) {
        res[i] = max(res[i], res_r[i]);
    }
    return res;
}

void solve() {
    cin >>n;
    x.resize(n);
    rep(i,0,n) {
        cin >>x[i].fi >>x[i].se;
    }
    sort(x.begin(), x.end(), [&](pll a, pll b) -> bool {
        return make_pair(a.se,a.fi) < make_pair(b.se,b.fi);
    });
    auto ans = sol(0, n);
    rep(i,1,n+1) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}