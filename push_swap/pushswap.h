/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:46:27 by afadouac          #+#    #+#             */
/*   Updated: 2024/02/24 21:38:21 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	int				index;
	int				moves;
	int				target;
	int				index2;
	int				flag;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int		*tab;
	int		size;
	int		*sorted;
	int		*sorted_index;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

int		ft_lstsize(t_stack *stack);
void	ft_lstclear(t_stack **stack);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(long content, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_fillstack(int ac, char **av, t_stack **stack_a);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_push_both(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, char *move);
char	**ft_split(char *s, char c);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		*ft_substr(int const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atoi(const char *str);
void	ft_is_doubled_or_max(t_stack *stack);
void	errors(int error, t_stack **stack_a);
void	ft_is_sorted(t_stack *stack_a, t_stack *stack_b);
int		max_of(int a, int b);
int		min_of(int a, int b);
void	flag_longest(t_stack *stack_a);
int		get_max_value_index(int *arr, int size);
int		get_min_value_index(t_stack *stack_a);
void	push_base(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
void	renisialize_index(t_stack **stack_a, t_stack **stack_b);
void	renisialize_index2(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_node_by_index(t_stack *stack, int index);
int		count_moves_a(t_stack *a, t_stack *b);
void	count_moves(t_stack **stack_a, t_stack **stack_b);
void	fill_data(t_data *data, t_stack *node);
void	do_moves(t_stack **stack_a, t_stack **stack_b, t_data *data);
void	push_to_a(t_stack **stack_a, t_stack **stack_b);
int		get_target_a(int value, t_stack *stack_b);
void	final_sort(t_stack **stack_a);
int		count_flag(t_stack *stack);
int		best_move(t_stack *stack_a);
int		sorted(t_stack *stack_a);
void	appliquer_operation(t_stack **stack_a, t_stack **stack_b);
void	appliquer_operation2(t_stack **stack_a, t_stack **stack_b, char *line);
int		ft_issorted(t_stack *stack);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*my_substr(char const *s, unsigned int start, size_t len);
#endif
