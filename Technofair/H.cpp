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
int n,m;

void solve() {
    cin >>n >>m;
    vector mat(n, vector<int>(m));
    rep(i,0,n) {
        string s; cin >>s;
        rep(j,0,m) {
            mat[i][j] = s[j]-'0';
        }
    }
    if(n>=4 && m>=4) {
        cout <<"-1\n";
        return;
    }
    if(min(n,m)==1) {
        cout <<"0\n";
        return;
    }
    if(n<m) {
        vector mat2(m, vector<int>(n));
        rep(j,0,m) {
            rep(i,0,n) {
                mat2[j][i] = mat[i][j];
            }
        }
        mat.swap(mat2);
        swap(n,m);
    }
    vector<int> ct(1<<m, 0);
    rep(bit,0,sz(ct)) {
        int cti = 0;
        rep(j,0,m) {
            int cur = (bit>>j)&1;
            cti += (mat[0][j]!=cur);
        }
        ct[bit] = cti;
    }
    auto ctf = [&](int i, int bit) -> int {
        int cti = 0;
        rep(j,0,m) {
            int cur = (bit>>j)&1;
            cti += (mat[i][j]!=cur);
        }
        return cti;      
    };
    auto isOk = [&](int bit, int newbit) -> bool {
        rep(j,0,m-1) {
            int cti = (bit>>j)&1;
            cti += ((bit>>(j+1))&1);
            cti += ((newbit>>j)&1);
            cti += ((newbit>>(j+1))&1);
            if((cti%2)==0) {
                return false;
            }
        }
        return true;
    };
    rep(i,1,n) {
        vector<int> ct_new(1<<m, 1e9);
        rep(newbit,0,sz(ct)) {
            int cti = ctf(i,newbit);
            rep(bit,0,sz(ct)) {
                if(isOk(bit,newbit)) {
                    min_self(ct_new[newbit], cti+ct[bit]);
                }
            }
        }
        ct.swap(ct_new);
    }
    int ans = 1e9;
    rep(i,0,sz(ct)) {
        min_self(ans, ct[i]);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}