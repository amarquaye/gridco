#include <iostream>

bool isPalindrome(int num) {
    int n, digit, rev = 0;

    n = num;

    do {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);

    //std::cout << " The reverse of the number is: " << rev << std::endl;

    if (n == rev) {
        //std::cout << " The number is a palindrome.";
        return true;
    } else {
        //std::cout << " The number is not a palindrome.";
        return false;
    }
}

int main() {
    int num1 = 0, num2 = 0, limit = 1000;

    while(num1 < limit && num2 < limit){
        for(int i = 0; i < limit; i++){
            for (int j = 0; j < limit; j++)
            {
                num1 = i;
                num2 = j;
                int sum = num1 * num2;
                if(isPalindrome(sum)){
                    if(num1 >800 && num2 > 800){
                        std::cout << num1 << " and " << num2 << std::endl;     
                    }
                }
            }
        }
        break;
    }

    return 0;
}
