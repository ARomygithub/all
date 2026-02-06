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

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

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
        i = j;
    }
    if(i0!=sz(ct[0]) || i1!=sz(ct[1])) {
        cout <<"-1\n";
        return;
    }
    map<int,int> ord;
    set<pii> s;
    rep(i,0,sz(awl)) {
        ord[awl[i]] = i;
        s.insert({i,awl[i]});
    }

    ll ans = 0;
    // debug() <<imie(awl);
    // debug() <<imie(akhir);
    auto cl = [&](int x) -> int {
        if(x<sz(ct[0])) return 0;
        return 1;
    };
    for(int i=0;i<sz(akhir);) {
        auto it = s.begin();
        if(akhir[i]==it->se) {
            s.erase(it);
            i++;
        } else {
            ans++;
            int j = i+1;
            while(it->se!=akhir[i]) {
                if(akhir[j]!= it->se) {
                    cout <<"-1\n";
                    return;
                }
                s.erase(it);
                it = s.begin();
                j++;
            }
            s.erase(it);
            if(sz(s)) {
                it = s.begin();
                while(cl(it->se)!=cl(akhir[i])) {
                    if(akhir[j]!= it->se) {
                        cout <<"-1\n";
                        return;
                    }
                    s.erase(it);
                    j++;
                    if(sz(s)) {
                        it = s.begin();
                    } else {
                        break;
                    }
                }
            }
            i = j;
            // s.erase({ord[akhir[i]],akhir[i]});
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