//
//  main.cpp
//  sd
//
//  Created by Shin Lee on 29/09/2019.
//  Copyright © 2019 Shin Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int arr['z'];
string a;
int main() {
    cin >> a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='a' && a[i]<='z')arr[a[i]-'a'+'A']++;
        else arr[a[i]]++;
        
    }
    int cnt=0;
    for(int i='A';i<='Z';i++){
        cnt = max(cnt,arr[i]);
    }
    char ans=0;
    int c=0;
    for(int i='A';i<='Z';i++){
        if(arr[i]==cnt){
            ans=i;
            c++;
        }
        if(c>1){
            printf("?");
            return 0;
        }
        
    }
    
    cout << ans;
    
    
    
    return 0;
}
