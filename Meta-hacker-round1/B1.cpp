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
int p,t;

void solve() {
    cin >>p;
    vector<int> ans;
    int sum=0;
    for(int i=2;1ll*i*i<=p;i++) {
        if((p%i)==0) {
            while((p%i)==0) {
                ans.push_back(i);
                sum +=i;
                p /=i;
            }
        }
    }
    if(p>1) {
        ans.push_back(p);
        sum +=p;
    }
    if(sum<=41) {
        int ct1 = 41-sum;
        for(int i=0;i<ct1;i++) {
            ans.push_back(1);
        }
        cout <<sz(ans) <<" ";
        for(int i=0;i<sz(ans);i++) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}