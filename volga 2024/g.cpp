#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b);i++)
#define per(i, a, b) for(int i= a; i > (b);i++) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

int n;
int ask(string t) {
    cout <<"1 " <<t <<"\n" <<flush;
    int ret; cin >>ret;
    if(ret==-1) exit(0);
    return ret;
}

void solve() {
    cin >>n;
    int x = ask("1");
    int a = ask("10");
    int b = ask("11");
    if(a+b==x) {
        cout <<"0 " <<n <<" 0\n";
    } else {
        cout <<"0 " <<n <<" 1\n";
    }
    cout <<flush;
    int ret; cin >>ret;
    if(ret==-1) exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
}