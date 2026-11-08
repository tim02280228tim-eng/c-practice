# C 語言課堂練習

每個練習是一個獨立的 `.c` 檔，可以單獨編譯執行。

## 編譯與執行

```sh
make                 # 編譯全部（gcc -std=c11 -Wall -Wextra -Werror）
./reverse_integer    # 執行其中一題
make clean           # 刪除編譯出來的執行檔
```

只編譯單一檔案：

```sh
gcc -Wall -Wextra -o sizeof_types sizeof_types.c
```

每次推送程式碼，GitHub Actions 會自動用同樣的參數編譯並執行全部練習，有任何警告就會失敗。

## 練習清單與重點

### 1. 整數反向輸出 `reverse_integer.c`、`reverse_digits_print.c`

- `n % 10` 取出最後一位數字，`n / 10` 去掉最後一位。
- 重複到 `n` 變成 0 為止，全程不需要把數字轉成字串。
- `reverse_integer.c` 把每一位組成新的數字：`reversed = reversed * 10 + n % 10`，所以 `1200` 會變成 `21`。
- `reverse_digits_print.c` 每取一位就直接印出，所以 `1200` 會印出 `0021`。
- 用 `do ... while` 而不是 `while`，輸入 `0` 時才會印出 `0`。
- 負數先記下符號、轉成正數再處理。

### 2. sizeof 與整數型別的 printf 格式 `sizeof_types.c`

| 型別 | printf 格式 | 常見大小（64 位元 Linux） |
| --- | --- | --- |
| `short` | `%hd` | 2 bytes |
| `int` | `%d` | 4 bytes |
| `unsigned int` | `%u` | 4 bytes |
| `long` | `%ld` | 8 bytes（Windows 是 4） |
| `long long` | `%lld` | 8 bytes |
| `sizeof` 的結果 (`size_t`) | `%zu` | 8 bytes |

- `sizeof` 的結果型別是 `size_t`，要用 `%zu`，用 `%d` 會被 `-Wall` 警告。
- 型別大小依平台而定，C 只保證 `short ≤ int ≤ long ≤ long long`。

### 3. 進位制輸出 `number_bases.c`

- `%d` 十進位、`%o` 八進位、`%x` / `%X` 十六進位（小寫 / 大寫）。
- `%#o` 會加上前綴 `0`，`%#x` 會加上前綴 `0x`。
- 程式碼裡 `0377` 是八進位常數，`0xFF` 是十六進位常數，三者都等於 255。
- `%o`、`%x` 對應 `unsigned int`，印負數要先轉型，結果會是補數表示。

### 4. 字元與字串宣告 `char_and_string.c`

- 字元用單引號 `'A'`，本質是整數（ASCII 碼），可以用 `%c` 或 `%d` 印出。
- 字串用雙引號 `"Hello"`，是結尾帶 `'\0'` 的 `char` 陣列。
- `char s[] = "Hello";` 的 `sizeof` 是 6（多了 `'\0'`），`strlen` 是 5。
- `char s[10] = "Hi";` 剩下的空間會自動補 `'\0'`。
- `const char *p = "World";` 是指向字串常數的指標，不能修改內容；`sizeof p` 是指標本身的大小，不是字串長度。
