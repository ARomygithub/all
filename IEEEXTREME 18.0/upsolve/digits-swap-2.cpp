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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
string n;
int k;

void findMax(string& s, int ki, int pos) {
    if(ki==0 || pos>=sz(s)-1) {
        if(n<s) {
            n = s;
        }
        return;
    }
    vi id;
    int mx = -1;
    rep(j,pos,sz(s)) {
        if(s[j]-'0' > mx) {
            mx = s[j] - '0';
            id.clear();
            id.push_back(j);
        } else if(s[j]-'0' == mx) {
            id.push_back(j);
        }
    }
    if(s[pos]-'0' !=mx) {
        for(auto j : id) {
            swap(s[pos], s[j]);
            findMax(s,ki-1,pos+1);
            swap(s[pos], s[j]);
        }
        findMax(s, ki, pos+1);
    } else {
        findMax(s,ki,pos+1);
    }
}

void solve() {
    cin >>n >>k;
    string s = n;
    int len = 0;
    rep(i,0,sz(n)) {
        int id = -1, mx = -1;
        rep(j,i,sz(n)) {
            if((n[j]-'0') >= mx) {
                id = j;
                mx = n[j]-'0';
            }
        }
        if(k) {
            if(mx != n[i]-'0') {
                swap(n[i], n[id]);
                k--;
            }
        }
        if(mx != (n[i]-'0')) {
            len = sz(n)-i;
            break;
        }
    }
    if(len>1) {
        findMax(s, k, 0);
    } 
    cout <<n <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}