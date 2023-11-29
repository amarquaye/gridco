#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

void circle(int& r){
    int circumference = 2*(M_PI)*(r);
    std::cout << "The circumference of the circle with radius "<< r <<" is: " << circumference << std::endl; 
}

int main(){
    int radius;
    std::cout << "Enter a radius: \n";
    std::cin >> radius;

    circle(radius);
}