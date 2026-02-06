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

const int mxn=1e2;
int n;
int d[mxn];

bool repdig(int num, int dig) {
    bool flag=1;
    while(num) {
        if((num%10)==dig) {
            num /=10;
        } else {
            flag = 0;
            break;
        }
    }
    return flag;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>d[i];
    }
    int ans=0;
    rep(i,1,n+1) {
        rep(j,1,d[i-1]+1) {
            rep(k,1,10) {
                if(repdig(i,k) && repdig(j,k)) {
                    ans++;
                }
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