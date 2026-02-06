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
typedef pair<char,char> pcc;

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
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<pcc> ans;
    int id = 1;
    stack<int> qbs;
    per(i,n-1,-1) {
        while(sz(qbs) && qbs.top()==id) {
            ans.push_back({'B','C'});
            qbs.pop();
            id++;
        }
        if(a[i]==id) {
            ans.push_back({'A','C'});
            id++;
        } else {
            ans.push_back({'A','B'});
            qbs.push(a[i]);
        }
    }
    while(sz(qbs) && qbs.top()==id) {
        ans.push_back({'B','C'});
        id++;
        qbs.pop();
    }
    if(id<=n) {
        cout <<"-1\n";
        return;
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}