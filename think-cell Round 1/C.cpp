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

const int mxn=3e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<int> s;
    vector<pii> v;
    rep(i,0,n) {
        v.push_back({a[i]+i+1,i+1});
    }
    sort(v.begin(),v.end(),[&](pii a, pii b) -> bool {
        return make_pair(a.fi,a.se*-1)>make_pair(b.fi,b.se*-1);
    });
    int nxt = 2e9;
    priority_queue<int> pq;
    for(int i=0;i<sz(v);) {
        auto [now,len] = v[i];
        while(now<nxt && sz(pq)) {
            while(sz(pq)) {
                int u = pq.top(); pq.pop();
                if(u<=nxt) {
                    s.insert(nxt);
                    nxt--;
                    break;
                }
            }
        }
        if(sz(pq)==0) {
            nxt = now;
        }
        int j = i;
        while(j<sz(v) && v[j].fi>=nxt) {
            pq.push(v[j].fi-v[j].se+1);
            j++;
        }
        i = j;
    }
    while(sz(pq)) {
        int u = pq.top(); pq.pop();
        if(u<=nxt) {
            s.insert(nxt);
            nxt--;
        }
    }    
    for(auto it = (--s.end());it!=s.begin();it--) {
        cout <<(*it) <<" ";
    }
    cout <<(*s.begin()) <<"\n";
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