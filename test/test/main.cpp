//
//  main.cpp
//  test
//
//  Created by Shin Lee on 2/28/21.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long num = 1000000000000000000;
    while(num){
        printf("%lld\n",num);
        num/=3;
    }
}
