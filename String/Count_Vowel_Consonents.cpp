#include <bits/stdc++.h>
using namespace std;

int main() {
char A[]="weLCoMe";
int i,v_count=0, c_count=0;
for(i=0;A[i]!=0;i++){
    if(A[i]=='A'|| A[i]=='a'||A[i]=='E'|| A[i]=='e'||A[i]=='i'|| A[i]=='I'||A[i]=='O'|| A[i]=='o'||A[i]=='U'|| A[i]=='u'){
        v_count++;
    }
    else if((A[i]>=97&&A[i]<=122)||(A[i]>=65&&A[i]<=90)){
        c_count++;
    }
}
cout<<"the number of Vowels are: "<<v_count<<" And The number of consonants are: "<<c_count;
return 0;
}
