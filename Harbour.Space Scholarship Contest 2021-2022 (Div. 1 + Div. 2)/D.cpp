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

const int mxn=1e5;
int t;
string s1,s2;

void solve() {
    cin >>s1;
    cin >>s2;
    int j1=0;
    int j2 = 0;
    for(int i1=0;i1<sz(s1);i1++) {
        // if(s1[i1]==s2[0]) {
        //     if(i1%2) {
        //         max_self(j2, 1);
        //     } else {
        //         max_self(j1, 1);
        //     }
        // }
        if((i1%2)==(j1%2) && j1<sz(s2) && s1[i1]==s2[j1]) {
            j1++;
        }
        if((i1%2)!=(j2%2) && j2<sz(s2) && s1[i1]==s2[j2]) {
            j2++;
        }
    }
    if(((sz(s2)%2)==(sz(s1)%2) && j1==sz(s2)) || ((sz(s2)%2)!=(sz(s1)%2) && j2==sz(s2))) {
        cout <<"YES\n";
        return;
    } else {
        cout <<"NO\n";
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