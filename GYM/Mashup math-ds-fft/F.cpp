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

const int mxn=1e5;
int n;
ll b[mxn];

struct node {
    ll val;
    int d;
    node* l=0;
    node* r=0;
    node(ll _val): val(_val) {}
};

using pin = pair<int,node*>;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<pll> v;
    rep(i,0,n) {
        ll pw = 0;
        while((1ll<<pw)*2<=b[i]) {
            pw++;
        }
        v.push_back({pw,b[i]});
    }
    sort(all(v),greater<pll>());
    // rep(i,0,n) {
    //     cout <<v[i].fi <<" " <<v[i].se <<"\n";
    // }
    node* r = new node(v[0].se);
    r->d = 0;
    priority_queue<pin> pq;
    pq.push({v[0].fi,r});
    rep(i,1,n) {
        node* u = new node(v[i].se);
        if(!sz(pq)) {
            cout <<"No\n";
            return;
        }
        auto [pw,pr] = pq.top(); pq.pop();
        if(v[i].fi>=pw) {
            cout <<"No\n";
            return;
        }
        if(!(pr->l)) {
            u->d = pr->d +1;
            pr->l = u;
            pq.push({pw,pr});
            pq.push({v[i].fi,u});
        } else if(!(pr->r)) {
            u->d = pr->d +1;
            pr->r = u;
            pq.push({v[i].fi,u});
        }
    }
    vector<ll> ans;
    function<void(node*)> rec;
    rec = [&](node* u) -> void {
        if(u->l) {
            rec(u->l);
        }
        ans.push_back(u->val);
        if(u->r) {
            rec(u->r);
        }
    };
    rec(r);
    ll xr = 0;
    rep(i,0,sz(ans)) {
        ll xrn = xr^ans[i];
        if(xr>=xrn) {
            cout <<"No\n";
            return;
        }
        xr = xrn;
    }
    cout <<"Yes\n";
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}