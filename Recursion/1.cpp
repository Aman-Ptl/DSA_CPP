#include<bits/stdc++.h>
using namespace std;

int fun1(int n){
if(n>0){
    cout<<n<<endl;
    fun1(n-1);
    
}
}

int main(){
    int x=5;
    fun1(x);
}