#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll avg = sum / n;

    vector<ll> x(n), y(n);
    int j = -1;
    for(int i=0; i<n; i++){
        if(a[i] != avg){
            j=i;
            break;
        }
    }
    if(j==-1){
        cout << 0 << "\n";
    } else {
        x[0] = a[j];
        for(int i=j+1; i%n != j; i = (i+1)%n){
            x[(i-j+n)%n] = a[i];
        }
        y[0] = a[j];
        for(int i=j-1; i%n!=j; i = (i + n-1)%n){
            y[(j-i+n)%n] = a[i];
        }
        

        vector<ll> prefx(n), prefy(n);
        prefx[0] = x[0];
        prefy[0] = y[0];
        int l = -1, r = -1;
        ll mn = 1e9;
        for(int i=1; i<n; i++){
            prefx[i] = prefx[i-1] + x[i];
            prefy[i] = prefy[i-1] + y[i];

            if(l == -1 && prefx[i] == avg * 1LL*(i+1)){
                l = i+1;
            }
            if(r == -1 && prefy[i] == avg * 1LL*(i+1)){
                r = i+1;
            }
        }

        int l1 = -1, r1 = -1;
        map<ll, int> m;
        for(int i=1; i<n; i++){
            m[prefy[i]-y[0]] = i+1;
        }

        for(int i=1; i<n; i++){
            
        }


    }






    return 0;
}