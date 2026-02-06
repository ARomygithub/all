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

const int mxn=2e5;
int n;
string s;

void solve() {
    cin >>s;
    n = s.length();
    int blok = 0;
    set<int> en;
    rep(i,0,26) {
        en.insert(i);
    }
    vector<vector<pii>> alfas;
    for(int i=0;i<n;) {
        map<int,int> mp;
        vector<pii> alfa;
        while(i<n &&sz(mp)<26) {
            if(!mp.count(s[i]-'a')) {
                alfa.push_back({s[i]-'a',i});
                mp[s[i]-'a']++;
            }
            i++;
        }
        blok += sz(mp)==26;
        if(sz(mp)==26) {
            alfas.push_back(alfa);
        } else {
            for(auto [ch, idx]: alfa) {
                en.erase(ch);
            }
        }
    }
    vector<vector<vector<int>>> v;
    int last = n-1;
    per(i,blok-1,-1) {
        set<int> st;
        rep(j,0,26) {
            st.insert(j);
        }
        vector vb(26, vector<int>());
        per(j,25,-1) {
            int ch = alfas[i][j].fi;
            // if(ch==0) {
            //     debug() <<imie(last);
            // }
            while(last>alfas[i][j].se) {
                st.erase(s[last]-'a');
                last--;
            }
            for(auto si : st) {
                vb[ch].push_back(si);
            }
        }
        last--;
        v.push_back(vb);
    }
    reverse(v.begin(),v.end());
    // cout <<"tes" <<endl;
    // debug() <<imie(alfas);
    // debug() <<imie(v[0][0]);
    vector vis(blok+1, vector<bool>(26, 0));
    for(auto si : en) {
        vis[blok][si] = 1;
    }
    per(i,blok-1,-1) {
        rep(j,0,26) {
            bool temp = 0;
            for(auto cnext : v[i][j]) {
                temp |= vis[i+1][cnext];
            }
            vis[i][j] = temp;
        }
    }
    string ans = "";
    function<void(int,int)> dfs;
    dfs = [&](int pos, int ch) -> void {
        ans += (char)(ch+'a');
        if(pos>=sz(v)) return;
        for(auto cnext: v[pos][ch]) {
            if(vis[pos+1][cnext]) {
                dfs(pos+1,cnext);
                return;
            } 
        }
    };
    rep(i,0,26) {
        if(vis[0][i]) {
            dfs(0,i);
            break;
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}