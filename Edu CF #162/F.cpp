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
#define all(x) x.begin(), x.end()
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e5;
const ll mod=1e9+7;
int n,k;
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

string calc0(string si) {
    int l=0,r=sz(si)-1;
    rep(i,0,k) {
        while(l<n && si[l]!='1') {
            l++;
        }
        while(r>=0 && si[r]!='0') {
            r--;
        }
        if(l>r) break;
        swap(si[l],si[r]);
        l++,r--;
    }
    return si.substr(si.find('1'));
}

string calc1(string si) {
    reverse(si.begin(),si.end());
    map<int,int> mp;
    SuffixArray sar(si);
    rep(i,1,n+1) {
        mp[sar.sa[i]] = i;
    }
    piii mn = {{n*2,1e9},-1};
    int u = 0, cur1=0;
    int ct1 = count(si.begin(),si.end(),'1');
    rep(i,0,n) {
        while(u<n && (u-i<ct1 || ct1-cur1>k-1)) {
            cur1 += si[u]=='1';
            // debug() <<imie(u) <<imie(cur1);
            u++;
        }
        if(u-i<ct1 || ct1-cur1>k-1) {
            break;
        }
        piii now = {{u-i,mp[i]},i};
        min_self(mn, now);
        // debug() <<imie(ct1) <<imie(cur1);
        // debug() <<imie(si.substr(mn.se,mn.fi.fi));
        cur1 -= si[i]=='1';
    }
    string res = si.substr(mn.se, mn.fi.fi);
    int toAdd = ct1 - count(res.begin(),res.end(),'1');
    per(i,sz(res)-1,-1) {
        if(toAdd==0) break;
        if(res[i]=='0') {
            res[i] = '1';
            toAdd--;
        }
    }
    return res.substr(res.find('1'));
}

void solve() {
    cin >>n >>k;
    cin >>s;
    string s1 = calc0(s);
    string s2 = calc1(s);
    // debug() <<imie(s1);
    // debug() <<imie(s2);
    if(sz(s1)>sz(s2) || (sz(s1)==sz(s2) && s1>s2)) {
        swap(s1,s2);
    }
    ll ans = 0;
    rep(i,0,sz(s1)) {
        ans = ans*2%mod + s1[i]-'0';
        ans %=mod;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}