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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n;
piii ca[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>ca[i].fi.se >>ca[i].fi.fi;
        ca[i].fi.se *=-1;
        ca[i].se = i+1;
    }
    sort(ca,ca+n);
    int ls = 0;
    vector<int> ans;
    int id = 0;
    while(id<n) {
        int j = id;
        while(j<n && ca[j].fi.fi==ca[id].fi.fi) {
            if(ca[j].fi.se*-1 >=ls) {
                ans.push_back(ca[j].se);
            }
            j++;
        }
        max_self(ls, ca[id].fi.se*-1);
        id = j;
    }
    sort(ans.begin(),ans.end());
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}