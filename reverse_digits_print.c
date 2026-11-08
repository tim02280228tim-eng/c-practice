/*
 * reverse_digits_print.c
 * 另一種寫法：不組成新數字，而是一位一位直接印出來。
 * 這樣尾端的 0 也會被印出，例：1200 -> 0021
 */
#include <stdio.h>

int main(void)
{
    int n;

    printf("請輸入一個正整數：");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("請輸入非負整數\n");
        return 1;
    }

    printf("反向輸出：");
    do {
        printf("%d", n % 10); /* 印出最後一位 */
        n /= 10;              /* 去掉最後一位 */
    } while (n > 0);
    printf("\n");

    return 0;
}
