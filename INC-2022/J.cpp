#include "bits/stdc++.h"
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
int n,q;
bool b[mxn+2];

ll f(ll k) {
    return (k)*(k+1)*(k+2)/6;
}

void solve() {
    cin >>n >>q;
    set<int> s;
    s.insert(0);
    s.insert(n+1);
    ll ans=f(1ll*n);
    b[0]=1;
    b[n+1]=1;
    while(q--) {
        int a; cin >>a;
        if(b[a]) {
            auto it =s.find(a);
            auto itr = it;
            itr++;
            auto itl = it;
            itl--;
            ans -=f(1ll*(*itr-*it-1)) + f(1ll*(*it-*itl-1));
            ans += f(1ll*(*itr-*itl-1));
            s.erase(a);
            b[a] = 0;
        } else {
            auto it = s.lower_bound(a);
            auto itl = it;
            itl--;
            ans -=f(1ll*(*it-*itl-1));
            ans +=f(1ll*(a-*itl-1))+f(1ll*(*it-a-1));
            s.insert(a);
            b[a] = 1;
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}