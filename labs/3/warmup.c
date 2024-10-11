#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void warmup_one() {
    printf("Testing warmup 1...\n");
    int rc = fork();
    if (rc == 0) {
        printf("Printing from child process\n");
        exit(0);
    }
    printf("\n");
}

void warmup_two() {
    printf("Testing warmup 2...\n");
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am the child and my PID is %d\n", rc);
        exit(0);
    } else {
        wait(NULL);
        printf("I am the parent of %d\n", rc);
    }
    printf("\n");
}

// Note: execvp will morph the current process into the program
// If you try to run to consecutive execvp in the same process, 
// it won't work because the first one morphs the current process 
// into something else; deleting the rest of the instructions
void warmup_three() {
    printf("Testing warmup 3...\n");
    char *args1[] = {"ls", NULL};
    char *args2[] = {"ls", "-l", NULL};
    // execvp(args1[0], args1);
    execvp(args2[0], args2);
    printf("\n");
}

int main(int argc, char *argv[]) {
    // warmup_one();
    // warmup_two();
    warmup_three();
    return 0;
}