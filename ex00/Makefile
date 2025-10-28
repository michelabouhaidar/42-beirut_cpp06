NAME    = ex00
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS    = isType.cpp  main.cpp  parseType.cpp  print.cpp  ScalarConverter.cpp
OBJS    = $(SRCS:.cpp=.o)
DEPS    = ScalarConverter.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re