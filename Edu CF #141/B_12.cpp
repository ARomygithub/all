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
int n,m,k;

void solve() {
    cin >>n >>m >>k;
    vector<int> v(k);
    for(int i=0;i<k;i++) {
        cin >>v[i];
    }
    ll ans = 0;
    for(int i=0;i<n;i++) {
        vector<int> a(m);
        for(int j=0;j<m;j++) {
            cin >>a[j];
            vector<int> v_new;
            v_new.push_back(a[j]);
            for(int l=0;l<k;l++) {
                if(v[l]==a[j]) {
                    ans += l+1;
                } else {
                    v_new.push_back(v[l]);
                }
            }
            v.swap(v_new);
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