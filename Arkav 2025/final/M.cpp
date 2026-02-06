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

const int mxn=5e3;
int n;

int ask(int i, int j) {
    cout <<"? " <<i <<" " <<j <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    cin >>n;
    // if(n==1) {
    //     cout <<"! 1 1\n" <<flush;
    //     return;
    // }
    pii ans = {1,1};    
    int id = 2;
    while(true) {
        if(id>n) break;
        int r1 = ask(ans.fi, id);
        if(r1) {
            ans.fi = id;
            id++;
            continue;
        }
        int r2 = ask(id, ans.fi);
        if(r2==0) {
            ans.se = id;
            id++;
            break;
        }
        id++;
    }
    while(id<=n) {
        int r1 = ask(ans.fi, id);
        if(r1) {
            ans.fi = id;
            id++;
            continue;
        }
        int r2 = ask(ans.se, id);
        if(r2) {
            ans.se = id;
            id++;
            continue;
        }
        id++;
    }
    cout <<"! " <<ans.fi <<" " <<ans.se <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}