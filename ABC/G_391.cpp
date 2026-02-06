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

const int mxn=10;
const ll mod = 998244353;
int n,m;
string s;

void solve() {
    cin >>n >>m;
    cin >>s;
    vector<vi> v;
    map<vi,int> mp;
    function<void(int,int,vi&)> rec;
    rec = [&](int pos, int val, vi& ve) -> void {
        ve.push_back(val);
        if(pos==n-1) {
            mp[ve] = sz(v);
            v.push_back(ve);
        } else {
            int posn = pos+1;
            rep(i,val,posn+2) {
                rec(posn, i, ve);
            }
        }
        ve.pop_back();
    };
    vi temp;
    rec(0,0, temp);
    temp.clear();
    rec(0,1, temp);
    vector<ll> dp(sz(v),0);
    dp[0] = 1;
    // debug() <<imie(sz(v));
    // debug() <<imie(1000*26*sz(v));
    vector nx(26, vi(sz(v)));
    rep(j,0,26) {
        rep(k,0,sz(v)) {
            vi& v0 = v[k];
            vi vn(n,0);
            rep(l,0,n) {
                if(s[l]-'a' == j) {
                    vn[l] = 1;
                    if(l>0) {
                        vn[l] += v0[l-1];
                    }
                } else {
                    vn[l] = v0[l];
                    if(l>0) {
                        max_self(vn[l],vn[l-1]);
                    }
                }
            }
            int idn = mp[vn];
            nx[j][k] = idn;
        }
    }
    rep(i,0,m) {
        vector<ll> dp_new(sz(v),0);
        rep(j,0,26) {
            rep(k,0,sz(v)) {
                int idn = nx[j][k];
                dp_new[idn] = (dp_new[idn] + dp[k])%mod;
            }
        }
        dp.swap(dp_new);
    }
    vector<ll> ans(n+1, 0);
    rep(i,0,sz(v)) {
        ans[v[i][n-1]] = (ans[v[i][n-1]] + dp[i])%mod;
    }
    rep(i,0,n+1) {
        cout <<ans[i] <<" \n"[i==sz(v)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}