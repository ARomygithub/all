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

const int mxn=500;
int n;
int p[mxn],q[mxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int a, int b) {
    return a + rng()%(b-a+1);
}

void solve() {
    cin >>n;
    // n = rnd(1,500);
    rep(i,0,n) {
        cin >>p[i]; p[i]--;
    }
    rep(i,0,n) {
        cin >>q[i]; q[i]--;
    }
    // rep(i,0,n) {
    //     p[i] = i;
    //     q[i] = i;
    // }
    // shuffle(p,p+n,rng);
    // shuffle(q,q+n,rng);
    vector ans(n, vector<char>(n, '0'));
    rep(i,1,n) {
        rep(j,i,n) {
            ans[p[j]][q[n-i]] = '1';
        }
        // cout <<p[i] <<" " <<q[n-1] <<"\n";
    } 
    rep(i,0,n) {
        rep(j,0,n) {
            cout <<ans[i][j];
        }
        cout <<"\n";
    }
    // vector<string> vr,vc;
    // rep(i,0,n) {
    //     string temp = "";
    //     rep(j,0,n) {
    //         temp +=ans[i][j];
    //     }
    //     vr.push_back(temp);
    // }
    // rep(j,0,n) {
    //     string temp = "";
    //     rep(i,0,n) {
    //         temp += ans[i][j];
    //     }
    //     vc.push_back(temp);
    // }
    // rep(i,0,n-1) {
    //     assert(vr[p[i]]<vr[p[i+1]]);
    // }
    // rep(i,0,n-1) {
    //     assert(vc[q[i]]<vc[q[i+1]]);
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}