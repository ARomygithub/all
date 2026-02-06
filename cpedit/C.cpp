// Problem: C. Binary Subsequence Value Sum
// Contest: Codeforces - Codeforces Round 1008 (Div. 1)
// URL: https://codeforces.com/contest/2077/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template <class c
#define ris return *this
#define dor > debug& operator<<
#define eni(x) \
  sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {
  c b, e;
};
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
  ~debug() { cerr << endl; }
  eni(!=) cerr << boolalpha << i;
  ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) { ris << "(" << d.fi << ", " << d.se << ")"; }
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it) {
    *this << ", " + 2 * (it == d.b) << *it;
  }
  ris << "]";
}
}
;
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]"

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i > (b); --i)
#define ar array
#define sz(x) (int)(x).size()
#define pii pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template <typename T>
void min_self(T& A, T B) {
  A = min(A, B);
}
template <typename T>
void max_self(T& A, T B) {
  A = max(A, B);
}

const int mxn = 2e5, mxa = 2e5;
const ll mod = 998244353;
int n, q, t;
string s;
ll iv[mxa + 1], fct[mxa + 1], ifc[mxa + 1];

void init_fac() {
  iv[1] = 1;
  for (int i = 2; i <= mxa; i++) {
    iv[i] = mod - mod / i * iv[mod % i] % mod;
  }
  fct[0] = 1, ifc[0] = 1;
  for (int i = 1; i <= mxa; i++) {
    fct[i] = fct[i - 1] * i % mod;
    ifc[i] = ifc[i - 1] * iv[i] % mod;
  }
}

ll C(ll a, ll b) {
  if (a < b || a < 0 || b < 0) return 0;
  ll ret = fct[a];
  ret = ret * ifc[b] % mod;
  ret = ret * ifc[a - b] % mod;
  return ret;
}

void solve() {
  cin >> n >> q;
  cin >> s;
  vector<ll> v(n + 1);
  rep(i, 0, n + 1) { v[i] = C(n, i); }
  vector<ll> pref0(n + 1, 0);
  pref0[0] = v[0];
  rep(i, 1, n + 1) { pref0[i] = (pref0[i - 1] + v[i]) % mod; }
  vector<ll> pref(n + 1, 0);
  pref[0] = v[0];
  pref[1] = (v[0] + v[1]) % mod;
  rep(i, 2, n + 1) {
    pref[i] = (v[i] + v[i - 1]) % mod;
    pref[i] = (pref[i] + pref[i - 2]) % mod;
    pref[i] = (pref[i] + pref0[i - 2]) % mod;
  }
  vector<ll> ans(n + 1, 0);
  rep(i, 2, n + 1) {
    ll cur = 1ll * (i / 2) * ((i + 1) / 2) % mod;
    cur = cur * v[n - i] % mod;
    ans[n] = (ans[n] + cur) % mod;
  }
  per(i, n - 1, 1) { ans[i] = (ans[i + 1] - pref[i - 1] + mod) % mod; }
  int cur = 0;
  rep(i, 0, n) {
    if (s[i] == '1') {
      cur++;
    }
  }
  // debug() <<imie(ans);
  while (q--) {
    int i;
    cin >> i;
    i--;
    if (s[i] == '1') {
      cur--;
      s[i] = '0';
    } else {
      cur++;
      s[i] = '1';
    }
    // debug() <<imie(cur);
    // if(cur<0) {
    //     cout <<"0\n";
    // } else {
    cout << (ans[cur] + ans[n - cur]) % mod << "\n";
    // }
    // cout <<flush;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  init_fac();
  while (t--) {
    solve();
  }
}