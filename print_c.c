#include "ft_printf.h"

void	print_c(char c, t_cas *stack)
{
	if (!stack->minus)
	{
		while (stack->width > 1)
		{
			ft_putchar_fd(' ', 1);
			stack->width--;
			stack->len++;
		}
		ft_putchar_fd(c, 1);
		stack->len++;
	}
	if (stack->minus)
	{
		ft_putchar_fd(c, 1);
		stack->len++;
		while (stack->width > 1)
		{
			ft_putchar_fd(' ', 1);
			stack->width--;
			stack->len++;
		}
	}
}
