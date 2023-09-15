SRCS = main.c utils.c time.c a_day_routine.c death_things.c arg_ctl.c

NAME = philo

CC = gcc
FLAGS = -Wall -Werror -Wextra

TFLAG = -lpthread
RM = rm -f

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -I ./ $< -o $@

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) $(TFLAG) -o $(NAME)

clean:
				$(RM) $(OBJS)
fclean:         clean
				$(RM) $(NAME)  
re:             fclean all
.PHONY:         all clean fclean re
