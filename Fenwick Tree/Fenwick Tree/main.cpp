//
//  main.cpp
//  Fenwick Tree
//
//  Created by dz2701 on 10/8/20.
//

#include <bits/stdc++.h>
using namespace std;
int arr[30]; //input array
int fw[30]; //binary index tree

void update (int p, int v){ //update arr[p] +v, update BIT(FT)
    for(; p<30;p+=p&-p){
        fw[p] += v;
    }
}

int sum(int p){//sum from 1~p;
    int ret=0;
    for(; p;p-=p&-p){
        ret+=fw[p];
    }
    return ret;
}
int main(){
    int n;cin >> n;
    while(n>=30){
        cerr << "WARNING: ARRAY CAPACITY EXCEEDED. RE-ENTER N.\n";
        cin >> n;
    }
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        update(i,arr[i]);
    }
    while(1){
        printf("enter 1 for query, 2 for update, 3 for exit.\n");
        int choice; cin >> choice;
        if(choice==1){
            printf("enter the range of sum you would like to obtain.\n");
            int st, ed; cin >> st >> ed;
            printf("the sum is %d\n",sum(ed)-sum(st));
        }else if(choice==2){
            printf("enter the index and the value you would like to change to.\n");
            int idx, val; cin >> idx >> val;
            update(idx,val-arr[idx]);
            arr[idx] = val;
        }else break;
    }
    printf("thanks for using the binary index tree, which only takes up log(n) for either query or update!\n");
}
