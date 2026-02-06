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
int wi[24];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        int w,x; cin >>w >>x;
        wi[x] +=w;
    }
    int ans=0;
    for(int i=0;i<24;i++) {
        int temp=0;
        for(int j=0;j<9;j++) {
            temp +=wi[(i+j)%24];
        }
        max_self(ans, temp);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}