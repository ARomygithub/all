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

const int mxn=3e5;
int n;

void solve() {
    cin >>n;
    vector<ll> v;
    v.push_back(0);
    int l = 0;
    while(n--) {
        int qt; cin >>qt;
        if(qt==1) {
            int le; cin >>le;
            v.push_back(v.back()+le);
        } else if(qt==2) {
            l++;
        } else {
            int k; cin >>k;
            cout <<v[k-1 + l] - v[l] <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}