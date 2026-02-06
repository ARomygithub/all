#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
 
vector<vector<int>> adj(maxn);
int firstMax[maxn] = {0};
int secondMax[maxn] = {0};
int diameter;
vector<int> leaf;
 
int dfsFirst(int idx, int par){
    vector<int> maxDistToLeaves;
    maxDistToLeaves.push_back(0);
    maxDistToLeaves.push_back(0); // to handle if the node doesn't have any child
 
    for(auto x : adj[idx]) if(x != par) maxDistToLeaves.push_back(dfsFirst(x,idx)+1);
    sort(maxDistToLeaves.begin(),maxDistToLeaves.end());
 
    firstMax[idx] = maxDistToLeaves[maxDistToLeaves.size()-1];
    secondMax[idx] = maxDistToLeaves[maxDistToLeaves.size()-2];
    diameter = max(diameter,firstMax[idx]+secondMax[idx]);
    return firstMax[idx];
}
 
void dfsToFindLeaves(int idx, int par){
    if(par == -1){
        // check the root, because the root itself could become the leaves
        if(secondMax[idx] == 0) leaf.push_back(idx);
        for(auto x : adj[idx]){
            if(firstMax[idx] == firstMax[x]+1 || secondMax[idx] == firstMax[x]+1){ // this means that the node x is part of the bamboo
                dfsToFindLeaves(x,idx);
            }
        }
    }else if(adj[idx].size() == 1 && adj[idx][0] == par){
        // this is the leaves
        leaf.push_back(idx);
    }else{
        // in part of the bamboo but not in the root yet
        for(auto x : adj[idx]) {
            if(x==par) continue;
            if(firstMax[idx] == firstMax[x]+1) {
                dfsToFindLeaves(x,idx);
            } else if(firstMax[idx]+secondMax[idx]==diameter) {
                if(firstMax[idx] == firstMax[x]+1 || secondMax[idx] == firstMax[x]+1) {
                    dfsToFindLeaves(x,idx);
                }
            }
        } 
    }
}
 
 
int main(){
 
    int n;
    cin >> n;
    for(int i = 0;i < n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    /// find the diameter
    dfsFirst(1,-1);
 
    int highestPoint;
    for(int i = 1; i<=n;i++) if(diameter == firstMax[i] +secondMax[i]) highestPoint = i;
    // cout <<highestPoint <<"\n";
 
    /// reroot the tree
    dfsFirst(highestPoint,-1);
    dfsToFindLeaves(highestPoint,-1);
    int dist[maxn];
    for(int i = 1; i <= n;i++) dist[i] = diameter;
 
    // add 1 to the leaves
    for(auto x : leaf) dist[x]++;
 
 
    for(int i = 1; i<=n;i++) cout << dist[i] << "\n";
 
 
 
    return 0;
}