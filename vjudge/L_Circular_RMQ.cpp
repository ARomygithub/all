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
int n,q;
int a[mxn];

const ll inf = 1e18;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    ll madd = 0, val = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void add(int L, int R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = min(l->val, r->val);
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
    Node st(0,n);
    rep(i,0,n) {
        cin >>a[i];
        st.add(i,i+1,a[i]);
    }
    cin >>q;
    string temp ;getline(cin,temp);
    while(q--) {
        string s; getline(cin, s);
        stringstream ss(s);
        int l,r,v; ss >>l >>r;
        if(ss >> v) {
            // cout <<l <<r <<v <<"\n";
            if(l>r) {
                st.add(l,n,v);
                st.add(0,r+1,v);
            } else {
                st.add(l,r+1,v);
            }
        } else {
            // cout <<l <<r <<"\n";
            ll ans = inf;
            if(l>r) {
               min_self(ans, st.query(l,n));
               min_self(ans, st.query(0,r+1)); 
            } else {
                min_self(ans, st.query(l,r+1));
            }
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}