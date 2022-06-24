#include "so_long.h"
#include "./libft/libft.h"

	/* counting function*/
		/* mode1 = count 2D malloc | mode2 = count lenght of a string |
		 mode3 = count until find newline in a string */
int	sl_checklen(char **rts, char *str, int mode)
{
	int	count;

	count = 0;
	if (mode == 1 && rts != NULL)
	{
		while (rts[count] != NULL)
			count++;
		return (count);
	}
	else if (mode == 2 && str != NULL)
	{
		while (str[count] != '\0')
			count++;
		return (count);
	}
	else if (mode == 3 && str != NULL)
	{
		while (str[count] != '\n' && str[count] != '\0')
			count++;
		return (count);
	}
	return (-1);
}

    /* tools function for char ** */
        /* mode1 = print value char ** | mode0 = free char ** */
void twostarstools(void **str, int mode)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		printf("str == NULL\n");
		return ;
	}
	else if (mode == 1)
	{
		while ((char *)str[count] != NULL)
			printf("%s\n", (char *)str[count++]);
		return ;
	}
	else if (mode == 0)
	{
		while (str[count] != NULL)
			free(str[count++]);
		free(str);
		return ;
	}
}
