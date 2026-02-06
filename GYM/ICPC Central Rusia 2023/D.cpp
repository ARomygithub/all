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

const int mxn=1e5;
string s;

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
    int n = s.length();
    string sr = "";
    map<char,char> mp;
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['G'] = 'C';
    mp['C'] = 'G';
    per(i,n-1,-1) {
        sr += mp[s[i]];
    }
    string concat = s + "$" + sr;
    SuffixArray sa(concat);
    int mn = 1e9;
    int mx = 0;
    int idxC = -1;
    int lastN = -1;
    rep(i,0,sz(concat)+1) {
        int st = sa.sa[i];
        if(st>=0 && st<n) {
            if(lastN == 0) {
                min_self(mn, sa.lcp[i]);
                if(mn > mx) {
                    mx = mn;
                    idxC = st;
                }
            }
            mn = n - st;
            lastN = 1;
        } else if(st>=n+1) {
            if(lastN == 1) {
                min_self(mn, sa.lcp[i]);
                if(mn > mx) {
                    mx = mn;
                    idxC = st;
                }
            }
            mn = n - (st-n-1);
            lastN = 0;
        }
    }
    cout <<mx <<"\n";
    if(mx>0) {
        cout <<concat.substr(idxC, mx) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}