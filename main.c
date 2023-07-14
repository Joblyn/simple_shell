#include "main.h"

/**
 * main - Main function handling the shell commands and interactions
 * @void: Pointer to the 2D array of integers.
 */
int main(void)
{

char command[BUFFER_SIZE]; /* Buffer to store user input */
int status = system(command);

while (1)
{
printf("$ "); /* Display the prompt */

/* Handle end of file (Ctrl+D) */
if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n");
break;
}

if (strcmp(command, "exit") == 0)
{
break;
}

/* Print an error message if execution failed */
if (status == -1)
{
perror("Command execution failed");
}

/* Execute the user command here */
printf("%s", command);
}

return (0);
}
