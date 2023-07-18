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
	char *toks[2];
	int counter = 0;
	size_t len = BUFFER_SIZE;
	pid_t child_pid = 1;
	ssize_t bytesread;
	char path[5] = "/bin/";
	char *envp[] = { "/bin/", NULL };

	while (1)
	{
		_printf("#hsh$ "); /* Display the prompt */

		bytesread = getline(&buffer, &len, stdin);

		/* Handle end of file (Ctrl+D)*/
		if (bytesread == -1)
		{
			_printf("\n");
			break;
		}

		token = strtok(buffer, " ");
		_printf("buffer: %s\n", buffer);
                _printf("token: %s\n", token);
		/*add path to beginning of command*/
		if (!(_strncmp(envp[0], token, _strlen(envp[0])) == 0)) {
			_strcat(path, token);
			token = path;
		}
		_printf("token: %s", token);
		counter = 0;
		while (token != NULL)
		{
			toks[counter] = _strdup(token);
			token = strtok(NULL, " ");
			counter++;
		}
		
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR");
			free(buffer);
			return(-1);
		}

		if (child_pid == 0)
		{
			_printf("toks[0]: %s\n", toks[0]);
			if (execve(toks[0], toks, envp) == -1)
			{
				perror("ERROR");
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
