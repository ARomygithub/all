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

const int mxn=2e5;
int n,a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ada = -1;
    rep(i,0,n) {
        if(a[i]==1) {
            ada = i;
            break;
        }
    }
    if(ada==-1) {
        if((n%4)==0) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
        return;
    }
    string tmp = "ARCR";
    vector<char> vc(n,'0');
    for(int i=ada+1;i<ada+n;) {
        if(a[(i%n)]==1) {
            i++;
            continue;
        }
        int j = i;
        while(j<ada+n && a[j%n]==0) {
            j++;
        }
        bool ganti = 0;
        if((j%2)!=(i%2)) {
            j++;
            if(vc[(j)%n]!='0' && vc[(j)%n]!=tmp[(j-i)%4]) {
                ganti = 1;
            }
        }
        if(vc[i%n]!='0' && vc[i%n]!=tmp[0]) {
            ganti = 1;
        }
        j++;
        rep(k,i,j) {
            int id = ganti? (k-i+2) : (k-i);
            char cur = tmp[(id)%4];
            if(vc[k%n]==cur || vc[k%n]=='0') {
                vc[k%n] = cur;
            } else {
                cout <<"No\n";
                return;
            }
        }
        i = j;
    }
    cout <<"Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}