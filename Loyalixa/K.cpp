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
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
ll n,m,x,y,t;

void solve() {
    cin >>n >>m >>x >>y;
    if(n>m) {
        swap(n,m);
        swap(x,y);
    }
    if(n>=3) {
        if(m==3) {
            if(x==2 && y==2) {
                cout <<"1\n";
            } else {
                cout <<"8\n";
            }
        } else {
            cout <<n*m <<"\n";
        }
    } else if(n==1) {
        cout <<"1\n";
    } else {
        int ans = (m+1)/2;
        if((m%2)!=0 && (y%2)==0) {
            ans--;
        }
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