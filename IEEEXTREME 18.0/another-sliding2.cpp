#pragma GCC optimize("Ofast")

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

const int mxn=1e5;
int n,q;
int a[mxn];

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    int mset = -inf, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            max_self(val, x);
            max_self(mset, x);
        }
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != -inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = -inf;
    }
    void reset() {
        mset = -inf, val = -inf;
        if(l) {
            l->reset();
        }
        if(r) {
            r->reset();
        }
    }
};

void solve() {
    cin >>n >>q;
    rep(i,0,n) {
        cin >>a[i];
    }
    vector<ll> pr(n+1,0);
    rep(i,0,n) {
        pr[i+1] = pr[i] + a[i];
    }
    // Node vle(0,n);
    while(q--) { //O(q.n.lg n)
        int x; cin >>x;
        vi r(n);
        // vle.reset();
        iota(all(r),0);
        {
            int le = -1;
            int li = 0, ri = n-2;
            while(li<=ri) {
                int mid = (li+ri)/2;
                if(a[mid]+a[mid+1]<=x) {
                    le = mid;
                    li = mid+1;
                } else {
                    ri = mid-1;
                }
            }
            if(le!=-1) {
                int rr = le+1;
                per(i,le,-1) {
                    while(rr<n && a[i]+a[rr]<=x) {
                        rr++;
                    }
                    r[i] = rr;
                }
            }
            rep(i,0,n) {
                if(a[i]<=x) {
                    max_self(r[i], i+1);
                }
            }
            // rep(i,0,n) {
            //     auto it = upper_bound(a+i,a+n, x-a[i])-a;
            //     if(it>i) {
            //         r[i] = it;
            //     } else {
            //         if(a[i]<=x) {
            //             r[i] = i+1;
            //         } else {
            //             r[i] = i;
            //         }
            //     }
            // }
        }
        // debug() <<imie(r);
        ll ans = 0;
        vi vle(n,-1);
        rep(i,0,n) {
            int ri = r[i];
            if((ri%2)==(i%2)) {
                ri++;
            }
            int ctr = (i+ri)/2;
            if(ctr<n) {
                // vle.set(ctr,n, i);
                max_self(vle[ctr], i);
            }
        }
        rep(i,0,n) {
            if(i) {
                max_self(vle[i], vle[i-1]);
            }
        }
        for(int i=1;i<n*2-1;i+=2) {
            int pos = i/2;
            // int le = vle.query(pos,pos+1);
            int le = vle[pos];
            // debug() <<imie(i) imie(pos) imie(le);
            if(le<0) {
                le = 0;
            } else {
                le++;
            }
            int dist = min(pos, n-1 - (pos+1));
            if(dist<0) continue;
            max_self(le,pos-dist);
            if(le<=pos) {
                int knn = pos*2-le;
                if(i%2) {
                    knn++;
                }
                // debug() <<imie(knn);                
                if(i%2) {
                    ans += (pr[knn+1]-pr[pos+1]) - (pr[pos+1]-pr[le]);
                }
            }
        }
        // // pos = p-1 given a[knn+1]<=x
        rep(i,0,n-2) {
            // int le = vle.query(i,i+1);
            int le = vle[i];
            if(le<0) {
                le = 0;
            } else {
                le++;
            }
            int dist = min(i, n-1 - (i+1));
            max_self(le,i-dist);   
            // debug() <<imie(i) imie(le);         
            if(le<=i) {
                int knn = i*2-le+1;
                if(!(knn+1 <n && a[knn+1]<=x)) {
                    knn--; le++;
                }
                // debug() <<imie(le) <<imie(knn);
                if(le<knn && knn+1<n && a[knn+1]<=x) {
                    // debug() <<imie((pr[knn+2] - pr[i+2]) - (pr[i+1]-pr[le]));
                    ans += (pr[knn+2] - pr[i+2]) - (pr[i+1]-pr[le]);
                }
            }
        }
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}