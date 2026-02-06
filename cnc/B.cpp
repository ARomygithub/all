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

const int mxn=1e5, mxa=1e9;
int x,n,t;

void solve() {
    string op;
    cin >>x >>n >>op;
    assert(x>0 && x<=mxa);
    if(op[0]=='A' || op[0]=='O') {
        vector<int> ans(n,x);
        for(int i=0;i<n;i++) {
            if(i==0) {
                cout <<ans[i];
            } else {
                cout <<" " <<ans[i];
            }
        }
        cout <<"\n";
    } else {
        if(n%2) {
            vector<int> ans(n,x);
            for(int i=0;i<n;i++) {
                if(i==0) {
                    cout <<ans[i];
                } else {
                    cout <<" " <<ans[i];
                }
            }
            cout <<"\n";            
        } else {
            // 0,1
            // x=1 masalah. oke
            int temp=0;
            int temp2 = 0;
            for(int j=0;j<31;j++) {
                if(x&(1<<j)) {
                    temp = 1<<j;
                    break;
                } else {
                    temp2 = 1<<j;
                }
            }
            if((x^temp) == 0) {
                if(temp2==0) {
                    temp2 = x*2;
                }
                assert((x^temp2)>0 && (x^temp2)<=mxa);
                vector<int> ans(n,x^temp2);
                ans[n-1] = temp2;
                assert(temp2>0 && temp2<=mxa);
                for(int i=0;i<n;i++) {
                    if(i==0) {
                        cout <<ans[i];
                    } else {
                        cout <<" " <<ans[i];
                    }
                }
                cout <<"\n";   
                return;                
            }
            assert((x^temp)>0 && (x^temp)<=mxa);
            assert((temp)>0 && temp<=mxa);
            vector<int> ans(n,x^temp);
            ans[n-1] = temp;
            for(int i=0;i<n;i++) {
                if(i==0) {
                    cout <<ans[i];
                } else {
                    cout <<" " <<ans[i];
                }
            }
            cout <<"\n";              
            // if(x!=1) {
            //     vector<int> ans(n,x^1);
            //     ans[n-1] = 1;
            //     for(int i=0;i<n;i++) {
            //         if(i==0) {
            //             cout <<ans[i];
            //         } else {
            //             cout <<" " <<ans[i];
            //         }
            //     }
            //     cout <<"\n";  
            // } else {
            //     vector<int> ans(n,x^2);
            //     ans[n-1] = 2;
            //     for(int i=0;i<n;i++) {
            //         if(i==0) {
            //             cout <<ans[i];
            //         } else {
            //             cout <<" " <<ans[i];
            //         }
            //     }
            //     cout <<"\n";             
            // }
        }
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