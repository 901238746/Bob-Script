#include <stdbool.h>
#include <string.h>
#include <stdio.h>
int findSubstring(char *txt, char *pat) {
    int n = strlen(txt);
    int m = strlen(pat);

    // Iterate through txt
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}
char stack[4000000];
char out[4000000];
char* getfromstack(char stack[]) {
    int counter = 0;
    int counter2 = 0;
    if (findSubstring(stack, "→") == -1) { return stack; }
    while (true) {
        if (stack[counter] == *"→") {
            break;
        }
        else {counter2++;}
        counter++;
    }
    strncpy(out, stack, counter2);
    return out;
}

char* appendtostack(char stack[], char toappend[]) {
    strcat(stack, "→");
    strcat(stack, toappend);
    return stack;
}

char* removefromstack(char stack[]) {
    int index = findSubstring(stack, "→") + 3;
    if (index == 2) {return "";}
    //memmove(str, str + 6, str_len - 6 + 1);
    memmove(stack, stack + index, strlen(stack) - index + 1);
    return stack;
}
/*| **NAME**     | **DESC.**                             | **ID** |
| ---------- | ------------------------------------- | ------ |
| null       | nothing                               | 0      |
| str        | a string                              | 1      |
| short      | a 8 bit number                        | 2      |
| int        | a 16 bit number                       | 3      |
| long       | a 32 bit number                       | 4      |
| long64     | a 64 bit number                       | 5      |
| long128    | a 128 bit number                      | 6      |
| float32    | a 32 bit float                        | 7      |
| float64    | a 64 bit float                        | 8      |
| unshort    | a unsigned 8 bit number               | 9      |
| unint      | a unsigned 16 bit number              | 10     |
| unlong     | a unsigned 32 bit number              | 11     |
| unlong64   | a unsigned 64 bit number              | 12     |
| unlong128  | a unsigned 128 bit number             | 13     |
| unfloat32  | a unsigned 32 bit float               | 14     |
| unfloat64  | a unsigned 64 bit float               | 15     |
| fint       | a fixed point 16 bit number           | 16     |
| flong      | a fixed point 32 bit number           | 17     |
| flong64    | a fixed point 64 bit number           | 18     |
| flong128   | a fixed point 128 bit number          | 19     |
| funshort   | a fixed point unsigned 8 bit number   | 20     |
| funint     | a fixed point unsigned 16 bit number  | 21     |
| funlong    | a fixed point unsigned 32 bit number  | 22     |
| funlong64  | a fixed point unsigned 64 bit number  | 23     |
| funlong128 | a fixed point unsigned 128 bit number | 24     |*/
char* variables = "0→0";
char* variableIDs = "elseFlag→Overflowed";
char* types = "1→1";
char* tocompile = "print \"lol\";";
int main() {
    char temp[2] = "";
    char temp2[100] = "";
    char temp3[100] = ""; // give me one sec ok
    for (int i = 0; i < strlen(tocompile); i++) {
        strncpy(temp, &tocompile[i], 1);
        if (strcmp(temp, " ") == 0) {
            printf("%s\n", temp2);
            strcpy(temp3, appendtostack(temp3, temp2));
            strcpy(temp2, "");
        }
        else if (strcmp(temp, ";") == 0) {
            printf("%s\n", temp3);
            strcpy(temp3, appendtostack(temp3, ";"));
        }
        strcat(temp2, temp);
    }
    strcpy(temp3, removefromstack(temp3));
    printf("%s\n", temp3);
    printf("%s\n", temp2);
    return 0;
}