#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* getNext ( const char* patt ) {
    int len = strlen(patt);
    int* next = ( int* ) malloc(sizeof(int) * len);
    next[ 0 ] = -1;
    int i = 0;
    int j = -1;
    while ( i < len ) {
        if ( j == -1 || patt[ i ] == patt[ j ] ) {
            i++;
            j++;
            next[ i ] = j;
        } else {
            j = next[ j ];
        }
    }
    return next;
}

int KMP ( const char* dest, const char* patt ) {
    int i = 0;
    int j = 0;
    int* next = getNext(patt);
    while ( i < strlen(dest) && j < strlen(patt)) {
        if ( j == -1 || dest[ i ] == patt[ j ] ) {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if( j == strlen(patt) ){
        return i-j;
    }else{
        return -1;
    }
}

int main () {
    char dest[20] = "abcdabcdefgh";
    char patt[20] = "abcde";
    printf("%d\n", KMP(dest,patt));
    return 0;
}
