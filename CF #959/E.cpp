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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int k,t;
int n[mxn];

void solve() {
    cin >>k;
    multiset<int> s;
    rep(i,0,k) {
        cin >>n[i];
        vector<int> p(n[i]-1);
        rep(j,0,n[i]-1) {
            cin >>p[j];
        }
        s.insert(n[i]);
    }
    int ans = 0;
    int bit = 19;
    while(bit>=0) {
        if(!sz(s)) break;
        auto it = (--s.end());
        if((*it)>=(1<<bit)) {
            ans += (1<<bit);
            int temp = (*it)-(1<<bit);
            s.erase(it);
            if(temp>0) {
                s.insert(temp);
            }
        }
        bit--;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}