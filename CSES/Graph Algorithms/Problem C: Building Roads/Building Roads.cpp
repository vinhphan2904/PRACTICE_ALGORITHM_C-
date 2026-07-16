#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
 
vector<vector<int>> ve(100001);
int cnt = 0;
bool visited[100005];
int n,m;
vector<pair<int,int>> next_path;
stack<int> st;
void DFS(int i){
    visited[i] = 1;
    st.push(i);
    for(auto x : ve[i]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
int main(){
    memset(visited,0,sizeof(visited));
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
 
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            if(!st.empty()){
                next_path.push_back({st.top(),i});
                st = stack<int>();
                cnt++;
                DFS(i);
            }
            else{
                DFS(i);
            }
        }
    }
    cout << cnt << endl;
    for(auto x : next_path){
        cout << x.first << " " << x.second << endl;
    }
}
