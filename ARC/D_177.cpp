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
typedef vector<int> vi;
typedef pair<pii,ll> piil;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
const ll mod = 998244353;
int n,h;
int x[mxn];

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

ll inv(ll a) {
    return fastexpo(a, mod-2);
}

void solve() {
    cin >>n >>h;
    rep(i,0,n) {
        cin >>x[i];
    }
    int ct = 0;
    vector<pii> v;
    vector<piil> val;
    rep(i,0,n) {
        v.push_back({x[i],i});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;) {
        int j = i+1;
        while(j<n && v[j].fi-v[j-1].fi<=h) {
            j++;
        }
        set<pii> s;
        rep(k,i,j) {
            s.insert({v[k].se,k});
        }
        map<int,int> mpl,mpr;
        stack<int> stl;
        rep(k,i,j) {
            while(sz(stl) && stl.top()>v[k].se) {
                stl.pop();
            }
            stl.push(v[k].se);
            mpl[k] = sz(stl);
        }
        stack<int> str;
        per(k,j-1,i-1) {
            while(sz(str) && str.top()>v[k].se) {
                str.pop();
            }
            str.push(v[k].se);
            mpr[k] = sz(str);
        }
        ll pref = 0;
        // debug() <<imie(i);
        // vector<int> vtemp(j-i,-1);
        for(auto [idx, ordx]: s) {
            ll temp = 0;
            bool add = 0;
            if(ordx==i) {
                add = 1;
                int len = j-i-mpr[ordx];
                temp = (temp + fastexpo(2ll,len))%mod;
            }
            if(ordx==j-1) {
                add = 1;
                int len = j-i - mpl[ordx];
                temp = (temp + fastexpo(2ll,len))%mod;
            }
            if(ordx>i && v[ordx-1].se<idx) {
                // R, L
                add = 1;
                int len = j-i;
                len -= mpr[ordx];
                len -= mpl[ordx-1];
                temp = (temp + fastexpo(2ll,len))%mod;
            }
            if(ordx<j-1 && v[ordx+1].se<idx) {
                add = 1;
                int len = j-i;
                len -= mpr[ordx+1];
                len -= mpl[ordx];
                temp = (temp + fastexpo(2ll,len))%mod;
            }
            if(add) {
                // vtemp[ordx-i] = temp;
                pref = (pref+temp)%mod;
                val.push_back({{idx,ct},pref});
            }
        }
        // rep(k,i,j) {
        //     cout <<v[k].se <<" \n"[k==j-1];
        // }
        // rep(k,i,j) {
        //     cout <<vtemp[k-i] <<" \n"[k==j-1];
        // }
        // rep(k,i,j) {
        //     cout <<mpl[k] <<" \n"[k==j-1];
        // }
        // rep(k,i,j) {
        //     cout <<mpr[k] <<" \n"[k==j-1];
        // }
        ct++;
        i = j;
    }
    vector<bool> vis(ct,0);
    vector<ll> cur(ct);
    sort(val.begin(),val.end());
    vector<ll> ans(n, 0);
    int ctvis = 0;
    ll pi = 1;
    ll pref = 0;
    // debug() <<imie(val);
    int ct0 = 0;
    rep(i,0,sz(val)) {
        if(vis[val[i].fi.se]) {
            if(cur[val[i].fi.se]==0ll) {
                ct0--;
            } else {
                pi = pi*inv(cur[val[i].fi.se])%mod;
            }
        } else {
            ctvis++;
            vis[val[i].fi.se] = 1;
        }
        if(val[i].se==0ll) {
            ct0++;
        } else {
            pi = pi*val[i].se%mod;
        }
        cur[val[i].fi.se] = val[i].se;
        // assert(pi!=0ll);
        ll pi_f = ct0>0?0ll:pi;
        if(ctvis==ct) {
            // ll tes = 1;
            // rep(j,0,sz(cur)) {
            //     tes = tes*cur[j]%mod;
            // }
            // assert(tes==pi);
            ll temp = (pi_f - pref + mod)%mod;
            ans[val[i].fi.fi] = temp;
        } 
        pref = (pref + ans[val[i].fi.fi])%mod;
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}