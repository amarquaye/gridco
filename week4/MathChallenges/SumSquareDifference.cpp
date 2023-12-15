#include <iostream>

int sumOfSquares(int start, int end){
    int sum = 0;
    int num = 0;
    for(int i = start; i <= end; i++){
        num = i * i;
        sum += num;
    }
    return sum;
}

int squareOfSums(int start, int end){
    int sum = 0;
    int num = 0;
    for(int i = start; i <= end; i++){
        sum += i;
    }
    return sum * sum;
}

int differenceOfSums(int start, int end){
    int difference;
    difference = squareOfSums(start, end) - sumOfSquares(start, end);
    return difference;    
}

int main(){
    int sos = differenceOfSums(1, 100);
    std::cout << sos;
}