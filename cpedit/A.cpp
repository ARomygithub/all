// Problem: A. Breach of Faith
// Contest: Codeforces - Codeforces Round 1008 (Div. 1)
// URL: https://codeforces.com/contest/2077/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i > (b); --i)
#define sz(x) (int)(x).size()
using pii = pair<int, int>;
#define fi first
#define se second
using ll = long long;
#define all(x) (x).begin(), (x).end()

template <typename T>
void min_self(T& A, T B) {
  A = min(A, B);
}
template <typename T>
void max_self(T& A, T B) {
  A = max(A, B);
}

const int mxn = 2e5;
int n, t;
int a[mxn * 2];

void solve() {
  cin >> n;
  // set<ll> s;
  rep(i, 0, n * 2) {
    cin >> a[i];
    // s.insert(a[i]);
  }
  sort(a, a + n * 2);
  ll x = 0;
  rep(i, n - 1, n * 2) { x += a[i]; }
  rep(i, 0, n - 1) { x -= a[i]; }

  // if(s.count(x)) {
  //     rep(i,n,n*2) {
  //         bool ok = 0;
  //         per(j,n-1,-1) {
  //             ll nx = x - (a[i]-a[j])*2;
  //             if(nx<=0) break;
  //             if(!s.count(nx)) {
  //                 x = nx;
  //                 swap(a[i],a[j]);
  //                 ok = 1;
  //                 break;
  //             }
  //         }
  //         if(ok) break;
  //     }
  // }
  cout << a[n - 1] << " " << x << " ";
  rep(i, 0, n * 2 - 1) {
    int j = (i / 2);
    if (i % 2) {
      cout << a[j] << " ";
    } else {
      cout << a[n + j] << " \n"[i == n * 2 - 2];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
}