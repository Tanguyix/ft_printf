NAME = libftprintf.a
SRC = ft_printf.c ft_parse2.c ft_bool.c ft_base.c ft_star.c ft_get_arg.c ft_base_handlers.c ft_c.c ft_n.c ft_d_handlers.c ft_s_uni_handlers.c ft_which_conversion.c ft_char_unicode.c ft_d.c ft_p.c ft_parse.c ft_s.c ft_str_unicode.c libftprintf/ft_get_size_nb.c libftprintf/ft_atoi.c libftprintf/ft_bzero.c libftprintf/ft_isdigit.c libftprintf/ft_itoa.c libftprintf/ft_memset.c libftprintf/ft_putchar_fd.c libftprintf/ft_putstr_fd.c libftprintf/ft_strcpy.c libftprintf/ft_strdup.c libftprintf/ft_strlen.c libftprintf/ft_itoa_base.c libftprintf/ft_size_base.c
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Iincludes -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
