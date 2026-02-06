#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
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

const int mxn=1e5;
ll w,l,x,y;

void solve() {
    cin >>w >>l;
    cin >>x >>y;
    ll ct = min(x,w-x+1)*min(y,l-y+1);
    ll body = w*l - ct;
    if(body>ct) {
        cout <<ct <<"\n";
    } else {
        cout <<"I don't wanna do this anymore!\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}