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

const int mxn=10;
int n,k;
string s;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>n >>k;
    // n = 10; k = 10;
    cin >>s;
    // s = "";
    // rep(i,0,n) {
    //     s += (char)(rng()%26 + 'a');
    // }
    // vector<int> v(n);
    // iota(v.begin(),v.end(),0);
    int ans = 0;
    sort(s.begin(), s.end());
    // set<string> st;
    do {
        string si = s;
        // rep(i,0,n) {
        //     si += s[v[i]];
        // }
        bool ok = 1;
        rep(i,0,n-k+1) {
            bool pal = 1;
            for(int d=i,b=i+k-1;d<b&&pal;d++,b--) {
                if(si[d]!=si[b]) {
                    pal = 0;
                }
            }
            if(pal) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            // st.insert(si);
            ans++;
        }
    } while(next_permutation(s.begin(),s.end()));
    // cout <<sz(st) <<"\n";
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}