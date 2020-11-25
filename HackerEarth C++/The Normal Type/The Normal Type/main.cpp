//
//  main.cpp
//  The Normal Type
//
//  Created by dz2701 on 7/16/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int arr[MAX], check1[MAX],check2[MAX], n, num[MAX];
vector<int>v;
int get_val(int i){
    if(i%2==0)return check1[i/2];
    else return check2[i/2];
}
int get_num(int i){
    if(i%2==0)return num1[i/2];
    else return num2[i/2];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(!get_val(arr[i]))v.push_back(arr[i]);
        if(i%2==0)check1[i/2]++;
        else check2[i/2]++;

    }
    long long ans =0;
    for(int i=1;i<n;i++){
        //start from i
        for(int j:v){
            num[j]=get_val(j);
        }
        //init
        for(int j=1;j<i;j++){
            num[arr[j]]--;
            if(!num[arr[j]]){
                cout << ans;
                return 0;
            }
        }
        for(int j=n;j>i;j--){
            ans++;
            //eliminate j
            num[arr[j]]--;
            if(!num[arr[j]])break;
        }

    }
    cout << ans;
}
