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
int l,r,t;

void solve() {
    cin >>l >>r;
    vi ans(r-l+1);
    function<void(int,int,int)> slv;
    ll sm = 0;
    slv = [&](int bit, int li, int ri) -> void {
        if(li==ri) {
            ans[li-l] = li;
            return;
        }
        int a1 = (1<<bit)-1;
        int ir = (ri&a1);
        // debug() <<imie(bit) imie(li) imie(ri) imie(ir) imie(ri-ir-1);
        if(ri-ir-1>=li) {
            int le = (ri-ir-1) - ir;
            max_self(le,li);
            int re = (ri-ir) + (ri-ir-1-le);
            // debug() <<imie(le) imie(re);
            rep(i,0,(re-le+1)/2) {
                ans[le+i-l] = re-i;
                ans[re-i-l] = le+i;
            } 
            if(le>li) {
                slv(bit-1, li,le-1);
            }
            if(re<ri) {
                slv(bit-1, re+1,ri);
            }
            return;
        }
        // int il = (li&a1);
        // if(li+a1-il+1 <= ri) {
            
        //     return;
        // }
        slv(bit-1,li,ri);
    };
    slv(30,l,r);
    rep(i,0,r-l+1) {
        sm += ((i+l)|ans[i]);
    }
    cout <<sm <<"\n";
    rep(i,0,r-l+1) {
        cout <<ans[i] <<" \n"[i==r-l];
    }
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