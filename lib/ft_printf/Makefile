#!----- NAME ------!
NAME:= libftprintf.a

#!----- COLORS -----!

GREEN  = \\033[0;32m
YELLOW = \\033[0;33m
BLUE   = \\033[0;34m
RESET  = \\033[0m

#!----- CC AND FLAGS -----!

CC= cc
CFLAGS:= -Wall -Wextra -Werror
AR:= ar -rcs
RM:= rm -rf

#!----- FILES ----!

SRC = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_base.c

OBJ = $(SRC:.c=.o)

#!----- RULES -----!

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "$(YELLOW)[Compilating] $(RESET)$<\n"

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	@echo -e "$(GREEN)[Cleaning files]$(RESET)\n"
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#!----- PHONY -----!

.PHONY: all clean fclean re
