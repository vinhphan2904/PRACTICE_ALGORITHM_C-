#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
vector<vector<int>> ve(100005);
int n,m;
bool visited[100005];
vector<int> parent(100005);
bool BFS(int i){
    visited[i] = 1;
    queue<int> qe;
    qe.push(i);
    parent[i] = -1;
    while(!qe.empty()){
        int u = qe.front();
        qe.pop();
        for(auto x : ve[u]){
            if(!visited[x]){
                qe.push(x);
                visited[x] = 1;
                parent[x] = u;
            }
        }
    }
    if(visited[n]) return true;
    else return false;
}
int main(){
    cin >> n >> m;
    memset(visited,0,sizeof(visited));
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    if(BFS(1)){
        vector<int> tmp;
        int u = n;
        while(u != -1){
            tmp.push_back(u);
            u = parent[u];
        }
        cout << tmp.size() << endl;
        reverse(tmp.begin(),tmp.end());
        for(auto x : tmp) cout << x << " ";
    }
    else cout << "IMPOSSIBLE";
}
