#include <stdio.h>

static int all_digits(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (1);
	}
	return (0);
}

int check_args(int argc, char **argv)
{	
	int i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	while (i < argc)
	{
		if (all_digits(argv[i]) == 1)
			return (1);
		i++;
	} 
}