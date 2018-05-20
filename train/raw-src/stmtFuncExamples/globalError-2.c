#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <values.h>

enum ERROR { NO = 0, TO_NUMBER, COMMA , OTHER, OVERFLOW };

enum ERROR error = NO;

void stringToNumber(int* num, char str[]){

    for (int i=0 ; i < strlen(str); ++i){
        if (isdigit(str[i])){
            *num = (*num) * 10 + (str[i] - '0');
            if (*num < 0){
                error = OVERFLOW;
                *num = INT_MAX;
            }
        }
        else if (str[i] == ','){
            error = COMMA;
            continue;
        }
        else {
            *num = 0;
           error = OTHER;
        }
    }
}
void stringsToNumber(int* num, char a[], char b[]){
    *num = 0;
    error = TO_NUMBER;
    stringToNumber (num, a);
    stringToNumber (num, b);

}

int main() {
    char a[] = "1345445cv5";
    char b[] = "123";
    int num;
    stringsToNumber (&num, a, b);
    printf("%d %d\n", num, error);
    return 0;
}


