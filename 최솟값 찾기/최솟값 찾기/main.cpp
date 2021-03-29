//
//  main.cpp
//  최솟값 찾기
//
//  Created by Shin Lee on 3/10/21.
//

#include <bits/stdc++.h>
using namespace std;
multiset<int>s; int n, l;
int arr[5000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> l;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=l;i++){
        s.insert(arr[i]);
        cout << *s.begin() << " ";
    }
    for(int i=l+1;i<=n;i++){
        s.erase(s.find(arr[i-l]));
        s.insert(arr[i]);
        cout << *s.begin() << " ";
    }
    return 0;
}
