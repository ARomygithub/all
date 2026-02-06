#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

template<class T> int sgn(T x) { return (x>0) - (x<0); }
template<class T>
struct Point
{
    using P = Point<ll>;
    T x, y;
    explicit Point(T x=0, T y=0): x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const {return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }

};
using P = Point<ll>;

const int mxn = 2e5;
P poly[mxn];
int n;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>poly[i].x >>poly[i].y;
    }
    int ans = 0;
    for(int i=0;i<n-2;) {
        int j = i+2;
        while(j<n) {
            bool ok = poly[j-2].cross(poly[j-1],poly[j]) < 0;
            if(!ok) break;
            j++;
        }
        rep(k,i+2,j) {
            while(true) {
                // cout <<i <<" " <<k <<endl;
                bool ok = poly[k-1].cross(poly[k],poly[i])<0 && poly[k].cross(poly[i],poly[i+1]) < 0; 
                if(ok) {
                    break;
                }
                i++;
            }
            max_self(ans, k-i+1);
        }
        i = j-1;
    }
    cout <<ans <<"\n";
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}