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
int r,c,t;
int n=12;

void solve() {
    cin >>r >>c;
    int ct=0;
    string ans = "";
    if(c<=6) {
        if(c==3 && (r==3 || r==10)) {
            cout <<ct <<"\n";
            cout <<ans <<"\n";
            return;
        }
        if(c==1 && (r==9 || r==10)) {
            ct +=r-3;
            for(int i=0;i<r-3;i++) {
                ans +='U';
            }
            ct +=2;
            ans +="RR";
        } else {
            if(c<=5) {
                ct +=5-c;
                for(int i=0;i<5-c;i++) {
                    ans +='R';
                }
            } else {
                ct +=c-5;
                for(int i=0;i<c-5;i++) {
                    ans +='L';
                }
            }
            c = 5;
            if(r<=3) {
                ct +=3-r;
                for(int i=0;i<3-r;i++) {
                    ans +='D';
                }
            } else {
                ct +=r-3;
                for(int i=0;i<r-3;i++) {
                    ans +='U';
                }
            }
            ct +=2;
            ans +="LL";
        }
        cout <<ct <<"\n";
        cout <<ans <<"\n";
    } else {
        if(c==10 && (r==3 || r==10)) {
            cout <<ct <<"\n";
            cout <<ans <<"\n";
            return;
        }
        if(c==12 && (r==9 || r==10)) {
            ct +=r-3;
            for(int i=0;i<r-3;i++) {
                ans +='U';
            }
            ct +=2;
            ans +="LL";
        } else {
            if(c>=8) {
                ct +=c-8;
                for(int i=0;i<c-8;i++) {
                    ans +='L';
                }
            } else {
                ct +=8-c;
                for(int i=0;i<8-c;i++) {
                    ans +='R';
                }
            }
            c = 8;
            if(r<=3) {
                ct +=3-r;
                for(int i=0;i<3-r;i++) {
                    ans +='D';
                }
            } else {
                ct +=r-3;
                for(int i=0;i<r-3;i++) {
                    ans +='U';
                }
            }
            ct +=2;
            ans +="RR";
        }
        cout <<ct <<"\n";
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