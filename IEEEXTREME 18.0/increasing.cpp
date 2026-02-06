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
ll n,m;
// try faster hash map?

ll toId(vi& ve) {
    ll ret = 0;
    ll p11 = 1;
    for(auto vei: ve) {
        ret += p11*vei;
        p11 *= 11;
    }
    return ret;
}

void solve() {
    cin >>n >>m;
    vi p(n);
    iota(all(p),0);
    map<ll,int> mp;
    vector<vi> v;
    do {
        mp[toId(p)] = sz(v);
        v.push_back(p);
    } while(next_permutation(all(p)));
    vi dp(sz(v),1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    // int tes = 3;
    rep(bit,0,1<<n) {
        vi vl, vr;
        rep(j,0,n) {
            if(j==n-1) continue;
            if((bit>>j)&1) {
                vl.push_back(j);
            } else {
                vr.push_back(j);
            }
        }
        if(sz(vl)==(n/2)) {
            sort(all(vl));
            vl.push_back(n-1);
            sort(all(vr),greater<int>());
            for(auto vri: vr) {
                vl.push_back(vri);
            }
            // if(tes) {
            //     tes--;
            //     debug() <<imie(vl);
            // }
            int id = mp[toId(vl)];
            dp[id] = 0;
            pq.push({dp[id],id});
        }
    }
    while(sz(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if(dp[u]<d) continue;
        vi cur = v[u];
        rep(i,0,n-1) {
            swap(cur[i],cur[i+1]);
            int nxt = mp[toId(cur)];
            if(dp[nxt] > d+1) {
                dp[nxt] = d+1;
                pq.push({dp[nxt],nxt});
            }
            swap(cur[i],cur[i+1]);
        }
    }
    ll ans = 0;
    for(auto d: dp) {
        // ans = (ans + d%m)%m;
        ans += d;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}