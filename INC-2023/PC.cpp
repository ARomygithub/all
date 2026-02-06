#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
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

const int mxn=2e5+50;
int n;
int num[mxn];
int ctp=0,ctn=0;

void solve() {
    cin >>n;
    rep(i,0,n) {
        char qt; int x;
        cin >>qt >>x;
        if(qt=='+') {
            num[x]++;
            if(num[x]==0) {
                ctn--;
            } else {
                ctp++;
            }
            if(num[x]==2) {
                int u=x;
                while(num[u]==2) {
                    num[u] -=2;
                    ctp -=2;
                    num[u+1] +=1;
                    if(num[u+1]==0) {
                        ctn--;
                    } else {
                        ctp++;
                    }
                    u++;
                }
            }
        } else {
            num[x]--;
            if(num[x]==0) {
                ctp--;
            } else {
                ctn++;
            }
            if(num[x]==-2) {
                int u=x;
                while(num[u]==-2) {
                    num[u] +=2;
                    ctn -=2;
                    num[u+1] -=1;
                    if(num[u+1]==0) {
                        ctp--;
                    } else {
                        ctn++;
                    }
                    u++;
                }
            }
        }
        if(ctp==0 && ctn==0) {
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}