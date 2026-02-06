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

const int mxn=1e5;
int n,m;
ll l[mxn];

void solve() {
    cin >>n >>m;
    ll sisa = n-m;
    vector<ll> gap(m,0);
    rep(i,0,m) {
        cin >>l[i];
    }
    sisa -=l[m-1]-1;
    if(sisa<0) {
        cout <<"-1\n";
        return;
    }
    bool f = 0;
    vector<ll> pos(m,0);
    pos[m-1] = n-l[m-1]+1;
    per(i,m-2,-1) {
        ll temp = min(l[i]-1,sisa);
        gap[i] = temp;
        pos[i] = pos[i+1]-temp-1;
        if(pos[i]+l[i]-1>n) {
            // cout <<pos[i] <<" " <<temp <<" " <<l[i] <<" " <<n <<"\n";
            f = 1;
            break;
        }
        sisa -= temp;
        // cout <<sisa <<"\n";
    }
    if(sisa>0 || f) {
        cout <<"-1\n";
        return;
    }
    int temp = 1;
    rep(i,0,m) {
        cout <<temp <<" \n"[i==m-1];
        temp += gap[i]+1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}