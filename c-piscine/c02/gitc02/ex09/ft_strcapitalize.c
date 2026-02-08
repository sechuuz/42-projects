/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:46:46 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/01 16:46:47 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	up(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}

void	low(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
	}
}

int	is_alphnum(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (is_alphnum(str[i]) && c == 0)
		{
			up(&str[i]);
			c = 1;
		}
		else if (is_alphnum(str[i]) && c == 1)
		{
			low(&str[i]);
		}
		else if (!is_alphnum(str[i]))
		{
			c = 0;
		}
		i++;
	}
	return (str);
}
