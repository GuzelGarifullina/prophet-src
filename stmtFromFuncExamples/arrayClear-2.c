#include <stdio.h>
#include <memory.h>
#include <malloc.h>


void addArray(int res[], size_t res_size, size_t * res_index_from,
              int a[], size_t a_size){
    //need to delete
    * res_index_from = 0;
    memcpy(res + *res_index_from, a, a_size * sizeof(int));
    *res_index_from += a_size;

}
void combineArrays(int res[], size_t res_size, size_t * res_index_from,
                   int a[], size_t a_size, int b[], size_t b_size ){
    memset(&res[0], 0, res_size);

    addArray(res, res_size, res_index_from, a, a_size);
    addArray(res, res_size, res_index_from, b, b_size);
}
int main() {
    size_t  res_size = 100;
    size_t res_last = 0;
    size_t *res_last_i = &res_last;
    int res[res_size];

    size_t a_size = 5;
    int a[a_size];
    a[0] = 5;
    a[1] = 5;
    a[2] = 5;
    a[3] = 5;
    a[4] = 5;

    size_t b_size = 4;
    int b[b_size];
    b[0]=1;
    b[1]=2;
    b[2]=3;
    b[3]=4;
    combineArrays(res, res_size, res_last_i, a, a_size, b, b_size );

    for(size_t i = 0; i < (*res_last_i); i++) {
        printf("%d ", res[i]);
    }

    return 0;
}