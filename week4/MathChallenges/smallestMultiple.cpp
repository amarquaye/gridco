#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int lcm(int start, int end){
    int result = 1;
    for(int i = start; i <= end; i++){
        result = result * (i/gcd(i, result));
    }
    return result;
}

int main(){
    int smallestMultiple = lcm(1, 20);
    std::cout << smallestMultiple;
}