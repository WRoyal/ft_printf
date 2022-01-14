#include "ft_printf.h"

static void	print_s1(char *str, t_cas *cas)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (cas->dot && cas->precision <= len - 1)
		len = cas->precision;
	while (i < len && cas->minus)
		ft_putchar_fd(str[i++], 1);
	while (cas->width > len)
	{
		ft_putchar_fd(' ', 1);
		cas->width--;
		cas->len++;
	}
	while (i < len && !cas->minus)
		ft_putchar_fd(str[i++], 1);
	cas->len += len;
}

void	print_s(char *str, t_cas *cas)
{
	if (str == NULL)
		str = "(null)";
	if (cas->precision < 0)
		cas->dot = 0;
	print_s1(str, cas);
}
