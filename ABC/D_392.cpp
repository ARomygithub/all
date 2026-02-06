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

const int mxn=1e2;
int n;

void solve() {
    cin >>n;
    vi k(n);
    vector mp(n, map<int,int>());
    rep(i,0,n) {
        cin >>k[i];
        rep(j,0,k[i]) {
            int aij; cin >>aij;
            mp[i][aij]++;
        }
    }
    double ans = 0.0;
    rep(i,0,n) {
        rep(j,i+1,n) {
            int i2 = i, j2= j;
            if(k[i2]>k[j2]) swap(i2,j2);
            double cur = 0.0;
            for(auto& [ke, val]: mp[i2]) {
                if(mp[j2].count(ke)) {
                    cur += (1.0*val/k[i2])*(1.0*mp[j2][ke]/k[j2]);
                }
            }
            max_self(ans, cur);
        }
    }
    cout <<fixed <<setprecision(10) <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}