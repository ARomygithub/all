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
const ll mxl = 1e18;
ll n,p[mxn];
ll m;

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>p[i];
    }
    ll ans = 0, cpi=0;
    ll l=0,r=1e15;
    vector<ll> vct;
    rep(i,0,n) {
        vct.push_back(0);
    }
    while(l<=r) {
        ll mid = (l+r)/2;
        ll ct = 0;
        ll cp = 0;
        vector<ll> vcti;
        rep(i,0,n) {
            ll cur = (mid/p[i]);
            if(cur>=1 && cp<=m) {
                ct += (cur+1)/2;
                ll cti = (cur+1)/2;
                vcti.push_back(cti);
                if(mxl/cti<cti || (m-cp)/(cti*cti) < p[i]) {
                    cp = m+1;
                } else {
                    cp += cti*cti*p[i];
                }
            } else {
                vcti.push_back(0);
            }
        }
        if(cp<=m) {
            ans = ct;
            cpi = cp;
            vct.swap(vcti);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    // rep(i,0,10) {
    //     debug() <<imie(vct[i]);
    // }
    // rep(i,0,10) {
    //     debug() <<imie(vct[n-i-1]);
    // }
    // debug() <<imie(cpi) imie(ans);
    multiset<ll> ms;
    rep(i,0,n) {
        if((m-cpi)/p[i] >= (vct[i]*2+1)) {
            ms.insert((vct[i]*2+1)*p[i]);
        }
    }
    while(sz(ms)) {
        auto it = ms.begin();
        assert((*it)>0);
        if(cpi + (*it)<=m) {
            ans++;
            cpi += (*it);
            ms.erase(it);
        } else {
            break;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}