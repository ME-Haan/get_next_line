/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:09:24 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/24 15:52:28 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		head = ft_lstlast(*lst);
		head->next = new;
	}
}
