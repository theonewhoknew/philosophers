NAME = philo

OBJECTS_DIR = objs
	
SRCS = $(addprefix srcs/, main.c check_args.c init.c simulation.c run_philo.c timer.c free.c \
						forks.c think_eat_sleep.c allocate.c fill.c allocate_aux.c)

OBJS = $(patsubst srcs/%.c,$(OBJECTS_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -I inc/ 

all: $(NAME) 

$(NAME) : $(OBJS) inc/philo.h 
	cc -pthread -g -o $(NAME) $(OBJS)

objs/%.o : srcs/%.c inc/philo.h | $(OBJECTS_DIR)
	cc -g -c  $< -o $@

$(OBJECTS_DIR) :
	mkdir -p $(OBJECTS_DIR)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: clean all clean fclean re