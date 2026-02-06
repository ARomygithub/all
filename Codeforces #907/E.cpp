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

const int mxn=1e5;
int n,k,t;
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pii> v;
    int ct=0;
    for(int i=0;i<n;) {
        if(i+1<n && __gcd(a[i],a[i+1])==1) {
            ct=2;
            int j = i+1;
            while(j+1<n && __gcd(a[j],a[j+1])==1) {
                ct++;
                j++;
            }
            v.push_back(ct);
            i = j;
        } else {
            i++;
        }
    }
    int ans=0;
    sort(v.begin(),v.end(),greater<int>());
    vector<int> v2;
    for(int vv : v) {
        if(k) {
            if(vv==2) {
                k--;
            } else {
                int kbisa = (vv-1)/2;
                int temp = min(k,kbisa);
                k -=temp;
                ans +=vv-1-(temp*2);
                if(temp==kbisa && (vv%2)==0) {
                    v2.push_back(2);
                    ans -=1;
                }
            }
        } else {
            ans +=vv-1;
        }
    }
    ans +=max(sz(v2)-k,0);
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