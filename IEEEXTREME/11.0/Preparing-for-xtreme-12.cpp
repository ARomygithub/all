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

const int mxn=1e2;
int n;

void solve() {
    vector<int> vt;
    vector<vector<string>> vs;
    set<string> st;
    string s;
    while(getline(cin,s)) {
        stringstream ss(s);
        int ti;
        vector<string> vsi;
        ss >>ti;
        string si;
        while(ss>>si) {
            st.insert(si);
            vsi.push_back(si);
        }
        vt.push_back(ti);
        vs.push_back(vsi);
    }
    n = sz(vt);
    int id=0;
    map<string,int> mp;
    for(auto si : st) {
        mp[si] = id;
        id++;
    }
    vector<int> vst(n);
    for(int i=0;i<n;i++) {
        vst[i] = 0;
        for(auto si : vs[i]) {
            vst[i] |= 1<<mp[si];
        }
    }
    vector<int> dp(1<<sz(st),1e9);
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        vector<int> dp_new(1<<sz(st),1e9);
        for(int j=0;j<(1<<sz(st));j++) {
            min_self(dp_new[j],dp[j]);
            int u = j | vst[i];
            min_self(dp_new[u],dp[j]+vt[i]);
        }
        dp.swap(dp_new);
    }
    cout <<dp[(1<<sz(st))-1] <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}