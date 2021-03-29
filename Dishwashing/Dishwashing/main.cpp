//
//  main.cpp
//  Dishwashing
//
//  Created by Shin Lee on 3/3/21.
//
#include <bits/stdc++.h>
using namespace std;

int n; const int MAX = 1e5+1;
int arr[MAX];
int ans = 1;
void Solve(int start, int cur, int prevStackStart, int curStackStart, int curStackEnd){
    //add new stack
    if(arr[cur]<curStackEnd){
        Solve(start,cur+1, curStackStart, arr[cur], arr[cur]);
    }
    //put in the original stack right now
    else if(prevStackStart>arr[cur] and arr[cur]>curStackEnd){
        Solve(start,cur+1, prevStackStart, curStackStart, arr[cur]);
    }
    
    ans = max(ans,cur-start);
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++)Solve(i,i,1e9,0,0); //start from an empty stack
    cout << ans;
}
