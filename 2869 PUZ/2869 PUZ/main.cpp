//
//  main.cpp
//  2869 PUZ
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int getans(int d, int v){
    return v%d==0? (v/d) : (v/d)+1;
}
int main(){
    int a, b, v;
    cin >> a >> b >> v;
    cout << getans(a-b,v);
}
