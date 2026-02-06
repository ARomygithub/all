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

const int mxn=1e6;
int n,m;
string s,t;

void solve() {
    cin >>n >>m;
    cin >>s >>t;
    vector<pii> v;
    rep(i,0,m) {
        v.push_back({t[i]-'0', i});
    }
    sort(all(v));
    int j = m;
    rep(i,0,n) {
        if(j>0) {
            int cur = s[i]-'0';
            if(cur < v[j-1].fi) {
                s[i] = (char)('0' + v[j-1].fi);
                j--;
            }
        } else {
            break;
        }
    }
    rep(i,0,j) {
        if(v[i].se==m-1) {
            bool ok = 0;
            rep(k,0,n) {
                if(s[k]-'0' <= v[i].fi) {
                    s[k] = (char)('0'+v[i].fi);
                    ok = 1;
                    break;
                }
            }
            if(!ok) {
                s[n-1] = (char)('0'+v[i].fi);
            }
            break;
        }
    }
    cout <<s <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}