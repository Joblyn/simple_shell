#ifndef MAIN_H
#define MAIN_H

/* standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* For fork and execve */
#include <sys/wait.h> /* For wait */

/* _printf */
#include "./_printf/main.h"

#define BUFFER_SIZE 1024

extern char **environ;

char *_strdup(char *org);
int _strlen(char *str);
int _strcmp(const char *X, const char *Y);
int _strncmp(const char * s1, const char * s2, size_t n);
char *_strcat(char* destination, const char* source);

#endif
