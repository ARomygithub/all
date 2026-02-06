#include <bits/stdc++.h>
using namespace std;

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5,mxa=3e5;
int n;
int a[mxn];

const ll inf = 0;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val += x*(hi-lo);
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s400;
    ll sm = 0;
    Node st1(0,mxa+1), st2(0,mxa+1);
    vector<ll> p(n,0);
    rep(i,0,n) {
        if(i>0) p[i] += p[i-1];
        if(a[i]<=400) {
            rep(j,0,i) {
                p[i] += (a[i]%a[j]) + (a[j]%a[i]);
            }
            s400.insert(a[i]);
            st2.add(a[i],a[i]+1,1);
            sm += a[i];
        } else {
            p[i] += sm;
            p[i] += st2.query(401,mxa+1)*a[i];
            for(auto si: s400) {
                p[i] += (a[i]%si);
            }
            p[i] -= st1.query(a[i],a[i]+1);
            for(int j=1;j*a[i]<=mxa;j++) {
                p[i] -= st2.query(j*a[i],mxa+1)*a[i];
            }
            sm += a[i];
            st2.add(a[i],a[i]+1, 1);
            for(int j=1;j*a[i]<=mxa;j++) {
                st1.add(j*a[i], mxa+1, a[i]);
            }
        }
    }
    rep(i,0,n) {
        cout <<p[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}