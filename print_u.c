#include "ft_printf.h"

static void	minus_period(char *str, t_cas *cas, int len)
{
	while (cas->precision-- > len)
	{
		ft_putchar_fd('0', 1);
		cas->len++;
		cas->width--;
	}
	ft_putstr_fd(str, 1);
	cas->len += len;
	while (cas->width > len)
	{
		ft_putchar_fd(' ', 1);
		cas->len++;
		cas->width--;
	}
}

static void	classic(char *str, t_cas *cas, int len)
{
	while (cas->width > cas->precision && cas->width-- > len)
	{
		ft_putchar_fd(' ', 1);
		cas->len++;
	}
	while (cas->precision > len)
	{
		len++;
		ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	cas->len += len;
}

static void	zero_minus_period(char *str, t_cas *cas)
{
	int		len;

	len = ft_strlen(str);
	if (cas->zero && !cas->minus && !cas->dot)
	{
		while (cas->width-- > len)
		{
			ft_putchar_fd('0', 1);
			cas->len++;
		}
		ft_putstr_fd(str, 1);
		cas->len += len;
	}
	else
		minus_period(str, cas, len);
}

static void	period(char *str, t_cas *cas)
{
	int	len;

	len = ft_strlen(str);
	if (cas->minus)
	{
		ft_putstr_fd(str, 1);
		cas->len += len;
		while (cas->width-- > len)
		{
			ft_putchar_fd(' ', 1);
			cas->len++;
		}
	}
	else
		classic(str, cas, len);
}

void	print_u(unsigned int i, t_cas *cas)
{
	char	*str;

	if (!i && !cas->precision && cas->dot)
	{
		str = malloc(1);
		*str = 0;
	}
	else
		str = ft_uitoa(i);
	if (!str)
	{
		cas->error = -1;
		return ;
	}
	if ((cas->zero && !cas->dot && !cas->minus)
		|| (cas->dot && cas->minus))
		zero_minus_period(str, cas);
	else
		period(str, cas);
	free (str);
}
