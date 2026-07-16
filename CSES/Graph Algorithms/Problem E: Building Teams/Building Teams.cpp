#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
vector<vector<int>> ve(100005);
bool visited[100005];
int color[100005];
bool DFS(int i){
    visited[i] = 1;
    for(auto x : ve[i]){
        if(color[x] == color[i]) return false;
        if(!visited[x]){
            color[x] = 3 - color[i];
            if(!DFS(x)) return false;
        }
    }
    return true;
}

bool BFS(int i){
    queue<int> qe;
    qe.push(i);
    visited[i] = 1;
    color[i] = 1;
    while(!qe.empty()){
        int u = qe.front();
        qe.pop();
        for(auto x : ve[u]){
            if(!visited[x]){
                qe.push(x);
                visited[x] = 1;
                color[x] = 3 - color[u];
            }
            else{
                if(color[x] == color[u]) return false;
            }
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            if(!BFS(i)){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i = 1;i <= n;i++) cout << color[i] << " ";
}