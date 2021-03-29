//
//  main.cpp
//  수들의 합 2
//
//  Created by Shin Lee on 2/15/21.
//

#include <bits/stdc++.h>
using namespace std;
int n,m, arr[10001];
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int st=1, ed = 0, cnt=0;
    int sum = 0;
    while(st<=n){
        //move one to the right if possible
        if(sum<m){
            if(ed<n)sum+=arr[++ed];
            else break;
        }
        else if(sum==m){
            cnt++;
            sum-=arr[st++];
        }else sum-=arr[st++]; //bigger, need to reduce
    }
    cout << cnt;
}
