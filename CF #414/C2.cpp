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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
int n;
string s,t;

void solve() {
    cin >>s >>t;
    n = s.length();
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int ls = 0, rs=(n+1)/2 -1;
    int lt = n-1-(n/2)+1, rt=n-1;
    vector<char> ans(n);
    int l=0,r=n-1;
    rep(i,0,n) {
        if(i%2) {
            if(t[rt]>s[ls]) {
                ans[l] =t[rt];
                l++, rt--;
            } else {
                ans[r] = t[lt];
                r--, lt++;
            }
        } else {
            if(s[ls] < t[rt]) {
                ans[l] = s[ls];
                l++, ls++;
            } else {
                ans[r] = s[rs];
                r--, rs--;
            }
        }
    }
    rep(i,0,n) {
        cout <<ans[i];
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}