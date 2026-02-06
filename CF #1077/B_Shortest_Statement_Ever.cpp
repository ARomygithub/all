#include <bits/stdc++.h>
using namespace std;

#define int long long

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
int x,y,t;

void solve() {
    cin >>x >>y;
    int p = 0, q= 0;
    per(bit,29,-1) {
        int i = (x>>bit)&1;
        int j = (y>>bit)&1;
        if(i+j==2) {
            p += (1<<bit);
            per(k,bit-1,-1) {
                q += (1<<k);
            }
            break;
        } else if(i) {
            p += (1<<bit);
        } else if(j) {
            q += (1<<bit);
        }
    }
    int pp = 1;
    while(pp<=x) {
        pp *= 2;
    }
    int qq = 1;
    while(qq<=y) {
        qq *= 2;
    }
    if(abs(x-p)+abs(y-q) > abs(x-pp)+abs(y-qq)) {
        p = pp; q = qq;
    }
    int q2 = 0;
    per(bit,29,-1) {
        if((y>>bit)&1) {
            int ad = 1<<bit;
            if(ad==pp) {
                q2 += ad-1;
                if((y>>(bit+1)&1)==0) {
                    int coba = q2 - (ad-1) + ad*2;
                    if(abs(y-q2)> abs(y-coba)) {
                        q2 = coba;
                    }
                }
                break;
            } else {
                q2 += ad;
            }
        }
    }
    int p2 = 0;
    per(bit,29,-1) {
        if((x>>bit)&1) {
            int ad = 1<<bit;
            if(ad==qq) {
                p2 += ad-1;
                if((x>>(bit+1)&1) == 0) {
                    int coba = p2 - (ad-1) + ad*2;
                    if(abs(x-p2) > abs(x-coba)) {
                        p2 = coba;
                    }
                }
                break;
            } else {
                p2 += ad;
            }
        }
    }    
    if(abs(x-p)+abs(y-q) > abs(x-pp)+abs(y-q2)) {
        p = pp;
        q = q2;
    }
    if(abs(x-p)+abs(y-q) > abs(x-p2)+abs(y-qq)) {
        p = p2;
        q = qq;
    }
    cout <<p <<" " <<q <<"\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}