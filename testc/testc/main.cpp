//
//  main.cpp
//  testc
//
//  Created by dz2701 on 6/18/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <iostream>
using namespace std;

int findd(int n, int ans){
    return n!=0? findd(n/10,ans+1) : ans;
}

int main(){
    cout << findd(99,0);
    return 0;
}
