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

int main() {
    long long int limit = 600851475143;

    for (long long int i = 2; i <= sqrt(limit); i++) {
        if (limit % i == 0 && isPrime(i)) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
