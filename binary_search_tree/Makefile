NAME = libtree.a

SRC = destroy.c\
	  empty.c\
	  retreive.c\
	  traverse.c\
	  create.c\
	  insert.c\
	  delete.c\

OBJECTS = *.o
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
