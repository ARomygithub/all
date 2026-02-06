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

const int mxn=2e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = 0;
    vi v;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && a[j]==a[i]) {
            j++;
        }
        // while(j+1<n && a[j+1]==a[i]) {
        //     swap(a[j],a[j+1]);
        //     j++;
        // }
        v.push_back(a[i]);
        i = j;
    }
    pii p = {-1,-1};
    for(int i=0;i<sz(v);) {
        if(i+2<sz(v)) {
            if(p.fi==-1) {
                if(v[i]!=v[i+2]) {
                    ans++;
                    i++;
                } else {
                    ans += 2;
                    p = {v[i+1],v[i+2]};
                    i += 2;
                }
            } else {
                if(v[i+1]==p.fi || v[i+1]==p.se) {
                    p = {-1,-1};
                    i++;
                } else {
                    if(v[i+2]==p.fi || v[i+1]==p.se) {
                        ans += 2;
                        p = {v[i+1],v[i+2]};
                        i += 2;
                    } else {
                        i++;
                        ans++;
                        p = {-1,-1};
                    }
                }
            }
        } else {
            if(p.fi==-1) {
                if(i+1<sz(v)) {
                    if(v[i]!=v[i+1]) {
                        ans += 2;
                    } else {
                        ans++;
                    }
                } else {
                    ans++;
                }
            } else {
                if(i+1<sz(v)) {
                    if((v[i+1]==p.fi || v[i+1]==p.se)) {
                        ans += 1;
                    } else {
                        ans += 2;
                    }
                } else {
                    ans++;
                }
            }
            break;
        }
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