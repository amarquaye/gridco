#include <iostream>

int main() {
    int firstNumber = 0;
    int secondNumber = 1;
    int limit = 4000000;
    int evenSum = 0;

    while (true) {
        int sum = firstNumber + secondNumber;

        if (sum >= limit) {
            break;
        }

        if(sum%2 == 0){
            evenSum += sum;
            //std::cout << evenSum << std::endl;
            std::cout << evenSum << " ";
        }
        
        //std::cout << sum << " ";



        firstNumber = secondNumber;
        secondNumber = sum;

    }

    return 0;
}
