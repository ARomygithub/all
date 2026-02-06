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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=500,mxc=25e4;
int h,w,n,m;
int a[mxn][mxn], b[mxn][mxn], c[mxn][mxn];
int len;
pii sta1[mxc+1],sta2[mxc+1];
pii ansA, ansB;
map<pii,int> f;

bool pipei() {
    // cout <<"pipei\n";
    f.clear();
    rep(i,2,len+1) {
        f[sta1[i]] = 1;
    }
    int cnt = 0;
    pii ww;
    rep(i,2,len+1) {
        pii tmp = sta2[i];
        tmp.fi -= sta2[1].fi-sta1[1].fi;
        tmp.se -= sta2[1].se-sta1[1].se;
        // cout <<tmp.fi <<" " <<tmp.se <<"\n";
        if(f[tmp]) {
            f[tmp] = 0;
        } else {
            ++cnt, ww = tmp;
        }
    }
    if(cnt!=1) return 0;
    rep(i,2,len+1) {
        if(f[sta1[i]]) {
            ansA = sta1[i];
            break;
        }
    }
    ansB = ww;
    return 1;
}

bool check() {
    len = 0;
    rep(i,0,h) {
        rep(j,0,h) {
            if(a[i][j]) {
                sta1[++len] = {i,j};
            }
        }
    }
    len = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            if(b[i][j]) {
                sta2[++len] = {i,j};
            }
        }
    }
    if(len==1) {
        ansA = sta1[1];
        ansB = ansA;
        ansB.se++;
        return 1;
    }
    if(pipei()) return 1;
    swap(sta1[1],sta1[2]);
    if(pipei()) return 1;
    swap(sta1[1],sta1[2]);
    rep(i,1,(len/2)+1) {
        swap(sta1[i], sta1[len-i+1]);
    }
    rep(i,1,(len/2)+1) {
        swap(sta2[i], sta2[len-i+1]);
    }
    if(pipei()) return 1;
    swap(sta1[1],sta1[2]);
    if(pipei()) return 1;
    return 0;
}

void rotate() {
    rep(i,0,n) {
        rep(j,0,n) {
            c[i][j] = b[n-j-1][i];
        }
    }
    rep(i,0,n) {
        rep(j,0,n) {
            b[i][j] = c[i][j];
        }
    }
}

void print() {
    cout <<ansA.fi <<" " <<ansA.se <<"\n";
    cout <<ansB.fi <<" " <<ansB.se <<"\n";
}

void solve() {
    cin >>h >>w;
    rep(i,0,h) {
        string s; cin >>s;
        rep(j,0,w) {
            a[j][i] = s[j]=='o';
        }
    }
    h = w = max(h,w);
    cin >>n >>m;
    rep(i,0,n) {
        string s; cin >>s;
        rep(j,0,m) {
            b[j][i] = s[j]=='o';
        }
    }
    n = m = max(n,m);
    rep(i,0,4) {
        // cout <<"i " <<i <<"\n";
        if(check()) {
            print();
            return;
        }
        rotate();
    }          
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}