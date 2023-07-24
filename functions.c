#include "main.h"
/**
 * print_env - print infromations of pc
 * @args: ponter of array of characters
 */
void print_env(char **args,char **env)
{
	if (strcmp(args[0], "env") == 0)
	{

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
/**
 * do_exit - exite if written exit
 * @args: ponter to array
 * Return: return 0 if exite or return to the main if not
 */
void do_exit(char **args)
{
	if (strcmp(args[0], "exit") == 0)
		exit(0);
	else
		return;
}
/**
 * seperte - seperte the string for more arguments
 * @buffer: array has string
 * @token: variable save the little string
 * Return: pointer to first char
 */
char *seperte(char *buffer,char **args, char *token)
{
	int i = 0;

	token = strtok(buffer, " ");

	while (token != NULL && i < 63)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (*args);
}
