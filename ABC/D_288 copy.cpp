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
int n,k,q;
ll a[mxn+1];

void solve() {
    cin >>n >>k;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    cin >>q;
    vector<ll> c(n+1,0);
    for(int i=1;i<=n;i++) {
        c[i] = a[i]-a[i-1];
        if(i-k>0) {
            c[i] +=c[i-k];
        }
        // cout <<c[i] <<" ";
    }
    // cout <<"\n";
    while(q--) {
        int l,r; cin >>l >>r;
        if(k==1) {
            cout <<"Yes\n";
            continue;
        }
        bool flag=0;
        ll temp = 0;
        for(int j=r;j>r-k;j--) {
            if(j-k+1>=l) {
                ll temp2 = c[j-k+1];
                for(int i=l-1;i>=0;i--) {
                    if((i%k)==((j-k+1)%k)) {
                        temp2 -=c[i];
                        if((i%k)==(l%k)) {
                            temp2 +=a[l-1];
                        }
                        break;
                    }
                }
                temp +=temp2;
            }
            // cout <<"\n";
            // cout <<temp;
            if(temp!=1ll*a[j]) {
                flag=1;
                // cout <<temp <<" " <<a[j];
                cout <<"No\n";
                break;
            }
        }
        if(!flag) {
            cout <<"Yes\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}