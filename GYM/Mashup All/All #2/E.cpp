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
int n,d,b;
int a[mxn];

void solve() {
    cin >>n >>d >>b;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = -1;
    int l = 0, r = n/2;
    while(l<=r) {
        int mid = (l+r)/2;
        vi c(n);
        rep(i,0,n) {
            c[i] = a[i];
        }
        int idl = 0,idr=n-1;
        int sisa = b*n;
        bool ok = 1;
        rep(i,0,(n+1)/2) {
            int j = n-i-1;
            int ri = min(1ll*i+1ll*d*(i+1),1ll*n-1), le =max(0ll,1ll*j-1ll*d*(i+1));
            if(i>=mid) {
                int sl = 0;
                while(idl<=ri && sl<b) {
                    int temp = min(b-sl,c[idl]);
                    sl += temp;
                    c[idl] -= temp;
                    if(c[idl]==0) idl++;
                }
                if(sl<b) {
                    ok = 0;
                    break;
                }
                sl -= b;
                sisa -= b;
                // cout <<"i: " <<i <<endl;
                // assert(c[i]==0 || idl<=i);
                if(j<=i) continue;
                int sr = 0;
                while(idr>=le && sr<b) {
                    int temp = min(b-sr,c[idr]);
                    sr += temp;
                    c[idr] -= temp;
                    if(c[idr]==0) idr--;
                }
                if(sr<b) {
                    ok = 0;
                    break;
                }
                sr -= b;
                sisa -= b;
                // cout <<i <<" " <<j <<endl;
                // assert(c[j]==0 || idr>=j);
            }
            // debug() <<imie(c);
        }
        if(ok) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
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