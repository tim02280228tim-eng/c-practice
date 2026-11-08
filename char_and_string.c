/*
 * char_and_string.c
 * 字元與字串的宣告方式。
 *   字元用單引號 'A'，本質是一個小整數 (ASCII 碼)。
 *   字串用雙引號 "Hi"，是以 '\0' 結尾的 char 陣列。
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char c = 'A';
    char next = c + 1;               /* 字元可以做加法 */

    char s1[] = "Hello";             /* 陣列大小自動算：5 個字 + '\0' = 6 */
    char s2[10] = "Hi";              /* 指定大小，剩下的位置補 '\0' */
    char s3[] = {'C', '\0'};         /* 逐字元寫法，記得自己加 '\0' */
    const char *p = "World";         /* 指向字串常數，內容不可修改 */

    printf("c = %c，ASCII 碼 = %d\n", c, c);
    printf("next = %c\n", next);

    printf("s1 = %s，strlen = %zu，sizeof = %zu\n", s1, strlen(s1), sizeof s1);
    printf("s2 = %s，strlen = %zu，sizeof = %zu\n", s2, strlen(s2), sizeof s2);
    printf("s3 = %s\n", s3);
    printf("p  = %s，sizeof(p) = %zu（指標本身的大小）\n", p, sizeof p);

    s1[0] = 'J';                     /* 陣列可以改內容 */
    printf("修改後 s1 = %s\n", s1);

    return 0;
}
