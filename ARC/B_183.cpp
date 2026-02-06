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

const int mxn=25e4;
int n,k,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i]; 
    }
    rep(i,0,n) {
        cin >>b[i]; 
    }
    // vi ctb(n,0),cta(n,0);
    // vi vb,va;
    // set<int> sb;
    // rep(i,0,n) {
    //     // ctb[b[i]]++;
    //     if(!sb.count(b[i])) {
    //         vb.push_back(b[i]);
    //     }
    //     sb.insert(b[i]);
    // }
    // rep(i,0,n) {
    //     if(sb.count(a[i])) {
    //         va.push_back(a[i]);
    //     }
    // }
    // debug() <<imie(vb);
    // debug() <<imie(va);
    if(k==1) {
        int j=0;
        for(int i=0;i<n&&j<n;i++) {
            while(j<n && a[i]==b[j]) {
                j++;
            }
        }
        if(j==n) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    } else {
        vi vb;
        multiset<int> msb;
        rep(i,0,n) {
            if(!msb.count(b[i])) {
                vb.push_back(b[i]);
            }
            if(i-k>=0) {
                msb.erase(msb.find(b[i-k]));
            }
            msb.insert(b[i]);
        }
        set<int> sa;
        rep(i,0,n) {
            sa.insert(a[i]);
        }
        if(sz(vb)<n) {
            rep(i,0,sz(vb)) {
                if(!sa.count(vb[i])) {
                    cout <<"No\n";
                    return;
                }
            }
            cout <<"Yes\n";
            return;
        } else {
            // bool ok = 1;
            // multiset<int> msa;
            rep(i,0,n) {
                if(a[i]!=b[i]) {
                    cout <<"No\n";
                    return;
                }
            }
            cout <<"Yes\n";
            return;
        }
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