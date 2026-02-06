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

const int mxn=1e4,mxa=3e5;
int n;

void solve() {
    cin >>n;
    vector div(mxa+1, vi());
    rep(i,2,mxa+1) {
        for(ll j = i;j<=mxa;j+=i) {
            div[j].push_back(i);
        }
    }
    int ct = 0;
    vector<bool> prac(mxa+1,0);
    rep(i,1,mxa+1) {
        if(i==1) {
            prac[i] = 1;
            ct++;
        } else {
            ll ri = 1;
            bool ok = 1;
            rep(j,0,sz(div[i])) {
                int cur = div[i][j];
                int cur2 = i/div[i][j];
                if((prac[cur] && (cur%cur2)==0) || (prac[cur] && prac[cur2])) {
                    prac[i] = 1;
                    ok = 0;
                    break;
                }
                if(ri>= div[i][j]-1) {
                    ri += div[i][j];
                } else {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                prac[i] = 1;
                ct++;
            }
        }
        if(ct==n) {
            cout <<i <<"\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}