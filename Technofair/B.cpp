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
int n;
string s,t;

void solve() {
    cin >>s;
    cin >>t;
    vector<int> pos;
    rep(i,0,sz(s)) {
        pos.push_back(i);
    }
    int ans = sz(s);
    do {
        int ct = 0;
        rep(i,0,sz(s)) {
            ct += (s[pos[i]]!=t[i]);
        }
        int jrk = 0;
        vector<int> pos2(pos.begin(),pos.end());
        vector<int> inv(sz(pos));
        rep(i,0,sz(pos2)) {
            inv[pos2[i]] = i;
        }
        rep(i,0,sz(pos2)) {
            if(pos2[i]!=i) {
                jrk++;
                int i2 = inv[i];
                swap(inv[i], inv[pos2[i]]);
                swap(pos2[i], pos2[i2]);
            }
        }
        ct += jrk;
        min_self(ans, ct);
    } while(next_permutation(pos.begin(),pos.end()));
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}