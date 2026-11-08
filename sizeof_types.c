/*
 * sizeof_types.c
 * 各整數型別的大小 (sizeof) 與正確的 printf 格式。
 *
 *   short          -> %hd   (unsigned short -> %hu)
 *   int            -> %d    (unsigned int   -> %u)
 *   long           -> %ld   (unsigned long  -> %lu)
 *   long long      -> %lld  (unsigned long long -> %llu)
 *   sizeof 的結果是 size_t -> %zu
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    short s = SHRT_MAX;
    int i = INT_MAX;
    long l = LONG_MAX;
    long long ll = LLONG_MAX;
    unsigned int u = UINT_MAX;

    printf("char      : %zu bytes\n", sizeof(char));
    printf("short     : %zu bytes, 最大值 %hd\n", sizeof(short), s);
    printf("int       : %zu bytes, 最大值 %d\n", sizeof(int), i);
    printf("unsigned  : %zu bytes, 最大值 %u\n", sizeof(unsigned int), u);
    printf("long      : %zu bytes, 最大值 %ld\n", sizeof(long), l);
    printf("long long : %zu bytes, 最大值 %lld\n", sizeof(long long), ll);

    /* sizeof 也可以用在變數上 */
    printf("sizeof(s) = %zu, sizeof(i) = %zu\n", sizeof s, sizeof i);

    return 0;
}
