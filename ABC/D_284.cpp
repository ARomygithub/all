#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mxa=3e6;
ll n;
int t;

void solve() {
    cin >>n;
    // ll _n = n;
    ll p,q;
    for(ll i=2;i*i<=n || i<=mxa;i++) {
        if(n%i==0) {
            // ans.push_back(i);
            int ct=0;
            while(n%i==0) {
                n /=i;
                ct++;
            }
            if(ct==1) {
                q = i;
                ll l=i+1, r=(ll)3e9;
                while(l<=r) {
                    ll mid = (l+r)/2;
                    if(mid*mid==n) {
                        p = mid;
                        break;
                    }
                    if(mid*mid<n) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                break;
            } else {
                p = i;
                q = n;
                break;
            }
        }
    }
    // if(n>1) q=n;
    // if(ans[1]*ans[1]*ans[0]==_n) {
    //     swap(ans[0],ans[1]);
    // }
    cout <<p <<" " <<q <<"\n";
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