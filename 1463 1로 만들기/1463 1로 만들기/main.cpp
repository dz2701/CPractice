//
//  main.cpp
//  1로 만들기
//
//  Created by Shin Lee on 22/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
//recursive form
/*
int rec(int num, int r){
    if(num==1)return r;
    
    if(num%3==0)return rec(num/3,r+1);
    else if(num%2==0)return rec(num/2,r+1);
    else return rec(num-1,r+1);
    
}
*/
long long arr[int(1e6+5)];
int main(){
    cin >> n;
    //cout << rec(n,0);
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(int i=4;i<=n;i++){
        if(i%3==0){
            arr[i]=arr[i/3]+1;
        }
        else if(i%2==0){
            arr[i]=arr[i/2]+1;
        }
        else arr[i] = arr[i-1]+1;
        arr[i]=min(arr[i-1]+1,arr[i]);
    }
    cout << arr[n];
}
