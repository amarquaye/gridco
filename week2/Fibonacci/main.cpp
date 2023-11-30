#include <iostream>

int main() {
    int firstNumber = 0;
    int secondNumber = 1;
    int sum;

    std::cout << firstNumber << " " << secondNumber << " ";

    while (true) {
        sum = firstNumber + secondNumber;

        if (sum > 200) {
            break;
        }

        std::cout << sum << " ";

        firstNumber = secondNumber;
        secondNumber = sum;
    }

    return 0;
}
