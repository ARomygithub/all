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
int n;
string s1,s2;

void solve() {
    cin >>n;
    map<char,int> mp1, mp2;
    cin >>s1 >>s2;
    for(int i=0;i<5;i++) {
        if(s1[i]!='#') {
            mp[s1[i]]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}