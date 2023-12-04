#include <iostream>

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 9, 0, 21};
    int arrsize = sizeof arr/sizeof arr[0];

    for(int i = 0; i < arrsize; i++){
        std::cout << arr[i] << " " ;
    }

    int num;
    std::cout << "\n Enter a number to search for: ";
    std::cin >> num;


    for(int i = 0; i < arrsize; i++){
        if(num == arr[i]){
            std::cout << "The number " << num << " exists at the " << i + 1 <<" position\n"; 
        }
        else{
            //std::cout << "Number doesn't exist\n";
        }
    }
}