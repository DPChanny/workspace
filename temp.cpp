#include <iostream>
#include <cstdlib>
#include <ctime>

void Reverse(int* a, int size){
    int temp;
    for(int i(0); i < size / 2; i++){
        temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;
    }
}

void Print(int* a, int size){
    for(int i(0); i < size; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

int Sum(int *a, int size){
    int sum(0);
    for(int i(0); i < size; i++)
        sum += a[i];
    return sum;
}

int main() {
    int a1[3] = {1, 2, 3};
    int a2[5] = {9, 8, 7, 6, 5};
    Reverse(a1, 3);   // a1의 요소가 {3, 2, 1}로 수정
    Reverse(a2, 5);   // a2의 요소가 {5, 6, 7, 8, 9}로 수정
    Print(a1, 3);   // a1의 요소를 출력
    Print(a2, 5);   // a2의 요소를 출력
    std::cout << Sum(a1, 3) << std::endl; // 6(3+2+1) 출력
    std::cout << Sum(a2, 4) << std::endl; // 26(5+6+7+8) 출력
}
 