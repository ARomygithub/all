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

const int mxk=1e3,mxa=26;
int n,m,k;
int a[mxk];
int ct[mxa];

void solve() {
    cin >>n >>m >>k;
    rep(i,0,k) {
        cin >>a[i];
        // ct[a[i]]++;
    }
    sort(a,a+k);
    if(n>m) swap(n,m);
    multiset<pii> ms;
    ms.insert({0,n});
    per(i,k-1,-1) {
        bool ok = 0;
        for(auto [h,len]: ms) {
            if(len>=(1<<a[i])) {
                ms.erase(ms.find({h,len}));
                ms.insert({(1<<a[i])+h,(1<<a[i])});
                if(len>(1<<a[i])) {
                    ms.insert({h,len-(1<<a[i])});
                }
                ok = 1;
                break;
            }
        }
        if(!ok) {
            cout <<"No\n";
            return;
        }
    }
    int mx = -1;
    for(auto [h,len]: ms) {
        max_self(mx, h);
    }
    if(mx>m) {
        cout <<"No\n";
    } else {
        cout <<"Yes\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}