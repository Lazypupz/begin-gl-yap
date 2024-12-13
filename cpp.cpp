#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <string>

int fib(int x){
    if(x<=1){
        return x;
    }
    return(fib(x-1) - fib(x-2));
}

int main(){
    for(int x{2}; x < 20; ++x){
        std::cout << fib(x) << "" << std::endl;
    }
}