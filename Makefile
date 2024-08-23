NAME = myserver

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp socket/SimpleSocket.cpp server/SimpleServer.cpp
HEADER = socket/SimpleSocket.hpp server/SimpleServer.hpp

all: $(NAME)

$(NAME):	$(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean