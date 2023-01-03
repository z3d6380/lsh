// File: lsh.h
// Author: Luis Moraguez
// Date: 2022-12-05
// Version: 0.1.0
// Description: lsh header file

#ifndef LSH_H
#define LSH_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "colors.h"

// Clearing the shell using escape sequences
#define clear() printf("\033[H\033[J")

// Command Data Structure
// Describes a simple command and arguments
struct SimpleCommand {
    // Available space for arguments currently preallocated
    int _numberOfAvailableArguments;

    // Number of arguments
    int _numberOfArguments;

    // Array of arguments
    char** _arguments;

    SimpleCommand();
    void insertArgument(char* argument);
};

// Describes a complete command with multiple pipes, if any,
// and input/output redirection, if any.
struct Command {
    int _numberOfAvailableSimpleCommands;
    int _numberOfSimpleCommands;
    SimpleCommand** _simpleCommands;
    char* _outFile;
    char* _inputFile;
    char* _errFile;
    int _background;

    void prompt();
    void print();
    void execute();
    void clear();

    Command();
    void insertSimpleCommand(SimpleCommand* simpleCommand);

    static Command _currentCommand;
    static SimpleCommand* _currentSimpleCommand;
};

// Function Prototypes
void init_shell(void);
char* prompt1(void);
char* prompt2(void);

// Interactive Mode Prototypes
void lsh_interactive_loop(void);
char* lsh_interactive_input(void);

#endif // LSH_H