// File: lsh.c
// Author: Luis Moraguez
// Date: 2022-12-05
// Version: 0.1.0
// Description: Main driver code for lsh shell loop

#include "lsh.h"

// NAME: init_shell
// INPUT: void
// OUTPUT: void
// DESCRIPTION: Displays shell initialization message
void init_shell(void) {
    clear();
    char* username = getenv("USER");
    printf("██╗     ███████╗██╗  ██╗" RED "    ██╗  \n" reset);
    printf("██║     ██╔════╝██║  ██║" RED "    ╚██╗ \n" reset);
    printf("██║     ███████╗███████║" RED "     ╚██╗\n" reset);
    printf("██║     ╚════██║██╔══██║" RED "     ██╔╝\n" reset);
    printf("███████╗███████║██║  ██║" RED "    ██╔╝ \n" reset);
    printf("╚══════╝╚══════╝╚═╝  ╚═╝" RED "    ╚═╝  \n" reset);
    printf("Welcome to lsh, " GRN "%s!\n" reset, username);
    printf("Type " BYEL "'help'" reset " for built-in command list\nType " BYEL "'exit'" reset " to exit the shell\n");
    sleep(3);
    clear();
}

// NAME: prompt1
// INPUT: void
// OUTPUT: char*
// DESCRIPTION: Displays the PS1 prompt
char* prompt1(void) {
    char* cwd = getcwd(NULL, 0);
    char* prompt;
    asprintf(&prompt, RED "┌[" CYN "%d" RED "]─[" YEL "%s" RED "]─[" MAG "%s" RED "]\n└╼" GRN "%s" YEL "$ " reset, (int)getpid(), "lsh", cwd, getenv("USER"));
    free(cwd);
    return prompt;
}

// NAME: prompt2
// INPUT: void
// OUTPUT: char*
// DESCRIPTION: Displays the PS2 prompt
char* prompt2(void) {
    return "> ";
}

// NAME: lsh_interactive_loop
// INPUT: void
// OUTPUT: void
// DESCRIPTION: Runs the shell in interactive mode
void lsh_interactive_loop(void) {
    // Variables
    char* input;

    // Main loop
    while (1) {
        // Get Input
        input = lsh_interactive_input();

        // Check for EOF (Ctrl-D)
        if (input == NULL) {
            printf("\n");
            break;
        }

        // Check for empty input
        if (strcmp(input, "") == 0) {
            continue;
        }
    }
}

// NAME: lsh_interactive_input
// INPUT: void
// OUTPUT: char*
// DESCRIPTION: Gets the user input and stores it in the buffer
char* lsh_interactive_input() {
    char* buf;

    // Get input from readline
    buf = readline(prompt1());
    if (buf != NULL && strlen(buf) != 0) {
        // Add input to history
        add_history(buf);
    }
    return buf;
}