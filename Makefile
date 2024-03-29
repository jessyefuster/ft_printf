NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

# LIBFT_DIR = ./libft
# PRINTF_DIR = ./printf

# HEADER = $(FT_SRC_DIR)/includes/libft.h
# PRINTF_SRC_HEADER =	$(PRINTF_SRC_DIR)/includes/ft_printf.h

SCRS =			libft/ft_memset.c \
				libft/ft_memcpy.c \
				libft/ft_memccpy.c \
				libft/ft_memchr.c \
				libft/ft_memmove.c \
				libft/ft_memcmp.c \
				libft/ft_memalloc.c \
				libft/ft_bzero.c \
				libft/ft_putchar.c \
				libft/ft_putstr.c \
				libft/ft_putnstr.c \
				libft/ft_putendl.c \
				libft/ft_putchar_fd.c \
				libft/ft_putchar_unicode.c \
				libft/ft_putstr_fd.c \
				libft/ft_putstr_unicode.c \
				libft/ft_putendl_fd.c\
				libft/ft_strcpy.c \
				libft/ft_strncpy.c \
				libft/ft_strcat.c \
				libft/ft_strncat.c \
				libft/ft_strlcat.c \
				libft/ft_strcmp.c \
				libft/ft_strncmp.c \
				libft/ft_strdup.c \
				libft/ft_strlen.c \
				libft/ft_strlen_unicode.c \
				libft/ft_strchr.c \
				libft/ft_strrchr.c \
				libft/ft_strstr.c \
				libft/ft_strnstr.c \
				libft/ft_isdigit.c \
				libft/ft_isalnum.c \
				libft/ft_isascii.c \
				libft/ft_isalpha.c \
				libft/ft_isprint.c \
				libft/ft_islower.c \
				libft/ft_isupper.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_str_toupper.c \
				libft/ft_atoi.c \
				libft/ft_itoa.c \
				libft/ft_ltoa.c \
				libft/ft_utob.c \
				libft/ft_putnbr.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putnbr_abs.c \
				libft/ft_putnbr_lint_abs.c \
				libft/ft_strclr.c \
				libft/ft_strequ.c \
				libft/ft_strnequ.c \
				libft/ft_strjoin.c \
				libft/ft_memdel.c \
				libft/ft_strnew.c \
				libft/ft_strdel.c \
				libft/ft_striter.c \
				libft/ft_striteri.c \
				libft/ft_strmap.c \
				libft/ft_strmapi.c \
				libft/ft_strsub.c \
				libft/ft_strtrim.c \
				libft/ft_strsplit.c \
				libft/ft_numlen.c \
				libft/get_next_line.c \
				\
				printf/ft_printf.c \
				printf/options.c \
				printf/tools.c

OBJS =			$(SCRS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "made" $(NAME)


%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean:
	/bin/rm -f $(OBJS)
	echo "cleaned" $(NAME)

fclean: clean
	/bin/rm -f $(NAME)
	echo "fcleaned" $(NAME)

re: fclean all
