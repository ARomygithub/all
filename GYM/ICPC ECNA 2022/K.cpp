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
string s1,s2;
map<int,int> mp1,mp2;

void slv(string si, map<int,int>& mpi) {
    int tmp = 0;
    stack<int> st;
    st.push(-1);
    // vector<bool> ff(1,1);
    rep(i,0,sz(si)) {
        if(si[i]==' ') continue;
        if(si[i]>='0' && si[i]<='9') {
            tmp = tmp*10 + (si[i]-'0');
        } else if(si[i]=='(') {
            if(tmp>0) {
                mpi[tmp] = st.top();
                // ff[sz(st)-1] = 0;
            }
            if(tmp>0) {
                st.push(tmp);
                // if(sz(st)> sz(ff)) {
                //     ff.push_back(1);
                // }
                // ff[sz(st)-1] = 1;
                tmp = 0;
            }
        } else if(si[i]==')') {
            if(tmp>0) {
                mpi[tmp] = st.top();
            } else {
                st.pop();
            }
            tmp = 0;
        }
    }
    if(sz(mpi)==0) {
        mpi[tmp] = -1;
    }
}

void solve() {
    getline(cin, s1);
    getline(cin, s2);
    slv(s1 ,mp1);
    slv(s2, mp2);
    // debug() <<imie(mp1);
    // debug() <<imie(mp2);
    for(auto [k,v]: mp1) {
        if(!mp2.count(k) || v!=mp2[k]) {
            cout <<"No\n";
            return;
        }
    }
    for(auto [k,v]: mp2) {
        if(!mp1.count(k) || v!=mp1[k]) {
            cout <<"No\n";
            return;
        }
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}