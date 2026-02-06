#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define L(n) (n << 1)
#define R(n) (n << 1 | 1)
#define print_vector(n) for(auto a0 : n) cout << a0 << ' '; cout << endl;
#define vector_sort(n) sort(n.begin(), n.end())
#define print_array(n, l, r) for(int a0 = l; a0 <= r; a0++) cout << n[a0] << ' '; cout << '\n';
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define ABS(a) ((a) > 0 ? (a) : -(a))
#define int long long
using namespace std;

template<class T>
istream & operator >> (istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}

template<class T>
ostream & operator <<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
  static void print(ostream &out, const Tuple& t) {
    TuplePrinter<Tuple, N-1>::print(out, t);
    out << ' ' << get<N-1>(t);
  }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(ostream &out, const Tuple& t) {
    out << get<0>(t);
  }
};

template<class... Args>
ostream & operator <<(ostream &out, const tuple<Args...> &p) {
  TuplePrinter<decltype(p), sizeof...(Args)>::print(out, p);
  return out;
}

int N, Q;
int A[400005], D[400005];
int B[400005];

int checkValue(int num) {
  return num < 0 ? -1 : (num == 0 ? 0 : 1);
}

namespace segtree {
  struct Node {
    int kiri, kanan, sum;

    Node() {
      kiri = kanan = sum = 0;
    }

    Node(int content) {
      kiri = kanan = content;
      sum = 0;
    }

    void merge(Node &l, Node &r) {
      sum = l.sum + r.sum;
      if (l.kiri == 0 && r.kiri == 0) {
        kiri = kanan = 0;
      }else if (l.kiri == 0) {
        kiri = r.kiri;
        kanan = r.kanan;
      }else if (r.kiri == 0) {
        kiri = l.kiri;
        kanan = l.kanan;
      }else {
        sum += (l.kanan != r.kiri);
        kiri = l.kiri;
        kanan = r.kanan;
      }
    }
  };

  Node tree[1000005];

  void build(int n, int l, int r) {
    if (l == r) {
      tree[n] = Node(B[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(L(n), l, mid);
    build(R(n), mid + 1, r);
    tree[n].merge(tree[L(n)], tree[R(n)]);
    // cout << l << " " << r << " -> " << tree[n].sum << "\n";
  }

  void build() {
    for (int i = 1; i < N; i++) {
      D[i] = A[i] - A[i + 1];
      B[i] = checkValue(D[i]);
      // cout << B[i] << " ";
    }
    // cout << "\n";
    build(1, 1, N-1);
  }

  void update(int n, int l, int r, int pos) {
    if (l == r) {
      tree[n] = Node(B[pos]);
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(L(n), l, mid, pos);
    else update(R(n), mid + 1, r, pos);
    tree[n].merge(tree[L(n)], tree[R(n)]);
  }

  void update(int pos, int val) {
    // if (pos == 0 || pos == N+1) return;
    int lastB = B[pos];
    D[pos] += val;
    B[pos] = checkValue(D[pos]);
    // cout << pos << " - " << val << "\n";
    if (lastB != B[pos]) update(1, 1, N-1, pos);
  }

  void update(int l, int r, int x) {
    if (l != 1) {
      update(l-1, -x);
    }
    if (r != N) {
      update(r, x);
    }
    // print_array(D, 1, N);
  }

  Node q_res;

  void query(int n, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      q_res.merge(q_res, tree[n]);
      // cout << "   " << l << " " << r << " -> " << q_res.sum << " " << q_res.kiri << " " << q_res.kanan << "\n";
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) query(L(n), l, mid, ql, qr);
    if (qr > mid) query(R(n), mid + 1, r, ql, qr);
  }

  int query(int ql, int qr) {
    if (ql == qr) return 1;
    qr--;
    q_res = Node();
    query(1, 1, N-1, ql, qr);
    // cout << "-> " << ql << " " << qr << ": " << q_res.sum << " " << q_res.kiri << " " << q_res.kanan << "\n";
    return q_res.sum + (q_res.kiri != 0) + 1;
  }
}

void prepare() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  if (N != 1) segtree::build();
}

void solve() {
  cin >> Q;
  int ty, l, r, x;
  while (Q--) {
    cin >> ty;
    if (ty == 1) {
      cin >> l >> r >> x;
      segtree::update(l, r, x);
    }else {
      cin >> l >> r;
      cout << segtree::query(l, r) << "\n";
    }
  }
}

int32_t main() {
  prepare();
  solve();
}