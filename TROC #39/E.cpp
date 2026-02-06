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

const int mxn=1e5,mxa=1e6;
int n,k;
ll a[mxn];

using ppll = pair<pll,pll>;

ll f(ll st, ll ct) {
    return ct*(st*2+ct-1)/2;
}

void solve() {
    cin >>n >>k;
    ll ans = 0;
    rep(i,0,n) {
        cin >>a[i];
        if(i) {
            ans += a[i-1]*a[i];
        }
    }
    vector<ll> b(n,0);
    rep(i,0,n) {
        if(i) {
            b[i-1] += a[i];
        }
        if(i+1<n) {
            b[i+1] += a[i];
        }
    }
    set<ppll> s;
    rep(i,0,n) {
        ll l = 0, r= 0;
        if(i) {
            l = b[i-1];
        }
        if(i+1<n) {
            r = b[i+1];
        }
        s.insert({{b[i],max(l,r)},{min(l,r),i}});
    }
    auto geti = [&](int i) -> ppll {
        ll l = 0, r= 0;
        if(i) {
            l = b[i-1];
        }
        if(i+1<n) {
            r = b[i+1];
        }
        return {{b[i],max(l,r)},{min(l,r),i}};        
    };
    auto er = [&](int id) -> void {
        s.erase(geti(id));
    };
    auto add = [&](int id) -> void {
        er(id);
        if(id) {
            er(id-1);
        }
        if(id+1<n) {
            er(id+1);
        }
        b[id]++;
        s.insert(geti(id));
        if(id) {
            s.insert(geti(id-1));
        }
        if(id+1<n) {
            s.insert(geti(id+1));
        }
    };
    auto upd = [&](int id) -> void {
        er(id);
        if(id) {
            add(id-1);
        }
        if(id+1<n) {
            add(id+1);
        }
        s.insert(geti(id));
    };
    debug() <<imie(b);
    vi v(5);
    rep(i,0,k) {
        auto [valmx,mnid] = *(--s.end());
        auto [val, mx] = valmx;
        auto [mn,id] = mnid;
        ans += val;
        upd(id);
        v[i%5] = id;
        if(i<=50) {
            debug() <<imie(i) imie(id);
        }
        if(i>=mxa) {
            set<int> sid;
            for(auto idp : v) {
                sid.insert(idp);
            }
            if(sz(sid)==2) {
                debug() <<imie(ans) imie(id);
                auto x = *sid.begin();
                auto y = *(++sid.begin());
                int sb = x+y-id;
                ll sisa = k-(i+1);
                debug() <<imie(b);
                debug() <<imie(sid) imie(sb);
                debug() <<imie(i) imie(sisa);
                ans += f(b[sb],(sisa+1)/2);
                ans += f(b[id],sisa/2);
                break;
            }
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