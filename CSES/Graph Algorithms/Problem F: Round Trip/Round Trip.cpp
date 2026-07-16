#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
vector<vector<int>> ve(100005);
bool visited[100005];
int parent[100005];

pair<int,int> DFS(int i){
    visited[i] = 1;
    for(auto x : ve[i]){
        if(!visited[x]){
            visited[x] = 1;
            parent[x] = i;
            auto tmp = DFS(x);
            if(tmp != pair<int,int>{-1,-1}) return tmp;
        }
        else if(visited[x] && parent[i] != x) return {x,i};
    }
    return {-1,-1};
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
    memset(parent,0,sizeof(parent));
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            parent[i] = -1;
            pair<int,int> tmp = DFS(i);
            if(tmp != pair<int,int>{-1,-1}){
                vector<int> ve;
                ve.push_back(tmp.first);
                int u = tmp.second;
                while(u != tmp.first){
                    ve.push_back(u);
                    u = parent[u];
                }
                ve.push_back(tmp.first);
                cout << ve.size() << endl;
                for(auto it = ve.rbegin();it != ve.rend();it++){
                    cout << *it << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}