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

const int mxn=1e5;
int n;
ll u,d;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>u >>d;
    vector<ll> dif(n);
    rep(i,0,n) {
        cin >>a[i]; 
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    rep(i,0,n) {
        dif[i] = b[i] - a[i];
    }
    // debug() <<imie(dif);
    ll sm = 0;
    rep(i,0,n) {
        sm += dif[i];
    }
    if(sm%3) {
        cout <<"-1\n";
        return;
    }
    vector<ll> cs(n,0);
    ll smc = sm/3;
    if(n%3) {
        cs[0] = 0;
        rep(i,1,n) {
            int prv = ((i-1)*3)%n;
            // if(prv<0) {
            //     prv += n;
            // }
            int i3 = (i*3)%n;
            cs[(i*3)%n] = cs[prv] + (dif[(i3-1+n)%n]-dif[(i3-2+n)%n]); 
        }
        ll sm0 = 0;
        rep(i,0,n) {
            sm0 += cs[i];
        }
        if(abs(smc-sm0)%n) {
            cout <<"-1\n";
            return;
        } else {
            ll difi = (smc-sm0)/n;
            rep(i,0,n) {
                cs[i] += difi;
            }
        }
    } else {
        cs[0] = 0, cs[1] = 0;
        rep(i,2,n) {
            cs[i] = dif[i-1] - cs[i-2] - cs[i-1]; 
        } 
    }
    rep(i,0,n) {
        int prv = (i-1+n)%n;
        int nxt = (i+1)%n;
        // assert(dif[i] == cs[i]+cs[prv]+cs[nxt]);
        if(dif[i] != cs[i]+cs[prv]+cs[nxt]) {
            cout <<"-1\n";
            return;
        }
    }
    // debug() <<imie(cs);
    vector<ll> c(n);
    rep(i,0,n) {
        ll temp = cs[i];
        if(cs[i]>0) {
            temp *= u;
        } else {
            temp *= -1*d;
        }
        c[i] = temp;
    }
    rep(i,0,n) {
        cout <<c[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}