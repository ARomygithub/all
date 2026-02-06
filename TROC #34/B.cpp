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
int n;
int ct[mxn+1];

void solve() {
    cin >>n;
    ll ans=0;
    int mx=0;
    for(int i=0;i<n;i++) {
        int a; cin >>a;
        max_self(mx,a);
        ct[a]++;
    }
    int j=mx-1;
    while(j>0 && ct[j]==0) {
        j--;
    }
    for(int i=mx;i>0;i--) {
        if(j==0 && ct[i]>0) {
            if(ct[i]>=2) {
                ans +=1ll*ct[i]*i;
            } else {
                ans +=2ll*i-1;
            }
            break;
        }
        while(ct[i]) {
            if(ct[i]>=2) {
                int temp = (ct[i]/2)*2;
                ct[i] -=temp;
                ct[j] +=temp;
                ans +=1ll*temp*(i-j);
                if(ct[i]==0)  {
                    j--;
                    while(j>0 && ct[j]==0) {
                        j--;
                    }
                }
            } else {
                int temp = min(i-j,ct[j]);
                ct[i]--;
                ct[i-temp]++;
                ct[j] -=temp;
                ct[j-1] +=temp;
                ans +=1ll*temp*2;
                j = j-1;
                // if(i-temp>j && ct[j]>0) {
                //     // ttp di j
                // } else if(i-temp==j) {
                //     j = j-1;
                // } else if(ct[j]==0) {
                //     j = j-1;
                // }
            }
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