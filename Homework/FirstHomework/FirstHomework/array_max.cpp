#include <iostream>
#include<opencv2/opencv.hpp>
#include <cstdio>

int findArrayMax(int score[], int n)
{
    int tmp = score[0];
    for (int i = 1; i < n; i++) {
        if (score[i] > tmp) {
            tmp = score[i];
        }
    }
    return tmp;
}
void main()
{
    int score1[] = { 3, 7, 2, 9, 10, 5 };
    int score2[] = { -10, -5, -3 };
    int score3[] = { 100, 200, 300, 50, 400 };
    int score4[] = { 0, 0, -2, 0 };
    int score5[] = { 10000 };
    int out1, out2, out3, out4, out5;
    out1 = findArrayMax(score1, 6);
    out2 = findArrayMax(score2, 3);
    out3 = findArrayMax(score3, 5);
    out4 = findArrayMax(score4, 4);
    out5 = findArrayMax(score5, 1);
    printf("result = %d\n", out1);
    printf("result = %d\n", out2);
    printf("result = %d\n", out3);
    printf("result = %d\n", out4);
    printf("result = %d\n", out5);
}