/*
 * number_bases.c
 * 進位制輸出：%d 十進位、%o 八進位、%x / %X 十六進位。
 * 加上 # 旗標會自動補前綴：%#o -> 0..., %#x -> 0x...
 */
#include <stdio.h>

int main(void)
{
    int n = 255;
    int oct = 0377;  /* 0 開頭的常數是八進位 */
    int hex = 0xFF;  /* 0x 開頭的常數是十六進位 */

    printf("十進位   %%d  : %d\n", n);
    printf("八進位   %%o  : %o\n", n);
    printf("十六進位 %%x  : %x\n", n);
    printf("十六進位 %%X  : %X\n", n);
    printf("加前綴   %%#o : %#o\n", n);
    printf("加前綴   %%#x : %#x\n", n);

    printf("0377 = %d, 0xFF = %d（三者相同）\n", oct, hex);

    /* %o、%x 對應的是 unsigned int，負數會顯示成補數 */
    printf("-1 的十六進位：%x\n", (unsigned int)-1);

    return 0;
}
