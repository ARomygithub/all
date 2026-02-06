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

const int mxn=1e5;
int n,t;
map<int,int> mp;

void solve() {
    cin >>n;
    n %=1000;
    cout <<mp[n] <<"\n";
}


void init() {
    mp[2] = 4;
    mp[5] = 4;
    mp[8] = 4;
    mp[10] = 4;
    mp[12] = 0;
    mp[13] = 0;
    mp[21] = 4;
    mp[22] = 4;
    mp[24] = 4;
    mp[25] = 8; //octopus
    mp[28] = 6;
    mp[29] = 6;
    mp[30] = 6;
    mp[33] = 0;
    mp[36] = 2;
    mp[39] = 2;
    mp[41] = 4;
    mp[44] = 0;
    mp[375] = 8;
    mp[419] = 6;
    mp[420] = 4;
    mp[428] = 4;
    mp[434] = 2;
    mp[437] = 4;
    mp[441] = 4;
    mp[442] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}