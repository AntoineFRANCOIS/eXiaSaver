CC	= gcc

RM	= rm -f

NAME	= exia_saver_static

SRCS	= mainoffi.c \
	  fonction.c

all:	$(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME) -lncurses

clean :
	$(RM) $(NAME)
