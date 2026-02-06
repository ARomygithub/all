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

const int mxn=2e5;
int n,k,t;
ll a[mxn];

void solve() {
    cin >>n >>k; k--;
    rep(i,0,n) {
        cin >>a[i];
    }
    queue<pll> q[2];
    for(int i = k-1;i>=0;) {
        int j = i-1;
        ll y = a[i],x=a[i];
        while(y<0 && j>=0) {
            y += a[j];
            min_self(x, y);
            j--;
        }
        // debug() <<imie(i) imie(j);
        // debug() <<imie(y) imie(x);
        q[0].push({y,x});
        i = j;
    }
    // debug() <<"1";
    for(int i = k+1;i<n;) {
        int j = i+1;
        ll y = a[i], x= a[i];
        while(y<0 && j<n) {
            y += a[j];
            min_self(x, y);
            j++;
        } 
        // debug() <<imie(i) imie(j);
        // debug() <<imie(y) imie(x);        
        q[1].push({y,x});
        i = j;
    }
    ll cur = a[k];
    // debug() <<imie(cur);
    while(sz(q[0]) || sz(q[1])) {
        // debug() <<imie(sz(q[0])) imie(sz(q[1]));
        bool ok = 0;
        rep(i,0,2) {
            // debug() <<imie(q[i].front());
            if(!sz(q[i])) continue;
            if(cur+q[i].front().se >=0) {
                ok = 1;
                cur += q[i].front().fi;
                q[i].pop();
                break;
            }
        }
        if(!ok) {
            break;
        }
    }
    if(sz(q[0]) && sz(q[1])) {
        cout <<"NO\n";
    } else {
        cout <<"YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}