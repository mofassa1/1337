/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:00:03 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/24 21:44:24 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
}					t_stack;

int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*my_substr(char const *s, unsigned int start, size_t len);

void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_push_both(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, char *move);
int		ft_issorted(t_stack *stack);
void	appliquer_operation2(t_stack **stack_a, t_stack **stack_b, char *line);
void	appliquer_operation(t_stack **stack_a, t_stack **stack_b);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
t_stack	*ft_fillstack(int ac, char **av, t_stack **stack_a);
void	ft_is_doubled_or_max(t_stack *stack);
long	ft_atoi(const char *str);
void	ft_lstclear(t_stack **stack);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(long content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	error(int error, t_stack **stack_a);
char	**ft_split(char *s, char c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

#endif