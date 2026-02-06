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

const int mxn=1e2;
int n;
string kode[mxn];
int skor[mxn];

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        cin >>kode[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int sx, sy; cin >>sx >>sy;
            if(sx==sy) {
                skor[i]++; skor[j]++;
            } else if(sx>sy) {
                skor[i] +=3;
                skor[j] -=1;
            } else {
                skor[j] +=3;
                skor[i] -=1;
            }
        }
    }
    string ans = "-1"; int mx=-1;
    for(int i=0;i<n;i++) {
        if(skor[i]>mx || (skor[i]==mx && (ans > kode[i]))) {
            mx = skor[i];
            ans = kode[i];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}