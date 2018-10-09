//
// Created by Kristina on 05.10.2018.
//
#include <iostream>
#include "SubsequenceSum.h"


int linear_mss(int array[], int n) {
    int maxSum = 0;
    int thisSum = 0;
    for (int i = 1;i <=  n; i++ ) {
        thisSum = thisSum + array[i -1];
        if (thisSum >maxSum) {
            maxSum = thisSum;
        }
        else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

int quadratic_mss(int array[], int n) {
    int maxSum = 0;

    for (int i = 1;i <=  n; i++ ) {
        int thisSum = 0;
        for (int j = i; j <= n; j++ ) {
           thisSum = thisSum + array[j -1];
                if (thisSum > maxSum) {
                    maxSum = thisSum;
                }
        }
    }
    return maxSum;
}

int cubic_mss(int array[], int n) {
    int maxSum = 0;

    for (int i = 1;i <=  n; i++ ) {
        for (int j = i; j <= n; j++ ) {
            int thisSum = 0;
            for (int k = i; k <= j; k++) {
                thisSum = thisSum + array[k-1];
                if (thisSum > maxSum) {
                    maxSum = thisSum;
                }
            }
        }
    }
    return maxSum;
}

int main () {
//linear
    //negative element
    int arr1_linear[] = {-5};
    int linear1 = quadratic_mss(arr1_linear, 1);
    std::cout << linear1 << std::endl; //expected: 0

    //solution are tow numbers
    int arr2_linear[] = {10, 50, -100, -500, 8};
    int linear2 = linear_mss(arr2_linear, 5);
    std::cout << linear2<< std::endl; //expected: 60

    //solution contains all numbers
    int arr3_linear[] = {6,5,-4, 8};
    int linear3 = quadratic_mss(arr3_linear, 4);
    std::cout << linear3<< std::endl; //expected: 15

    //solution is one number
    int arr4_linear[] = {-1, 1};
    int linear4 = quadratic_mss(arr4_linear, 2);
    std::cout << linear4<< std::endl; //expected: 1

    //solution contains negative number
    int arr5_linear[] = {10,20,-10, 50, 80, 70, -300, 40};
    int linear5 = linear_mss(arr5_linear, 6);
    std::cout << linear5 << std::endl; //expected: 220




    //quadratic
    //one element
    int arr1_quadratic[] = {5};
    int quadratic1 = quadratic_mss(arr1_quadratic, 1);
    std::cout << quadratic1 << std::endl; //expected: 5

    //solution contains negative
    int arr2_quadratic[] = {1, 20, -1, 200, 8};
    int quadratic2 = quadratic_mss(arr2_quadratic, 5);
    std::cout << quadratic2<< std::endl; //expected: 228

    //empty
    int arr3_quadratic[] = {};
    int quadratic3 = quadratic_mss(arr3_quadratic, 0);
    std::cout << quadratic3<< std::endl; //expected: 0

    //solution are positive numbers
    int arr4_quadratic[] = {80, 20, -100, 4};
    int quadratic4 = quadratic_mss(arr4_quadratic, 4);
    std::cout << quadratic4<< std::endl; //expected: 100

    //single number
    int arr5_quadratic[] = {1,-1, 1,-1,1,-1};
    int quadratic5 = quadratic_mss(arr5_quadratic, 6);
    std::cout << quadratic5 << std::endl; //expected: 1



    //cubic
    //solution is an addition
    int arr1[] = {1, 2, -30, 4, 5};
    int cubic1 = cubic_mss(arr1, 5);
    std::cout << cubic1<< std::endl; //expected: 9

    //only positive
    int arr2_cubic[] = {1, 20, 100, 200, 8};
    int cubic2 = cubic_mss(arr2_cubic, 5);
    std::cout << cubic2<< std::endl; //expected: 329

    //only negative
    int arr3_cubic[] = {-1, -20, -100, -200, -8};
    int cubic3 = cubic_mss(arr3_cubic, 5);
    std::cout << cubic3<< std::endl; //expected: 0

    //solution is a single number
    int arr4_cubic[] = {10, 5, -100, 200, -8};
    int cubic4 = cubic_mss(arr4_cubic, 5);
    std::cout << cubic4<< std::endl; //expected: 200

    //empty
    int arr5_cubic[] = {};
    int cubic5 = cubic_mss(arr5_cubic, 0);
    std::cout << cubic5<< std::endl; //expected: 0

    return 0;
};
