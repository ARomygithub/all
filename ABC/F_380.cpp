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

const int mxn=12;
int n,m,l;
vi aw;

string biner(int x) {
    string ret = "";
    while(x) {
        ret += (char)('0'+(x%2));
        x /= 2;
    }
    reverse(all(ret));
    return ret;
}
using piii = pair<pii,int>;

void solve() {
    cin >>n >>m >>l;
    aw.resize(n+m+l);
    rep(i,0,n+m+l) {
        cin >>aw[i];
    }
    map<piii,bool> dp;
    function<bool(int,int,int)> getdp;
    getdp = [&](int sn, int sm, int p) -> bool {
        // cout <<biner(sn) <<" " <<biner(sm) <<endl;
        // int al = 1<<(n+m+l);
        // assert(sn <= al && sm<=al);
        if(dp.count({{sn,sm},p})) {
            return dp[{{sn,sm},p}];
        }
        dp[{{sn,sm},p}] = 0;
        vi cur(2);
        cur[0] = sn;
        cur[1] = sm;
        vi ip, il;
        rep(i,0,n+m+l) {
            if((cur[p]>>i)&1) {
                ip.push_back(i);
            } else if((cur[1-p]>>i)&1) {
                ;
            } else {
                il.push_back(i);
            }
        }
        // if(p==0) {
        //     assert(sz(ip)==n);
        // } else {
        //     assert(sz(ip)==m);
        // }
        // assert(sz(il)==l);
        // debug() <<imie(ip);
        // debug() <<imie(il);
        for(auto ipi : ip) {
            for(auto ili : il) {
                if(aw[ipi]> aw[ili]) {
                    int dif = (1<<ili)-(1<<ipi);
                    cur[p] += dif;
                    bool lw = getdp(cur[0], cur[1], 1-p);
                    cur[p] -= dif;
                    if(!lw) {
                        dp[{{sn,sm},p}] = 1;
                        return 1;
                    }
                }
            }
            int dif = -(1<<ipi);
            cur[p] += dif;
            bool lw = getdp(cur[0], cur[1], 1-p);
            if(!lw) {
                dp[{{sn,sm},p}] = 1;
                return 1;
            }                        
            cur[p] -= dif;
        }
        return dp[{{sn,sm},p}];
    };
    if(getdp((1<<n)-1,((1<<m)-1)<<n , 0)) {
        cout <<"Takahashi\n";
    } else {
        cout <<"Aoki\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}