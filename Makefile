NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f
NM = norminette
LIB_H = includes/ft_printf.h \
LIBFT = libft/libft.a

SRCS = \
	srcs/ft_printf.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME)
	@ar -crs $(NAME) $(OBJS)

norme: 
	@norminette
	
git: 
	@git add .
	@git commit -m "makefile"
	@git push
	clear
	
clean:
	$(RM) $(OBJS)
	@cd libft && $(MAKE) clean
	@rm -rf a.out* tripouille
	
fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: norme all fclean r clean