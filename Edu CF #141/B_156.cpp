#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
int t;

double getDist(int x1, int y1, int x2, int y2) {
    return sqrt(1.0*(1ll*(x2-x1)*(x2-x1)+1ll*(y2-y1)*(y2-y1)));
}

void solve() {
    int px,py,ax,ay,bx,by;
    cin >>px >>py;
    cin >>ax >>ay;
    cin >>bx >>by;
    double pb = getDist(px,py,bx,by);
    double pa = getDist(px,py,ax,ay);
    double oa = getDist(0,0,ax,ay);
    double ob = getDist(0,0,bx,by);
    double ab = getDist(ax,ay,bx,by);
    double ans = 1e5;
    min_self(ans, max(pb,ob));
    min_self(ans, max(pa,oa));
    double temp = max(ab/2,min(ob,oa));
    max_self(temp, min(pb,pa));
    min_self(ans, temp);
    cout <<fixed <<setprecision(7) <<ans <<"\n";
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