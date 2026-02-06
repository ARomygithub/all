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

#include <bits/extc++.h> /** keep-include */
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
__gnu_pbds::gp_hash_table<ll,int,chash> mp({},{},{},{},{1<<25});

const int mxn=1e5;
int n,t;
vector<vector<string>> vs;
const vector<char> alf = {'G','L','M','S'};
using vss = vector<string>;
// map<ll,int> mp;
map<char,int> ma;
ll pw[16];

ll toid(const vss& vsi) {
    ll id = 0;
    rep(i,0,4) {
        rep(j,0,4) {
            id = id*5 + ma[vsi[i][j]];
        }
    }
    return id;
}

int slv(vss& cur, int rem) {
    vector v(2,vi());
    bool ada = 0;
    ll id = toid(cur);
    rep(i,0,4) {
        rep(j,0,4) {
            if(cur[i][j]!='X') {
                char tmp = cur[i][j];
                cur[i][j] = 'X';
                int bwh = (3-j) + 4*(3-i);
                ll dif = ma[tmp]*pw[bwh];
                if(mp[id-dif]==1) {
                    ada = 1;
                    int ret = slv(cur, rem+1);
                    v[ret%2].push_back(ret);
                }
                cur[i][j] = tmp;
            }
        }
    }
    if(!ada) {
        return rem;
    }
    if(rem%2) {
        if(sz(v[0])) {
            return v[0].back();
        } else {
            return v[1][0];
        }
    } else {
        if(sz(v[1])) {
            return v[1].back();
        } else {
            return v[0][0];
        }
    }
}

void solve() {
    vss cur(4);
    rep(i,0,4) {
        cin >>cur[i];
    }
    int rem = 0;
    rep(i,0,4) {
        rep(j,0,4) {
            rem += (cur[i][j]=='X');
        }
    }
    cout <<16-slv(cur,rem) <<"\n";
}

void gen(vss& vsi, int i, int j, ll curid) {
    if(i==4) {
        mp[curid]++;
        return;
    }
    int in = i, jn = j;
    if(j<3) {
        jn = j+1;
    } else {
        jn = 0;
        in++;
    }
    int bwh = (3-j) + 4*(3-i);
    char tmp = vsi[i][j];
    ll curidn = curid + pw[bwh]*ma[tmp];
    gen(vsi, in, jn, curidn);
    vsi[i][j] = 'X';
    gen(vsi, in, jn, curid);
    vsi[i][j] = tmp;
}

void init() {
    vector<char> alf1 = alf;
    do {
        vector<char> alf2 = alf;
        string s1 = "";
        rep(i,0,4) {
            s1 += alf1[i];
        }
        do {
            vector<char> alf3 = alf;
            string s2 = "";
            rep(i,0,4) {
                s2 += alf2[i];
            }            
            do {
                string s3 = "";
                rep(i,0,4) {
                    s3 += alf3[i];
                }                
                bool ok = 1;
                rep(i,0,4) {
                    if(s1[i]==s2[i] || s1[i]==s3[i] || s2[i]==s3[i]) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    string s4 = "";
                    rep(i,0,4) {
                        rep(j,0,4) {
                            if(alf[j]!=s1[i] && alf[j]!=s2[i] && alf[j]!=s3[i]) {
                                s4 += alf[j];
                            }
                        }
                    }
                    vector<string> vsi = {s1,s2,s3,s4};
                    vs.push_back(vsi);
                }
            } while(next_permutation(all(alf3)));
        } while(next_permutation(all(alf2)));
    } while(next_permutation(all(alf1)));
    // cout <<sz(vs) <<"\n"; 576
    rep(i,0,sz(vs)) {
        vss vsi = vs[i];
        gen(vsi, 0, 0, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    ma['G'] = 1;
    ma['L'] = 2;
    ma['M'] = 3;
    ma['S'] = 4;
    ma['X'] = 0;
    pw[0] = 1;
    rep(i,1,16) {
        pw[i] = pw[i-1]*5;
    }
    init();
    // while(t--) {
    //     solve();
    // }
}