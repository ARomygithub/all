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

const int mxn=1e5;
int n;
string t;

bool check0(string s1, string s2) {
    int diff=0;
    for(int i=0;i<sz(s1);i++) {
        diff +=(s1[i]!=s2[i]);
    }
    return diff<=1;
}

bool checkMin(string s1, string s2) {
    int skip=0;
    int idx=0;
    for(int i=0;i<sz(s1)&&idx<sz(s2);i++) {
        if(s1[i]!=s2[idx]) {
            skip++;
        } else {
            idx++;
        }
    }
    return skip<=1;
}

void solve() {
    cin >>n;
    cin >>t;
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        string s; cin >>s;
        if(sz(t)==sz(s)) {
            if(check0(t,s)) {
                ans.push_back(i);
            }
        } else if(sz(t)==sz(s)+1 && checkMin(t,s)) {
            ans.push_back(i);
        } else if(sz(t)+1==sz(s) && checkMin(s,t)) {
            ans.push_back(i);
        }
    }
    cout <<sz(ans) <<"\n";
    for(int i=0;i<sz(ans);i++) {
        cout <<ans[i] <<" \n"[i==sz(ans)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}