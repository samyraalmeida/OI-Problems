// Fliper - OBI 2014
// By Samyra Almeida

#include <bits/stdc++.h>
using namespace std;

int p, r;

int main(){
    scanf("%d%d", &p, &r);

    if(p==0 && (r==0 || r==1)){
        printf("C\n");
    }else{
        if(r==0){
            printf("B\n");
        }
        else{
            printf("A\n");
        }
    }
    return 0;
}