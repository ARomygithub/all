#include<bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define ll long long
#define ar array
 
const int mxn= 2e5, mod=1e9+7;
int n, q;
ll xa[mxn];

struct node {
    ll ct, mxl, mxr;
    bool nd=true;
} st[1<<19];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
    if(l2==r2) {
        st[i].ct=1;
        st[i].mxl=1;
        st[i].mxr=1;
        st[i].nd=true;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1<=m2) {
        upd(l1,x,2*i,l2,m2);
    } else {
        upd(l1,x,2*i+1,m2+1,r2);
    }
    st[i].mxl= st[2*i].mxl==(m2-l2+1)&&xa[m2]<=xa[m2+1]?st[2*i].mxl+st[2*i+1].mxl:st[2*i].mxl;
    st[i].mxr= st[2*i+1].mxr==(r2-m2)&&xa[m2]<=xa[m2+1]?st[2*i+1].mxr+st[2*i].mxr:st[2*i+1].mxr;
    st[i].ct = st[2*i].ct + st[2*i+1].ct + (xa[m2]<=xa[m2+1]?st[2*i].mxr*st[2*i+1].mxl:0ll);
    st[i].nd = st[2*i].nd && st[2*i+1].nd && (xa[m2]<=xa[m2+1]);
}

bool qry4(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].nd;
    }
    int m2=(l2+r2)/2;
    return (l1<=m2?qry4(l1,r1,2*i,l2,m2):true) && (r1>m2?qry4(l1,r1,2*i+1,m2+1,r2):true) &&(l1<=m2&&r1>m2?xa[m2]<=xa[m2+1]:true);
    // return (l1<=m2?qry(l1,r1,2*i,l2,m2):0) + (r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0);
}

ll qry2(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mxl;
    }
    int m2=(l2+r2)/2;
    if(l1<=m2 && r1>m2) {
        if(qry4(l1,r1,2*i,l2,m2) && xa[m2+1]>=xa[m2]) {
            return qry2(l1,r1,2*i+1,m2+1,r2)+(ll)m2-l1+1;
        } else {
            return qry2(l1,r1,2*i,l2,m2);
        }
    } else if(l1<=m2) {
        return qry2(l1,r1,2*i,l2,m2);
    } else if(r1>m2) {
        return qry2(l1,r1,2*i+1,m2+1,r2);
    }
}

ll qry3(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].mxr;
    }
    int m2=(l2+r2)/2;
    if(l1<=m2 && r1>m2) {
        if(qry4(l1,r1,2*i+1,m2+1,r2) && xa[m2]<=xa[m2+1]) {
            return qry3(l1,r1,2*i,l2,m2)+(ll)r1-m2;
        } else {
            return qry3(l1,r1,2*i+1,m2+1,r2);
        }
    } else if(l1<=m2) {
        return qry3(l1,r1,2*i,l2,m2);
    } else if(r1>m2) {
        return qry3(l1,r1,2*i+1,m2+1,r2);
    }
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
    if(l1<=l2 && r2<=r1) {
        return st[i].ct;
    }
    int m2=(l2+r2)/2;
    return (l1<=m2?qry(l1,r1,2*i,l2,m2):0ll) + (r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0ll) +(l1<=m2&&r1>m2&&qry4(l1,r1,2*i,l2,m2)&&xa[m2]<=xa[m2+1]?qry3(l1,r1,2*i,l2,m2)*qry2(l1,r1,2*i+1,m2+1,r2):0ll);
    // return (l1<=m2?qry(l1,r1,2*i,l2,m2):0) + (r1>m2?qry(l1,r1,2*i+1,m2+1,r2):0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>xa[i]; upd(i,xa[i]);
    }
    while(q--) {
        int qt, a,b; cin >>qt >>a >> b;
        if(qt==2) {
            a--, b--;
            cout <<qry(a,b) <<"\n";
        }
        else {
            a--;
            xa[a]=b;
            upd(a,b);
        }
    }
    for(int i=0;i<=4;i++) {
        for(int j=i;j<=4;j++) {
            cout <<i+1 <<j+1 <<"\n";
            debug() << imie(qry4(i,j)) <<"\n";
            debug() << imie(qry2(i,j)) <<"\n";
            debug() << imie(qry3(i,j)) <<"\n";
            debug() << imie(qry(i,j)) <<"\n";
        }
    }
}