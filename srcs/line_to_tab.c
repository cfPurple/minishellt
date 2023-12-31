#include "minishell.h"

char **line_to_tab(char *str)
{
    char    **tab;
    int     i;
    int     j;
    int     start;
    int     end;

    tab = ft_calloc(nbr_of_token(str) + 1, sizeof(char *));
	if (!tab)
		return (0);
	j = 0;
    i = 0; 
	while (j < nbr_of_token(str) && str[i])
	{
		start = start_of_word(str, i);
		end = end_of_word(str, start);
		tab[j] = ft_substr(str, start, end - start);
		if (!tab[j])
			return (NULL);
		while (i < end && str[i])
			i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}