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

const int mxn=1e4;
int n;
string s,sq;
vector<int> frontPal[mxn];

void solve() {
    cin >>n;
    cin >>sq;
    int ans=0;
    for(int i=0;i<n;i++) {
        if(sq[i]=='-') {
            ans -=sz(frontPal[sz(s)-1]);
            frontPal[sz(s)-1].clear();
            s.pop_back();
        } else {
            s +=sq[i];
            if(sz(s)>1) {
                for(auto front : frontPal[sz(s)-2]) {
                    if(front>0 && s[front-1]==sq[i]) {
                        frontPal[sz(s)-1].push_back(front-1);
                        ans++;
                    }
                }
                if(s[sz(s)-2]==s[sz(s)-1]) {
                    frontPal[sz(s)-1].push_back(sz(s)-2);
                    ans++;
                }
            }
            frontPal[sz(s)-1].push_back(sz(s)-1);
            ans++;
        }
        cout <<ans <<" \n"[i==n-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}