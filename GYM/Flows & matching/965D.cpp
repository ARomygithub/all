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
int n,l;
int a[mxn+1];

void solve() {
    cin >>n >>l;
    a[0] = 1;
    for(int i=1;i<=n-1;i++) {
        cin >>a[i];
    }
    a[n] = 1;
    int ans = 0;
    int li=0, ri=1e9;
    while(li<=ri) {
        int mid = (li+ri)/2;
        int idxr=0;
        int ct=a[0];
        int mx_diff=0;
        for(int i=0;i<=n;i++) {
            while(idxr+1<=n && ct-a[i]<mid) {
                idxr++;
                ct +=a[idxr];
            }
            max_self(mx_diff, idxr-i);
            if(ct-a[i]<mid) {
                break;
            }
            ct -=a[i];
        }
        if(mx_diff>l) {
            ri = mid-1;
        } else {
            ans = mid;
            li = mid+1;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}