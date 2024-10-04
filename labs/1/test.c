#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *p;
char *q;

int testPointer(void) {
    *p = NULL;
    printf(p);
    printf("This works");
    return 0;
}


int main(){
    testPointer();
    return 0;
};

