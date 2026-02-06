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
int n,m,t;
char truf;
map<char,int> mp = {{'6',6},{'7',7},{'8',8},{'9',9},{'T',10},{'J',11},{'Q',12},{'K',13},{'A',14}};

bool canWin(string sa, string sb) {
    if(sa[1]==truf && sb[1]!=truf) {
        return true;
    }
    if(sa[1]!=sb[1]) return false;
    return mp[sa[0]]>mp[sb[0]];
} 

bool better(string sa, string sb) {
    if(sa[1]!=truf && sb[1]==truf) {
        return true;
    }
    if(sa[1]!=sb[1]) return false;
    return mp[sa[0]]<mp[sb[0]];
}

void solve() {
    cin >>n >>m >>truf;
    vector<bool> used(n,false);
    vector<string> vn(n);
    vector<string> vm(m);
    for(int i=0;i<n;i++) {
        cin >>vn[i];
    } 
    for(int i=0;i<m;i++) {
        cin >>vm[i];
    }
    bool flag=true;
    for(int i=0;i<m&&flag;i++) {
        int idxWin = -1;
        string win = "";
        for(int j=0;j<n;j++) {
            if(used[j]) continue;
            if(canWin(vn[j],vm[i])) {
                if(idxWin==-1 || better(vn[j],win)) {
                    idxWin = j;
                    win = vn[j];
                }
            }
        }
        if(idxWin==-1) {
            flag=false;
        } else {
            used[idxWin] = 1;
        }
    }
    if(flag) {
        cout <<"YA\n";
    } else {
        cout <<"TIDAK\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}