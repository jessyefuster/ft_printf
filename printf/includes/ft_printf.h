#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define PRECISION			0
# define SPACES				1
# define SHOW_SIGN			2
# define ZERO_SPACES		3
# define HASHTAG			4
# define LEFT_ALIGN			5
# define PRECISION_EXISTS	6
# define A_SPACE			7
# define CONVERSION			8

# define H		(1)
# define HH		(1 << 1)
# define L		(1 << 2)
# define LL		(1 << 3)
# define J		(1 << 4)
# define Z		(1 << 5)

int			ft_printf(const char *format, ...);

/*
**		OPTIONS.C
*/
void		percentage_case(int *modifiers);
void		string_case(va_list args, int *modifiers);
void		integer_case(va_list args, char flag, int *modifiers);
void		character_case(va_list args, int *modifiers);
void		unicode_case(va_list args, int *modifiers);
void		unicode_str_case(va_list args, int *modifiers);
void		hexadecimal_case(va_list args, char flag, int *modifiers);
void		octal_case(va_list args, char flag, int *modifiers);
void		pointer_case(va_list args);
void		unsigned_case(va_list args, char flag, int *modifiers);

/*
**		TOOLS.C
*/
void		print_precision(int *modifiers, int len);
void		left_align(int *modifiers, int len);
void		right_align(int *modifiers, int len, int force_space);
intmax_t	convert_svalue(intmax_t value, int conversions);
uintmax_t	convert_uvalue(uintmax_t value, int conversions);

#endif
