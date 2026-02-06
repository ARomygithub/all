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

const int mxn=140582, mxb=187126;
int n;
ll b[mxn];
/*
a1 = k1*a2 + b1
a2 = k2*a3 + b2
a3 = k3*a4 + b3
..
an = kn*a1 + bn

bi <= ai, a(i+1)
[0,0,..,0] <--> [1,1,..,1]
bi = ai, ai<a(i+1). a(i-1) = k(i-1)*bi + b(i-1) [syarat b(i-1)<bi or ai].
naik, naik, naik, hingga bj = aj (turun).
kasus b(i-1)>=bi : artinya fase naik

1 3 1 0

1 3 5 2

_ 3 _ _

4 4

b sama semua artinya gada a(i+1) > ai. artinya a sama semua. Sama semua artinya b 0 semua
 */

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>b[i];
    }
    rep(i,0,n) {
        if(b[i]> b[(i-1+n)%n]) {
            cout <<"YES\n";
            vector<ll> ans(n,-1);
            ans[i] = b[i];
            rep(j,1,n) {
                int now =  (i-j+n)%n;
                int prv = (now-1+n)%n;
                int nxt = (now+1)%n;
                // b[now] + k.ans[nxt] > b[prv]
                ll k = 0;
                if(b[prv]>b[now]) {
                    max_self(k, (b[prv]-b[now])/ans[nxt] + 1);
                }
                ans[now] = b[now] + k*ans[nxt];
            }
            rep(j,0,n) {
                cout <<ans[j] <<" \n"[j==n-1];
            }
            return;
        }
    }
    if(b[0]==0) {
        cout <<"YES\n";
        vi ans(n,1);
        rep(i,0,n) {
            cout <<ans[i] <<" \n"[i==n-1];
        } 
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}