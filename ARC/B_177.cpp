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

const int mxn=30;
int n;
string s;

void solve() {
    cin >>n;
    cin >>s;
    string ans = "";
    int id = n-1;
    while(s[id]!='1') {
        id--;
    }
    int st = 0;
    per(i,id,-1) {
        if(s[i]=='1' && st==0) {
            rep(j,0,i+1) {
                ans += 'A';
            }
            st = 1;
        } else if(s[i]=='0' && st==1) {
            rep(j,0,i+1) {
                ans += 'B';
            }
            st = 0;
        }
    }
    cout <<sz(ans) <<"\n";
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}