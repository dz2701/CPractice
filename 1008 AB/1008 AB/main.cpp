//
//  main.cpp
//  1008 AB
//
//  Created by dz2701 on 6/13/20.
//  Copyright © 2020 dz2701. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
float round(float var, int n){
    float val = (int)(var * pow(10,n) + 0.5);
    return (float)val/pow(10,n);
}
int main(){
    float a,b; cin >> a >> b;
    float ans = a/b;
    cout <<fixed<<setprecision(100)<<ans;
    
}
