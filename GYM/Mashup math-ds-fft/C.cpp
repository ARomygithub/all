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

const int mxn=1e9;
int n;

void solve() {
    cin >>n;
    vi bts(9,48);
    set<ll> s;
    vector<set<pll>> lr(49);
    lr[0].insert({0,n});
    rep(i,0,9) {
        if(i>0) {
            min_self(bts[i], bts[i-1]);
        }
        int btsi = bts[i];
        rep(j,0,btsi+1) {
            ll cur = 1ll*i*4 + 1ll*j*9;
            if(cur>0 && (cur%49)==0) {
                bts[i] = j-1;
                break;
            } else {
                if(i+j<=n) {
                    ll l = (cur/49);
                    ll r = l+(n-i-j);
                    lr[cur%49].insert({l,r});
                }
                s.insert(cur);
            }
        }
    }
    // debug() <<imie(bts);
    // debug() <<imie(s);
    ll ans = 0;
    rep(i,0,49) {
        ll ri = -1;
        for(auto [l,r]: lr[i]) {
            ans += max(0ll, r-max(l-1,ri));
            max_self(ri, r);
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