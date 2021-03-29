#include "ft_printf.h"

char *ft_ptrtoa(void *ptr)
{
	char *hex;
	char *out;

	hex = ft_lltoa_base((unsigned long)ptr, "0123456789abcdef");
	out = ft_strjoin("0x", hex);
	free(hex);
	return (out);
}