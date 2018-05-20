#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <values.h>


const int NO_ERROR = 0;
const int READ_ERROR =1;
const int WRITE_ERROR =2;


int error ;

void check (char a){

    switch(a) {

        case 'a': case 'b' : case 'c' :
            error = READ_ERROR;
            break;
        case 'd':
            error = WRITE_ERROR;
            break;
    }
}
int checkConnection(int port){
    return 1;
}
void tryConnect(int port){
    char res = 'a';
    if (checkConnection(port)){
        printf("Happy");
    }
    res = 'b';
    error = NO_ERROR;
    check(res);
}
int main() {
    const int n = 2;
    int arr[2] = {0,0};
    error = NO_ERROR;
    check('b');
    arr[0] = error;

    tryConnect(45);
    check('c');
    arr[1] = error;
    for (int i = 0; i < n; ++i ){
        if (arr[i] != NO_ERROR){
            return 1;
        }
    }

}


