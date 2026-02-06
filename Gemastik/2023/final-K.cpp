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
typedef pair<pii,bool> piib;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n;
int d[mxn],e[mxn];
ll sumB=0;

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        int a,b,c; cin >>a >>b >>c;
        sumB +=b;
        d[i] = a+b;
        e[i] = b+c;
    }
    vector<int> optOrder(n);
    vector<piib> v;
    for(int i=0;i<n;i++) {
        v.push_back({{d[i],i},0});
        v.push_back({{e[i],i},1});
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    vector<bool> udh(n,false);
    for(int i=0;i<sz(v);i++) {
        auto [ti,flag] = v[i];
        auto [t,idx] = ti;
        if(!udh[idx]) {
            if(flag) {
                optOrder[r] = idx;
                r--;
            } else {
                optOrder[l] = idx;
                l++;
            }
            udh[idx] = 1;
        }
    }
    pll ans = {0,0};
    for(auto idx : optOrder) {
        ans = {ans.fi+d[idx],max(ans.fi+d[idx],ans.se)+e[idx]};
    }
    cout <<ans.se-sumB <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}