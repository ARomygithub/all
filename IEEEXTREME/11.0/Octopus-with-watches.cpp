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

const int mxn=9;
int n,m;
int a[mxn][mxn];

string toString3(int i) {
    string ret="";
    while(i) {
        ret +=(char)((i%3)+'0');
        i /=3;
    }
    while(sz(ret)<n) {
        ret +='0';
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

void solve() {
    cin >>n >>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >>a[i][j];
            a[i][j] %=3;
        }
    }
    int n3=1;
    for(int i=0;i<n;i++) {
        n3 *=3;
    }
    int ans=0;
    for(int i=0;i<n3;i++) {
        string s = toString3(i);
        vector<vector<int>> temp(n,vector<int>(m));
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                temp[j][k] = a[j][k]+(s[j]-'0');
                temp[j][k] %=3;
            }
        }
        int ansi=0;
        for(int j=0;j<m;j++) {
            int ct[3] = {0,0,0};
            for(int k=0;k<n;k++) {
                ct[temp[k][j]]++;
            }
            ansi +=max({ct[0],ct[1],ct[2]});
        }
        max_self(ans, ansi);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}