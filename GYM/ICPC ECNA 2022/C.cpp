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
using pil = pair<int,ll>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=100;
int n;
int a[14];

void solve() {
    cin >>n;
    map<char,int> mp;
    mp['A'] = 1;
    mp['T'] = 10;
    mp['J'] = 11;
    mp['Q'] = 12;
    mp['K'] = 13;
    rep(i,1,10) {
        mp[(char)('0'+i)] = i;
    }
    rep(i,0,n) {
        char c; cin >>c;
        a[mp[c]]++;
    }
    ll ans = 0;
    map<int,ll> ct;
    rep(i,1,14) {
        int cur = min(i,10);
        rep(j,0,a[i]) {
            vector<pil> v;
            for(auto [k,val]: ct) {
                if(k+cur>15) continue;
                v.push_back({k+cur,val});
            }
            ct[cur]++;
            for(auto vei : v) {
                ct[vei.fi] += vei.se;
            }
            // debug() <<imie(ct);
        }
    }
    ans += ct[15]*2;
    // cout <<ans <<endl;
    rep(i,1,14) {
        ans += 1ll*a[i]*(a[i]-1);
    }
    // cout <<ans <<endl;
    for(int i=1;i<14;) {
        if(a[i]==0) {
            i++;
            continue;
        }
        ll tmp = 1;
        int j = i;
        while(j<14 && a[j]>0) {
            tmp *= a[j];
            j++;
        }
        if(j-i>=3) {
            ans += tmp*(j-i);
        }
        i = j;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}