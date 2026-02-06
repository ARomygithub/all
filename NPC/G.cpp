#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
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

const int mxn=1e6;
int n,q;
ll w;
int t[mxn], poin[mxn];
bool vis[mxn];
int rt[mxn], rp[mxn], cr[mxn], cs[mxn], d[mxn];
vector<int> adj[mxn], cyc;
vector<vector<ll>> cycPref;
vector<ll> dPref[mxn+3];

void dfs1(int u) {
    for(int v: adj[u]) {
        if(rt[v]^v) {
            d[v] = d[u]+1;
            rt[v] = rt[u];
            if(sz(dPref[rt[v]])) {
                dPref[rt[v]].push_back(dPref[rt[v]].back()+poin[v]);
            } else {
                dPref[rt[v]].push_back(poin[v]);
            }
            cr[v] = cr[u];
            dfs1(v);
        }
    }
}

void solve() {
    string temps;
    getline(cin, temps);
    stringstream tempss(temps);
    tempss >>n >>w;
    memset(rt, -1, 4*n);
    for(int i=0;i<n;i++) {
        string s; getline(cin,s);
        stringstream ss(s);
        ss >>t[i]; t[i]--;
        adj[t[i]].push_back(i);
        string nama = "";
        char c;
        int poini = ss.str().size()-2;
        while(ss >> c) {
            if(c >= 'a' && c<='z') {
                nama +=c;
            } else if(c >='A' && c<='Z') {
                nama +=(char)('a'+(c-'A'));
            }
        }
        bool isPalin = true;
        for(int j=0;j<nama.length()-j-1;j++) {
            if(nama[j]!=nama[nama.length()-j-1]) {
                isPalin = false;
                break;
            }
        }
        if(isPalin) {
            poin[i] = poini;
        }
    }
    for(int i=0;i<n;i++) {
        if(~rt[i]) continue;
        int u = i;
        while(!vis[u]) {
            vis[u]=1;
            u = t[u];
        }
        vector<ll> cycPrefi;
        ll prefi=0ll;
        while(!sz(cyc)||u^cyc[0]) {
            rp[u] = sz(cyc);
            cyc.push_back(u);
            prefi +=poin[u];
            cycPrefi.push_back(prefi);
            rt[u] = u;
            cr[u] = sz(cycPref);
            u = t[u];
        }
        cycPref.push_back(cycPrefi);
        for(int ci: cyc) {
            dfs1(ci);
            cs[ci] = sz(cyc);
        }
        cyc.clear();
    }
    getline(cin, temps);
    stringstream tempsi(temps);
    tempsi >> q;
    int ctWin=0, ctLose = 0;
    // cout <<"TES\n";
    // cout <<flush;
    debug() <<imie(poin[0]);
    debug() <<imie(poin[1]);
    debug() <<imie(poin[2]);
    debug() <<imie(poin[3]);    
    debug() <<imie(cycPref);    
    while(q--) {
        getline(cin, temps);
        stringstream tempsj(temps);
        int st,m;
        tempsj >>st >>m; st--;
        ll ans=0;
        if(rt[st]==st) {
            // masuk cycle
            ll putaran = (m+1)/cs[st];
            ll sisa = (m+1)%(cs[st]);
            debug() <<imie(putaran);
            debug() <<imie(sisa);
            ans +=putaran*cycPref[cr[st]][cs[st]-1];
            if(sisa!=0) {
                if(rp[st]+sisa-1>=cs[st]) {
                    ans +=cycPref[cr[st]][cs[st]-1]-(rp[st]>0?cycPref[cr[st]][rp[st]-1]:0ll);
                    ans +=cycPref[cr[st]][rp[st]+sisa-1-cs[st]];
                } else {
                    ans +=cycPref[cr[st]][rp[st]+sisa-1]-(rp[st]>0?cycPref[cr[st]][rp[st]-1]:0ll);
                }
            }
        } else {
            // not
            if(d[st]>=m) {
                ans +=dPref[rt[st]][d[st]-1];
                m -=d[st];
                st = rt[st];
                ll putaran = (m+1)/cs[st];
                ll sisa = (m+1)%(cs[st]);
                ans +=putaran*cycPref[cr[st]][cs[st]-1];
                if(rp[st]+sisa-1>=cs[st]) {
                    ans +=cycPref[cr[st]][cs[st]-1]-(rp[st]>0?cycPref[cr[st]][rp[st]-1]:0ll);
                    ans +=cycPref[cr[st]][rp[st]+sisa-1-cs[st]];
                } else {
                    ans +=cycPref[cr[st]][rp[st]+sisa-1]-(rp[st]>0?cycPref[cr[st]][rp[st]-1]:0ll);
                }          
            } else {
                ans +=dPref[rt[st]][d[st]-1]- (d[st]-m-1>0?dPref[rt[st]][d[st]-1-m-1]:0ll); 
            }
        }
        if(ans>w) {
            cout <<ans <<" win\n";
            ctWin++;
        } else if(ans==w) {
            cout <<ans <<" tie\n";
        } else if(ans<w) {
            cout <<ans <<" lose\n";
            ctLose++;
        }
    }
    if(ctWin>ctLose) {
        cout <<"Sleep soundly all night he is\n";
    } else {
        cout <<"It'll be a sleepless night\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}