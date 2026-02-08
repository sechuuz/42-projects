/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:18:02 by sechavez          #+#    #+#             */
/*   Updated: 2025/07/14 11:30:07 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define FT_BOOLEAN_H
#include <unistd.h>
#define EVEN(nbr) (((nbr) % 2) == 0)
#define TRUE 1
#define FALSE 0
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0

typedef int	t_bool;
