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

const int mxn=15e4,mxm=10;
int n,m;
int a[mxn];

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

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    string s = "";
    rep(i,0,n) {
        s += (char)('A'+a[i]);
    }
    SuffixArray sa(s);
    RMQ<int> rmq(sa.lcp);
    ll ans = n;
    int st = 0, leni=n;
    rep(i,2,n+1) {
        int len = sa.lcp[i];
        int le = i;
        int l=0,r=i-1;
        while(l<=r) {
            int mid = (l+r)/2;
            int qry = rmq.query(mid,i+1);
            if(qry>=len) {
                le = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        int ri = i;
        l = i+1, r = n;
        while(l<=r) {
            int mid = (l+r)/2;
            int qry = rmq.query(i,mid+1);
            if(qry>=len) {
                ri = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        if(1ll*len*(ri-le+2)>ans) {
            ans = 1ll*len*(ri-le+2);
            leni = len;
            st = sa.sa[i];
        }
    }
    cout <<ans <<"\n";
    cout <<leni <<"\n";
    rep(i,0,leni) {
        cout <<a[i+st] <<" \n"[i==leni-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}