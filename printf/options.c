#include "includes/ft_printf.h"

void	percentage_case(int *modifiers)
{
	right_align(modifiers, 1, 1);
	ft_putchar('%');
	left_align(modifiers, 1);
}

void	string_case(va_list args, int *modifiers)
{
	char	*str;
	int		len;
	int		len_bis;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	len_bis = modifiers[PRECISION] < len && modifiers[PRECISION_EXISTS] ? modifiers[PRECISION] : len;

	right_align(modifiers, len_bis, 0);

	if (modifiers[PRECISION_EXISTS] && modifiers[PRECISION] < len)
		ft_putnstr(str, modifiers[PRECISION]);
	else
		ft_putstr(str);

	left_align(modifiers, len_bis);
}

void	character_case(va_list args, int *modifiers)
{
	int		c;

	c = va_arg(args, int);

	right_align(modifiers, 1, 1);
	ft_putchar(c);
	left_align(modifiers, 1);
}

void	unicode_case(va_list args, int *modifiers)
{
	wchar_t	c;

	c = va_arg(args, wchar_t);

	right_align(modifiers, 1, 1);
	ft_putchar_unicode(c);
	left_align(modifiers, 1);
}

void	unicode_str_case(va_list args, int *modifiers)
{
	wchar_t	*str;
	int		len;
	int		len_bis;

	str = va_arg(args, wchar_t *);
	len = ft_strlen_unicode(str);
	len_bis = modifiers[PRECISION] > len ? modifiers[PRECISION] : len;

	right_align(modifiers, len_bis, 0);

	ft_putstr_unicode(str);
}

void	unsigned_case(va_list args, char flag, int *modifiers)
{
	uintmax_t	i;
	int			len;
	int			len_bis;

	i = va_arg(args, uintmax_t);
	if (!modifiers[CONVERSION] && flag == 'u')
		i = (unsigned int)i;
	else if (flag == 'U')
		i = (unsigned long int)i;
	if (modifiers[CONVERSION] && flag == 'u')
		i = convert_uvalue(i, modifiers[CONVERSION]);

	len = ft_numlen(i, 10);
	len_bis = modifiers[PRECISION] > len ? modifiers[PRECISION] : len;

	!modifiers[ZERO_SPACES] ? right_align(modifiers, len_bis, modifiers[PRECISION] > len) : 0;

	modifiers[ZERO_SPACES] ? right_align(modifiers, len_bis, modifiers[PRECISION] > len) : 0;

	print_precision(modifiers, len);

	ft_putnbr_lint_abs(i);

	left_align(modifiers, len_bis);
}

void	integer_case(va_list args, char flag, int *modifiers)
{
	intmax_t	i;
	int			len;
	int			len_bis;

	i = va_arg(args, intmax_t);
	if (!modifiers[CONVERSION] && flag != 'D')
		i = (int)i;
	else if (flag == 'D')
		i = (long int)i;
	if (modifiers[CONVERSION] && flag != 'D')
		i = convert_svalue(i, modifiers[CONVERSION]);
	len = ft_numlen(i, 10);
	len_bis = modifiers[PRECISION] > len ? modifiers[PRECISION] : len;
	len_bis += modifiers[SHOW_SIGN] || i < 0 ? 1 : 0;
	len_bis += modifiers[A_SPACE] && i >= 0 ? 1 : 0;

	modifiers[A_SPACE] && i >= 0 && !modifiers[SHOW_SIGN] ? ft_putchar(' ') : 0;
	!modifiers[ZERO_SPACES] ? right_align(modifiers, len_bis, modifiers[PRECISION] > len) : 0;

	if (i < 0)
		ft_putchar('-');
	else if (modifiers[SHOW_SIGN])
		ft_putchar('+');
	modifiers[ZERO_SPACES] ? right_align(modifiers, len_bis, modifiers[PRECISION] > len) : 0;
	print_precision(modifiers, len);

	ft_putnbr_lint_abs(i);

	left_align(modifiers, len_bis);
}

void	hexadecimal_case(va_list args, char flag, int *modifiers)
{
	uintmax_t	value;
	char		*str;
	int			len;
	int			len_bis;

	value = va_arg(args, uintmax_t);
	if (!modifiers[CONVERSION])
		value = (unsigned int)value;
	else
		value = convert_uvalue(value, modifiers[CONVERSION]);
	str = ft_utob(value, 16, "0123456789abcdef");
	if (flag == 'X')
		ft_str_toupper(str);
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	len = ft_strlen(str);
	len_bis = modifiers[PRECISION] > len ? modifiers[PRECISION] : len;
	len_bis += modifiers[HASHTAG] ? 2 : 0;

	!modifiers[ZERO_SPACES] ? right_align(modifiers, len_bis, modifiers[PRECISION] > len) : 0;
	if (modifiers[HASHTAG] && flag == 'x' && value != 0)
			ft_putstr("0x");
	else if (modifiers[HASHTAG] && flag == 'X' && value != 0)
			ft_putstr("0X");
	modifiers[ZERO_SPACES] ? right_align(modifiers, len_bis, modifiers[PRECISION] > len) : 0;
	print_precision(modifiers, len);
	ft_putstr(str);
	left_align(modifiers, len_bis);
}

void	octal_case(va_list args, char flag, int *modifiers)
{
	uintmax_t	value;
	char		*str;
	int			len;
	int			len_bis;

	value = va_arg(args, uintmax_t);
	if (!modifiers[CONVERSION])
		value = (unsigned int)value;
	if (flag == 'o' && modifiers[CONVERSION])
		value = convert_uvalue(value, modifiers[CONVERSION]);
	str = ft_utob(value, 8, "01234567");
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	len = ft_strlen(str);
	len_bis = modifiers[PRECISION] > len + modifiers[HASHTAG] ? modifiers[PRECISION] : len + modifiers[HASHTAG];
	// len_bis += modifiers[HASHTAG] + len < modifiers[PRECISION] ? 0 : 1;

	right_align(modifiers, len_bis, modifiers[PRECISION] > len);

	if (modifiers[HASHTAG])
		ft_putstr("0");
	print_precision(modifiers, len + modifiers[HASHTAG]);
	ft_putstr(str);
	left_align(modifiers, len_bis);
}

void	pointer_case(va_list args)
{
	uintptr_t	value;
	char		*str;

	value = va_arg(args, uintptr_t);
	str = ft_utob(value, 16, "0123456789abcdef");
	while (*str == '0')
		str++;
	ft_putstr("0x");
	ft_putstr(str);
}
