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

const int mxn=12;
int n;
ll a[mxn];
unordered_set<ll> sx;

void rec(vector<ll>& v, int id, int udh) {
    if(id==n) {
        ll cur = 0;
        rep(i,0,udh) {
            cur ^= v[i];
        }
        sx.insert(cur);
        // vx.push_back(cur);
        return;
    }
    rep(i,0,udh+1) {
        v[i] += a[id];
        int udhn = i==udh?udh+1:udh;
        rec(v, id+1, udhn);
        v[i] -= a[id];
    }
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    // if(n==1) {
    //     cout <<"1\n";
    //     return;
    // }
    vector<ll> v(n,0);
    v[0] = a[0];
    rec(v, 1, 1);
    cout <<sz(sx) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}