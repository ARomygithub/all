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
int n,qq,t;
int a[mxn];

bool chk(int li, int ri) {
    vector<int> p(ri-li+1);
    rep(i,li,ri+1) {
        p[i-li] = a[i];
    }
    sort(p.begin(),p.end());
    rep(i,0,sz(p)-5) {
        rep(j,i+1,i+6) {
            rep(k,j+1,i+6) {
                int q[3]; int id=0;
                rep(m,i+1,i+6) {
                    if(m!=j && m!=k) {
                        q[id] = p[m]; id++;
                    }
                }
                if(p[i]+p[j]>p[k] && q[0]+q[1]>q[2]) {
                    return 1;
                }
            }
        }
    }
    bool bisa = 0;
    for(int i=0;i<sz(p)-2;i++) {
        if(p[i]+p[i+1]>p[i+2]) {
            if(bisa) {
                return 1;
            } else {
                bisa = 1;
                i +=2;
            }
        }
    }
    return false;
}

void solve() {
    cin >>n >>qq;
    rep(i,0,n) {
        cin >>a[i];
    }
    while(qq--) {
        int li,ri; cin >>li >>ri;li--,ri--;
        if(ri-li+1 >=48) {
            cout <<"YES\n";
        } else {
            if(chk(li,ri)) {
                cout <<"YES\n";
            } else {
                cout <<"NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // vector<int> v(2,1);
    // rep(i,3,1e5) {
    //     v.push_back(v[sz(v)-1]+v[sz(v)-2]);
    //     cout <<i <<" " <<v.back() <<"\n";
    // }
    solve();
}