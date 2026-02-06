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

const int mxn=5e5;
int n;
string s;
string ans = "";

struct Node {
    bool kur = 0;
    char c;
    vector<Node*> ch;
    Node* par = 0;
    Node(bool kur, char c): kur(kur), c(c) {}
};

void dfs(Node* u, int ct) {
    if(u->kur) {
        if(ct) {
            per(i,sz(u->ch)-1, -1) {
                dfs(u->ch[i], (ct+1)%2);
            }
        } else {
            rep(i,0,sz(u->ch)) {
                dfs(u->ch[i], (ct+1)%2);
            }
        }
    } else {
        char ci = u->c;
        if(!ct) {
            if(ci>='a' && ci<='z') {
                ci = (char)(ci-'a'+'A');
            } else {
                ci = (char)(ci-'A'+'a');
            }
        }
        ans += ci;
    }
}

void solve() {
    cin >>s;
    n = sz(s);
    Node* r = new Node(1, ' ');
    Node* cur = r;
    rep(i,0,n) {
        if(s[i]=='(') {
            Node* kuri = new Node(1, ' ');
            cur->ch.push_back(kuri);
            kuri->par = cur;
            cur = kuri;
        } else if(s[i]==')') {
            // reverse(cur->ch.begin(), cur->ch.end());
            cur = cur->par;
        } else {
            Node* nx = new Node(0, s[i]);
            nx->par = cur;
            cur->ch.push_back(nx);
        }
    }
    dfs(r, 0);
    cout <<ans <<"\n";    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}