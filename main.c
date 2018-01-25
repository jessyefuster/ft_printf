#include "printf/includes/ft_printf.h"
#include <locale.h>

int		main(void)
{
	char	*str;
	char	c;
	wchar_t	*c2;
	wchar_t c3;
	int		i;
	char	i_convert;
	int		i2;
	double	f;
	int		ret;

	setlocale(LC_CTYPE, "");
	c2 = L"本本本本本本本本";
	c3 = L'本';
	i = 300;
	i_convert = i;
	i2 = -6;
	c = 'c';
	f = 5.67;
	str = ft_strdup("abcdefghi");

	char *strVLA = "%lu\n";

	ft_printf(strVLA, -42);
	ret = printf(strVLA, -42);

	ft_putnbr(ret);

	// printf("UINTPTR %ld\n", LONG_MIN);
	//printf("ULLONG %llu - %lu\n", ULLONG_MAX, sizeof(unsigned long));
	//printf("ULONG  %lu - %lu\n", ULONG_MAX, sizeof(unsigned long long));
	// ft_printf(ft_strjoin("FT_", strVLA), 16407409, i, c, c2, str, &i);
	// printf(ft_strjoin("   ", strVLA), 16407409, i, c, c2, str, &i);

	//0xFA5B71

	// printf("4567 |%-105d| plip\n", 12);
	// printf("4567 |%105d| plip\n", 12);
	// printf("|%10.5d|\n", -12);
	// printf("|%10d|\n", -12);
	// printf("|%010d|\n", -12);
	// printf("|%-10.5d|\n", -12);
	// printf("|%-010.5d|\n", -12);
	// printf("%x\n", 0x45D6);

	return (0);
}