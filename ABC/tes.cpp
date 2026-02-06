#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
} 

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn = 1e5;
int n,t;

void solve() {
    cout <<gcd(4,-2) <<"\n";
    ll x1 = -2, y1 = -2, z1 = 2;
    ll d1 = gcd(gcd(x1,y1), z1);
    ll x2 = 2, y2 = 2, z2 = -2;
    ll d2 = gcd(gcd(x2,y2), z2); 
    cout <<d1 <<" " <<d2 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}