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

const int mxn=2e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    if(n%2) {
        int mid = (n+1)/2;
        int idx=-1;
        for(int i=0;i<n;i++) {
            if(a[i]==mid) {
                idx = i;
                break;
            }
        }
        int ans=(n-1)/2;
        for(int i=idx,j=idx,vi=mid-1,vj=mid+1;i>=0&&j<n;) {
            while(i>=0 && a[i]!=vi) {
                i--;
            }
            if(i<0) break;
            vi--;
            while(j<n && a[j]!=vj) {
                j++;
            }
            if(j==n) break;
            vj++;
            ans--;
        }
        cout <<ans <<"\n";
    } else {
        int l=-1,r=-1;
        for(int i=0;i<n;i++) {
            if(a[i]==(n/2)) {
                l=i;
            }
            if(a[i]==(n/2)+1) {
                r=i;
            }
        }
        int ans=n/2;
        if(l>r) {
            cout <<ans <<"\n";
            return;
        }
        ans--;
        for(int i=l-1,j=r+1,vi=(n/2)-1,vj=(n/2)+2;i>=0&&j<n;) {
            while(i>=0 && a[i]!=vi) {
                i--;
            }
            if(i<0) break;
            vi--;
            while(j<n && a[j]!=vj) {
                j++;
            }
            if(j==n) break;
            vj++;
            ans--;            
        }
        cout <<ans <<"\n";
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