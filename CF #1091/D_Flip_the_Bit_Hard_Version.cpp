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
int a[mxn], p[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,k) {
        cin >>p[i]; p[i]--;
    }
    int ct = 1;
    int cur = a[p[0]];
    set<int> v;
    int j = 0;
    rep(i,0,n) {
        if(a[i]!=cur) {
            ct++;
            cur = a[i];
        }
        if(j < k && p[j]==i) {
            v.insert(ct);
            j++;
        }
    }
    if(cur!=a[p[0]]) {
        ct++;
    }
    if(ct==1) {
        cout <<"0\n";
        return;
    }
    int ans = 0;
    auto it = v.begin();
    int ansi = max(1,(*it)-2);
    ans += ansi;
    int ri = (*it) + ansi;
    // debug() <<imie(ansi) imie(ri);
    it++;
    while(it!=v.end()) {
        if((*it) <= ri) {
            it++;
            continue;
        }
        if((ri%2) == 1) {
            ri++;
        }
        ansi = (*it)-ri;
        ans += ansi;
        ri = (*it) + ansi;
        // debug() <<imie(ansi) imie(ri);
    }
    // cout <<ans <<" ";
    if(ri < ct) {
        ans += ct-ri;
    } else {
        it--;
        // if((*it) < ct) {
            if(ri==ct) {
                ans++;
            }
        // }
    }

    // for(auto pos: v) {
    //     min_self(ans, max(pos-1,ct-pos));
    // }
    cout <<ans <<"\n";
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