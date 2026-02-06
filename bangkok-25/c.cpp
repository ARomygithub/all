#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i= a; i < (b);i++)
#define per(i,a,b) for(int i= a; i > (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second

int x; 

void solve() {
    cin >>x;
    if(x==1) {
        cout <<"1\n1\n";
    } else if(x==3) {
        cout <<"2\n1+2\n";
    } else if(x==-1) {
        cout <<"2\n1-2\n";
    } else if(x==6) {
        cout <<"3\n1+2+3\n";
    } else if(x==2) {
        cout <<"3\n1-2+3\n";
    } else if(x==0) {
        cout <<"3\n1+2-3\n";
    } else if(x==-4) {
        cout <<"3\n1-2-3\n";
    } else {
        ll le = 4, ri = abs(x);
        ll n = -1;
        while(le<=ri) {
            ll mid = (le+ri)/2;
            ll N = mid*(mid+1)/2;
            if(N >= abs(x)) {
                n = mid;
                ri = mid-1;
            } else {
                le = mid+1;
            }
        }
        while(true) {
            ll N = n*(n+1)/2;
            if((N%2)!=(abs(x)%2)) {
                n++;
                continue;
            }
            ll s = (N-x)/2;
            if(s>=0 && s<=N-1 && s!=1 && s!=N-2) {
                vi v;
                per(i,n,0) {
                    if(s>=i) {
                        v.push_back(i);
                        s -= i;
                        if(s==0) break;
                    }
                }
                if(sz(v) && v.back()==1) {
                    assert(sz(v)>=2);
                    v[sz(v)-2]--;
                    v[sz(v)-1]++;
                }
                cout <<n <<"\n";
                set<int> st(all(v));
                cout <<"1";
                rep(i,2,n+1) {
                    if(st.count(i)) {
                        cout <<"-" <<i;
                    } else {
                        cout <<"+" <<i;
                    }
                }
                cout <<"\n";
                break;
            }
            n++;
        }
    }
}

const int mxn = 2e5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
    // rep(i,53015,mxn+1) {
    //     x = i;
    //     cout <<"tes" <<i <<endl;
    //     solve();
    // }
}