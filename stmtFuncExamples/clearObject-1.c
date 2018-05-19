#include <stdio.h>
#include <memory.h>

struct Books {
    char  title[50];
    int last_author;
    int  authors[50];
};
void addAuthor(struct Books *book, int id);
void addAuthors(struct Books *book, int ids[], int size);
void clearAuthors(struct Books *book);
void clearBook(struct Books *book);
void addTitle(struct Books *book, char title[]);
void fun (struct Books *book);
int dummy(struct Books *book);

int main() {
    struct Books book;
    clearBook(&book);

    addTitle(&book, "Lucky");

    addAuthor(&book, 1);

    int ids[5] = {2,3,4,5,6};
    addAuthors(&book, ids,  5);
    int f = dummy(&book);
    fun(&book);


    f = dummy(&book);
    return 0;
}
void fun (struct Books *book){
    int id2s[2] = {2,3};
    addTitle(book, "Lo");
    addAuthors(book, id2s,  2);
}
int dummy(struct Books *book){
    printf("%s ", book->title);
    for(int i = 0; i < book->last_author; i++) {
        printf("%d ", book->authors[i]);
    }
    printf("\n");
    return 1;

}
void addAuthors(struct Books *book, int ids[], int size){
    clearAuthors(book);
    for (int i = 0 ; i < size; ++i){
        addAuthor(book, ids[i]);
    }
}

void clearAuthors(struct Books *book){
    book->last_author = 0;
    memset(&book->authors[0], 0, 50);
}
void clearBook(struct Books *book){
    strcpy( book->title, "");
    clearAuthors(book);
}

void addAuthor(struct Books *book, int id){
    book->authors[book->last_author] = id;
    ++book->last_author;
}

void addTitle(struct Books *book, char title[]){
    strcpy( book->title, title);
}
