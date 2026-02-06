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
const double eps = 1e-6;
int n,l,t;
int a[mxn];

void solve() {
    cin >>n >>l;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<double> t1(n+2), t2(n+2);
    t1[0] = 0.0;
    rep(i,1,n+2) {
        int jrk = (i==n+1?l:a[i-1])-(i-1==0?0:a[i-2]);
        t1[i] = t1[i-1] + 1.0*jrk/i;
        // cout <<fixed <<setprecision(8) <<t1[i] <<" t1\n";
    }
    t2[n+1] = 0.0;
    per(i,n,-1) {
        int jrk = (i==n?l:a[i])-(i==0?0:a[i-1]);
        t2[i] = t2[i+1] + 1.0*jrk/(n+1-i);
        // cout <<fixed <<setprecision(8) <<t2[i] <<" t2 \n";
    }
    rep(i,0,n+1) {
        if(t1[i+1]>t2[i+1]) {
            int jrk = (i+1==n+1?l:a[i])-(i==0?0:a[i-1]);
            double li = max(t2[i+1],t1[i]), ri = min(t2[i],t1[i+1]);
            // cout <<"jrk " <<jrk <<endl;
            // cout <<fixed <<setprecision(8) <<li <<" " <<ri <<endl;
            double ans = li;
            while(ri-li>eps) {
                // cout <<fixed <<setprecision(8) <<li <<" " <<ri <<endl;
                double tf = (li+ri)/2;
                double sm = (tf-t1[i])*(i+1) + (tf-t2[i+1])*(n-i+1);
                if(sm>=1.0*jrk) {
                    ans = tf;
                    ri = tf;
                } else {
                    li = tf;
                }
            }
            cout <<fixed <<setprecision(8) <<ans <<"\n";
            return;
        }
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