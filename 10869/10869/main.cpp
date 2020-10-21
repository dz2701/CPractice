//
//  main.cpp
//  10869
//
//  Created by dz2701 on 9/17/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    //int a, b; std::cin >> a >> b; printf("%d\n%d\n%d\n%d\n%d\n",a+b,a-b,a*b,a/b,a%b);
    int a, b, c; std::cin >> a >> b >> c; printf("%d\n%d\n%d\n%d\n",(a+b)%c,((a%c)+(b%c))%c,(a*b)%c,((a%c)*(b%c))%c);
}
