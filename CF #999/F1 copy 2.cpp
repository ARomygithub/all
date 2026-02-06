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

const int mxn=4e5;
int t;
string s1,s2;

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    cin >>s1;
    cin >>s2;
    vector ct(2, vi());
    int n = sz(s1);
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s1[j]==s1[i]) {
            j++;
        }
        int cur = s1[i]-'0';
        ct[cur].push_back(j-i);
        i = j;
    }
    vi awl;
    if(s1[0]=='0') {
        rep(i,0,sz(ct[0])) {
            awl.push_back(i);
            if(i<sz(ct[1])) {
                awl.push_back(sz(ct[0])+i);
            }
        }
    } else {
        rep(i,0,sz(ct[1])) {
            awl.push_back(sz(ct[0])+i);
            if(i<sz(ct[0])) {
                awl.push_back(i);
            }
        }
    }
    vi akhir;
    int i0=0,i1=0;
    int p2 = 0;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s2[j]==s2[i]) {
            j++;
        }
        if(s2[i]=='0') {
            int len = j-i;
            while(i0<sz(ct[0]) && len>0) {
                if(ct[0][i0]<=len) {
                    akhir.push_back(i0);
                    len -= ct[0][i0];
                    i0++;
                } else {
                    break;
                }
            }
            if(len>0) {
                cout <<"-1\n";
                return;
            }
        } else {
            int len = j-i;
            while(i1<sz(ct[1]) && len>0) {
                if(ct[1][i1]<=len) {
                    akhir.push_back(i1+sz(ct[0]));
                    len -= ct[1][i1];
                    i1++;
                } else {
                    break;
                }
            }
            if(len>0) {
                cout <<"-1\n";
                return;
            }
        }
        p2++;
        i = j;
    }
    if(i0!=sz(ct[0]) || i1!=sz(ct[1])) {
        cout <<"-1\n";
        return;
    }
    map<int,int> ord,ord2;
    Tree<pii> s;
    rep(i,0,sz(awl)) {
        ord[awl[i]] = i;
        s.insert({i,awl[i]});
    }
    rep(i,0,sz(akhir)) {
        ord2[akhir[i]] = i;
    }
    // auto cl  = [&](int x) -> int {
    //     if(x<sz(ct[0])) return 0;
    //     return 1;
    // };
    ll ans = 0;
    // debug() <<imie(awl);
    // debug() <<imie(akhir);
    rep(i,0,sz(akhir)) {
        auto it = s.begin();
        if(akhir[i]==it->se) {
            s.erase(it);
        } else {
            ans++;
            s.erase({ord[akhir[i]],akhir[i]});
            // auto it3 = s.lower_bound({ord[akhir[i]],akhir[i]});
            // it = s.begin();
            // if(cl(it3->se) != cl(it->se)) {
            //     it3--;
            // }
            // if(ord2[it3->se]-ord2[it->se] != (int)s.order_of_key(*it3)) {
            //     cout <<"-1\n";
            //     return;
            // }
        }
    }
    int p1 = sz(ct[0])+sz(ct[1]);
    if(p1>2) {
        int tes = 0;
        if(s1[0]!=s2[0]) tes++;
        tes += s1.back()!=s2.back();
        int mx = p1 - ans*2 + tes;
        if(mx < p2) {
            cout <<"-1\n";
            return;
        }
    }
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