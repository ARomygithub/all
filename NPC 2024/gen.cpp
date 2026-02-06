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

int rnd(int a, int b) {
    return a + rand()%(b-a+1);
}
using pss = pair<string,string>;
const string s[3] = {"cipherpol", "vegapunk", "gorosei"};
const string cmd[2] = {"serang", "berhenti"};

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(atoi(argv[1]));
    int n = rnd(10,1000), m = rnd(10,1000);
    vector p(n, vector(m, 0));
    rep(i,0,n) {
        rep(j,0,m) {
            if(i==0 && j==0) continue;
            if(rnd(0,1)) {
                p[i][j] = rnd(1,4);
            }
        }
    }
    cout <<n <<" " <<m <<"\n";
    rep(i,0,n) {
        rep(j,0,m) {
            cout <<p[i][j] <<" \n"[j==m-1];
        }
    }
}