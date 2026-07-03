#include <iostream>
using namespace std;

int n;
string father, mother;
string child;

void backtrack(int pos){
    if(pos == n){
        cout << child << '\n';
        return;
    }

    if(father[pos] == mother[pos]){
        child[pos] = father[pos];
        backtrack(pos + 1);
    }
    else{
        child[pos] = father[pos];
        backtrack(pos + 1);

        child[pos] = mother[pos];
        backtrack(pos + 1);
    }
}

int main(){
    cin >> n;
    cin >> father;
    cin >> mother;

    child.resize(n);

    backtrack(0);

    return 0;
}