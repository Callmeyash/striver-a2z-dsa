#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int node,int col,vector<vector<int>>& graph,vector<int>& color){
    for(int k =0;k<graph.size();k++){
        if(graph[node][k]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}

bool solve(int node,vector<vector<int>>& graph,vector<int>& color,int m){
    int n = graph.size();
    if(node==n){
        return true;
    }
    for(int col=1;col<=m;col++){
        if(isSafe(node,col,graph,color)){
            color[node]=col;
            if(solve(node+1,graph,color,m)) return true;
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph,int m){

    vector<int> color(graph.size(),0);

    return solve(0,graph,color,m);
}

int main() {

    vector<vector<int>> graph = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };

    int m = 2;

    if(graphColoring(graph, m))
        cout << "Coloring Possible" << endl;
    else
        cout << "Coloring Not Possible" << endl;

    return 0;
}