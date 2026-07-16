#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
 
bool visited[1005][1005];
 
int Dy[4] = {0,1,0,-1};
int Dx[4] = {-1,0,1,0};
char vt[4] = {'U','R','D','L'};
char a[1005][1005];
pair<int,int> parent[1005][1005];
char path[1005][1005];
int n,m,res = 0;
vector<char> result;
 
// void DFS(int i,int j,int &size){
//     visited[i][j] = 1;
//     if(a[i][j] == 'B'){
//         if(path.size() < size){
//             vector<char> ve;
//             stack<char> tmp = path;
//             while(!tmp.empty()){
//                 ve.push_back(tmp.top());
//                 tmp.pop();
//             }  
//             reverse(ve.begin(),ve.end());
//             size = ve.size();
//             result = ve;
//         }
//         return;
//     }
//     for(int k = 0;k < 4;k++){
//         int x = i + Dx[k],y = j + Dy[k];
//         char z = vt[k];
//         if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#' && !visited[x][y]){
//             path.push(z);
//             DFS(x,y,size);
//             path.pop();
//             visited[x][y] = 0;
//         }
//     }
// }
 
pair<int,int> BFS(int i,int j){
    queue<pair<int,int>> qe;
    qe.push({i,j});
    visited[i][j] = 1;
    while(!qe.empty()){
        pair<int,int> u = qe.front();
        qe.pop();
        int l = u.first,r = u.second;
        if(a[l][r] == 'B') return {l,r};
        for(int pos = 0;pos < 4;pos++){
            int x = u.first + Dx[pos];
            int y = u.second + Dy[pos];
            char moving = vt[pos];
            if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#' && !visited[x][y]){
                qe.push({x,y});
                visited[x][y] = 1;
                parent[x][y] = {l,r};
                path[x][y] = moving;
            }
        }
    }
    return {-1,-1};
}
int main(){
    cin >> n >> m;
    memset(visited,0,sizeof(visited));
    fill(&a[0][0],&a[0][0] + (n + 5) * (m + 5),'#'); 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    int cnt = INT_MAX;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == 'A'){
                parent[i][j] = {-1,-1};
                pair<int,int> re = BFS(i,j);
                if(re != pair<int,int>{-1,-1}){
                    cout << "YES" << endl;
                    vector<char> ve;
                    while(parent[re.first][re.second] != pair<int,int>{-1,-1}){
                        ve.push_back(path[re.first][re.second]);
                        re = parent[re.first][re.second];
                    }
                    cout << ve.size() << endl;
                    reverse(ve.begin(),ve.end());
                    for(auto x : ve) cout << x;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}
