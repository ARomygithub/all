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

struct FT2 {
    vector<vi> ys; vector<FT> ft;
    FT2(int limx) : ys(limx) {}
    void fakeUpdate(int x, int y) {
        for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
    }
    void init() {
        for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
    }
    int ind(int x, int y) {
        return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
    void update(int x, int y, ll dif) {
        for (; x < sz(ys); x |= x + 1)
            ft[x].update(ind(x, y), dif);
    }
    ll query(int x, int y) {
        ll sum = 0;
        for (; x; x &= x - 1)
            sum += ft[x-1].query(ind(x-1, y));
        return sum;
    }
};

const int mxn=2e5;
int n,q;
int a[mxn];
typedef pair<pii,pii> pipi;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    FT2 ft2(n);
    rep(i,0,n) {
        ft2.fakeUpdate(i, a[i]);
    } 
    ft2.init();
    rep(i,0,n) {
        ft2.update(i, a[i], 1ll);
    }
    vector<pipi> sq;
    sq.push_back({{0,1},{n-1,n}});
    cin >>q;
    auto get_xy = [&](int x1, int y1, int x2, int y2) -> int {
        ll ret = ft2.query(x2+1,y2+1);
        ret -= ft2.query(x2+1, y1);
        ret -= ft2.query(x1, y2+1);
        ret += ft2.query(x1, y1);
        return ret;
    };
    rep(i,0,q) {
        int t,s,x; cin >>t >>s >>x;
        auto [xyi1, xyi2] = sq[s];
        auto [xi1, yi1] = xyi1;
        auto [xi2, yi2] = xyi2;
        if(t==1) {
            int ct = xi2==-1?0:get_xy(xi1, yi1, xi2, yi2);
            int ansi = 0;
            if(x==0) {
                sq.push_back({{xi1,yi1},{xi2,yi2}});
                sq[s] = {{-1,-1},{-1,-1}};
                ansi = ct;
            } else if(x>=ct) {
                sq.push_back({{-1,-1},{-1,-1}});
            } else {
                ansi = ct-x;
                int l = xi1, r = xi2;
                int p1 = -1;
                while(l<=r) {
                    int mid = (l+r)/2;
                    int cti = get_xy(xi1,yi1,mid,yi2);
                    if(cti>=x) {
                        p1 = mid;
                        r = mid-1;
                        if(cti==x) {
                            break;
                        }
                    } else {
                        l = mid+1;
                    }
                }
                sq.push_back({{p1+1,yi1},{xi2,yi2}});
                sq[s] = {{xi1,yi1},{p1,yi2}};
            }
            cout <<ansi <<"\n";
        } else {
            int ansi = 0;
            if(x>=yi2) {
                sq.push_back({{-1,-1},{-1,-1}});
            } else if(x<yi1) {
                sq.push_back({{xi1,yi1},{xi2,yi2}});
                sq[s] = {{-1,-1},{-1,-1}};
                ansi = xi1==-1?0:get_xy(xi1,yi1,xi2,yi2);
            } else {
                sq.push_back({{xi1,x+1},{xi2,yi2}});
                sq[s] = {{xi1,yi1},{xi2,x}};
                ansi = xi1==-1?0:get_xy(xi1,x+1,xi2,yi2);
            }
            cout <<ansi <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}