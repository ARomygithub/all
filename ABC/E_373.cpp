#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
ll n,m,k;
ll a[mxn];

void solve() {
    cin >>n >>m >>k;
    ll sa = 0;
    rep(i,0,n) {
        cin >>a[i];
        sa += a[i];
    }
    if(m==n) {
        rep(i,0,n) {
            cout <<0 <<" \n"[i==n-1];
        }
        return;
    }
    vector<pll> vb(n);
    rep(i,0,n) {
        vb[i] = {-a[i],i};
    }
    sort(all(vb));
    vector<ll> ansy(n,1e18);
    vector<ll> pr(n+1,0);
    rep(i,1,n+1) {
        pr[i] = pr[i-1]+vb[i-1].fi*-1;
    }
    // debug() <<imie(pr);
    // debug() <<imie(sa);
    ll inf = 1e18;
    rep(i,0,n) {
        auto [val, id] = vb[i];
        val *= -1;
        ll l = val, r = 1e12;
        // debug() <<imie(i);
        while(l<=r) {
            ll mid = (l+r)/2;
            auto it = lower_bound(all(vb),pll{-mid-1,inf}) - vb.begin();
            ll sm = 0;
            if(it<m) {
                sm += (mid+1)*(m-it) - (pr[m]-pr[it]);
            }
            ll bj = sm+1+mid - (k+1-sa);
            // debug() <<imie(mid) imie(sm) imie(bj); 
            if(i<m) {
                if(vb[m].fi*-1 < bj) {
                    ansy[id] = mid;
                    r = mid -1;
                } else {
                    l = mid+1;
                }
            } else {
                if(vb[i].fi*-1 < bj) {
                    ansy[id] = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
        // debug() <<imie(ansy[id]);
    }
    rep(i,0,n) {
        ll cur = ansy[i] - a[i];
        max_self(cur, 0ll);
        if(cur>k-sa) {
            cur = -1;
        }
        cout <<cur <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}