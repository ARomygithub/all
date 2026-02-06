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

const int mxn=5e5;
int n,k;
string s;

void solve() {
    cin >>n >>k;
    cin >>s;
    vector<pii> bl;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && s[j]==s[i]) {
            j++;
        }
        bl.push_back({j-i,s[i]-'0'});
        i = j;
    }
    int ct = 0;
    rep(i,0,sz(bl)) {
        ct += bl[i].se==1;
        if(ct==k) {
            swap(bl[i],bl[i-1]);
            break;
        }
    }
    rep(i,0,sz(bl)) {
        rep(j,0,bl[i].fi) {
            cout <<(char)('0'+bl[i].se);
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}