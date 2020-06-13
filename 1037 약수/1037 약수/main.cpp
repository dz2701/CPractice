//
//  main.cpp
//  약수
//
//  Created by Shin Lee on 24/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;int arr[51];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    cout << arr[0]*arr[n-1];
    return 0;
}
