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

const int mxn=3e5;
int n;
int a[mxn],p[mxn];

struct node {
    vector<node*> chi;
    int sub = 0;
    node(): chi(2,(node*)(0)) {}

};

void add(node* r, int pi) {
    r->sub++;
    per(bit,29,-1) {
        int cur = (pi>>bit)&1;
        if(!(r->chi[cur])) {
            r->chi[cur] = new node();
        }
        r = r->chi[cur];
        r->sub++;
        // cout <<"cek" <<endl;
    }
}

int getans(node* r, int ai) {
    node* ri = r;
    int ret = 0;
    per(bit,29,-1) {
        // assert(r->sub >0);
        // cout <<"ans " <<endl;
        int cur = (ai>>bit)&1;
        if(!(r->chi[cur])) {
            // assert(r->chi[1-cur]);
            r = r->chi[1-cur];
            ret += (1<<bit)*(1-cur);
        } else {
            r = r->chi[cur];
            ret += (1<<bit)*cur;
        }
    }
    ri->sub--;
    per(bit,29,-1) {
        // cout <<"cr" <<endl;
        int cur = (ret>>bit)&1;
        auto cr = ri->chi[cur];
        cr->sub--;
        if(cr->sub ==0) {
            ri->chi[cur] = 0;
            break;
        }
        ri = cr;
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>p[i];
    }
    node* r = new node();
    rep(i,0,n) {
        add(r, p[i]);
    }
    // cout <<"tes" <<endl;
    vi ans(n);
    rep(i,0,n) {
        ans[i] = getans(r,a[i])^a[i];
    }
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