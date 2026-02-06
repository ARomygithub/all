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

const int mxn=1e5;
int t;
string s;

bool cek(string si) {
    return si[0]==si[4]&&si[1]==si[3];
}

void solve() {
    cin >>s;
    int cur = 0;
    while(!cek(s)) {
        cur++;
        if(s=="23:59") {
            break;
        }
        if(s[4]=='9') {
            s[4] = '0';
            if(s[3]=='5') {
                s[3] = '0';
                if(s[1]=='9') {
                    s[1] = '0';
                    s[0] = (char)(s[0]+1);
                } else {
                    s[1] = (char)(s[1]+1);
                }
            } else {
                s[3] = (char)(s[3]+1);
            }
        } else {
            s[4] = (char)(s[4]+1);
        }
    }
    cout <<cur <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}