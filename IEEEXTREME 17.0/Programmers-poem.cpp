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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;

void solve() {
    map<string, int> mp;
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >>n >>m;
    int ct=1;
    rep(i,0,n) {
        getline(cin,s);
        stringstream ssi(s);
        while(ssi >> s) {
            rep(j,0,sz(s)) {
                if(s[j]>='A' && s[j]<='Z') {
                    s[j] = (char)('a'+s[j]-'A');
                }
            }
            mp[s] = ct;
            // cout <<s <<"\n";
        }
        ct++;
    }
    char cc = 'A';
    getline(cin,s);
    string ans="";
    map<char,char> mp2;
    vector<string> sm;
    rep(i,0,m) {
        string s2;
        getline(cin, s2);
        stringstream ssi(s2);
        while(ssi >> s2) {
        }
        rep(j,0,sz(s2)) {
            if(s2[j]>='A' && s2[j]<='Z') {
                s2[j] = (char)('a'+s2[j]-'A');
            }
        }
        // cout <<s <<"\n";
        sm.push_back(s2);
        ans +='X';
    }
    set<int> st;
    vector<int> last(n+1,-1);
    rep(i,0,m) {
        // cout <<sm[i] <<"\n";
        // cout <<mp.count("sleep") <<"\n";
        if(mp.find(sm[i])!=mp.end()) {
            if(st.find(mp[sm[i]])!=st.end()) {
                char mpc = mp[sm[i]];
                if(!mp2.count(mpc)) {
                    mp2[mpc] = cc;
                    cc = (char)(cc+1);
                    if(cc=='X') {
                        cc = (char)(cc+1);
                    }
                }
                ans[i] = mp2[mpc];
                ans[last[mp[sm[i]]]] = mp2[mpc];              
            }
            st.insert(mp[sm[i]]);
            last[mp[sm[i]]] = i;
        }
    }
    map<char,char> mp3;
    string ans2="";
    cc = 'A';
    rep(i,0,m) {
        if(ans[i]!='X') {
            char mpc = ans[i];
            if(!mp3.count(mpc)) {
                mp3[mpc] = cc;
                cc = (char)(cc+1);
                if(cc=='X') {
                    cc = (char)(cc+1);
                }
            }
            ans2 +=mp3[mpc];
        } else {
            ans2 +=ans[i];
        }
    }
    cout <<ans2 <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}