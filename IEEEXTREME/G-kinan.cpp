#include<bits/stdc++.h>
using namespace std;
#define pdl pair<double, long long>

long long n, x_1, y_1, x_2, y_2, g;
double m1, m2;
vector<pdl> gkanan, gkiri;
long long cur = 0, ans = 0;
long long plusbawah = 0, minbawah = 0, plusatas = 0, minatas = 0;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        g = abs(__gcd(abs(x_1), abs(y_1)));
        x_1 /= g; x_2 /= g;
        g = abs(__gcd(abs(x_2), abs(y_2)));
        x_2 /= g; y_2 /= g;
        
        if(x_1 < 0){
            m1 = (double) y_1/x_1;
            if(x_2 < 0){
                m2 = (double) y_2/x_2;
                gkiri.push_back({min(m1, m2), -1});
                gkiri.push_back({max(m1, m2), 1});
            }else if(x_2 > 0){
                m2 = (double) y_2/x_2;
                if(y_1*abs(x_2) + y_2*abs(x_1) < 0){
                    cur++;
                    gkiri.push_back({m1, -1});
                    gkanan.push_back({m2, 1});
                }else{
                    gkanan.push_back({m2, -1});
                    gkiri.push_back({m1, 1});
                }
            }else{
                if(y_2 < 0){
                    gkiri.push_back({m1, -1});
                    minbawah++; cur++;
                }else{
                    plusatas++;
                    gkiri.push_back({m1, 1});
                }
            }
        }else if(x_1 > 0){
            m1 = (double) y_1/x_1;
            if(x_2 < 0){
                m2 = (double) y_2/x_2;
                if(y_1*abs(x_2) + y_2*abs(x_1) < 0){
                    cur++;
                    gkiri.push_back({m2, -1});
                    gkanan.push_back({m1, 1});
                }else{
                    gkanan.push_back({m1, -1});
                    gkiri.push_back({m2, 1});
                }
 }else if(x_2 > 0){
                m2 = (double) y_2/x_2;
                gkanan.push_back({min(m1, m2), -1});
                gkanan.push_back({max(m1, m2), 1});
            }else{
                if(y_2 < 0){
                    gkanan.push_back({m1, 1});
                    plusbawah++; cur++;
                }else{
                    minatas++;
                    gkanan.push_back({m1, -1});
                }
            }
        }else{ // x_1 == 0
            m2 = (double) y_2/x_2;
            if(x_2 < 0){
                if(y_1 < 0){
                    gkiri.push_back({m2, -1});
                    minbawah++; cur++;
                }else{
                    plusatas++;
                    gkiri.push_back({m2, 1});
                }
            }else{
                if(y_1 < 0){
                    gkanan.push_back({m2, 1});
                    plusbawah++; cur++;
                }else{
                    minatas++;
                    gkanan.push_back({m2, -1});
                }
            }
        }
    }
    ans = cur;
    cur -= minbawah;
    ans = max(ans, cur);
    sort(gkanan.begin(), gkanan.end());
    for(int i=0; i<gkanan.size(); i++){
        cur -= gkanan[i].second;
        ans = max(ans, cur);
    }
    cur += plusatas;
    ans = max(ans, cur);
    cur -= minatas;
    ans = max(ans, cur);
    sort(gkiri.begin(), gkiri.end());
    for(int i=0; i<gkiri.size(); i++){
        cur -= gkiri[i].second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
