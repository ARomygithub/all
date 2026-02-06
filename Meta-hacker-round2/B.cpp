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

const int mxn=2e6;
int n,t;
int a[mxn],b[mxn];

bool cek(int ans) {
    vector<int> v1(n),v2(n);
    for(int i=0;i<n;i++) {
        pii ab = {a[i],b[i]};
        int u = i;
        int diff=ans;
        while(diff>=n) {
            swap(ab.fi,ab.se);
            diff -=n;
        }
        if(i<diff) {
            swap(ab.fi,ab.se);
        }
        u = (i-diff+n)%n;
        v1[u] = ab.fi; v2[u]=ab.se;
    }
    bool ret=1;
    for(int i=0;i<n&&ret;i++) {
        if(2*(i+1)<n+1) {
            ret &= v1[i]<v2[i];
        } else if(2*(i+1)>n+1) {
            ret &= v1[i]>v2[i];
        }
        ret &=v1[i]==v2[n-1-i];
    }
    return ret;
}

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>a[i];
    }
    for(int i=0;i<n;i++) {
        cin >>b[i];
    }
    int k=n/2;
    if(n%2) {
        int mid=-1;
        for(int i=0;i<n;i++) {
            if(a[i]==b[i]) {
                mid = i;
                break;
            }
        }
        if(mid==-1) {
            cout <<"-1\n";
            return;
        }
        int ans=0;
        if(mid>=k) {
            ans +=mid-k;
        } else {
            ans +=mid+n-k;
        }
        if(cek(ans)) {
            cout <<ans <<"\n";
            return;
        }        
        ans +=n;
        if(cek(ans)) {
            cout <<ans <<"\n";
            return;
        }
        cout <<"-1\n";
    } else {
        // cout <<"-";
        // cout <<flush;
        int firstT=-1;
        for(int i=0;i<n;i++) {
            if(a[i]>b[i]) {
                firstT = i;
                break;
            }
        }
        int ans=0;
        if(firstT==-1) {
            ans++;
            firstT = n-1;
        }
        int mid=k;
        if(firstT>=mid) {
            ans +=firstT-mid;
        } else {
            ans +=firstT+n-mid;
        }
        // cout <<"-";
        // cout <<ans <<"\n";
        // cout <<flush;
        if(cek(ans)) {
            cout <<ans <<"\n";
            return;
        }
        ans +=n;
        if(cek(ans)) {
            cout <<ans <<"\n";
            return;
        }
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
        // cout <<flush;
    }
}