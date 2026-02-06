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
string a,b;

typedef uint64_t ull;
struct H {
    ull x; H(ull x=0) : x(x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator-(H o) { return *this + ~o.x; }
    H operator*(H o) { auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64); }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

void solve() {
    cin >>n >>m;
    cin >>a;
    cin >>b;
    HashInterval hia(a), hib(b);
    int ans = 0;
    bool dbl = 0;
    set<char> s;
    rep(i,0,m) {
        if(s.count(b[i])) {
            dbl = 1;
            break;
        }
        s.insert(b[i]);
    }
    rep(i,0,n-m+1) {
        int posl = m;
        int l =0, r = m-1;
        while(l<=r) {
            int mid = (l+r)/2;
            bool dif = hia.hashInterval(i,i+mid+1).get() != hib.hashInterval(0,mid+1).get();
            if(dif) {
                posl = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(posl==m) {
            ans += dbl;
            continue;
        }
        int posr = -1;
        l = 0, r = m-1;
        while(l<=r) {
            int mid = (l+r)/2;
            bool dif = hia.hashInterval(i+mid,i+m).get() != hib.hashInterval(mid,m).get();
            if(dif) {
                posr = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        bool ok = a[i+posl]==b[posr] && a[i+posr]==b[posl];
        if(i+posl+1 < i+posr) {
            ok = ok && hia.hashInterval(i+posl+1,i+posr).get() == hib.hashInterval(posl+1,posr).get(); 
        }
        ans += ok;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}