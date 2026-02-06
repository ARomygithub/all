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

const int mxn=1e5;
int n;

string add(string t, int i) {
    int jam = stoi(t.substr(0,2));
    int mnt = stoi(t.substr(2,2));
    mnt += i;
    if(mnt>=60) {
        jam++;
        mnt -=60;
    }
    string ret = "";
    if(jam<10) {
        ret +='0';
    }
    ret +=to_string(jam);
    if(mnt<10) {
        ret +='0';
    }
    ret += to_string(mnt);
    return ret;
}

void solve() {
    string tm = "0958";
    string ans = "";
    // tm, tm+1, .., +18, + 19, submit di +20
    rep(i,0,20) {
        tm = add(tm, i);
        ans += tm;
    }
    reverse(ans.begin(),ans.end());
    cout <<ans <<"\n";
    // cout <<"submit di " <<add(tm,20) <<"\n";   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}