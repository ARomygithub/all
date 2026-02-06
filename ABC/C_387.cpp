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
ll l,r;

void solve() {
    cin >>l >>r;
    vector pw(10, vector<ll>(18,1));
    rep(i,1,10) {
        rep(j,1,18) {
            pw[i][j] = pw[i][j-1]*i;
        }
    } 
    // debug() <<imie(pw);
    auto f = [&](ll x) -> ll {
        string s = to_string(x);
        ll ret = 0;
        rep(d,2,sz(s)) {
            rep(i,1,10) {
                ret += pw[i][d-1];
            }
        }
        int d = 1;
        int a0 = s[0]-'0';
        int bts = sz(s);
        if(sz(s)<=1) return ret;
        while(bts>0 && (bts==sz(s) || s[sz(s)-bts]<s[0])) {
            bts--;
        }
        ret += (bts==0);
        // debug() <<imie(bts) imie(s);
        while(x) {
            int cur = x%10;
            if(d>=bts) {
                if(cur>0 && a0>0) {
                    if(d==sz(s)) {
                        rep(i,1,cur) {
                            ret += pw[i][d-1];
                        }
                        // ret += 1ll*min(cur-1,a0-1)*pw[a0][d-1];
                    } else {
                        ret += 1ll*min(cur,a0)*pw[a0][d-1];
                    }
                    // debug() <<imie(cur) imie(a0) imie(d);
                }
            }
            x /= 10;
            d++;
        }
        // debug() <<imie(ret);
        return ret;
    };
    cout <<f(r)- f(l-1) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}