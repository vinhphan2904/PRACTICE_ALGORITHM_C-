#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<int>> ve(1005);
bool visited[1005][1005];
pair<int,int> parent[1005][1005];
int step[1005][1005];
char path[1005][1005];
char a[1005][1005];
int Dx[4] = {-1,0,1,0};
int Dy[4] = {0,1,0,-1};
char pos[4] = {'U','R','D','L'};
int moving[1005][1005];
void BFS1(){
    queue<pair<int,int>> qe;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == 'M'){
                qe.push({i,j});
                visited[i][j] = 1;
                step[i][j] = 0;
            }
        }
    }
    while(!qe.empty()){
        auto u = qe.front();
        qe.pop();
        for(int i = 0;i < 4;i++){
            int x = u.first + Dx[i];
            int y = u.second + Dy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && !visited[x][y] && a[x][y] != '#'){
                qe.push({x,y});
                visited[x][y] = 1;
                step[x][y] = min(step[x][y],step[u.first][u.second] + 1);
            }
        }
    }
}

pair<int,int> BFS2(int i,int j){
    queue<pair<int,int>> qe;
    qe.push({i,j});
    visited[i][j] = 1;
    while(!qe.empty()){
        auto u = qe.front();
        qe.pop();
        for(int i = 0;i < 4;i++){
            int x = u.first + Dx[i];
            int y = u.second + Dy[i];
            char z = pos[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && !visited[x][y] && a[x][y] != '#'){
                if(moving[u.first][u.second] + 1 < step[x][y]){
                    parent[x][y] = {u.first,u.second};
                    path[x][y] = z;
                    moving[x][y] = moving[u.first][u.second] + 1;
                    if((x == 1 || x == n || y == 1 || y == m) && a[x][y] != '#'){
                        return {x,y};
                    }
                    else{
                        qe.push({x,y});
                        visited[x][y] = 1;
                    }
                }
            }
        }
    }
    return {-1,-1};
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    fill(&step[0][0],&step[0][0] + 1005 * 1005,INT_MAX);
    memset(path,0,sizeof(path));
    memset(moving,0,sizeof(moving));
    BFS1();
    memset(visited,0,sizeof(visited));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == 'A'){
                if(i == 1 || i == n || j == 1 || j == m){
                    cout << "YES" << endl << '0';
                    return 0;
                }
                parent[i][j] = {-1,-1};
                auto tmp = BFS2(i,j);
                if(tmp != pair<int,int>{-1,-1}){
                    vector<char> res;
                    while(tmp != pair<int,int>{-1,-1}){
                        res.push_back(path[tmp.first][tmp.second]);
                        tmp = parent[tmp.first][tmp.second];
                    }
                    res.pop_back();
                    cout << "YES" << endl;
                    cout << res.size() << endl;
                    reverse(res.begin(),res.end());
                    for(auto x : res) cout << x;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}