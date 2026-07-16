#include <iostream>
#include <cstring>
#include <queue>
 
using namespace std;
 
bool visited[1005][1005];
 
int Dy[4] = {0,1,0,-1};
int Dx[4] = {-1,0,1,0};
char a[1005][1005];
int n,m;
void DFS(int i,int j){
    visited[i][j] = 1;
    for(int k = 0;k < 4;k++){
        int x = i + Dx[k],y = j + Dy[k];
        if(x >= 1 && x <= n && y >= 1 && y <= m &&a[x][y] != '#' && !visited[x][y]){
            DFS(x,y);
        }
    }
}
 
void BFS(int i,int j){
    queue<pair<int,int>> qe;
    qe.push({i,j});
    visited[i][j] = 1;
    while(!qe.empty()){
        pair<int,int> u = qe.front();
        qe.pop();
        for(int pos = 0;pos < 4;pos++){
            int x = u.first + Dx[pos];
            int y = u.second + Dy[pos];
            if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#' && !visited[x][y]){
                qe.push({x,y});
                visited[x][y] = 1;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    memset(visited,0,sizeof(visited));
    fill(&a[0][0],&a[0][0] + (n + 5) * (m + 5),'#'); 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(!visited[i][j] && a[i][j] != '#'){
                cnt++;
                BFS(i,j);
            }
        }
    }
    cout << cnt;
}
