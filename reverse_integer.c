/*
 * reverse_integer.c
 * 整數反向輸出：只用 % 10 與 / 10，不轉成字串。
 * 例：輸入 12345 -> 輸出 54321；輸入 -120 -> 輸出 -21
 */
#include <stdio.h>

int main(void)
{
    long n;
    long reversed = 0;

    printf("請輸入一個整數：");
    if (scanf("%ld", &n) != 1) {
        printf("輸入錯誤\n");
        return 1;
    }

    int negative = n < 0;
    if (negative) {
        n = -n;
    }

    /* 每次取出最後一位 (n % 10)，接到 reversed 後面，再把 n 去掉最後一位 (n / 10) */
    do {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    } while (n > 0);

    printf("反向結果：%s%ld\n", negative ? "-" : "", reversed);
    return 0;
}
