#include "so_long.h"

char	**sl_join_map(char **rts, char *str)
{
	char	**result;
	int		index;
	int		xedni;

	//index = 0;
	if (str == NULL)
		return (rts);
	if (rts == NULL)
		result = (char **)ft_calloc(sizeof(char *), 2);
	else
		result = (char **)ft_calloc(sizeof(char *), sl_checklen(rts, NULL, 1) + 2);
	if (result == NULL)
	{
		/* free another result that use to malloc ??*/
		exit(0);
	}
	// while (rts != NULL && rts[index] != NULL)
	// {
	// 	xedni = 0;
	// 	result[index] = (char *)ft_calloc(sizeof(char), sl_checklen(NULL, rts[index], 3) + 1);
	// 	if (result == NULL)
	// 	{
	// 		/* free another result that use to malloc ??*/
	// 		exit(0);
	// 	}
	// 	while (rts[index][xedni] != '\0' && rts[index][xedni] != '\n')
	// 	{
	// 		result[index][xedni] = rts[index][xedni];
	// 		xedni++;
	// 	}
	// 	result[index][xedni] = '\0';
	// 	index++;
	// }
	index = sl_moveinfo_result(rts, result);
	// result[index] = (char *)ft_calloc(sizeof(char *), sl_checklen(NULL, str, 3) + 1);
	// if (result == NULL)
	// {
	// 	/* free another result that use to malloc ??*/
	// 	exit(0);
	// }
	// xedni = 0;
	// while (str[xedni] != '\0' && str[xedni] != '\n')
	// {
	// 	result[index][xedni] = str[xedni];
	// 	xedni++;
	// }
	// result[++index] = NULL;
	result = sl_joininfo_result(result, str, index);
	sl_twostars_tools(rts, 2);
	// if (rts != NULL)
	// {
	// 	index = 0;
	// 	while (rts[index] != NULL)
	// 		free(rts[index++]);
	// 	free(rts);
	// }
	free(str);
	return (result);
}

int	sl_moveinfo_result(char **rts, char **result)
{
	int	index;
	int xedni;

	index = 0;
	while (rts != NULL && rts[index] != NULL)
	{
		xedni = 0;
		result[index] = (char *)ft_calloc(sizeof(char), sl_checklen(NULL, rts[index], 3) + 1);
		if (result == NULL)
		{
			/* free another result that use to malloc ??*/
			exit(0);
		}
		while (rts[index][xedni] != '\0' && rts[index][xedni] != '\n')
		{
			result[index][xedni] = rts[index][xedni];
			xedni++;
		}
		result[index][xedni] = '\0';
		index++;
	}
	return (index);
}

char **sl_joininfo_result(char **result, char *str, int index)
{
	int	xedni;

	result[index] = (char *)ft_calloc(sizeof(char *), sl_checklen(NULL, str, 3) + 1);
	if (result == NULL)
	{
		/* free another result that use to malloc ??*/
		exit(0);
	}
	xedni = 0;
	while (str[xedni] != '\0' && str[xedni] != '\n')
	{
		result[index][xedni] = str[xedni];
		xedni++;
	}
	result[++index] = NULL;
	return (result);
}