#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;

/* Fundamental functions  */

int _putchar(char c);
void prints(char *str);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *place, char *origin);
int _strlen(const char *x);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);
char *_strdup(char *str);
char *_memcpy(char *place, char *origin, unsigned int n);
char *_itoa(int num, int base);
int _atoi(char *a);

/* Important functions */

char **split_str(char *line, char **env);
void prompt(void);
char *read_input();
void printenv(char **environ);
void _puts(char *str);

/* Functions for Processes */

int execute_cmd(char **av, char **args, char **environ, int maxx, int maxxiz);
char **search(char **environ);
char **_maxx(char *maxxpath);

/*Signal Functions */

void handle_signal(int signal);
int _maxxstat(char **cmd, char **joined);
int *maxx_error(char *argv, int count, char *args);


/*Function for memory */

void *_calloc(unsigned int nmaxx, unsigned int size);

#endif /* MAIN_H */
