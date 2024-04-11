#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void execute_command(char *cmd);
void initialize_shell();
void cleanup_shell();

int main() {
    char *input;
    char prompt[256];

    initialize_shell();
    while (1) {
        snprintf(prompt, sizeof(prompt), "minishell> ");
        input = readline(prompt);
        if (input == NULL) {
            printf("\n");
            break;
        }
        if (*input) {
            add_history(input);
        }
        execute_command(input);
        free(input);
    }
    cleanup_shell();

    return 0;
}

void execute_command(char *cmd) {
    printf("Executing command: %s\n", cmd);
}

void initialize_shell() {
    printf("Initializing shell...\n");
}

void cleanup_shell() {
    printf("Cleaning up shell...\n");
}
