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

const int mxn=1e5;
int n,k;
int a[mxn];

struct node {
    int val;
    node* l=0;
    node* r=0;
    node(int val): val(val) {}
};

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    map<int,node*> mp;
    node* st = new node(a[0]);
    mp[a[0]] = st;
    rep(i,1,n) {
        auto it = mp[a[i-1]];
        node* ni = new node(a[i]);
        it->r = ni;
        ni->l = it;
        mp[a[i]] = ni;
    }
    while(k--) {
        char qt; cin >>qt;
        if(qt=='G') {
            int x; cin >>x;
            st = mp[x];
        } else {
            int y; cin >>y;
            node* ni = new node(y);
            ni->r = st;
            node* stl = st->l;
            st->l = ni;
            ni->l = stl;
            if(stl) {
                stl->r = ni;
            }
            st = ni;
            mp[y] = ni;
        }
    }
    vector<int> ans,ans2;
    function<void(node*)> doR, doL;
    doR = [&](node* it) -> void {
        ans.push_back(it->val);
        if(it->r) {
            doR(it->r);
        }
    };
    doR(st);
    doL = [&](node* it) -> void {
        ans2.push_back(it->val);
        if(it->l) {
            doL(it->l);
        }
    };
    if(st->l) {
        doL(st->l);
    }
    per(i,sz(ans2)-1,-1) {
        ans.push_back(ans2[i]);
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}