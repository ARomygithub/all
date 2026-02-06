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
int n;
string s;

string getString(string s1, int n1) {
    string ret="";
    for(int i=0;i<n;i++) {
        ret +=s1[i%3];
    }
    return ret;
}

void solve() {
    cin >>n;
    cin >>s;
    vector<string> vs;
    vs.push_back(getString("abc",n));
    vs.push_back(getString("acb",n));
    vs.push_back(getString("bac",n));
    vs.push_back(getString("bca",n));
    vs.push_back(getString("cab",n));
    vs.push_back(getString("cba",n));
    for(int i=0;i<6;i++) {
        bool flag=true;
        for(int j=0;j<n&&flag;j++) {
            if(s[j]!='.' && s[j]!=vs[i][j]) {
                flag=0;
                break;
            }
        }
        if(flag) {
            cout <<vs[i] <<"\n";
            return;
        }
    }
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}