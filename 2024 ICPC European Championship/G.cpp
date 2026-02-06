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

const int mxn=2e3;
const char pc[3] = {'-','C','M'};
int n;
string s,t;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>n;
    cin >>s;
    cin >>t;
    // n = 0;
    // s = "";
    // t = "";
    // vector<int> ss(3,0);
    // vector<int> tt(3,0);
    // rep(i,0,3) {
    //     if(i==0) {
    //         ss[i] = rng()%29 + 1;
    //     } else {
    //         ss[i] = rng()%30;
    //     }
    //     n += ss[i];
    // }
    // int sisa = ss[0];
    // rep(i,1,3) {
    //     tt[i] = ss[i] + rng()%(sisa+1);
    //     sisa -= (tt[i]-ss[i]);
    // }
    // tt[0] = sisa;
    // rep(i,0,n) {
    //     int cur = rng()%3;
    //     while(ss[cur]==0) {
    //         cur = rng()%3;
    //     }
    //     s += pc[cur];
    //     ss[cur]--;
    //     cur = rng()%3;
    //     while(tt[cur]==0) {
    //         cur = rng()%3;
    //     }
    //     t += pc[cur];
    //     tt[cur]--;
    // }
    // cout <<n <<endl;
    // cout <<s <<endl;
    // cout <<t <<endl;
    vector<pii> ans;
    map<char,int> mp;
    mp['-'] = 0;
    mp['C'] = 1;
    mp['M'] = 2;
    vector q(3, vector(3, queue<int>()));
    rep(i,0,n) {
        q[mp[t[i]]][mp[s[i]]].push(i);
    }
    int bw = 0;
    int ct = 50;
    while(true) {
        ct--;
        if(bw==0) {
            if(sz(q[1][2]) + sz(q[2][1]) + sz(q[0][1]) + sz(q[0][2]) ==0) break;
            if(sz(q[1][0]) && sz(q[0][1])+sz(q[2][1])>0) {
                int fr = q[1][0].front(); q[1][0].pop();
                ans.push_back({0, fr+1});
                bw = 1;
                ans.push_back({1,-1});
            } else if(sz(q[2][0]) && sz(q[0][2]) + sz(q[1][2])>0) {
                int fr = q[2][0].front(); q[2][0].pop();
                ans.push_back({0, fr+1});
                bw = 2;
                ans.push_back({1,-1});
            }
        } else {
            if(sz(q[3-bw][bw])) {
                int fr = q[3-bw][bw].front(); q[3-bw][bw].pop();
                ans.push_back({0, fr+1});
                ans.push_back({2,-1});
                if(sz(q[0][3-bw])+sz(q[bw][3-bw])>0) {
                    ans.push_back({1,-1});
                    bw = 3-bw;
                } else {
                    bw = 0;
                }
            } else if(sz(q[0][bw])) {
                int fr = q[0][bw].front(); q[0][bw].pop();
                ans.push_back({0, fr+1});
                ans.push_back({2,-1});
                bw = 0;
            }
        }
        // if(ct<0) {
        //     cout <<bw <<endl;
        //     rep(i,0,3) {
        //         rep(j,0,3)  {
        //             cout <<i <<" " <<j <<endl;
        //             while(sz(q[i][j])) {
        //                 cout <<q[i][j].front() <<" ";
        //                 q[i][j].pop();
        //             }
        //             cout <<endl;
        //         }
        //     }
        //     break;
        // }
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        if(ans[i].fi==0) {
            cout <<"DRIVE ";
            cout <<ans[i].se;
        } else if(ans[i].fi==1) {
            cout <<"PICKUP";
        } else if(ans[i].fi==2) {
            cout <<"DROPOFF";
        }
        cout <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}