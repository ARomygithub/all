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
int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 1e5;
    vector<string> vs;    
    int c[4];
    c[0] = rnd(10,99), c[1] = rnd(10,99), c[2] = rnd(10,99), c[3] = rnd(10,99);
    rep(i,0,n-1) {
        int icur = rnd(1000,9999);
        string cur = to_string(icur) + to_string(c[rnd(0,2)]);
        vs.push_back(cur);
    }
    rep(i,n-1,n) {
        int icur = rnd(1000,9999);
        string cur = to_string(icur) + to_string(c[3]);
        vs.push_back(cur);        
    }
    cout << n <<"\n";
    rep(i,0,n) {
        cout <<vs[i] <<"\n";
    }
}