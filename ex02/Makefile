# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 16:15:58 by sakitaha          #+#    #+#              #
#    Updated: 2025/01/27 16:32:41 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS     := main.cpp
OBJS     := $(SRCS:.cpp=.o)
DEPS     := $(OBJS:.o=.d)

NAME     := ex02

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	@echo "== Running Tests  =="
	./$(NAME)
	@echo "== Tests Completed =="

test: CXXFLAGS += -DDISPLAY_DEBUG_MSG
test: re run

debug: CXXFLAGS += -fsanitize=address -g
debug: $(NAME)
	./$(NAME)

valgrind: all
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run test debug valgrind
