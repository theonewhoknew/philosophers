NAME = philo

OBJECTS_DIR = objs
	
SRCS = $(addprefix srcs/, main.c check_args.c init_struct.c simulation.c run.c time.c)

OBJS = $(patsubst srcs/%.c,$(OBJECTS_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -I inc/ 

all: $(NAME) 

$(NAME) : $(OBJS) inc/philo.h 
	cc -pthread -o $(NAME) $(OBJS)

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