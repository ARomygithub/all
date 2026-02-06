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

const int mxn=3e5;
int n,m;
int p[mxn],c[mxn];

void solve() {
    cin >>n >>m;
    int awl = 0;
    vector v(m, vi());
    rep(i,0,n) {
        cin >>p[i] >>c[i];
        awl += (p[i]==1);
        v[p[i]-1].push_back(c[i]);
    }
    rep(i,0,m) {
        sort(all(v[i]));
    }
    ll ans = 1e15;
    rep(w,awl,n+1) {
        multiset<int> ms;
        int ct = awl;
        ll temp = 0;
        rep(i,1,m) {
            rep(j,0,sz(v[i])) {
                if(sz(v[i])-j <w) {
                    ms.insert(v[i][j]);
                } else {
                    temp += v[i][j];
                    ct++;
                } 
            }
        }
        while(ct<w) {
            auto it = ms.begin();
            temp += *it;
            ms.erase(it);
            ct++;
        }
        min_self(ans, temp);
    } 
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}