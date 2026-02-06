#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<bool,bool> pbb;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int a,b,c,d,m,t;

string getString5(int u) {
    string res="";
    while(u) {
        res +=(char)('0'+(u%5));
        u /=5;
    }
    while(sz(res)<8) {
        res +='0';
    }
    reverse(res.begin(),res.end());
    return res;
}

void solve() {
    int n=1;
    for(int i=0;i<8;i++) {
        n *=5;
    }
    vector<int> dp(n,1e9);
    vector<bool> vis(n,0), act(n,0);
    dp[0] = 0;
    vis[0] = 1;
    int base = stoi("12341234",nullptr,5);
    dp[base] = 0;
    vis[base] = 1;
    function<int(int)> dfs;
    vector<vector<char>> move(4),move2(4);
    // move[0] = vector<char>({'1','2','1','4'});
    // move[1] = vector<char>({'1','4','3','4'});
    // move[2] = vector<char>({'1','2','4','3'});
    // move[3] = vector<char>({'1','2','3','4'});
    // move2[0] = vector<char>({'1','2','1','4'});
    // move2[1] = vector<char>({'1','4','3','4'});
    // move2[2] = vector<char>({'1','2','4','3'});
    // move2[3] = vector<char>({'2','1','4','3'});
    move[0] = vector<char>({'3','2','z','4'});
    move[1] = vector<char>({'1','z','3','2'});
    move[2] = vector<char>({'1','2','4','3'});
    move[3] = vector<char>({'1','2','3','4'});
    move2[0] = vector<char>({'3','2','z','4'});
    move2[1] = vector<char>({'1','z','3','2'});
    move2[2] = vector<char>({'1','2','4','3'});
    move2[3] = vector<char>({'2','1','4','3'});
    dfs = [&](int u) -> int {
        if(vis[u]) return dp[u];
        act[u] = 1;
        string us = getString5(u);
        bool flag=true;
        for(int i=0;i<8&&flag;i++) {
            if(us[i]=='0') {
                flag = false;
                for(int j=1;j<=4;j++) {
                    us[i] = (char)('0'+j);
                    int usi = stoi(us, nullptr, 5);
                    if(!act[usi]) {
                        min_self(dp[u],dfs(usi));
                    }
                }
            }
        }
        if(flag) {
            for(int i=0;i<4;i++) {
                string usi=us;
                bool flag2=1;
                pii alt;
                vector<int> valt;
                for(int j=0;j<4;j++) {
                    usi[j] = move[i][us[j]-'1'];
                    if(usi[j]=='z') flag2=0;
                    if(i==0 && usi[j]=='3') {
                        alt = {'1','3'};
                        valt.push_back(j);
                    }
                    if(i==1 && usi[j]=='2') {
                        alt = {'2','4'};
                        valt.push_back(j);
                    }
                }
                for(int j=4;j<8;j++) {
                    usi[j] = move2[i][us[j]-'1'];
                    if(usi[j]=='z') flag2=0;
                    if(i==0 && usi[j]=='3') {
                        alt = {'1','3'};
                        valt.push_back(j);
                    }
                    if(i==1 && usi[j]=='2') {
                        alt = {'2','4'};
                        valt.push_back(j);
                    }
                }
                if(!flag2) continue;
                if(sz(valt)) {
                    for(int l=0;l<(1<<sz(valt));l++) {
                        for(int o=0;o<sz(valt);o++) {
                            usi[valt[o]] = (l>>o)&1?alt.se:alt.fi;
                        }
                        int usii = stoi(usi,nullptr,5);
                        if(!act[usii]) {
                            min_self(dp[u],1+dfs(usii));
                        }
                    }
                    continue;
                }
                int usii = stoi(usi, nullptr, 5);
                if(!act[usii]) {
                    // debug() <<imie("usaha");
                    min_self(dp[u],1+dfs(usii));
                }
            }
        }
        act[u] = 0;
        vis[u] = 1;
        // if(dp[u]<1e9) {
        //     debug() <<imie(us) <<imie(dp[u]);
        // }
        return dp[u];
    };
    while(t--) {
        cin >>a >>b >>c >>d >>m;
        map<pbb,int> mp,mp2;
        mp[{0,0}] = 0;
        mp[{0,1}] = 0;
        mp[{1,0}] = 0;
        mp[{1,1}] = 0;
        mp2[{0,0}] = 0;
        mp2[{0,1}] = 0;
        mp2[{1,0}] = 0;
        mp2[{1,1}] = 0;
        bool flag0=1;      
        for(int i=0;i<30&&flag0;i++) {
            pbb bi;
            bi.fi = (a>>i)&1;
            bi.se = (b>>i)&1;
            pbb bi2 = {(c>>i)&1,(d>>i)&1};
            int tes2 = 1;
            if(bi2.se) tes2+=1;
            if(bi2.fi) tes2+=2;
            if((m>>i)&1) {
                if(mp2[bi]!=0 && mp2[bi]!=tes2) {
                    cout <<"-1\n";
                    flag0 = 0;
                } else if(mp2[bi]==0) {
                    mp2[bi] = tes2;
                }
            } else {
                if(mp[bi]!=0 && mp[bi]!=tes2) {
                    cout <<"-1\n";
                    flag0=0;
                } else if(mp[bi]==0) {
                    mp[bi] = tes2;
                }
            }
        }
        if(!flag0) continue;
        string querys = "";
        for(auto [bi,tes2] : mp) {
            querys +=(char)('0'+tes2);
        }
        for(auto [bi,tes2]: mp2) {
            querys +=(char)('0'+tes2);
        }       
        // debug() <<imie(querys);
        int query = stoi(querys,nullptr,5);
        int ans = dfs(query);
        if(ans>=1e9) {
            cout <<"-1\n";
        } else {
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    solve();
}