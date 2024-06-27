NAME	=	pipex
#BONUS 	=

SRCS	= \
		main.c\
		child.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc 

RM	=	rm -f

SANITIZE = 	-fsanitize=address -fsanitize=leak -g3
CFLAGS	=	-Wall -Wextra -Werror $(SANITIZE)

all		:	$(NAME)

bonus	: 	$(BONUS)

$(NAME)	:	$(OBJS) 
		make -C ./libft
		$(CC) $(CFLAGS) $(OBJS) -I ./libft/libft.h ./libft/libft.a -o $(NAME)

#$(BONUS) :	$(NAME)
#		ln -s $(NAME) $@
	   
clean	:
			$(RM) $(OBJS)
			make fclean -C ./libft	

fclean	:	clean
			$(RM) $(NAME) $(BONUS)

.PHONY	:	all clean fclean re

re	:	fclean all
