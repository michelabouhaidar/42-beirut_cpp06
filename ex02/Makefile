NAME       := ex02
CXX        := c++
CXXFLAGS   := -Wall -Wextra -Werror -std=c++98
RM         := rm -f

SRCS       := main.cpp Base.cpp functions.cpp
OBJS       := $(SRCS:.cpp=.o)

INCS       := Base.hpp A.hpp B.hpp C.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
