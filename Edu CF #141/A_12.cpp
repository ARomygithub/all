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
int a,ta,b,tb;

void solve() {
    cin >>a >>ta;
    cin >>b >>tb;
    string s; cin >>s;
    int ti = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
    int ct = 0;
    if(ti+ta-1>=300) {
        int temp = min(ti+ta-1, 1439);
        ct += (temp-300)/b + 1;
    }
    if(ti-tb+1>=300) {
        ct -= (ti-tb+1-300+b-1)/b;
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}