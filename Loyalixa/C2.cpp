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

const int mxn=1e6;
int n, a[mxn],q;

using piii = tuple<int,int,int,int,int,int,int>;

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

void solve() {
    cin >>n;
    int mx = 0;
    rep(i,0,n) {
        cin >>a[i];
        max_self(mx, a[i]);
    }
    vector id(mx+1, vi());
    rep(i,0,n) {
        id[a[i]].push_back(i);
    }
    cin >>q;
    vector<piii> qry;
    int fmx = mx;
    rep(i,0,q) {
        int x,k,l,r,s,e; cin >>x >>k >>l >>r >>s >>e; s--,e--;
        qry.push_back({x,k,l,r,s,e,i});
        max_self(fmx, r);
    }
    sort(all(qry));
    FT2 ft2(fmx+1);
    rep(i,0,n) {
        ft2.fakeUpdate(a[i],i);
    }
    ft2.init();
    vi ansq(q,-2);
    for(int i=0;i<q;) {
        int j = i;
        while(j<q && get<0>(qry[i])==get<0>(qry[j])) {
            j++;
        }
        int x = get<0>(qry[i]);
        vector<pii> v;
        for(int l = x;l<=mx;l+=x) {
            for(auto idi: id[l]) {
                v.push_back({l,idi});
            }
        }
        for(auto [val,idi]: v) {
            ft2.update(val,idi, 1);
        }
        rep(m,i,j) {
            auto [xi, k, l,r,s,e, iq] = qry[m]; 
            int st = ft2.query(r+1,s) - ft2.query(l,s);
            int li = s, ri = e;
            int cur = -1;
            while(li<=ri) {
                int mid = (li+ri)/2;
                int stq = ft2.query(r+1,mid+1) - ft2.query(l,mid+1);
                if(stq>=st+k) {
                    cur = mid;
                    ri = mid-1;
                } else {
                    li = mid+1;
                }
            }
            if(cur>=0) {
                ansq[iq] = cur;
            }
        }
        for(auto [val,idi]: v) {
            ft2.update(val,idi, -1);
        }        
        i = j;
    }
    rep(i,0,q) {
        cout <<ansq[i]+1 <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}