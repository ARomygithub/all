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

int main() {
    int n;
    cin >> n; cin.ignore();
    vector img(n, vector<char>(n,'.'));
    // game loop
    while (1) {
        string command;
        getline(cin, command);
        if(command[0]=='C') {
            int cl = command[1]-'0';
            rep(i,0,n) {
                img[i][cl] = '#';
            }
        } else {
            int rw = command[1]-'0';
            rep(j,0,n) {
                img[rw][j] = '.';
            }
        }
        rep(i,0,n) {
            rep(j,0,n) {
                cout <<img[i][j];
            }
            cout <<"\n";
        }
        cout <<flush;
    }
}