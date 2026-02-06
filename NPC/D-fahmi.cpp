#include<bits/stdc++.h>
#define ll long long

using namespace std;

typedef struct{
    ll p;
    ll l;
    ll t;
    ll msh;
    bool is_box;
} Bangun;

vector<Bangun> bangunn;

void push_bangunn(bool is_box, int p, int l, int t){
    Bangun pyr;
    pyr.p = p;
    pyr.l = l;
    pyr.t = t;
    pyr.msh = t;
    pyr.is_box = is_box;
    bangunn.push_back(pyr);
}

bool compare(Bangun a, Bangun b){
    return a.p * a.l >= b.p * b.l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int c; ll p,l,t;
        cin >> c >> p >> l >> t;
        if(c==0){
            push_bangunn(false,p,l,t);
            push_bangunn(false,l,p,t);
        }
        else{
            push_bangunn(true,p,l,t);
            push_bangunn(true,l,p,t);
            push_bangunn(true,p,t,l);
            push_bangunn(true,t,p,l);
            push_bangunn(true,t,l,p);
            push_bangunn(true,l,t,p);
        }
    }

    sort(bangunn.begin(), bangunn.end(), compare);
    for(int i=1; i<bangunn.size(); i++){
        for(int j=0; j<i; j++){
            if(bangunn[i].p < bangunn[j].p && bangunn[i].l < bangunn[j].l && bangunn[i].msh < bangunn[j].msh + bangunn[i].t && bangunn[j].is_box){
                bangunn[i].msh = bangunn[j].msh + bangunn[i].t;
            }
        }
    }

    ll max = -1;
    for ( int i = 0; i < bangunn.size(); i++ )
        if ( max < bangunn[i].msh )
            max = bangunn[i].msh;
    cout << max << '\n';
}