/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 00:58:53 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:55 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "parser.h"

static char	*variable_replace(t_list *lst, char *str)
{
	char		*expanded;
	char		*data;
	uint32_t	i;

	if (*str == '\0')
		return (str);
	expanded = NULL;
	i = ft_strcspn(str, EXP_INTERUPT);
	str[i] = character_swap(str[i]);
	data = get_data(lst, str);
	str[i] = character_swap('\0');
	if (i == 0)
		ft_asprintf(&expanded, "$%s", str);
	else if (data != NULL)
		ft_asprintf(&expanded, "%s%s", data, str + i);
	else
		ft_asprintf(&expanded, "%s", str + i);
	return (expanded);
}

static char	*variable_concat(t_list *lst, char **str, int i)
{
	char	*expanded;
	char	*holder;

	holder = NULL;
	expanded = variable_replace(lst, *str + i + 1);
	ft_asprintf(&holder, "%.*s%s%c", i, *str, expanded, '\0');
	ft_strdel(&expanded);
	ft_strdel(str);
	return (holder);
}

static int	check_expansion(t_parser *parse, char **str, int i, t_quote quote)
{
	int		check;

	check = 0;
	if ((*str)[i] == '$' && (*str)[i + 1] != '\0')
	{
		if (ft_strchr(EXP_INTERUPT, (*str)[i + 1]))
			check = 0;
		else if (quote != QUOTE_SINGLE)
		{
			*str = variable_concat(parse->env, str, i);
			check = 1;
		}
	}
	return (check);
}

char		*variable_expansion(t_parser *parse, char *str)
{
	t_quote		quote;
	uint32_t	i;
	uint32_t	len;

	i = 0;
	quote = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_strchr("\'\"", str[i]) && (parse->special_case & QUOTING))
			quote = select_quoting(quote, str[i]);
		if (check_expansion(parse, &str, i, quote) == 1)
			len = ft_strlen(str);
		else
			++i;
	}
	return (str);
}
