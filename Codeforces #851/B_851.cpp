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
        cout <<n/2 <<" " <<n/2 <<"\n";
        return;
    }
    int x = n/2;
    if((n%20)==19) {
        int xb=x+1;
        int diff=0;
        int pow10=1;
        for(int i=0;i<9;i++) {
            pow10 *=10;
        }
        int ansa=0, ansb=0;
        for(int i=9;i>=0;i--) {
            if(abs(x/pow10-xb/pow10)>1) {
                if(diff>0) {
                    ansa +=4*pow10;
                    ansb +=5*pow10;
                    diff +=-1;
                } else {
                    ansa +=5*pow10;
                    ansb +=4*pow10;
                    diff +=1;
                }
                x %=pow10;
                xb %=pow10;
            } else {
                diff +=x/pow10 - xb/pow10;
                ansa +=x/pow10 * pow10;
                ansb +=xb/pow10 * pow10;
                x %=pow10;
                xb %=pow10;
            }
            pow10 /=10;
        }
        cout <<ansa <<" " <<ansb <<"\n";
    } else {
        cout <<x <<" " <<x+1 <<"\n";
        return;
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