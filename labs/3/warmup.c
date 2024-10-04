#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void warmup_one() {
    printf("Testing warmup 1...\n");
    int rc = fork();
    printf("rc = %d\n", rc);
}

int main(int argc, char *argv[]) {
    warmup_one();
    return 0;
}