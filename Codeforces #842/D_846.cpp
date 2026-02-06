#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod=1e9+7;
int n,t;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

int ask(int x) {
    cout <<"- " <<x <<"\n";
    cout <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    int cnt;
    cin >>cnt;
    n = 0;
    int x =1;
    int _cnt=cnt;
    int ct=0;
    while(ct<_cnt) {
        int cnti = ask(x);
        ll temp =fastexpo(2ll,cnti-cnt+1)*x;
        n +=temp;
        cnt = cnti;
        x = temp;
        ct++;
    }   
    cout <<"! " <<n <<"\n";
    cout <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
    return 0;
}