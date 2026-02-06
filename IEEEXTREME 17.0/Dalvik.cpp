#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod=1e9+7;
int t;
ll a,b,c;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>a >>b >>c;
    a %=b;
    ll dd = __gcd(a,b);
    ll aa = a/dd;
    ll bb = b/dd;
    ll phic = 1;
    ll u = bb;
    for(int i=2;i*i<=u;i++) {
        if((u%i)==0) {
            ll temp=1;
            while((u%i)==0) {
                temp *=i;
                u /=i;
            }
            temp /=i;
            temp *=i-1;
            phic *=temp;
        }
    }
    if(u>1) {
        phic *=u-1;
    }
    ll ainv = fastexpo(aa,phic-1,bb);
    ll j0 = -1;
    if(bb<=c) {
        j0 = bb;
    }
    // debug() <<imie(ainv);
    // debug() <<imie(j0);
    // debug() <<imie(phic);
    // debug() <<imie(aa);
    // debug() <<imie(bb);
    if(j0!=-1 && j0<=c) {
        cout <<j0 <<"\n";
        return;
    }
    ll ians = 1,jans=-1;
    for(int i=1;;i++) {
        ll ji = -1;
        if(i<=(b/2)) {
            if(((i)%dd)==0) {
                ll rhs = (i)/dd;
                ll j1 = rhs*ainv%bb;
                if(j1<=c) {
                    ll ct = (c-j1)/bb;
                    j1 = j1+ct*bb;
                    max_self(ji,j1);
                }
            }
        }
        if(i<((b-1)/2)) {
            if(((b-i)%dd)==0) {
                ll rhs = (b-i)/dd;
                ll j2 = rhs*ainv%bb;
                if(j2<=c) {
                    ll ct = (c-j2)/bb;
                    j2 = j2+ct*bb;
                    max_self(ji,j2);
                }
            }
        }
        if(ji!=-1 && ji*ians>jans*i) {
            ians = i;
            jans = ji;
            // debug() <<imie(jans) <<imie(ians);
        }
        if(jans>0) {
            ll temp = (jans*(i+1)+ians-1)/ians;
            if(temp>c) break;
        }
    }
    cout <<jans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}