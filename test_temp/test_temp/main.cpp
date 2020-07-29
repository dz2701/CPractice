//
//  main.cpp
//  test_temp
//
//  Created by dz2701 on 7/27/20.
//  Copyright © 2020 dz2701. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    set<long long>s;
    for(int i=1;i<=5;i++){
        s.insert(i);
    }
    cout << *s.rbegin() << endl;
    s.erase(5);
    cout << *s.rbegin();
}
