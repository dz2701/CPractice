//
//  main.cpp
//  Dishwashing
//
//  Created by Shin Lee on 1/19/21.
//

#include <bits/stdc++.h>
using namespace std;

int n; const int MAX = 1e5+1;
int arr[MAX];
int ans = 1;
void Solve(int cur, int prevStackStart, int curStackStart, int curStackEnd){
    printf("Solve(%d %d %d %d)\n",cur,prevStackStart,curStackStart,curStackEnd);
    //add new stack
    if(arr[cur]>curStackStart){
        Solve(cur+1, curStackStart, arr[cur], arr[cur]);
    }
    //put in the original stack right now
    if(prevStackStart>arr[cur] and arr[cur]>curStackEnd){
        Solve(cur+1, prevStackStart, curStackStart, arr[cur]);
    }
    
    ans = max(ans,cur);
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    Solve(1,0,0,0); //start from an empty stack
    cout << ans;
}
