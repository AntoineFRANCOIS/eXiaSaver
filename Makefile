CC	= gcc

RM	= rm -f

NAME	= exia_saver_dynamique

SRCS	= Nomain.c \
	  fonct.c

all:	$(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME) -lncurses

clean :
	$(RM) $(NAME)
