#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long long LL;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> PLL;

const int MOD = 1000000007;

LL expo(LL a, LL b, LL MODULO = MOD) {
  // a %= MOD; // USE THIS WHEN N IS REALLY BIG!
  LL ret = 1;
  while (b > 0) {
    if (b & 1) ret = (ret * a) % MODULO;
    a = (a * a) % MODULO; b >>= 1;
  }
  return ret;
}

struct PowersArray {
  vector <vector <int>> p;
  PowersArray(int n, int m, int primes){
    if(n > m) swap(n, m);
    p.resize(m);
    rep(i, 0, m){
      int curm = (i < n ? m : n);
      p[i].resize(curm);
      p[i][curm - 1] = expo(primes, m * (m - i - 1) + (m - curm));
      rrep(j, curm - 2, -1){
        p[i][j] = (1LL * p[i][j + 1] * primes) % MOD;
      }
    }
  }
};

template<class T>
struct SubMatrix {
  vector<vector<T>> p;
  SubMatrix(vector<vector<T>>& v) {
    int R = sz(v), C = sz(v[0]);
    p.assign(R + 1, vector<T>(C + 1));
    rep(r, 0, R) rep(c, 0, C) {
      p[r + 1][c + 1] = (v[r][c] + p[r][c + 1] + p[r + 1][c] - p[r][c] + MOD);
      while (p[r + 1][c + 1] >= MOD) p[r + 1][c + 1] -= MOD;
    }
  }
  T sum(int u, int l, int d, int r) {
    T ret = (p[d][r] - p[d][l] - p[u][r] + p[u][l] + (MOD << 1));
    while (ret >= MOD) ret -= MOD;
    return ret;
  }
};

typedef SubMatrix<LL> matrix;

// This is hashing int, please mind you're hashing string and map 'a'-> 1, 'b'-> 2, and such
LL goodPrimes[] = {196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};

matrix hasher(vvl &isi, LL prime, int N) {
  int n = sz(isi);
  int m = sz(isi[0]);
  vvl tmp(n, vl(m));
  rep(i, 0, n) {
    LL base = expo(prime, N * i);
    rep(j, 0, m) {
      tmp[i][j] = isi[i][j] * base % MOD;
      base = base * prime % MOD;
    }
  }
  matrix ret(tmp);
  return ret;
}

LL getNum(LL x, LL y, LL c, bool oneIndex = 1) {
  return (x - oneIndex) * c + y;
}

void adjust(LL &hasha, pii pos, PowersArray &tmp) {
  hasha = hasha * tmp.p[pos.fi][pos.se] % MOD;
}

// Rotate 90 deg
pii rotate (pii st, pii ed, int times) {
  if (times == 0) return st;
  if (times == 1) return {st.fi, ed.se};
  if (times == 2) return ed;
  if (times == 3) return {ed.fi, st.se};
  assert(false);
  return st;
}

template <class T>
vector <vector <T>> rotate(const vector <vector <T>> &tmp) {
  int n = sz(tmp);
  int m = sz(tmp[0]);
  vector <vector <T>> ret(m, vector <T>(n));
  rep(i, 0, m) rep(j, 0, n) {
    ret[i][j] = tmp[n - j - 1][i];
  }
  return ret;
}



int main() {
  int n, m; cin >> n >> m;
  int N = max(n, m);
  vector<vvl> isi(4, vvl(n, vector<ll>(m)));
  vector<vvi> indexes(4);
  indexes[0] = vvi(n, vi(m));
  vector <matrix> myHash[4];

  int cnt = 0;
  rep(i, 0, n) rep(j, 0, m) {
    char ch; cin >> ch;
    isi[0][i][j] = ch - 'a' + 1;
    indexes[0][i][j] = cnt++;
    assert(getNum(i, j, m, 0) == indexes[0][i][j]);
  }


  // Use 2 hash
  rep(i, 1, 4) isi[i] = rotate(isi[i - 1]), indexes[i] = rotate(indexes[i - 1]);
  rep(i, 0, 4) {
    myHash[i].pb(hasher(isi[i], goodPrimes[0], N));
    myHash[i].pb(hasher(isi[i], goodPrimes[1], N));
  }

  vector <PowersArray> myPower;
  myPower.pb(PowersArray(n, m, goodPrimes[0]));
  myPower.pb(PowersArray(n, m, goodPrimes[1]));

  int kiri = 1;
  int kanan = min(n, m) + 1;
  while (kiri < kanan) {
    int mid = (kiri + kanan) >> 1;
    vector <pair<PLL, int>> ori;
    // Check with mid large
    rep(i, 0, n) {
      if (i + mid > n) break;
      rep(j, 0, m) {
        if (j + mid > m) break;
        PLL curHash = {myHash[0][0].sum(i, j, i + mid, j + mid),
                       myHash[0][1].sum(i, j, i + mid, j + mid)
                      };
        adjust(curHash.fi, {i, j}, myPower[0]);
        adjust(curHash.se, {i, j}, myPower[1]);
        ori.pb({curHash, indexes[0][i][j]});
      }
    }
    sort(all(ori));
    int tmps = sz(ori);
    bool isOK = 1;
    rep(i, 1, tmps) {
      if (ori[i].fi == ori[i - 1].fi) {
        isOK = 0;
        break;
      }
    }
    rep(dir, 1, 4) {
      if (!isOK) break;
      int curn = n, curm = m;
      if (dir & 1) swap(curn, curm);
      rep(i, 0, curn) {
        if (!isOK) break;
        if (i + mid > curn) break;
        rep(j, 0, curm) {
          if (!isOK) break;
          if (j + mid > curm) break;
          PLL curHash = {myHash[dir][0].sum(i, j, i + mid, j + mid),
                         myHash[dir][1].sum(i, j, i + mid, j + mid)
                        };
          adjust(curHash.fi, {i, j}, myPower[0]);
          adjust(curHash.se, {i, j}, myPower[1]);
          int pos = lower_bound(all(ori), (pair<PLL, int>) {curHash, 0}) - ori.begin();
          rep(nxpos, pos, pos + 2) {
            if (nxpos >= sz(ori)) continue;
            pii cur = rotate({i, j}, {i + mid - 1, j + mid - 1}, dir);
            if (ori[nxpos].fi == curHash && ori[nxpos].se != indexes[dir][cur.fi][cur.se]) {
              isOK = 0;
              break;
            }
          }
        }
      }
    }
    if (isOK) kanan = mid;
    else kiri = mid + 1;
    // return 0;
  }
  cout << kiri << endl;
}