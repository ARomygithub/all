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
typedef pair<int,char> pic;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=5e5;
int n;
string s,t;

void solve() {
    cin >>n;
    cin >>s;
    cin >>t;
    stack<char> st1,st2;
    auto chk = [&](stack<char>& st) -> void {
        if(sz(st)>=3) {
            string temp = "";
            temp += st.top(); st.pop();
            temp += st.top(); st.pop();
            temp += st.top(); st.pop();
            reverse(temp.begin(),temp.end());
            if(temp=="ABC" || temp=="BCA" || temp=="CAB") {
                return;
            } else {
                rep(i,0,sz(temp)) {
                    st.push(temp[i]);
                }
            }
        }
    };
    rep(i,0,n) {
        st1.push(s[i]);
        st2.push(t[i]);
        chk(st1);
        chk(st2);
    }
    bool ok = sz(st1)==sz(st2);
    while(ok && sz(st1)) {
        ok = (st1.top()==st2.top());
        st1.pop(); st2.pop();
    }
    if(ok) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}