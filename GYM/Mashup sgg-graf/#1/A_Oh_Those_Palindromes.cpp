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
int t;
string s;

void solve() {
    int n; cin >>n;
    cin >>s;
    // vector<char> v(26,0);
    // rep(i,0,sz(s)) {
    //     v[s[i]-'a']++;
    // }
    // string awl = "";
    // string mid = "";
    // rep(i,0,26) {
    //     rep(j,0,v[i]/2) {
    //         awl += (char)('a'+i);
    //     }
    //     if(v[i]%2) {
    //         mid += (char)('a'+i);
    //     }
    // }
    // string ans = awl + mid;
    // reverse(all(awl));
    // ans += awl;
    sort(all(s));
    cout <<s <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}