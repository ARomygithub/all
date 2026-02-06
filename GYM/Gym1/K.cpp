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

const int mxn=1e6;
int n,k;
string s;
int pref[mxn];

void solve() {
    cin >>n >>k;
    cin >>s;
    int ctb= 0, ctw=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='B') {
            pref[ctb] = ctw;
            ctb++;
        } else {
            ctw++;
        }
    }
    if(k>=ctb) {
        cout <<ctw <<"\n";
        return;
    }
    int ans = 0;
    ans = max(pref[k]+(ctw-pref[ctb-1]),(ctw-pref[ctb-k-1])+pref[0]);
    for(int i=1;i<k;i++) {
        max_self(ans, pref[i]+(ctw-pref[ctb-(k-i)-1]));
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}