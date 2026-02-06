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
int n,t;

void solve() {
    cin >>n;
    int n4 = n%4;
    if(n4 != 0 && n4!=1) {
        cout <<"-1\n";
        return;
    } else {
        if(n==1) {
            cout <<"1 1\n";
            return;
        }
        // https://www.teferi.net/ps/%EC%97%AC%EB%9F%AC%EA%B0%80%EC%A7%80_%EC%88%98%ED%95%99_%EC%A0%95%EB%A6%AC#langford_pairing
        int n1 = n-1;
        int x = (n1+3)/4;
        int a = x*2-1;
        int b = x*4 - 2;
        int c = x*4 - 1;
        int d = x*4;
        vi p;
        for(int i=1;i<a;i+=2) {
            p.push_back(i);
        }
        vi q;
        for(int i=2;i<a;i+=2) {
            q.push_back(i);
        }
        vi r;
        for(int i=a+2;i<b;i+=2) {
            r.push_back(i);
        }
        vi s;
        for(int i=a+1;i<b;i+=2) {
            s.push_back(i);
        }
        vi ans;
        per(i,sz(s)-1,-1) {
            ans.push_back(s[i]);
        }
        per(i,sz(p)-1,-1) {
            ans.push_back(p[i]);
        }
        ans.push_back(b);
        rep(i,0,sz(p)) {
            ans.push_back(p[i]);
        }
        ans.push_back(c);
        rep(i,0,sz(s)) {
            ans.push_back(s[i]);
        }
        if(n1%4) {
            ans.push_back(a);
            per(i,sz(r)-1,-1) {
                ans.push_back(r[i]);
            }
            per(i,sz(q)-1,-1) {
                ans.push_back(q[i]);
            }
            ans.push_back(b);
            ans.push_back(a);
            rep(i,0,sz(q)) {
                ans.push_back(q[i]);
            }
            ans.push_back(c);
            rep(i,0,sz(r)) {
                ans.push_back(r[i]);
            }
        } else {
            ans.push_back(d);
            per(i,sz(r)-1,-1) {
                ans.push_back(r[i]);
            }
            per(i,sz(q)-1,-1) {
                ans.push_back(q[i]);
            }
            ans.push_back(b);
            ans.push_back(a);
            rep(i,0,sz(q)) {
                ans.push_back(q[i]);
            }
            ans.push_back(c);
            rep(i,0,sz(r)) {
                ans.push_back(r[i]);
            }
            ans.push_back(a);
            ans.push_back(d);                        
        }
        ans.push_back(0);
        ans.push_back(0);
        rep(i,0,sz(ans)) {
            cout <<ans[i]+1 <<" \n"[i==sz(ans)-1];
        }
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