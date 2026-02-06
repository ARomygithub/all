#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

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

void solve() {
    cin >>n >>m;
    vector<pii> vn(n);
    for(int i=0;i<n;i++) {
        cin >>vn[i].fi >>vn[i].se;
    }
    vector<pii> vm(m);
    for(int i=0;i<m;i++) {
        cin >>vm[i].fi >>vm[i].se;
    }
    int ans=1;
    for(int i=0;i<n;i++) {
        map<pii,int> mp;
        for(int j=0;j<m;j++) {
            int di=vm[j].fi-vn[i].fi;
            int dj=vm[j].se-vn[i].se;
            int d = __gcd(abs(di),abs(dj));
            di /=d;
            dj /=d;
            mp[make_pair(di,dj)]++;
            // if(mp[make_pair(di,dj)]==3) {
            //     cout <<i <<" " <<j <<"\n";
            //     cout <<di <<" " <<dj <<" " <<d <<"\n";
            // }
        }
        for(auto [k,v]: mp) {
            max_self(ans, v);
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}