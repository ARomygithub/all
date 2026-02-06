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
int n;

void solve() {
    cin >>n;
    vector v(n+1, vi());
    rep(i,0,n) {
        int ai; cin >>ai;
        v[ai].push_back(i);
    }
    ll ans = 0;
    rep(i,1,n+1) {
        int le = -1;
        int j2 = 0;
        rep(j,0,sz(v[i])) {
            int pos = v[i][j];
            // debug() <<imie(i) imie(pos);
            while(j2<sz(v[i-1]) && v[i-1][j2]<pos) {
                max_self(le, v[i-1][j2]);
                j2++;
            }
            int ri = n-1;
            if(j2<sz(v[i-1])) {
                min_self(ri, v[i-1][j2]-1);
            }
            // debug() <<imie(le) <<imie(ri);
            ll ad = 1ll*(ri-pos+1)*(pos-le);
            // debug() <<imie(ad);
            ans += ad;
            max_self(le, v[i][j]);
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