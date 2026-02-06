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

};
using P = Point<ll>;

double vec_angle(P a, P b, P c)
{
    P ab = b - a;
    P ac = c - a;
    ab = ab / (ab.dot(ab));
    ac = ac / (ac.dot(ac));
    double ans = acos(ab.dot(ac));
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

    int cross_sm[n] = {0};
    double ang_sum[n] = {0};

    for (int i = 0; i < n - 2; i++)
    {
        ll direction = (poly[i].cross(poly[i + 1], poly[i + 2]));
        double ang = vec_angle(poly[i], poly[i + 1], poly[i + 2]);
        if (direction == 0) cross_sm[i] = -1;
        else if (direction > 0LL) cross_sm[i] = -1;
        else cross_sm[i] = 1;

        ang_sum[i] = ang;
    }
    for (int j = 1; j < n - 2; j++)
    {
        cross_sm[j] += cross_sm[j - 1];
        ang_sum[j] += ang_sum[j - 1];
    }

    auto subsum = [&](int l, int r)
    {
        assert(r - l >= 2);
        ll cross_res = cross_sm[r - 2] - ( l > 0 ? cross_sm[l - 1] : 0 );
        double angle_res = ang_sum[r - 2] - ( l > 0 ? ang_sum[l - 1] : 0 );
        return make_pair(cross_res, angle_res);
    };

    int ok = 3;
    int ng = n + 1;
    while (ng - ok > 1) 
    {
        int mid = (ok + ng) >> 1;
        int le = mid;
        bool found = 0;
        for (int l = 0; l + le - 1 < n; l++)
        {
            int r = l + le - 1;
            auto [base, ang] = subsum(l, r);
            ll direction1 = (poly[r].cross(poly[l], poly[l + 1]));
            ll direction2 = (poly[r - 1].cross(poly[r], poly[l]));
            
            if (direction1 == 0) direction1 = 0;
            else if (direction1 > 0LL) direction1 = -1;
            else direction1 = 1;
            if (direction2 == 0) direction2 = 0;
            else if (direction2 > 0LL) direction2 = -1;
            else direction2 = 1;
            
            base += (direction1 + direction2);

            double req_angle = (double)3.141592653589793 * (le - 2);
            ang = ang + vec_angle(poly[r - 1], poly[r], poly[l]);
            ang = ang + vec_angle(poly[r], poly[l], poly[l + 1]);

            bool ang_yes = abs(req_angle - ang) < 1e-6;
            found = found || ( base == le );
            // found = found || ( base == le  && ang_yes );
            what_is(ang)
            what_is(req_angle)
            what_is(base)
            what_is(le)
            if (found) break; 
        }
        if (found) ok = mid;
        else ng = mid;
    }

    int le = ok;
    bool found = 0;
    for (int l = 0; l + le - 1 < n; l++)
    {
        int r = l + le - 1;
        auto [base, ang] = subsum(l, r);
        ll direction1 = (poly[r].cross(poly[l], poly[l + 1]));
        ll direction2 = (poly[r - 1].cross(poly[r], poly[l]));
        
        if (direction1 == 0) direction1 = 0;
        else if (direction1 > 0LL) direction1 = -1;
        else direction1 = 1;
        if (direction2 == 0) direction2 = 0;
        else if (direction2 > 0LL) direction2 = -1;
        else direction2 = 1;
        
        base += (direction1 + direction2);


        double req_angle = (double)180 * (le - 2);
        ang = ang + vec_angle(poly[r - 1], poly[r], poly[l]);
        ang = ang + vec_angle(poly[r], poly[l], poly[l + 1]);

        bool ang_yes = abs(req_angle - ang) < 1e-6;
        found = found || ( base == le  && ang_yes );
        if (found) break; 
    }
    ll ans;
    if (found) ans = ok;
    else ans = 0;
    cout << ans << '\n';
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