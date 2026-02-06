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

const int mxn=5e5,mxa=5e5;
const ll mod = 998244353;
int n,c,t;
int l[mxn],r[mxn],val[mxn];
ll iv[mxa+1];

void init() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }    
}

void solve() {
    cin >>n >>c;
    vector<int> v;
    rep(i,0,n) {
        cin >>l[i] >>r[i] >>val[i]; 
        if(l[i]!=-1) l[i]--;
        if(r[i]!=-1) r[i]--;
    }
    function<void(int)> inorder;
    inorder = [&](int u) -> void {
        if(l[u]!=-1) inorder(l[u]);
        v.push_back(val[u]);
        if(r[u]!=-1) inorder(r[u]);
    };
    inorder(0);
    int idx=0;
    ll ans = 1;
    // debug() <<imie(v);
    while(idx<n) {
        int valL=1,valR=c;
        while(idx<n && v[idx]!=-1) {
            idx++;
        }
        if(idx<n) {
            if(idx>0) {
                max_self(valL, v[idx-1]);
            }
            // debug() <<imie(valL);
            int ct=1;
            while(idx+1<n && v[idx+1]==-1) {
                idx++;
                ct++;
            }
            if(idx+1<n) {
                min_self(valR, v[idx+1]);
            }
            // debug() <<imie(valR);
            ll len = valR-valL+1;
            ll pi = 1;
            // debug() <<imie(len);
            rep(i,1,ct+1) {
                ll temp = 1ll*(len-1+i)*iv[i]%mod;
                pi = pi*temp%mod;
            }
            ans = (ans*pi)%mod;
            idx++;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}