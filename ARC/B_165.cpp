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

const int mxn=2e5;
int n,k;
int p[mxn];

void solve() {
    cin >>n >>k;
    for(int i=0;i<n;i++) {
        cin >>p[i];
    }
    int ct=1;
    bool flag=false;
    int tempk= 0;
    for(int i=1;i<n;i++) {
        if(p[i]>p[i-1]) {
            ct++;
        } else {
            ct = 1;
        }
        if(ct>=k) {
            flag = true;
            break;
        }
        if(i==n-k-1) {
            tempk = ct;
        }
    }
    if(!flag) {
        bool useFront = true;
        if(n!=k) {
            for(int i=n-k;i<n-k+k-tempk;i++) {
                if(p[i]<p[n-k-1]) {
                    useFront = false;
                    break;
                }
            }
        } else {
            useFront = false;
        }
        if(useFront) {
            sort(p+n-k,p+n-tempk);
        } else {
            sort(p+n-k,p+n);
        }
    }
    for(int i=0;i<n;i++) {
        cout <<p[i] <<" \n"[i==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}