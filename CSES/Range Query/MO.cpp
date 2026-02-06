#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=1e5;
int n,m,q;
int a[mxn], ct[mxn];

void remove(int idx) {
    ct[a[idx]]--;
}
void add(int idx) {
    ct[a[idx]]++;
}
int get_answer(int x) {
    return ct[x];
}

const int block_size=317;

struct Query {
    int l,r, idx, x;
    bool operator<(Query q) const {
        return make_pair(l/block_size,r) < make_pair(q.l/block_size,q.r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>m >>q;
    for(int i=0;i<n;i++) {
        cin >>a[i]; a[i]--;
    }
    vector<Query> que(q);
    for(int i=0;i<q;i++) {
        int a,b,c; cin >>a >>b >>c; a--, b--, c--;
        que[i].l=a, que[i].r=b, que[i].idx=i, que[i].x=c;
    }
    vector<int> ans(q);
    sort(que.begin(),que.end());
    int curl = 0;
    int curr = -1;
    for(Query p : que) {
        while(curl>p.l) {
            curl--;
            add(curl);
        }
        while(curr<p.r) {
            curr++;
            add(curr);
        }
        while(curl<p.l) {
            remove(curl);
            curl++;
        }
        while(curr>p.r) {
            remove(curr);
            curr--;
        }
        ans[p.idx] = get_answer(p.x);
    }
    for(int i=0;i<q;i++) {
        cout <<ans[i] <<"\n";
    }
}
