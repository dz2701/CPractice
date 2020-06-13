//
//  main.cpp
//  이친수
//
//  Created by Shin Lee on 08/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <iostream>
using namespace std;
long arr[95][2];
int main(){
    int n;
    cin >> n;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for(int i=2;i<=n;i++){
        arr[i][0] = arr[i-1][0]+arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    cout << arr[n][0]+arr[n][1];
    return 0;
}
