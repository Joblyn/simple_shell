#include "main.h"

/**
 * main - Main function handling the shell commands and interactions
 * Return: 0 on success; -1 on failure
 */
int main(void)
{

	char *buffer = malloc(BUFFER_SIZE);
	int status;
	char *token;
	char *toks[1];
	int counter = 0;
	size_t len = BUFFER_SIZE;
	pid_t my_pid;
	pid_t child_pid = 1;

	my_pid = getpid();

	while (1)
	{
		_printf("#hsh$ "); /* Display the prompt */

		int bytesread = getline(&buffer, &len, stdin);

		/* Handle end of file (Ctrl+D) */
		if (bytesread == -1)
		{
			free(buffer);
			_printf("\n");
			break;
		}
		/*strcmp not allowed*/
		/* if (strcmp(command, "exit") == 0)
		{
			break;
		} */

		/* Print an error message if execution failed */
		if (status == -1)
		{
			perror("ERROR: Command execution failed");
			free(buffer);
			return(-1);
		}

		/* Execute the user command here */
		_printf("%s", buffer);
		token = strtok(buffer, " ");
		while (token != NULL)
		{
			toks[counter] = _strdup(token);
			token = strtok(NULL, " ");
			counter++;
		}
		
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR: Error creating child process");
			free(buffer);
			return(-1);
		}
		if (child_pid == 0)
		{
			child_pid = getpid();
			if (execve(toks[0], toks, NULL) == -1)
			{
				perror("ERROR: Error executing command");
				free(buffer);
				return (-1);
			}	
		} else {
			wait(&status);
		}
	}

	free(buffer);

	return (0);
}
