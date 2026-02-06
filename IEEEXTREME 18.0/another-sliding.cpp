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
int n,q;
ll a[mxn];

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pr(n+1,0);
    rep(i,0,n) {
        pr[i+1] = pr[i] + a[i];
    }
    while(q--) { //O(q.n.lg n)
        ll x; cin >>x;
        vi r(n);
        iota(all(r),0);
        {
            int ri = 0;
            rep(i,0,n) {
                while(ri<n && a[i]+a[ri]<=x) {
                    ri++;
                }
                r[i] = ri;
                if(ri==i && a[i]<=x) {
                    r[i] = i+1;
                }
                if(i==ri) {
                    ri++;
                }
            }
            // per(i,n-2,-1) {
            //     min_self(r[i], r[i+1]);
            // }
            
        }
        debug() <<imie(r);
        ll ans = 0;
        for(int i=1;i<n*2-1;i+=2) {
            int pos = i/2;
            int li = 0, ri = pos;
            int le = -1;
            while(li<=ri) {
                int mid = (li+ri)/2;
                int knn = pos*2-mid;
                if(i%2) {
                    knn++;
                }
                if(r[mid]>knn) {
                    le = mid;
                    ri = mid-1;
                } else {
                    li = mid+1;
                }
            }
            debug() <<imie(i) imie(pos) imie(le);
            if(le!=-1) {
                int knn = pos*2-le;
                if(i%2) {
                    knn++;
                }
                debug() <<imie(knn);                
                if(i%2) {
                    ans += (pr[knn+1]-pr[pos+1]) - (pr[pos+1]-pr[le]);
                    debug() <<imie((pr[knn+1]-pr[pos+1]) - (pr[pos+1]-pr[le]));
                } else {
                    // ans += (pr[knn+1] - pr[pos]) - (pr[pos+1] - pr[le]);
                    // debug() <<imie((pr[knn+1] - pr[pos]) - (pr[pos+1] - pr[le]));
                }
            }
        }
        // pos = p-1 given a[knn+1]<=x
        rep(i,0,n-2) {
            int le = -1;
            int li = 0, ri = i;
            while(li<=ri) {
                int mid = (li+ri)/2;
                int knn = i+1 + (i-mid);
                if(knn<=n-2 && r[mid]>knn)
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}