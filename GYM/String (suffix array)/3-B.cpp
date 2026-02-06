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

const int mxn=3e5;
int n,m;
string s,t;

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

void solve() {
    cin >>s;
    n = sz(s);
    SuffixArray sa(s);
    cin >>m;
    while(m--) {
        cin >>t;
        int le=-1;
        int l = 1, r= n;
        while(l<=r) {
            int mid = (l+r)/2;
            int start = sa.sa[mid];
            bool ok = 1;
            rep(i,0,sz(t)) {
                if(i+start>=n || s[i+start]<t[i]) {
                    l = mid+1;
                    ok = 0;
                    break;
                } else if(s[i+start]>t[i]) {
                    r = mid-1;
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                le = mid;
                r = mid-1;
            }
        }
        int ri = -1;
        l = 1, r = n;
        while(l<=r) {
            int mid = (l+r)/2;
            int start = sa.sa[mid];
            bool ok = 1;
            rep(i,0,sz(t)) {
                if(i+start>=n || s[i+start]<t[i]) {
                    l = mid+1;
                    ok = 0;
                    break;
                } else if(s[i+start]>t[i]) {
                    r = mid-1;
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                ri = mid;
                l = mid+1;
            }
        }
        if(le!=-1) {
            cout <<ri-le+1 <<"\n";
        } else {
            cout <<"0\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}