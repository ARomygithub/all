#pragma GCC optimize("Ofast")

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

const int mxk=1e2;
ll n,k, e[mxk];
ll ans = 0;

void dfs(ll& val, int pos, int& ct) {
    if(pos==k) {
        if(ct>0) {
            if(ct%2) {
                ans += (n/val);
            } else {
                ans -= (n/val);
            }
        } 
        return;
    }
    if(n/val>= e[pos]) {
        val *= e[pos];
        ct++;
        dfs(val, pos+1, ct);
        val /= e[pos];
        ct--;
        dfs(val, pos+1, ct);
    } else {
        dfs(val, k, ct);
    }
}

void solve() {
    cin >>n >>k;
    rep(i,0,k) {
        cin >>e[i];
    }
    sort(e,e+k);
    rep(i,0,k) {
        if(e[i]==1) {
            cout <<n <<"\n";
            return;
        }
    }
    ll val=1, pos=0; 
    int ct = 0;
    dfs(val, pos, ct);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}