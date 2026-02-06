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
int n,t;
string s;

void solve() {
    cin >>s;
    ll pos; cin >>pos;
    n = s.length();
    int ukr = n;
    while(pos>ukr) {
        pos -=ukr;
        ukr--;
    }
    pos--;
    int ct=0;
    stack<char> st;
    for(int i=0;i<n;i++) {
        if(ukr+ct==n) {
            st.push(s[i]);
            continue;
        }
        if(sz(st)) {
            while(sz(st) && st.top()>s[i] && ukr+ct<n) {
                st.pop();
                ct++;
            }
            st.push(s[i]);
        } else {
            st.push(s[i]);
        }
    }
    string revS = "";
    while(sz(st)) {
        revS +=st.top(); st.pop();
    }
    reverse(revS.begin(),revS.end());
    // cout <<revS <<"\n";
    cout <<revS[pos];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}