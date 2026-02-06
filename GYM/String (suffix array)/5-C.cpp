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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=4e5;
int n,m;
string s;
int l[mxn],r[mxn];

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
    }
};

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

using piii = tuple<int,int,int>;

void solve() {
    cin >>s;
    n = sz(s);
    cin >>m;
    rep(i,0,m) {
        cin >>l[i] >>r[i]; l[i]--,r[i]--;
    }
    SuffixArray sa(s);
    vi isa(n), isam(m);
    rep(i,1,n+1) {
        int st = sa.sa[i];
        isa[st] = i;
    }
    RMQ<int> rmq(sa.lcp);
    rep(i,0,m) {
        int isami = isa[l[i]];
        int len = r[i]-l[i]+1;
        int li = 0, ri=isami-1;
        while(li<=ri) {
            int mid = (li+ri)/2;
            int qry = rmq.query(mid+1,isa[l[i]]+1);
            if(qry>=len) {
                isami = mid;
                ri = mid-1;
            } else {
                li = mid+1;
            }
        }
        isam[i] = isami;
        r[i] = len;
    }
    vi idx(m);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(), [&](int i, int j) -> bool {
        return (piii){isam[i],r[i],l[i]} < (piii){isam[j],r[j],l[j]};
    });
    rep(j,0,m) {
        int i = idx[j];
        cout <<l[i]+1 <<" " <<l[i]+r[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}