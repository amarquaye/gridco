#include <iostream>

int main(){
    int num = 1000;
    int sum = 0;
    int zero = 0;

    for(int i =0; i < num; i++){
        if(i%3 == 0 || i%5 == 0){   
            sum = sum + i; 
            std::cout << sum << std::endl;
        }
        //sum ++;
    }
}