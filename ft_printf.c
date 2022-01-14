#include "ft_printf.h"

static void	free_cas(t_cas *cas)
{
	cas->minus = 0;
	cas->zero = 0;
	cas->width = 0;
	cas->precision = 0;
	cas->mod = 0;
	cas->dot = 0;
}

static void	print(t_cas *cas, va_list *args)
{
	if (cas->mod == 'c')
		print_c(va_arg(*args, int), cas);
	else if (cas->mod == 'i' || cas->mod == 'd')
		print_i(va_arg(*args, int), cas);
	else if (cas->mod == 's')
		print_s(va_arg(*args, char *), cas);
	else if (cas->mod == 'u')
		print_u(va_arg(*args, unsigned int), cas);
	else if (cas->mod == 'x' || cas->mod == 'X')
		print_x(va_arg(*args, unsigned int), cas);
	else if (cas->mod == 'p')
		print_p((unsigned long)va_arg(*args, void *), cas);
	else if (cas->mod == '%')
		print_c('%', cas);
}

static void	handle_pars_two(const char **format, va_list *args, t_cas *cas)
{
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		cas->dot = 1;
		(*format)++;
		if (ft_isdigit(**format))
			cas->precision = ft_atoi(*format);
		else if (**format == '*')
		{
			cas->precision = va_arg (*args, int);
			(*format)++;
		}
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (ft_strchr("cspdiuxX%", **format))
		cas->mod = *(*format)++;
	if (cas->width < 0)
	{
		cas->width *= -1;
		cas->minus = 1;
	}
	if (cas->precision < 0)
		cas->dot = 0;
}

static void	handle_pars(const char **format, va_list *args, t_cas *cas)
{
	free_cas(cas);
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			cas->zero = 1;
		if (**format == '-')
			cas->minus = 1;
		(*format)++;
	}
	if (ft_isdigit(**format))
		cas->width = ft_atoi(*format);
	else if (**format == '*')
	{
		cas->width = va_arg(*args, int);
		(*format)++;
	}
	handle_pars_two(format, args, cas);
	print(cas, args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_cas	cas;

	cas.error = 0;
	cas.len = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_pars(&format, &args, &cas);
			if (cas.error)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			cas.len++;
		}
	}
	va_end(args);
	return (cas.len);
}
