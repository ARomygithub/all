#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,x,ka;
using ipii = pair<int,pii>;
// const ll inf = 1e15;

#include <cstddef>
#include <cstdint>

using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

#include <functional>
#include <numeric>
#include <vector>

template <class Select>
std::vector<usize> smawk(const usize row_size, const usize col_size,
                         const Select &select) {
  using vec_zu = std::vector<usize>;

  const std::function<vec_zu(const vec_zu &, const vec_zu &)> solve =
      [&](const vec_zu &row, const vec_zu &col) -> vec_zu {
    const usize n = row.size();
    if (n == 0)
      return {};
    vec_zu c2;
    for (const usize i : col) {
      while (!c2.empty() && select(row[c2.size() - 1], c2.back(), i))
        c2.pop_back();
      if (c2.size() < n)
        c2.push_back(i);
    }
    vec_zu r2;
    for (usize i = 1; i < n; i += 2)
      r2.push_back(row[i]);
    const vec_zu a2 = solve(r2, c2);
    vec_zu ans(n);
    for (usize i = 0; i != a2.size(); i += 1)
      ans[i * 2 + 1] = a2[i];
    usize j = 0;
    for (usize i = 0; i < n; i += 2) {
      ans[i] = c2[j];
      const usize end = i + 1 == n ? c2.back() : ans[i + 1];
      while (c2[j] != end) {
        j += 1;
        if (select(row[i], ans[i], c2[j]))
          ans[i] = c2[j];
      }
    }
    return ans;
  };
  vec_zu row(row_size);
  std::iota(row.begin(), row.end(), 0);
  vec_zu col(col_size);
  std::iota(col.begin(), col.end(), 0);
  return solve(row, col);
}

template <class T>
std::vector<T> concave_max_plus_convolution(const std::vector<T> &a,
                                            const std::vector<T> &b) {
  const usize n = a.size();
  const usize m = b.size();
  const auto get = [&](const usize i, const usize j) {
    return a[j] + b[i - j];
  };
  const auto select = [&](const usize i, const usize j, const usize k) {
    if (i < k)
      return false;
    if (i - j >= m)
      return true;
    return get(i, j) <= get(i, k);
  };
  const std::vector<usize> amax = smawk(n + m - 1, n, select);
  std::vector<T> c(n + m - 1);
  for (usize i = 0; i != n + m - 1; i += 1)
    c[i] = get(i, amax[i]);
  return c;
}


vector<ll> dotes(vector<ll>& a, vector<ll>& b) {
    vector<ll> ret(sz(a),0);
    rep(i,0,sz(a)) {
        rep(j,0,sz(b)) {
            if(i+j<=sz(a)) {
                max_self(ret[i+j], a[i]+b[j]);
            }
        }
    }
    return ret;
}

void solve() {
    cin >>n >>x >>ka;
    vector<ipii> v;
    rep(i,0,n) {
        int p,u,c; cin >>p >>u >>c;
        v.push_back({c,{p,u}});
    }
    sort(all(v));
    vector<vector<ll>> vdp;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && v[j].fi==v[i].fi) {
            j++;
        }
        vector<ll> dp(x+1,0);
        rep(k,i,j) {
            auto [p,u] = v[k].se;
            per(xi,x,p-1) {
                max_self(dp[xi], dp[xi-p]+u);
            }
        }
        rep(xi,0,x+1) {
            if(dp[xi]>0) {
                dp[xi] += ka;
            }
        }
        vdp.push_back(dp);
        i = j;
    }
    debug() <<imie(sz(vdp));
    rep(i,0,sz(vdp)-1) {
        debug() <<imie(i);
        vector<ll> tes = dotes(vdp[i],vdp[i+1]);
        vdp[i+1] = concave_max_plus_convolution(vdp[i],vdp[i+1]);
        // rep(j,0,x+1) {
        //     if(tes[j]!=vdp[i+1][j]) {
        //         debug() <<imie(j);
        //         debug() <<imie(vdp[i+1]);
        //         debug() <<imie(tes);
        //         assert(false);
        //     }
        // }
    }
    ll ans = 0;
    rep(xi,0,x+1) {
        max_self(ans, vdp.back()[xi]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}