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

const int mxn=1e5, mxa=1e5;
int k,l,r,t;
int ct[mxa+1];
vector<vector<int>> v;
int tim=0;

void solve() {
    cin >>k >>l >>r;
    // cout <<*upper_bound(v[k].begin(),v[k].end(),r) <<"\n";
    // cout <<*lower_bound(v[k].begin(),v[k].end(),l) <<"\n";
    if(k>tim) {
        cout <<"0\n";
        return;
    }
    cout <<upper_bound(v[k].begin(),v[k].end(),r) - lower_bound(v[k].begin(),v[k].end(),l) <<"\n";
}

void init() {
    vector<bool> comp(mxa+1,0);
    for(int i=2;i<=mxa;i++) {
        if(!comp[i]) {
            tim++;
            for(int j=i;j<=mxa;j+=i) {
                comp[j] = 1;
                ct[j]++;
            }
        }
    }
    v.resize(tim+1);
    for(int i=2;i<=mxa;i++) {
        v[ct[i]].push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >>t;
    while(t--) {
        solve();
    }
}