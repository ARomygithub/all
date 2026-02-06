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

const int mxn=1e5;
string s;

void solve() {
    cin >>s;
    if(s[0]=='t') {
        cout <<"3858\n";
    } else if(s[0]=='k') {
        cout <<"3679\n";
    } else if(s[0]=='B') {
        cout <<"3658\n";
    } else if(s[0]=='U') {
        cout <<"3648\n";
    } else if(s[0]=='a') {
        cout <<"3638\n";
    } else if(s[0]=='S') {
        cout <<"3630\n";
    } else if(s[0]=='e') {
        cout <<"3613\n";
    } else if(s[0]=='m') {
        cout <<"3555\n";
    } else if(s[0]=='n') {
        cout <<"3516\n";
    } else if(s[0]=='s') {
        cout <<"3481\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}