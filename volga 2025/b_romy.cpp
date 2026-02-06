#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<(b);i++)
#define per(i,a,b) for(int i=a;i>(b);i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

#define what_is(x) cerr << #x << ": " << x << endl;

template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

template<class T> int sgn(T x) { return (x>0) - (x<0); }
template<class T>
struct Point
{
    using P = Point<ll>;
    T x, y;
    explicit Point(T x=0, T y=0): x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const {return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    double angle() const { return atan2(y, x); }
};
using P = Point<ll>;

double vec_angle(P a, P b, P c)
{
    P ab = b - a;
    P ac = c - a;
    return acos(ab.dot(ac));
}

const int mxn = 2e5;
P poly[mxn];
int n;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >> poly[i].x >> poly[i].y;
    }

    // int cross_sm[n] = {0};

    // for (int i = 0; i < n - 2; i++)
    // {
    //     ll direction = (poly[i].cross(poly[i + 1], poly[i + 2]));
    //     if (direction == 0) cross_sm[i] = -1;
    //     else if (direction > 0LL) cross_sm[i] = -1;
    //     else cross_sm[i] = 1;
    // }
    // for (int j = 1; j < n - 2; j++)
    // {
    //     cross_sm[j] += cross_sm[j - 1];
    // }

    // auto subsum = [&](int l, int r)
    // {
    //     assert(r - l >= 2);
    //     return cross_sm[r - 2] - ( l > 0 ? cross_sm[l - 1] : 0 );

    // };

    vi ri(n,-1);
    for(int i=0;i<n;) {
        int j = i+2;
        while(j<n) {
            bool ok = poly[j-2].cross(poly[j-1],poly[j])< 0;
            if(!ok) break;
            // angle poly[j-1] di antara poly[j-2] dan poly[i]
            // if(j==i+2) {
            //     ri[i] = j;
            // } else {
                while(i<=j-2) {
                    if(i==j-2) {
                        ri[i] = j;
                        break;
                    }
                    double ale = (poly[j-1]-poly[j-2]).angle(), ari = (poly[i+1]-poly[i]).angle();
                    double cur = (poly[j]-poly[j-1]).angle();
                    if(ale>ari) {
                        if(cur < ale && cur > ari) {
                            ok = 1;
                        } else {
                            ok = 0;
                        }
                    } else {
                        if(cur < ale || cur > ari) {
                            ok = 1;
                        } else {
                            ok = 0;
                        }
                    }
                    if(ok) {
                        ri[i] = j;
                        break;
                    } else {
                        ri[i] = j-1;
                        i++;
                    }
                }
            // }
            j++;
        }
        i = j-1;
    }
    // rep(i,0,n) {
    //     what_is(i)
    //     what_is(ri[i])
    // }
    int ok = 3;
    int ng = n;
    int ansi = 0;
    while (ok <= ng) 
    {
        int mid = (ok + ng) >> 1;
        // what_is("=======")
        // what_is(mid)
        int le = mid;
        bool found = 0;
        for (int l = 0; l + le - 1 < n; l++)
        {
            int r = l + le - 1;
            bool oki = (ri[l]>=r);
            if(!oki) continue;
            // what_is(l)
            // what_is(r)
            ll direction1 = (poly[r].cross(poly[l], poly[l + 1]));
            ll direction2 = (poly[r - 1].cross(poly[r], poly[l]));
            double ale = (poly[r]-poly[r-1]).angle();
            double ari = (poly[l+1]-poly[l]).angle();
            double cur = (poly[l]-poly[r]).angle();
            if(ale>ari) {
                if(cur < ale && cur > ari) {
                    oki = 1;
                } else {
                    oki = 0;
                }
            } else {
                if(cur < ale || cur > ari) {
                    oki = 1;
                } else {
                    oki = 0;
                }
            }            
            if(!oki) continue;
            // what_is(direction1)
            // what_is(direction2)
            
            if (direction1 == 0) direction1 = 0;
            else if (direction1 > 0LL) direction1 = -1;
            else direction1 = 1;
            if (direction2 == 0) direction2 = 0;
            else if (direction2 > 0LL) direction2 = -1;
            else direction2 = 1;

            int bs = (direction1 + direction2);
            // what_is(base)
            found = found || ( bs == 2 );
            if (found) break; 
        }
        if (found) {
            ok = mid+1;
            ansi = mid;
        }
        else ng = mid-1;
        // what_is(ok)
        // what_is(ng)
    }
    cout << ansi << '\n';
    // int ans = 0;
    // for(int i=0;i<n;) {
    //     int j=i+2;
    //     while(j<n) {
    //         bool ok = poly[j-2].cross(poly[j-1],poly[j]) < 0;
    //         if(!ok) break;
    //         int le = i, ri = j-2;
    //         int cur = -1;
    //         while(le<=ri) {
    //             int mid = (le+ri)/2;
    //             bool ok2 = (poly[j-1].cross(poly[j],poly[mid])<0) && (poly[j].cross(poly[mid],poly[mid+1])<0);
    //             // bool ok2 = poly[j-1].cross(poly[j],poly[mid])<0;
    //             if(ok2) {
    //                 cur = mid;
    //                 ri = mid-1;
    //             } else {
    //                 le = mid+1;
    //             }
    //         }
    //         if(poly[j].cross(poly[cur],poly[cur+1])<0) {
    //             max_self(ans, j-cur+1);
    //         }
    //         j++;
    //     }
    //     i = j-1;
    // }
    // reverse(poly,poly+n);
    // for(int i=0;i<n;) {
    //     int j=i+2;
    //     while(j<n) {
    //         bool ok = poly[j-2].cross(poly[j-1],poly[j]) > 0;
    //         if(!ok) break;
    //         int le = i, ri = j-2;
    //         int cur = -1;
    //         while(le<=ri) {
    //             int mid = (le+ri)/2;
    //             bool ok2 = (poly[j-1].cross(poly[j],poly[mid])>0) && (poly[j].cross(poly[mid],poly[mid+1])>0);
    //             // bool ok2 = poly[j-1].cross(poly[j],poly[mid])>0;
    //             if(ok2) {
    //                 cur = mid;
    //                 ri = mid-1;
    //             } else {
    //                 le = mid+1;
    //             }
    //         }
    //         if(poly[j].cross(poly[cur],poly[cur+1])>0) {
    //             max_self(ans, j-cur+1);
    //         }
    //         j++;
    //     }
    //     i = j-1;
    // }    
    // cout <<ans <<"\n";
}

int  main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; 
    cin >>t;
    while(t--) {
        solve();
    }
}