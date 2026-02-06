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

const int mxn=1e6;
int n,t;
string s;

void solve() {
    cin >>n;
    cin >>s;
    vi v;
    for(int i = 0;i<n;) {
        int j = i;
        int cur = 0;
        while(j<n && s[j]==s[i]) {
            cur++;
            j++;
        }
        v.push_back(cur);
        i = j;
    }
    if(s[n-1]==s[0]) {
        if(sz(v)>1) {
            v[0] += v.back();
            v.pop_back();
        }
    }
    int cto=0,cte=0;
    rep(i,0,sz(v)) {
        if(i%2) {
            cte += (v[i]>1);
        } else {
            cto += (v[i]>1);
        }
    }
    if(cte>0 && cto>0) {
        cout <<"NO\n";
        return;
    }
    if((sz(v)%2)==0 && (cto+cte>0)) {
        cout <<"YES\n";
    } else {
        if(sz(v)==1) {
            cout <<"YES\n";
            return;
        }
        cout <<"NO\n";
    }
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