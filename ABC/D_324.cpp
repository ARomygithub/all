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

const int mxn=1e5,mxa=1e7;
int n;
string s;
int ct[10];

void solve() {
    cin >>n;
    cin >>s;
    for(char c: s) {
        ct[c-'0']++;
    }
    int ans=0;
    for(int i=0;i<mxa;i++) {
        ll num = 1ll*i*i;
        vector<int> cti(10,0);
        while(num) {
            cti[num%10]++;
            num /=10;
        }
        bool flag=1;
        for(int j=1;j<=9&&flag;j++) {
            flag &=ct[j]==cti[j];
        }
        flag &=ct[0]>=cti[0];
        if(flag) ans++;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}