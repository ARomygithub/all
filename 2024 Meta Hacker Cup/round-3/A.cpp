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

const int mxn=25e2;
int n,k,t;
string s[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>s[i];
    }
    int l=n-1,r=0,u=n-1,d=0;
    vi le(n,-1), ri(n,-1);
    int l0=n-1,r0=0,u0=n-1,d0=0;
    rep(i,0,n) {
        rep(j,0,n) {
            if(s[i][j]=='1') {
                min_self(l,j);
                max_self(r,j);
                min_self(u,i);
                max_self(d,i);
            } else if(s[i][j]=='?') {
                min_self(l0,j);
                max_self(r0,j);
                min_self(u0,i);
                max_self(d0,i);
                if(le[i]==-1) {
                    le[i] = j;
                    ri[i] = j;
                } else {
                    min_self(le[i],j);
                    max_self(ri[i],j);
                }
            }
        }
    }
    int ans = 1;
    int len1 = max(1, d-u+1), len2 = max(1,r-l+1);
    max_self(ans, len1*len2);
    if(k>=4) {
        cout <<(max(d,d0)-min(u,u0)+1)*(max(r,r0)-min(l,l0)+1) <<"\n";
    } else if(k==1) {
        rep(i,0,n) {
            if(le[i]==-1) continue;
            int x = i, y = le[i];
            max_self(ans, (max(d,x)-min(u,x)+1)*(max(r,y)-min(l,y)+1));
        }
        rep(i,0,n) {
            if(ri[i]==-1) continue;
            int x = i, y = ri[i];
            max_self(ans, (max(d,x)-min(u,x)+1)*(max(r,y)-min(l,y)+1));
        }
        cout <<ans <<"\n";
    } else if(k==2) {
        rep(i1,0,n) {
            rep(i2,0,n) {
                if(le[i1]==-1 || ri[i2]==-1) continue;
                int x1 = i1, y1 = le[i1], x2=i2, y2 = ri[i2];
                if(x1>x2) swap(x1,x2);
                if(y1>y2) swap(y1,y2);
                max_self(ans, (max(d,x2)-min(u,x1)+1)*(max(r,y2)-min(l,y1)+1));
            }
        }
        cout <<ans <<"\n";
    } else if(k==3) {
        rep(i1,0,n) {
            rep(i2,0,n) {
                if(le[i1]==-1 || ri[i2]==-1) continue;
                int x1 = i1, y1 = le[i1], x2=i2, y2 = ri[i2];
                if(x1>x2) swap(x1,x2);
                if(y1>y2) swap(y1,y2);
                max_self(ans, (max(d,max(x2,d0))-min(u,x1)+1)*(max(r,y2)-min(l,y1)+1));
                max_self(ans, (max(d,x2)-min(u,min(u0,x1))+1)*(max(r,y2)-min(l,y1)+1));
                max_self(ans, (max(d,x2)-min(u,x1)+1)*(max(r,max(y2,r0))-min(l,y1)+1));
                max_self(ans, (max(d,x2)-min(u,x1)+1)*(max(r,y2)-min(l,min(y1,l0))+1));            
            }
        }
        cout <<ans <<"\n";        
    } else if(k==0) {
        cout <<ans <<"\n";
    }
}

void main_() {
    // implement your solution here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }    
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}