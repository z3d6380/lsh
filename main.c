// File: main.c
// Author: Luis Moraguez
// Date: 2022-12-05
// Version: 0.1.0
// Description: Main driver code for lsh shell

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "lsh.h"

int main(int argc, char *argv[]) {
    // Calling the shell
    // If there is an argument, run in batch mode
    if (argc == 2) {
        printf("Batch mode not implemented yet\n");
        // lsh_batch_mode(argv[1]);
        return EXIT_FAILURE;
    } else {
        // Signal Handling
        signal(SIGINT, SIG_IGN); // Ignore Ctrl-C
        signal(SIGTSTP, SIG_IGN); // Ignore Ctrl-Z

        // Initialize Shell
        init_shell();

        lsh_interactive_loop();
    }

    return EXIT_SUCCESS;
}