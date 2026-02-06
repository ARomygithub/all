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
int n,t;

void solve() {
    cin >>n;
    if((n%2)==0) {
        cout <<"1 " <<n/2 <<"\n";
        return;
    }
    for(int i=1;i<=30;i++) {
        for(int j=1;j<=30;j++) {
            int m=n;
            if((m%i)!=0) continue;
            m /=i;
            if((m%j)!=0) continue;
            m /=j;
            ll temp1=1,temp2=1;
            ll ct1=0,ct2=0;
            while(ct1<j-1) {
                ct1++;
                temp1 *=i;
                if(temp1>m) {
                    break;
                }
            }
            while(ct2<i-1) {
                ct2++;
                temp2 *=j;
                if(temp2>m) {
                    break;
                }
            }
            if(ct1<j-1 || ct2<i-1) {
                continue;
            }
            if(temp1+temp2==1ll*m) {
                cout <<i <<" " <<j <<"\n";
                return;
            }
        }
    }
    cout <<"-1\n";
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