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

const int mxn=3e5;
int n,q,t;
int b[mxn];
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>b[i];
    }
    vi a(n+q,0);
    vector<ipii> upd(q);
    rep(i,0,q) {
        cin >>upd[i].se.fi >>upd[i].se.se >>upd[i].fi;
        upd[i].fi--;
        upd[i].se.fi--;
        upd[i].se.se--;
    }
    vi id(n);
    iota(all(id),0);
    vi bf;
    rep(i,0,q) {
        auto [z,xy] = upd[i];
        auto [x,y] = xy;
        bf.push_back(id[z]);
        id[z] = n+i;
    }
    rep(i,0,n) {
        a[id[i]] = b[i];
    }
    per(i,q-1,-1) {
        auto [z,xy] = upd[i];
        auto [x,y] = xy;
        int br = id[z];
        id[z] = bf[i];
        max_self(a[id[x]], a[br]);
        max_self(a[id[y]], a[br]);        
    }
    // debug() <<imie(a);
    vi tes(a.begin(),a.begin()+n);
    rep(i,0,q) {
        auto [z,xy] = upd[i];
        auto [x,y] = xy;
        tes[z] = min(tes[x],tes[y]);        
    }
    // debug() <<imie(tes);
    rep(i,0,n) {
        if(tes[i]!= b[i]) {
            cout <<"-1\n";
            return;
        }
    }
    rep(i,0,n) {
        cout <<a[i] <<" \n"[i==n-1];
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