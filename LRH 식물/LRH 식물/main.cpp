//
//  main.cpp
//  LRH 식물
//
//  Created by Shin Lee on 1/20/21.
//

#include <bits/stdc++.h>
using namespace std;
int n; const int MAX = 1e5+1;
int enter[MAX], out[MAX], fw[MAX], red[MAX];

int query(int p){
    int ret =0;
    for(;p;p-=p&-p){
        ret+= fw[p];
    }
    return ret;
}

void update(int p, int v){
    for(;p<MAX;p+=p&-p){
        fw[p]+=v;
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b; cin >> a >> b;
        a++; b++;
        for(int i=0;i<=7;i++){
            printf("%d ",query(i+1)-query(i));
        }
        //printf("\n");
        int temp = query(b)-query(a-1) - red[a] - red[b];
        red[a]+=temp; red[b]+=temp;
        update(b,1); update(a-1,-1);
        printf("temp=%d\n",temp);
    }
    return 0;
}
