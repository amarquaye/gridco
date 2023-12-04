#include <iostream>

int main(){
    int arr[] = {4, 4, 11, 5, 7, 3, 2, 8};
    int arrsize = sizeof arr/sizeof arr[0];

    int i = 0;
    while(i < arrsize){
        for(int j = 0; j < arrsize; j++){
            if(arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            std::cout << arr[j] << " ";
        }
        std::cout << std::endl;
        i++;
    }

    // for(int k = 0; k < arrsize; k++){
    //     std::cout << arr[k] << " ";
    // }

    std::cout << std::endl;
}
