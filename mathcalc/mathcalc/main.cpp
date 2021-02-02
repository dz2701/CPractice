//
//  main.cpp
//  mathcalc
//
//  Created by Shin Lee on 12/28/20.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int a=1; a<=10000; a++){
        for(int b=1; b<=10000;b++){
            if(pow(a,3) == pow(b,4))printf("%d %d\n",a,b);
        }
    }
}
