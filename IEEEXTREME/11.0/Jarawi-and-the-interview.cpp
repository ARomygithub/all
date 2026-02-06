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

const int mxn=1e5;
int n,q;
string s;
vector<int> v[26];

void solve() {
    cin >>s;
    n = s.length();
    cin >>q;
    for(int i=n-1;i>=0;i--) {
        v[s[i]-'a'].push_back(n-i-1);
    }
    while(q--) {
        string p; cin >>p;
        int idx=0;
        int ct=0;
        for(;ct<sz(p);ct++) {
            char c = p[sz(p)-1-ct];
            auto it = lower_bound(v[c-'a'].begin(),v[c-'a'].end(),idx);
            if(it==v[c-'a'].end()) {
                break;
            } else {
                idx = *it;
                idx++;
            }
        }
        cout <<ct <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}