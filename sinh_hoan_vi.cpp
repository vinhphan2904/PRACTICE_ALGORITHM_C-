#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100];
bool check = true;
void Sinh(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]){
        i--;
    }
    if(i == 0){
        check = false;
        return;
    }
    int j = n;
    while(a[j] < a[i]){
        j--;
    }
    swap(a[i],a[j]);
    reverse(a + i + 1,a + j + 1);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        a[i] = i;
    }
    while(check){
        for(int i = 1;i <= n;i++) cout << a[i];
        cout << endl;
        Sinh();
    }
}