#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/**
 * Splits the string by space and returns the array of tokens.
 */
char **tokenize(char *line) {
	char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
	char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
	int i, tokenIndex = 0, tokenNo = 0;

	for (i = 0; i < strlen(line); i++) {
		char readChar = line[i];

		if (readChar == ' ' || readChar == '\n' || readChar == '\t') {
			token[tokenIndex] = '\0';
			if (tokenIndex != 0) {
				tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE * sizeof(char));
				strcpy(tokens[tokenNo++], token);
				tokenIndex = 0; 
			}
		}
		else {
			token[tokenIndex++] = readChar;
		}
	}

	free(token);
	tokens[tokenNo] = NULL ;
	return tokens;
}

int main(int argc, char* argv[]) {
	char line[MAX_INPUT_SIZE];            
	char **tokens;              
	int i;

	while (1) {
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		printf("$ ");
		scanf("%[^\n]", line);
		getchar();
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);

		// Check if empty string or value we cannot accessed was entered
		// Prevents empty string or blank character segfault error
		if (tokens[0] == NULL || strlen(tokens[0]) == 0) {
			continue;
		}

		// Check for 'cd' command
		if (strcmp(tokens[0], "cd") == 0) {
			int chdir_val = chdir(tokens[1]);
			if (chdir_val < 0) {
				printf("my_shell: No such directory\n");
			}
		} else {
			int rc = fork();
			if (rc < 0) {
				fprintf(stderr, "fork failed\n");
				exit(1);
			} else if (rc == 0) {
				execvp(tokens[0], tokens);
				// Following doesn't get executed unless the previous results in an error
				perror("my_shell");
				exit(1);
			} else {
				wait(NULL);
			}
		}

		// Freeing the allocated memory	
		for(i = 0; tokens[i] != NULL; i++) {
			free(tokens[i]);
		}
		free(tokens);

	}
	return 0;
}
