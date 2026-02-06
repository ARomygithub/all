#include <bits/stdc++.h>
using namespace std;

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

const int mxn=25e4;
int n;
pll t[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        int d; ll l; cin >>l >>d;
        t[i] = {l+d,d};
    }
    sort(t,t+n);
    priority_queue<pll> pq;
    ll last=0;
    for(int i=0;i<n;i++) {
        if(last+t[i].se<=t[i].fi) {
            pq.push({t[i].se,i});
            last +=t[i].se;
        } else {
            auto [di,idx] = pq.top();
            if(di>t[i].se && last+t[i].se-di<=t[i].fi) {
                pq.pop();
                last +=t[i].se-di;
                pq.push({t[i].se,i});
            }
        }
    }
    cout <<sz(pq) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}