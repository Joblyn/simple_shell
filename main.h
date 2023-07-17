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

char *_strdup(char *org);
int _strlen(char *str);

#endif
