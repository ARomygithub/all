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

int ask(int i, int j, int k) {
    cout <<i <<" " <<j <<" " <<k <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    map<int,int> mp1, mp2;
    int a,b;
    int ct = 0;
    while(true) {
        int ret = ask(1,0,0);
        mp1[ret]++;
        ct++;
        if(mp1[ret]>=2) {
            a = ret;
            break;
        }
    }
    while(true) {
        int ret = ask(0,1,0);
        mp2[ret]++;
        ct++;
        if(mp2[ret]>=2) {
            b = ret;
            break;
        }
    }
    while(ct<5) {
        ask(1,0,0);
        ct++;
    }
    cout <<a <<" " <<b <<" 6\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}