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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        deque<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        
 
        bool bisa = false;
        for(int i=0; i<n; i++){
            vector<int> v1, v2;
            for(int j=i; j<n; j++){
                v1.pb(a[j]);
                v2.pb(b[j]);
            }
            for(int j=0; j<i; j++){
                v1.pb(a[j]);
                v2.pb(b[j]);
            }
            vector<int> v;
            for(int j=0; j<n; j++){
                int temp = v2[j];
                v.pb(temp);
                while(j<n && v2[j] == temp){
                    j++;
                }
                j--;
            }
            int k = 0;
            for(int j=0; j<n; j++){
                if(v1[j] == v[k]){
                    k++;
                }
                if(k == v.size()){
                    bisa = true;
                    break;
                }
            }
            if(bisa){
                break;
            }
        }
        if(bisa){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
 
    return 0;
}