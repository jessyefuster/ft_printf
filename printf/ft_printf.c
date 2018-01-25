#include "includes/ft_printf.h"
#include <limits.h>

int		is_valid_type(char c)
{
	if (c == 's' || c == 'd' || c == 'c' || c == 'C' || c == 'S' ||
		c == 'x' || c == 'X' || c == 'p' || c == '%' || c == 'o' || c == 'O'
		|| c == 'i' || c == 'D' || c == 'u' || c == 'U')
	{
		return (1);
	}
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

char	*check_conversions(char *str, int *modifiers)
{
	if (str[0] == 'l' && str[1] == 'l')
		modifiers[CONVERSION] += LL;
	else if (str[0] == 'l')
		modifiers[CONVERSION] += L;
	else if (str[0] == 'h' && str[1] == 'h')
		modifiers[CONVERSION] += HH;
	else if (str[0] == 'h')
		modifiers[CONVERSION] += H;
	else if (str[0] == 'j')
		modifiers[CONVERSION] += J;
	else if (str[0] == 'z')
		modifiers[CONVERSION] += Z;
	while (*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z')
		str++;
	return (str);
}

char	*check_modifiers(char *str, int *modifiers)
{
	while (!is_valid_type(*str))
	{
		if (*str == '0' && str++)
			modifiers[ZERO_SPACES] = 1;
		else if (*str == '-' && str++)
			modifiers[LEFT_ALIGN] = 1;
		else if (*str == '#' && str++)
			modifiers[HASHTAG] = 1;
		else if (*str == '.' && str++ && *str != '-')
		{
			modifiers[PRECISION_EXISTS] = 1;
			modifiers[PRECISION] = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str == '+' && str++)
			modifiers[SHOW_SIGN] = 1;
		else if (*str == ' ' && str++)
			modifiers[A_SPACE] = 1;
		else if (ft_isdigit(*str))
		{
			modifiers[SPACES] = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else
			str++;
	}
	return (str);
}

char	*parse_option(va_list args, char *flag)
{
	int		modifiers[9];

	ft_bzero(modifiers, sizeof(int) * 9);
	flag = check_modifiers(flag, modifiers);
	flag = check_conversions(flag, modifiers);
	if (flag[0] == 's' && !(modifiers[CONVERSION] & L))
		string_case(args, modifiers);
	else if (flag[0] == 'S' || (flag[0] == 's' && modifiers[CONVERSION] & L))
		unicode_str_case(args, modifiers);
	else if (flag[0] == 'd' || flag[0] == 'i' || flag[0] == 'D')
		integer_case(args, flag[0], modifiers);
	else if (flag[0] == 'c' && !(modifiers[CONVERSION] & L))
		character_case(args, modifiers);
	else if (flag[0] == 'C' || (flag[0] == 'c' && modifiers[CONVERSION] & L))
		unicode_case(args, modifiers);
	else if (flag[0] == 'x' || flag[0] == 'X')
		hexadecimal_case(args, flag[0], modifiers);
	else if (flag[0] == 'p')
		pointer_case(args);
	else if (flag[0] == 'o' || flag[0] == 'O')
		octal_case(args, flag[0], modifiers);
	else if (flag[0] == 'u' || flag[0] == 'U')
		unsigned_case(args, flag[0], modifiers);
	else if (flag[0] == '%')
		percentage_case(modifiers);
	flag++;
	return (flag);
}

int		analyse(va_list args, const char* format)
{
	char	*ptr;
	char	*start;
	// int		*ret;

	ptr = (char *)format;
	start = (char *)format;
	while ((ptr = ft_strchr(ptr, '%')) != NULL)
	{
		ft_putnstr(start, ptr - start);
		ptr = parse_option(args, ptr + 1);
		start = ptr;
	}
	ft_putstr(start);

	return (4);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = analyse(args, format);
	va_end(args);
	return (ret);
}
