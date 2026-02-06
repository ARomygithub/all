#include<bits/stdc++.h>

using namespace std;
int n, ironman[2], k, res=0;
int ultron[1000][2];
int side[100][4];
int garis_ultron[1000][3];
int garis_side[100][3];

void garis_ultron_generator(int i, int x1, int y1, int x2, int y2){
    garis_ultron[i][0] = (y2-y1);
    garis_ultron[i][1] = (x1-x2);
    garis_ultron[i][2] = ((x2-x1)*y1 - (y2-y1)*x1);
}

void garis_side_generator(int i, int x1, int y1, int x2, int y2){
    garis_side[i][0] = (y2-y1);
    garis_side[i][1] = (x1-x2);
    garis_side[i][2] = ((x2-x1)*y1 - (y2-y1)*x1);
}

bool bentrok(int ux, int uy, int x1, int y1, int x2, int y2, int i, int j) {
    if((garis_side[j][0]*ironman[0]+garis_side[j][1]*ironman[1]+garis_side[j][2]>0 && garis_side[j][0]*ux+garis_side[j][1]*uy+garis_side[j][2]<0) || (garis_side[j][0]*ironman[0]+garis_side[j][1]*ironman[1]+garis_side[j][2]<0 && garis_side[j][0]*ux+garis_side[j][1]*uy+garis_side[j][2]>0)) {
        return 1;
    }
    if((garis_ultron[i][0]*x1+garis_ultron[i][1]*y1+garis_ultron[i][2]>0 && garis_ultron[i][0]*x2+garis_ultron[i][1]*y2+garis_ultron[i][2]<0) || (garis_ultron[i][0]*x1+garis_ultron[i][1]*y1+garis_ultron[i][2]<0 && garis_ultron[i][0]*x2+garis_ultron[i][1]*y2+garis_ultron[i][2]>0)) {
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ironman[0] >> ironman[1];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ultron[i][0] >> ultron[i][1];
        garis_ultron_generator(i,ironman[0],ironman[1],ultron[i][0],ultron[i][1]);
    }

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> side[i][0] >> side[i][1] >> side[i][2] >> side[i][3];
        garis_side_generator(i,side[i][0],side[i][1],side[i][2],side[i][3]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(bentrok(ultron[i][0],ultron[i][1], side[j][0], side[j][1], side[j][2], side[j][3], i, j)){
                
                break;
            }
            if(j==k-1){
                res++;
            }
        }
    }

    cout << res << endl;
}