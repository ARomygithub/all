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

const int mxn=2e5;
int n,t;
struct node {
    int a,id;
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
        if(i>0) {
            v[i].prv = &v[i-1];
        }
        if(i+1<n) {
            v[i].nxt = &v[i+1];
        }
    }
    priority_queue<pii> pq;
    vector<bool> used(n,0);
    rep(i,0,n) {
        bool f1 = i>0 && (v[i].a==v[i-1].a+1);
        bool f2 = i+1<n && (v[i].a==v[i+1].a+1);
        if(f1 || f2) {
            pq.push({v[i].a,i});
        }
    }
    while(sz(pq)) {
        auto [a,i] = pq.top(); pq.pop();
        used[i] = 1;
        node* nl = v[i].prv;
        node* nr = v[i].nxt;
        if(nl!=nullptr) {
            nl->nxt = nr;
        }
        if(nr!=nullptr) {
            nr->prv = nl;
        }
        if(nl!=nullptr && nr!=nullptr) {
            if(nl->a == nr->a+1) {
                pq.push({nl->a,nl->id});
            } else if(nl->a+1 == nr->a) {
                pq.push({nr->a,nr->id});
            }
        }
    }
    int ct=0,ctd=0;
    rep(i,0,n) {
        ct += !used[i];
        if(!used[i]) {
            ctd +=v[i].a;
        }
    }
    if(ct==1 && ctd==0) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
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