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
int n;

int ask(int i, int j) {
    cout <<"? " <<i <<" " <<j <<"\n";
    cout <<flush;
    int ret; cin >>ret;
    if(ret==-1) exit(0);
    return ret;
}

void solve() {
    cin >>n;
    pii p1 = {-1,-1};
    vi v0;
    rep(i,2,n+1) {
        int ret = ask(1,i);
        if(ret==1) {
            p1 = {i,1};
            continue;
        }
        ret = ask(i,1);
        if(ret==1) {
            p1 = {i,0};
        } else {
            v0.push_back(i);
        }
    }
    if(p1.fi==-1) {
        cout <<"! 1\n";
        cout <<flush; 
    } else {
        for(auto a : v0) {
            if(p1.se) {
                int ret = ask(a,p1.fi);
                if(ret==0) {
                    cout <<"! " <<a <<"\n";
                    return;
                }
            } else {
                int ret = ask(p1.fi,a);
                if(ret==0) {
                    cout <<"! " <<a <<"\n";
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}