NAME = Webserv

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

g++ = c++

RM = rm -rf

SRC = Config.cpp\
			main.cpp\
			funcs_helper.cpp\
			errors.cpp\


OBJS := $(SRC:.cpp=.o)

all: $(NAME)

%.o:%.cpp Config.hpp
	$(g++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(g++) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all