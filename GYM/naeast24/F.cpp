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

const int mxn=2e3;

void solve() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    char qt;
    string k;
    stringstream ss1(s1);
    ss1 >>qt;
    ss1 >>k;
    string t = "";
    for(auto c: s2) {
        if((c>='a' && c<='z')) {
            t += c;
        } else if (c>='A' && c<='Z') {
            t +=(char)(c-'A' + 'a');
        }
    }
    vi pos(sz(t));
    set<int> s;
    rep(i,0,sz(t)) {
        s.insert(i);
    }
    vi d(sz(k));
    rep(i,0,sz(k)) {
        d[i] = k[i]-'a'+2;
    }
    d.push_back(1);
    bool knn = 1;
    int id = 0, pi = 0;
    while(sz(s)) {
        vi er;
        if(knn) {
            int ct = 0;
            auto it = s.begin();
            while(it!=s.end()) {
                ct++;
                if(ct==d[id]) {
                    pos[pi] = *it;
                    er.push_back(*it);
                    ct = 0;
                    pi++;
                }
                it++;
            }
        } else {
            int ct = 0;
            auto it = --s.end();
            while(true) {
                ct++;
                if(ct==d[id]) {
                    pos[pi] = *it;
                    er.push_back(*it);
                    ct = 0;
                    pi++;
                }
                if(it==s.begin()) break;
                it--;
            }
        }
        for(auto eri : er) {
            s.erase(eri);
        }
        id++;
        knn = !knn;
        // debug() <<imie(er);
    }
    string ans = "";
    rep(i,0,sz(t)) {
        ans += ' ';
    }
    if(qt=='E') {
        rep(i,0,sz(t)) {
            ans[pos[i]] = t[i];
        }
    } else {
        rep(i,0,sz(t)) {
            ans[i] = t[pos[i]];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}