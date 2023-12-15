#include <iostream>
#include <cmath>

bool isPrime(long long int n) {
    if (n <= 1) {
        return false;
    }

    if (n == 2) {
        return true;
    }

    if (n % 2 == 0) {
        return false;
    }

    for (long long int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    long long int arr[10001];
    int counter = 0;
    int position = 10001;
   
    int i = 0;
    while(1){
        if(isPrime(i)){
            for(int j = 0; j < 1; j++){
               arr[j] = i;
               std::cout << arr[j] << " ";
            }
            counter++;
            if(counter == position){
                break;
            }
        }
        i++;
    }

    // for(int i = 0; i < 10; i++){
    //     std::cout << arr[i] << " ";
    // }

    std:: cout << std::endl;
    std::cout << counter;
}