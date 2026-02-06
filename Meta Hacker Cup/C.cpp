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

const int mxn=3e5;
int n,t;
int a[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n*2-1;i++) {
        cin >>a[i];
    }
    sort(a,a+n*2-1);
    if(n==1) {
        cout <<"1\n";
        return;
    }
    int ans=2e9;
    int sumi = a[n-2]+a[n-1];
    int l=n-3, r=n;
    bool flag=true;
    int temp=-1;
    while(l>=0 || r<=n*2-2) {
        if(l<0) {
            if(temp==-1) {
                temp = sumi-a[r];
                if(temp<=0) {
                    flag = false;
                    break;
                }
                r++;
            } else {
                flag = false;
                break;
            }
        } else if(r>n*2-2) {
            flag = false;
            break;
        } else if(a[l]+a[r]!=sumi) {
            if(temp==-1) {
                temp = sumi-a[r];
                if(temp<=0) {
                    flag=false;
                    break;
                }
                r++;
            } else {
                flag = false;
                break;
            }
        } else {
            l--,r++;
        }
    }
    if(flag) {
        ans = temp;
        cout <<ans <<"\n";
        return;
    }
    sumi = a[n-2]+a[n];
    l = n-3, r=n+1;
    flag=true;
    temp=sumi-a[n-1];
    while(l>=0 && r<=n*2-2) {
        if(a[l]+a[r]!=sumi) {
            flag=false;
            break;
        } else {
            l--,r++;
        }
    }
    if(flag) {
        ans = temp;
        cout <<ans <<"\n";
        return;
    }
    sumi = a[n-1]+a[n];
    l = n-2,r=n+1;
    flag = true;
    temp=-1;
    while(l>=0 || r<=n*2-2) {
        if(l<0) {
            flag = false;
            break;
        } else if(r>n*2-2) {
            if(temp==-1) {
                // cout <<"TES1\n";
                temp = sumi-a[l];
                if(temp<=0) {
                    flag=false;
                    break;
                }
                l--;
            } else {
                flag=false;
                break;
            }
        } else if(a[l]+a[r]!=sumi) {
            if(temp==-1) {
                // cout <<"TES2\n";
                temp = sumi-a[l];
                if(temp<=0) {
                    flag=false;
                    break;
                }
                l--;
            } else {
                flag = false;
                break;
            }
        } else {
            l--,r++;
        }
    }
    if(flag) {
        ans = temp;
        cout <<ans <<"\n";
        return;
    }
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}