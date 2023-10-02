NAME = philo

OBJECTS_DIR = objs
	
SRCS = $(addprefix srcs/, main.c check_args.c init.c simulation.c routine.c check_threads.c forks.c timer.c print_utils.c)
						

OBJS = $(patsubst srcs/%.c,$(OBJECTS_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -I inc/ 

all: $(NAME) 

$(NAME) : $(OBJS) inc/philo.h
	gcc -pthread -o $(NAME) $(OBJS)

objs/%.o : srcs/%.c inc/philo.h Makefile | $(OBJECTS_DIR)
	cc -c  $< -o $@

$(OBJECTS_DIR) :
	mkdir -p $(OBJECTS_DIR)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: clean all clean fclean re