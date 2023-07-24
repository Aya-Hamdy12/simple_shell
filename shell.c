#include "main.h"

/**
 * main - simple shell command line for alx intern
 * in the main we have 4 function and one header
 * Return: return nothing
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *args[64];
	pid_t child_pid;
	int status;
	char *token = NULL;
	char **env = environ;

	while (1)
	{
		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);
		if (feof(stdin))
		{
			printf("\n");
			return (0);
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		*args = seperte(buffer, args, token);
		do_exit(args);
		print_env(args, env);
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
}
