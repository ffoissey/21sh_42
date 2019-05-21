/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:54:20 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:23 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "libft.h"
# define GET_HEAD		0
# define FLUSH_MEMORY	1

void	*ft_malloc(size_t size);
void	*ft_calloc(size_t size);
void	*ft_realloc(void *old_ptr, size_t size);
void	ft_free(void *ptr);
void	ft_flush_memory(void);
void	*ft_get_head_list_allocation(int flush);
t_list	*ft_lstnew_no_malloc(unsigned char **data);

#endif
