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

const ll mxn=1e11;
const int bts = 1e7;
ll n,l,r,k;

void solve() {
    cin >>n >>l >>r >>k;
    ll ans = -1;
    ll len = 0;
    if(l<=r) {
        len = r-l+1;
    } else {
        len = n+1-l + r;
    }
    if(k-len<0) {
        cout <<"-1\n";
        return;
    }
    if(n<=bts) {
        rep(swo,0,n+1) {
            ll re = (k-len)%(n+swo);
            if(re<=swo && re<=len && re>=swo-(n-len)-1) {
                ans = swo;
            }
        }
    } else {
        rep(x,0,((k-len)/n)+1) {
            if(x==0) {
                ll swi = k-len-n*x;
                // debug() <<imie(x) imie(swi);
                if(swi<=len) {
                    swi++;
                    min_self(swi,len);
                    ll swo = swi + (n-len);
                    // debug() <<imie(swi) imie(swo);
                    max_self(ans, swo);
                }
            } else {
                ll rhs = k-len-n*x;
                ll swo = (rhs+1+(n-len))/(x+1);
                // debug() <<imie(x) imie(rhs) imie(swo);
                min_self(swo,n);
                ll lhs = rhs- swo*x;
                // debug() <<imie(lhs);
                if(lhs<=len && lhs<=swo) {
                    // assert((n+swo)*x+lhs+len==k);
                    max_self(ans, swo);
                }
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