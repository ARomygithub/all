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

const int mxn=2e5;
int n;
string s;
int suv[mxn];

void solve() {
    cin >>n;
    cin >>s;
    stack<int> st;
    int temp = 0;
    for(int i=0;i<s.length();i++) {
        if(s[i]>='0' && s[i]<='9') {
            temp = temp*10+(s[i]-'0');
        } else if(s[i]=='(') {
            if(temp!=0) {
                st.push(temp);
                temp = 0;
            }
        } else {
            if(temp!=0) {
                st.push(temp);
                temp = 0;
            }
            int temp2 = st.top(); st.pop();
            if(sz(st)) {
                suv[temp2] = st.top();
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(i==1) {
            cout <<suv[i];
        } else {
            cout <<" " <<suv[i];
        }
    }
    cout <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}