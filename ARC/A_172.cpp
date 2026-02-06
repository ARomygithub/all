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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxk=1e3,mxa=26;
int n,m,k;
int a[mxk];
int ct[mxa];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,k) {
        cin >>a[i];
        ct[a[i]]++;
    }
    if(n>m) swap(n,m);
    auto trying = [&](int n1, int m1) -> void {
        
    };
    per(i,mxa-1,-1) {
        if(ct[i]) {
            if(n < (1<<i)) {
                cout <<"No\n";
                return;
            }
            int atas = n/(1<<i);
            int kanan = (ct[i]+atas-1)/atas;
            m -= (1<<i)*kanan;
            if(kanan*atas>ct[i]) {
                trying(n-(1<<i)*atas,(kanan-1)*(1<<i));
                trying(n-(1<<i)*(ct[i]%atas),(1<<i));
            } else {
                trying(n-(1<<i)*atas,kanan*(1<<i));
            }
            ct[i] = 0;
            if(n>m) swap(n,m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}