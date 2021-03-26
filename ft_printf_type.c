#include "ft_printf.h"

void print_hexdigit(int n, int uppercase)
{
	char *digits;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	ft_putchar_fd(digits[n], 1);
}

int print_hex(long long n, t_spec *spec)
{
	int n_chars;

	if (n < 0)
	{
		n_chars = 2;
		ft_putchar_fd('-', 1);
		if (n < -9)
			n_chars += print_hex(0 - (n / 16), spec);
		print_hexdigit(n % 16, spec->specifier == 'X');
	}
	else
	{
		n_chars = 1;
		if (n > 9)
			n_chars += print_hex(n / 16, spec);
		print_hexdigit(n % 16, spec->specifier == 'X');
	}
	return (n_chars);
}

int print_dec(long long n, t_spec *spec)
{
	int n_chars;

	if (n < 0)
	{
		n_chars = 2;
		ft_putchar_fd('-', 1);
		if (n < -9)
			n_chars += print_dec(0 - (n / 16), spec);
		ft_putchar_fd('0' - (n % 10), 1);
	}
	else
	{
		n_chars = 1;
		if (n > 9)
			n_chars += print_dec(n / 16, spec);
		ft_putchar_fd('0' + (n % 10), 1);
	}
	return (n_chars);
}

int print_ptr(void *ptr, t_spec *spec)
{
	int n_chars;

	ft_putstr_fd("0x", 1);
	spec->specifier = 'x';
	n_chars = 2;
	n_chars += print_hex((unsigned long)ptr, spec);
	return (n_chars);
}

int print_char(char c, t_spec *spec)
{
	(void)spec;
	ft_putchar_fd(c, 1);
	return (1);
}

int print_whitespace(int len)
{
	int index;
	while (index++ < len)
		ft_putchar_fd(' ', 1);
	return (len);
}

int print_str(char *s, t_spec *spec)
{
	(void)spec;
	if (s == NULL)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int print_nbr(int nb, t_spec *spec)
{
	(void)spec;
	ft_putnbr_fd(nb, 1);
	return (3);
}