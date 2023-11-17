#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define MAX_INPUT_LENGTH 100
extern char **environ;

void execute_command(char *command);
char *get_input(void);
int main(void);
void exit_shell(void);
void print_env(void);

#endif
