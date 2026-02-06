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
int n;
int a[mxn];

void solve() {
    cin >>n;
    int mx = 0;
    rep(i,0,n) {
        cin >>a[i];
        max_self(mx, a[i]);
    }
    vector<ll> ct(mx+1);
    set<pii> s;
    s.insert({0,n-1});
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    rep(i,0,n) {
        pq.push({a[i],i});
    }
    rep(i,1,mx+1) {
        while(pq.top().fi <i) {
            auto [val, idx] = pq.top(); pq.pop();
            auto it = s.upper_bound({idx,n});
            it--;
            auto [l,r] = *it;
            s.erase(it);
            if(l<idx) {
                s.insert({l,idx-1});
            }
            if(r>idx) {
                s.insert({idx+1,r});
            }
        }
        ct[i] = sz(s);
    }
    vector<ll> ans(mx+1,0);
    rep(i,1,mx+1) {
        for(int j=1;j<=mx;j+=i) {
            ans[i] += ct[j];
        }
    }
    rep(i,1,mx+1) {
        cout <<ans[i] <<" \n"[i==mx];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}