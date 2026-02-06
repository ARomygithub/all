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

const int mxn=2e5;
int n,m;
int a[mxn];

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
        a[i] %= m;
    }
    rep(i,1,n) {
        a[i] = (a[i] + a[i-1])%m;
    }
    FT ftv(m), ftc(m);
    ll ans = 0;
    ftc.update(0,1);
    rep(i,0,n) {
        ll qv = ftv.query(a[i]+1);
        ll qv2 = ftv.query(m);
        ll qc = ftc.query(a[i]+1);
        ll qc2 = ftc.query(m);
        ans += 1ll*a[i]*qc - qv;
        ans += 1ll*(m+a[i])*(qc2-qc) - (qv2-qv);
        ftv.update(a[i], a[i]);
        ftc.update(a[i], 1);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}