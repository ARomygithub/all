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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
int n,t;
struct node {
    int a,d,id;
    node* prv = nullptr;
    node* nxt = nullptr;
};

void solve() {
    cin >>n;
    vector<node> v(n);
    rep(i,0,n) {
        v[i].id = i;
        cin >>v[i].a;
    }
    rep(i,0,n) {
        cin >>v[i].d;
    }
    vector<int> ans(n,0);
    rep(i,0,n) {
        if(i>0) {
            v[i].prv = &v[i-1];
        }
        if(i+1<n) {
            v[i].nxt = &v[i+1];
        }
    }
    vector<bool> mati(n,0);
    queue<int> q;
    rep(i,0,n) {
        q.push(i);
    }
    rep(i,0,n) {
        queue<int> q_new;
        while(sz(q)) {
            auto id = q.front(); q.pop();
            if(mati[id]) continue;
            int atk = 0;
            if(v[id].prv!=nullptr) {
                atk +=v[id].prv->a;
            }
            if(v[id].nxt!=nullptr) {
                atk +=v[id].nxt->a;
            }
            if(v[id].d < atk) {
                mati[id] = 1;
                ans[i]++;
                q_new.push(id);
            }
        }
        while(sz(q_new)) {
            auto id = q_new.front(); q_new.pop();
            node* nl = v[id].prv;
            node* nr = v[id].nxt;
            if(nl!=nullptr) {
                nl->nxt = nr;
                q.push(nl->id);
            }
            if(nr!=nullptr) {
                nr->prv = nl;
                q.push(nr->id);
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i] <<" \n"[i==n-1];
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