//
//  main.cpp
//  1
//
//  Created by Shin Lee on 2/28/21.
//

#include <bits/stdc++.h>
using namespace std;
int n; const int MAX = 1e5+2;
long long arr[MAX];
int cnt = 0;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    //initial calculation
    long long N = arr[1];
    for(int i=2;i<=n;i++)N=N^arr[i];
    for(int i=1;i<=n;i++){
        if(arr[i]<=(N^arr[i])){
            cnt++;
        }
    }
    cout << cnt;
}
