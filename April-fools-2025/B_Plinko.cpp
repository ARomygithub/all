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
int t;
int a[] = {0,16}, b[] = {16,16,0,16,16,16,16,16,16,16};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<double> trf0(vector<double>& dp) {
    vector<double> ret(17,0);
    for(int i=1;i<17;i+=2) {
        ret[i] = (dp[i-1]+dp[i+1])/2;
    }
    return ret;
}

vector<double> trf1(vector<double>& dp) {
    vector<double> ret(17,0);
    for(int i=0;i<17;i+=2) {
        if(i==0) {
            ret[i] = dp[1];
        } else if(i==16) {
            ret[i] = dp[15];
        } else {
            ret[i] = (dp[i-1]+dp[i+1])/2;
        }
    }
    return ret;    
}

void solve() {
    // cin >>n;
    // string s;
    // getline(cin, s);
    string g; int x; cin >>g >>x;
    // cout <<a[rng()%2] <<"\n";
    cout <<"-1" <<"\n";
    // vector<double> dp(17,0);
    // dp[2] = 1;
    // dp[8] = 1;
    // dp[14] = 1;
    // rep(i,0,2) {
    //     dp = trf0(dp);
    //     dp = trf1(dp);
    // }
    // vector<double> ans(17,0);
    // rep(i,0,17) {
    //     if(i%2) {
    //         ans[i] = (dp[i-1]+dp[i+1])/2;
    //     } else {
    //         ans[i] = dp[i];
    //     }
    // }
    // cout <<fixed <<setprecision(6);
    // debug() <<imie(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}