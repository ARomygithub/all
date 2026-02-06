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

const int mxn=1e3;
const string s[4] = {"", "cipherpol", "vegapunk", "gorosei"};
int n;

void solve() {
    cin >>n;
    int sto = 0, sta = -1;
    map<char,int> mpo,mpa;
    mpo['c'] = 1;
    mpo['v'] = 2;
    mpo['g'] = 3;
    mpa['s'] = 1;
    mpa['b'] = 2;
    rep(i,0,n) {
        string o, a; cin >>o >>a;
        int oi = mpo[o[0]], ai = mpa[a[0]];
        if(i==0 && ai==2) {
            cout <<"Pacifista ngambek karena belum diperintah tetapi sudah disuruh berhenti!\n";
            return;
        }
        if(oi>=sto) {
            if(ai==sta) {
                cout <<"Pacifista sudah diperintah untuk " <<a <<" oleh " <<s[sto] <<".\n";
            } else {
                cout <<"Pacifista " <<a <<" sesuai dengan keinginan " <<o <<".\n";
                sta = ai;
            }
            sto = oi;
        } else {
            cout <<"Pacifista tidak nurut karena wewenang " <<o <<" lebih rendah dari " <<s[sto] <<".\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}