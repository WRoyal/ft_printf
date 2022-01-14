#ifndef FT_PRINTF_H
# define FT_PRINTF_H 
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <limits.h>
# define HEXADECIMAL_UPPERCASE "0123456789ABCDEF"
# define HEXADECIMAL_LOWERCASE "0123456789abcdef"

typedef struct s_cas
{
	bool	minus;
	bool	zero;
	int		precision;
	int		width;
	char	mod;
	bool	dot;
	int		error;
	int		len;
}				t_cas;

int		ft_printf(const char *format, ...);
void	print_c(char c, t_cas *stack);
void	print_i(int i, t_cas *stack);
void	print_s(char *str, t_cas *stack);
void	print_u(unsigned int i, t_cas *stack);
void	print_x(unsigned int n, t_cas *stack);
void	print_p(unsigned long n, t_cas *stack);
int		ft_ulength(unsigned int n);
int		ft_xlength(unsigned int n);
int		ft_plength(unsigned long n);
char	*ft_uitoa (unsigned int i);
char	*ft_xitoa(unsigned int i, t_cas *stack);
char	*ft_pitoa(unsigned long i);

#endif