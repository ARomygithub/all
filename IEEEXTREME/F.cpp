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

struct ST {
    struct node {
        int ctp, cte, ctk, cto;
    } sti[1<<16];
    void upd(int l1, char c, int i, int l2, int r2) {
        if(l2==r2) {
            sti[i].ctp = (c=='p');
            sti[i].cte = (c=='e');
            sti[i].ctk = (c=='k');
            sti[i].cto = (c=='o');
            return;
        }
        int m2 = (l2+r2)/2;
        if(l1<=m2) {
            upd(l1,c,2*i,l2,m2);
        } else {
            upd(l1,c,2*i+1,m2+1,r2);
        }
        sti[i].ctp = sti[2*i].ctp + sti[2*i+1].ctp;
        sti[i].cte = sti[2*i].cte + sti[2*i+1].cte;
        sti[i].ctk = sti[2*i].ctk + sti[2*i+1].ctk;
        sti[i].cto = sti[2*i].cto + sti[2*i+1].cto;                        
    }
    int qryP(int l1, int r1, int i, int l2, int r2) {
        if(l1<=l2 && r2<=r1) {
            return sti[i].ctp;
        }
        int m2=(l2+r2)/2;
        return (l1<=m2?qryP(l1,r1,2*i,l2,m2):0) + (r1>m2?qryP(l1,r1,2*i+1,m2+1,r2):0);
    }
    int qryE(int l1, int r1, int i, int l2, int r2) {
        if(l1<=l2 && r2<=r1) {
            return sti[i].cte;
        }
        int m2=(l2+r2)/2;
        return (l1<=m2?qryE(l1,r1,2*i,l2,m2):0) + (r1>m2?qryE(l1,r1,2*i+1,m2+1,r2):0);
    }
    int qryK(int l1, int r1, int i, int l2, int r2) {
        if(l1<=l2 && r2<=r1) {
            return sti[i].ctk;
        }
        int m2=(l2+r2)/2;
        return (l1<=m2?qryK(l1,r1,2*i,l2,m2):0) + (r1>m2?qryK(l1,r1,2*i+1,m2+1,r2):0);
    }
    int qryO(int l1, int r1, int i, int l2, int r2) {
        if(l1<=l2 && r2<=r1) {
            return sti[i].cto;
        }
        int m2=(l2+r2)/2;
        return (l1<=m2?qryO(l1,r1,2*i,l2,m2):0) + (r1>m2?qryO(l1,r1,2*i+1,m2+1,r2):0);
    }
} st0, st1, st2, st3;

string s;
int n,m;

void solve() {
    cin >>s;
    n = s.length();
    int n0=(n/4)+((n%4)>=1);
    int n1=(n/4)+((n%4)>=2);
    int n2=(n/4)+((n%4)>=3);
    int n3=(n/4);
    cin >>m;
    for(int i=0;i<n;i+=4) {
        st0.upd(i/4,s[i],1,0,n0);
    }
    for(int i=1;i<n;i+=4) {
        st1.upd((i-1)/4,s[i],1,0,n1);
    }
    for(int i=2;i<n;i+=4) {
        st2.upd((i-2)/4,s[i],1,0,n2);
    }
    for(int i=3;i<n;i+=4) {
        st3.upd((i-3)/4,s[i],1,0,n3);
    }
    while(m--) {
        int j; char c; cin >>j >>c; j--;
        if((j%4)==0) {
            st0.upd(j/4,c,1,0,n0);
        } else if((j%4)==1) {
            st1.upd((j-1)/4,c,1,0,n1);
        } else if((j%4)==2) {
            st2.upd((j-2)/4,c,1,0,n2);
        } else if((j%4)==3) {
            st3.upd((j-3)/4,c,1,0,n3);
        }
        int i,k; cin >>i >>k; i--;
        int ans=k*4;
        if((i%4)==0) {
            ans -=st0.qryP(i/4,(i/4)+k-1,1,0,n0);
            ans -=st1.qryE(i/4,(i/4)+k-1,1,0,n1);
            ans -=st2.qryK(i/4,(i/4)+k-1,1,0,n2);
            ans -=st3.qryO(i/4,(i/4)+k-1,1,0,n3);
        } else if((i%4)==1) {
            ans -=st0.qryO((i-1)/4+1,(i-1)/4+k-1+1,1,0,n0);
            ans -=st1.qryP((i-1)/4,(i-1)/4+k-1,1,0,n1);
            ans -=st2.qryE((i-1)/4,(i-1)/4+k-1,1,0,n2);
            ans -=st3.qryK((i-1)/4,(i-1)/4+k-1,1,0,n3);
        } else if((i%4)==2) {
            ans -=st0.qryK((i-2)/4+1,(i-2)/4+k-1+1,1,0,n0);
            ans -=st1.qryO((i-2)/4+1,(i-2)/4+k-1+1,1,0,n1);
            ans -=st2.qryP((i-2)/4,(i-2)/4+k-1,1,0,n2);
            ans -=st3.qryE((i-2)/4,(i-2)/4+k-1,1,0,n3);
        } else {
            ans -=st0.qryE((i-3)/4+1,(i-3)/4+k-1+1,1,0,n0);
            ans -=st1.qryK((i-3)/4+1,(i-3)/4+k-1+1,1,0,n1);
            ans -=st2.qryO((i-3)/4+1,(i-3)/4+k-1+1,1,0,n2);
            ans -=st3.qryP((i-3)/4,(i-3)/4+k-1,1,0,n3);
        }
        cout <<ans <<"\n";
        // if((j%4)==0) {
        //     st0.upd(j/4,s[j],1,0,n0);
        // } else if((j%4)==1) {
        //     st1.upd((j-1)/4,s[j],1,0,n1);
        // } else if((j%4)==2) {
        //     st2.upd((j-2)/4,s[j],1,0,n2);
        // } else if((j%4)==3) {
        //     st3.upd((j-3)/4,s[j],1,0,n3);
        // }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}