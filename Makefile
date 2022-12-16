#**************************************************************************** #
# #
# :: : :: :: :: ::#
#Makefile : + : : + : : + : #
#+ : + + : + + : + #
#By : hben - bou < hben - bou @student .1337.ma> + # + + : ++# + #
#+ #+ #+ #+ #+ #+ + #+ #
#Created : 2022 / 11 / 04 00 : 47 : 57 by hben - bou # + # # + # #
#Updated : 2022 / 11 / 04 00 : 47 : 58 by hben - bou## # ########.fr #
# #
#**************************************************************************** #
NAME = libftprintf.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -cr
RM = rm -f

SRC =	ft_printf.c\
		ft_printf_hexa.c\
		ft_printf_number.c\
		ft_printf_pointer.c\
		ft_printf_unsigned.c\
		ft_printf_utils.c

OBJ = 	ft_printf.o\
		ft_printf_hexa.o\
		ft_printf_number.o\
		ft_printf_pointer.o\
		ft_printf_unsigned.o\
		ft_printf_utils.o

all : $(NAME)
	
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

clean:
	$(RM) $(OBJ)
	
fclean:
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
