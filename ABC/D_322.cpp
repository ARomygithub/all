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
int n;
vector<vector<vector<bool>>> p[3];
pii szi[3][4];

vector<vector<bool>> pojokin1(vector<vector<bool>> pi0) {
    int kr=3,up=3;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(pi0[i][j]) {
                min_self(kr,j);
                min_self(up,i);
            }
        }
    }
    vector<vector<bool>> res(4,vector<bool>(4,0));
    for(int i=0;i+up<4;i++) {
        for(int j=0;j+kr<4;j++) {
            res[i][j] = pi0[i+up][j+kr];
        }
    }
    return res;
}

vector<vector<bool>> rotasi(vector<vector<bool>> pi0) {
    vector<vector<bool>> res(4,vector<bool>(4,0));
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            res[3-j][i] = pi0[i][j];
        }
    }
    return res;
}

vector<vector<vector<bool>>> pojokin(vector<vector<bool>> pi0) {
    vector<vector<vector<bool>>> res;
    res.push_back(pojokin1(pi0));
    pi0 = rotasi(pi0);
    res.push_back(pojokin1(pi0));
    pi0 = rotasi(pi0);
    res.push_back(pojokin1(pi0));
    pi0 = rotasi(pi0);
    res.push_back(pojokin1(pi0));
    return res;
}

void applyI(vector<vector<bool>>& temp, vector<vector<bool>> pi0, int i0, int j0, bool& flag) {
    for(int i=0;i+i0<4;i++) {
        for(int j=0;j+j0<4;j++) {
            if(pi0[i][j]) {
                if(temp[i+i0][j+j0]) {
                    flag= 0;
                    return;
                } else {
                    temp[i+i0][j+j0] = 1;
                }
            }
        }
    }
}

void solve() {
    n = 4;
    int ct[3] = {0,0,0};
    for(int i=0;i<3;i++) {
        p[i].resize(4, vector<vector<bool>>(4,vector<bool>(4,0)));
        for(int j=0;j<4;j++) {
            for(int k=0;k<4;k++) {
                char c; cin >>c;
                p[i][0][j][k] = (c=='#');
                ct[i] +=(c=='#');
            }
        }
        p[i] = pojokin(p[i][0]);
    }
    if(ct[0]+ct[1]+ct[2]!=16) {
        cout <<"No\n";
        return;
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            int kn=0,bw=0;
            for(int k=0;k<4;k++) {
                for(int l=0;l<4;l++) {
                    if(p[i][j][k][l]) {
                        max_self(kn,l);
                        max_self(bw,k);
                    }
                }
            }
            szi[i][j] = {bw,kn};
        }
    }
    for(int r0=0;r0<4;r0++) {
        for(int i0=0;i0+szi[0][r0].fi<4;i0++) {
            for(int j0=0;j0+szi[0][r0].se<4;j0++) {
                for(int r1=0;r1<4;r1++) {
                    for(int i1=0;i1+szi[1][r1].fi<4;i1++) {
                        for(int j1=0;j1+szi[1][r1].se<4;j1++) {
                            for(int r2=0;r2<4;r2++) {
                                for(int i2=0;i2+szi[2][r2].fi<4;i2++) {
                                    for(int j2=0;j2+szi[2][r2].se<4;j2++) {
                                        vector<vector<bool>> temp(4,vector<bool>(4,0));
                                        bool flag=true;
                                        applyI(temp,p[0][r0],i0,j0,flag);
                                        if(!flag) continue;
                                        applyI(temp,p[1][r1],i1,j1,flag);
                                        if(!flag) continue;
                                        applyI(temp,p[2][r2],i2,j2,flag);
                                        if(flag) {
                                            // cout <<r0 <<" " <<r1 <<" " <<r2 <<"\n";
                                            cout <<"Yes\n";
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}