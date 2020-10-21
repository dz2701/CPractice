//
//  main.cpp
//  2588
//
//  Created by dz2701 on 9/17/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;
    int t1 = b%10; int t2 = (b%100)/10; int t3 = b/100;
    printf("%d\n%d\n%d\n%d\n",a*t1,a*t2,a*t3,a*t1+10*a*t2+100*t3*a);
}
