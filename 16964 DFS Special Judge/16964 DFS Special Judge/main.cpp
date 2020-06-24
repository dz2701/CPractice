//
//  main.cpp
//  16964 DFS Special Judge
//
//  Created by dz2701 on 6/22/20.
//  Copyright © 2020 dz2701. All rights reserved.
//


#include <bits/stdc++.h>
using namespace std;

int idx, N, ans[100005];
set<int> adj[100005];

int dfs(int root) {
   if (root != ans[idx++]) return 0;

   int ret = 1;

   while(idx != N && adj[root].count(ans[idx]))
       ret = ret && dfs(ans[idx]);

   return ret;
}

int main() {
   cin >> N;

   for (int i=0; i<N-1; i++){
       int a, b;
       cin >> a >> b;
       adj[a].insert(b);
       adj[b].insert(a);
   }

   for (int i=0; i<N; ++i) cin >> ans[i];

   int ret = dfs(1);
   cout << (ret && idx == N);
   return 0;
}
