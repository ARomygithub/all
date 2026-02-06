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

const int mxn=4e5;
int n;
string s;

vector<int> b3(int x) {
    vector<int> ret;
    while(x) {
        ret.push_back(x%3);
        x /=3;
    }
    return ret;
}

void solve() {
    cin >>n;
    cin >>s;
    map<char,int> mp;
    mp['B'] = 0;
    mp['W'] = 1;
    mp['R'] = 2;
    vector C(3, vector<int>(3,0));
    rep(i,0,3) {
        int fct = 1;
        rep(j,1,i+1) {
            fct *=j;
        }
        rep(j,0,i+1) {
            int temp = fct;
            rep(k,1,j+1) {
                temp /=k;
            }
            rep(k,1,i-j+1) {
                temp /=k;
            }
            C[i][j] = temp;
        }
    }
    int ans = 0;
    vector<int> n1 = b3(n-1);
    rep(i,0,n) {
        vector<int> i3 = b3(i);
        while(sz(i3)<sz(n1)) {
            i3.push_back(0);
        }
        int temp = 1;
        rep(j,0,sz(i3)) {
            temp = temp*C[n1[j]][i3[j]]%3;
        }
        ans = (ans + temp*mp[s[i]]%3)%3;
    }
    rep(i,0,n-1) {
        ans = ans*2%3;
    }
    if(ans==0) {
        cout <<"B";
    } else if(ans==1) {
        cout <<"W";
    } else {
        cout <<"R";
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}