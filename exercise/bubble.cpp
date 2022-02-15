#include <iostream>
#include <vector>
#include <string>
#include <stdio.h> 
#include <assert.h> 

using namespace std;

# define NDEBUG // 忽略断言

#include<assert.h>

int main(){
    int x=7;
    assert(x==5);
    return 0;
}