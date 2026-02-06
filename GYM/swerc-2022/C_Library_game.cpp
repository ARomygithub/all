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

const int mxn=1e2;
int n,m,t;
int x[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>x[i];
    }
    sort(x,x+n);
    bool a = 1;
    multiset<int> ms;
    ms.insert(m);
    per(i,n-1,-1) {
        // debug() <<imie(x[i]);
        // debug() <<imie(ms);
        if(sz(ms)==0) {
            a = 0;
            break;
        }
        auto it = --ms.end();
        if((*it) < x[i]) {
            a = 0;
            break;
        }
        if(((*it)+1)/2  <= x[i]) {
            it = ms.lower_bound(x[i]);
        }
        int len = (*it);
        if((len+1)/2 <= x[i]) {
            ms.erase(it);
            ms.insert(((len+1)/2)-1);
            ms.insert(len - ((len+1)/2));
        } else {
            ms.erase(it);
            ms.insert(x[i]-1);
            ms.insert(len-x[i]);
        }
    }
    // debug() <<imie(a);
    if(a) {
        cout <<"Alessia\n" <<flush;
        set<pii> s;
        s.insert({m,1});
        per(i, n-1, -1) {
            if(sz(s)==0) {
                assert(false);
            }
            auto it = --s.end();
            auto [len, a] = *it;
            if(len < x[i]) assert(false);
            int tg = (len+1)/2;
            if(tg <= x[i]) {
                it = s.lower_bound({x[i],-1});
                len = it->fi; a = it->se;
                tg = (len+1)/2;
            }
            cout <<x[i] <<" " <<a <<"\n" <<flush;
            int mid; cin >>mid;
            s.erase({len,a});
            if(mid>a) {
                s.insert({mid-a,a});
            }
            if(mid < a+len-1) {
                s.insert({a+len-1 - mid, mid+1});
            }
        }
    } else {
        cout <<"Bernardo\n" <<flush;
        set<int> s;
        rep(i,0,n) {
            int y,a; cin >>y >>a;
            auto it =  s.lower_bound(a);
            int nx = m+1, pr = 0;
            if(it!=s.end()) {
                nx = *it;
            }
            if(it!=s.begin()) {
                it--;
                pr =  *it;
            }
            if(nx <= a+y-1) {
                cout <<nx <<"\n" <<flush;
                continue;
            }
            int len = nx - pr - 1;
            int tg = (len+1)/2 + pr;
            int mid = clamp(tg, a, a+y-1);
            cout <<mid <<"\n" <<flush;
            s.insert(mid);
        }
    }
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