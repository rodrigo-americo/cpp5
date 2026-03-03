NAME    = main
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC     = main.cpp Bureaucrat.cpp Form.cpp
OBJ     = $(SRC:.cpp=.o)
HEADER  = Bureaucrat.hpp Form.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re