#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef long long ll;
typedef pair<LL, LL> PLL;

const ll LINF = 4557430888798830399LL;

inline void fasterios() {
  // Do not use if interactive
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  // cout << fixed << setprecision(10);
}

LL chanek, C;

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  static const ll inf = LINF;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    k = -k; m = -m;
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return -(l.k * x + l.m);
  }
};


LineContainer segTree[800005];

// Make interval tree here
void insertLine(int kiri, int kanan, int idx, int &tar, ll &k, ll &m) {
  if (kiri > tar || kanan < tar) return;
  segTree[idx].add(k, m);
  if (kiri == kanan) return;
  int mid = (kiri + kanan) >> 1;
  insertLine(kiri, mid, idx * 2, tar, k, m);
  insertLine(mid + 1, kanan, idx * 2 + 1, tar, k, m);
}

int findLeftBefore(int kiri, int kanan, int idx, int &tar, ll &x, ll &c) {
  if (kiri > tar) return -1;
  if (kiri == kanan) return (segTree[idx].query(x) <= chanek - c) ? kiri : -1;
  // cout << kiri << " " << kanan << " " << idx << " " << tar << endl;
  int mid = (kiri + kanan) >> 1;
  // kiri mid tar kanan
  if (mid <= tar) {
    // cout << segTree[idx * 2].query(x) + c << endl;
    if (segTree[idx * 2].query(x) <= chanek - c) {
      // cout << "Going left " << endl;
      // Can be used
      return findLeftBefore(kiri, mid, idx * 2, tar, x, c);
    } else {
      // Use its right
      return findLeftBefore(mid + 1, kanan, idx * 2 + 1, tar, x, c);
    }
  } else {
    return findLeftBefore(kiri, mid, idx * 2, tar, x, c);
    // kiri tar mid kanan
  }
}

int findRightAfter(int kiri, int kanan, int idx, int &tar, ll &x, ll&c) {
  if (kanan < tar) return -1;
  if (kiri == kanan) return (segTree[idx].query(x) <= chanek - c) ? kiri : -1;
  int mid = (kiri + kanan) >> 1;

  // kiri tar mid kanan
  if (tar <= mid) {
    if (segTree[idx * 2 + 1].query(x) <= chanek - c) {
      return findRightAfter(mid + 1, kanan, idx * 2 + 1, tar, x, c);
    } else {
      return findRightAfter(kiri, mid, idx * 2, tar, x, c);
    }
  } else {
    return findRightAfter(mid + 1, kanan, idx * 2 + 1, tar, x, c);
  }
}

void build(int kiri, int kanan, int idx, vector<LL> &b) {
  for (int j = kiri; j <= kanan; j++) {
    segTree[idx].add(j, C * j * j + b[j]);
  }
  if (kiri == kanan) return;
  int mid = (kiri + kanan) >> 1;
  build(kiri, mid, idx * 2, b);
  build(mid + 1, kanan, idx * 2 + 1, b);
}

int solve2(int n) {
  vector <LL> a(n);
  vector <LL> b(n);
  rep(i, 0, n) cin >> a[i];
  rep(j, 0, n) cin >> b[j];
  build(0, n - 1, 1, b);
  rep(i, 0, n) {
    // Cost a[i] + b[j] + C*i*i + C * j * j - 2 * C * i * j)
    ll m = a[i] + C * i * i;
    ll x = -2 * C * i;
    // cout << "Computing " << i << endl;
    PLL ans = {0, chanek};

    rep(j, 0, 2) {
      ll idx = (!j ? findLeftBefore(0, n - 1, 1, i, x, m) : findRightAfter(0, n - 1, 1, i, x, m));
      if (idx == -1) continue;
      // cout << (j ? "kiri " : "kanan ") << idx << endl;
      ll curcost = a[i] + b[idx] + C * (i - idx) * (i - idx);
      // cout << curcost << endl;
      PLL curans = {abs(idx - i) + 1, chanek - curcost};
      // bcout << "Computing " << i << " with idx: " << idx << endl;
      // rcout << curcost << endl;
      // gcout << curans.fi << " " << curans.se << endl;
      ans = max(ans, curans);
    }
    cout << ans.fi << " " << ans.se << endl;
  }
  return 0;
}

int solve1(int n) {

  vector <LL> A(n + 1), B(n + 1);
  rep(i, 1, n + 1) cin >> A[i];
  rep(i, 1, n + 1) cin >> B[i];
  vector <PLL> tmpAns(n + 1, {0, chanek});
  // Cari tahu jika pergi dari stasiun ke-i, terbaik j mana yang paling bagus dengan i <= j
  // Cost(i, j) = A[i] + B[j] + C * j - C * i
  PLL ans(0, chanek);
  // Binary search, if cost is higher than the previous, dont insert. maintain decreasing array.
  vector <PLL> v;
  for (int i = 1; i <= n; i++) {
    // Update
    if (v.empty() || v.back().se > B[i] - C * i) {
      v.pb({i, B[i] - C * i});
    }
    // Query
    LL qCost = chanek - (A[i] + C * i);
    int kiri = 0;
    int kanan = sz(v);
    while (kiri < kanan) {
      int mid = (kiri + kanan) >> 1;
      if (v[mid].se <= qCost) kanan = mid;
      else kiri = mid + 1;
    }
    if (sz(v) == kiri) continue; // No index suffice
    PLL curans = {i - v[kiri].fi + 1, qCost - v[kiri].se};
    tmpAns[i] = curans;
  }

  v.clear();

  for (int i = n; i >= 1; i--) {
    // Update
    if (v.empty() || v.back().se > B[i] + C * i) {
      v.pb({i, B[i] + C * i});
    }
    // Query
    LL qCost = chanek - (A[i] - C * i);
    int kiri = 0; int kanan = sz(v);
    while (kiri < kanan) {
      int mid = (kiri + kanan) >> 1;
      if (v[mid].se <= qCost) kanan = mid;
      else kiri = mid + 1;
    }
    if (sz(v) == kiri) continue; // No index suffice
    PLL curans = {v[kiri].fi - i + 1, qCost - v[kiri].se};
    tmpAns[i] = max(tmpAns[i], curans);
  }

  for (int i = 1; i <= n; i++) cout << tmpAns[i].fi << " " << tmpAns[i].se << endl;
  return 0;
}

int main() {
  fasterios();
  int n, p; cin >> n >> chanek >> C >> p;
  if (p == 1) solve1(n);
  else solve2(n);
}