#include "main.h"

/**
 * lookforslash - This function will identifies if first
 * char is a slash.
 * @cmd: is  first string
 * Return: 1 if yes 0 if no.
 */
int lookforslash(char *cmd)
{
	int cont = 0;

	while (cmd[cont])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return (1);
		}

		cont++;
	}
	return (0);
}

/**
 * compareExit - This functoin will identifies if
 * first char is a slash.
 * @s1: is first string
 * @s2: is exit string
 * Return: 1 if yes 0 if no.
 */
int compareExit(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * compareEnv - This functio will identifies if first
 * char is a slash.
 * @s1: is first string
 * @s2: is exit string
 * Return: 1 if yes 0 if no.
 */
int compareEnv(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 2)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 * identify_string - this function will identyfy keyboard input.
 * @parameter: is call prompt from another function (prompt)
 * Return: str
 **/
char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *split;
	int i = 0;
	char *delim = " \t\n";


	split = strtok(parameter, delim);

	while (split != NULL)
	{
		buf[i] = split;
		i++;
		split = strtok(NULL, delim);
	}
	execute_proc(buf);
	return (buf);

}
/**
 * controlC - this function avoid close the shell
 * @sig: keep going shell
 **/
void  controlC(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}
