#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
typedef double db;
int sgn(int x) {
    return x<0?-1:x>0;
}
struct Point {
    int x,y;
    Point operator +(const Point &s) const{
        return {x+s.x,y+s.y};
    }
    Point operator -(const Point &s) const{
        return {x-s.x,y-s.y};
    }
    bool operator ==(const Point &s) const{
        return x==s.x && y==s.y;
    }
    db Len() const{
        return sqrt(x*x+y*y);
    }
};
int dot(Point a,Point b) {
    return a.x*b.x+a.y*b.y;
}
int det(Point a,Point b) {
    return a.x*b.y-a.y*b.x;
}
bool in_segment(Point a,Point b,Point c,bool strict=1) {
    // cerr << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << ' ' << c.x << ' ' << c.y << endl;
    if(strict) return det(b-a,c-a)==0 && dot(a-c,b-c)<0;
    return det(b-a,c-a)==0 && dot(a-c,b-c)<=0;
}
bool intersection(Point a,Point b,Point c,Point d) {
    return sgn(det(b-a,c-a))*sgn(det(b-a,d-a))==-1 && sgn(det(d-c,a-c))*sgn(det(d-c,b-c))==-1;
}
const int N=205;
Point a[N],b[N];
pair<pair<int,db>,int> q[N];
db dis[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n-1) cin >> a[i].x >> a[i].y;
    FOR(i,0,m-1) cin >> b[i].x >> b[i].y;
    FOR(i,0,m-1) {
        FOR(j,0,n-1) {
            if(in_segment(a[j],a[(j+1)%n],b[i],0)) {
                // cerr << " -- " << endl;
                q[i]={{j,(b[i]-a[j]).Len()},i};
                break;
            }
        }
    }
    sort(q,q+m);
    FOR(i,n,n+m-1) a[i]=b[i-n];
    FOR(i,0,n+m-1) FOR(j,0,n+m-1) {
        dis[i][j]=1e9;
        if(i==j) dis[i][j]=0;
        int w=1;
        FOR(k,0,n-1) {
            if(intersection(a[i],a[j],a[k],a[(k+1)%n])) {
                w=0;
                break;
            }
        }
        FOR(k,0,n-1) {
            if(in_segment(a[i],a[j],a[k])) {
                Point p=a[(k+1)%n]-a[k],q=a[(k-1+n)%n]-a[k];
                if(det(p,q)<=0) {
                    if(sgn(det(a[j]-a[i],p))*sgn(det(a[j]-a[i],q))<0) {
                        w=0;
                        break;
                    }
                } else {
                    w=0;
                    break;
                }
            }
        }
        FOR(k,0,n-1) {
            if(in_segment(a[k],a[(k+1)%n],a[i])) {
                if(det(a[(k+1)%n]-a[k],a[j]-a[i])>=0) ;
                else {
                    w=0;
                    break;
                }
            }
            if(in_segment(a[k],a[(k+1)%n],a[j])) {
                if(det(a[(k+1)%n]-a[k],a[i]-a[j])>=0) ;
                else {
                    w=0;
                    break;
                }
            }
        }
        FOR(k,0,n-1) {
            if(a[k]==a[i]) {
                Point p=a[(k+1)%n]-a[k],q=a[(k-1+n)%n]-a[k];
                Point e=a[j]-a[i];
                if(det(p,q)>=0) {
                    if(det(p,e)>=0 && det(e,q)>=0) ;
                    else {
                        w=0;
                        break;
                    }
                } else {
                    if(det(p,e)>=0 || det(e,q)>=0) ;
                    else {
                        w=0;
                        break;
                    }
                }
            }
            if(a[k]==a[j]) {
                Point p=a[(k+1)%n]-a[k],q=a[(k-1+n)%n]-a[k];
                Point e=a[i]-a[j];
                if(det(p,q)>=0) {
                    if(det(p,e)>=0 && det(e,q)>=0) ;
                    else {
                        w=0;
                        break;
                    }
                } else {
                    if(det(p,e)>=0 || det(e,q)>=0) ;
                    else {
                        w=0;
                        break;
                    }
                }
            }
        }
        if(w) {
            dis[i][j]=(a[i]-a[j]).Len();
        }
    }
    FOR(k,0,n+m-1) FOR(i,0,n+m-1) FOR(j,0,n+m-1) {
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    db res=0;
    FOR(i,0,m-1) {
        // cerr << q[i].second << '-' << q[(i+1)%m].second << endl;
        res+=dis[n+q[i].second][n+q[(i+1)%m].second];
    }
    cout << res << '\n';
    return 0;
}