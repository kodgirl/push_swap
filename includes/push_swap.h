# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> //delete
#include <stdlib.h>
#include <unistd.h>

# define ERROR_NOT_INT		"some arguments are not integers"
# define ERROR_BIGGER_INT	"some arguments are bigger than an integer"
# define ERROR_DUBL			"there are duplicates"
# define ERROR_BAD_INSTRUCT	"an instruction don’t exist"

typedef struct		s_swap
{
	int				num;
	struct s_swap	*next;	
}					t_swap;

t_swap	*ft_lstnew(int num);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
int		ft_atoi(const char *str, char **error);
void	ft_lstadd(t_swap **stack, t_swap *new);


#endif