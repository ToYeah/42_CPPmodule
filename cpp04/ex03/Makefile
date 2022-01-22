NAME			:= materia
CXX				:= clang++
CXXFLAGS		:= -Wall -Wextra -Werror -MMD -MP -std=c++98
SRCSDIR			:= .
OBJSDIR			:= objs
SRCS			:= $(shell find $(SRCSDIR) -type f -name "*.cpp" | xargs basename -a)
INCLUDES		:= $(shell find $(SRCSDIR) -type d | awk '{print "-I " $$0}')
VPATH			:= $(shell find $(SRCSDIR) -type d | awk '{print $$0":"}')
OBJS			:= $(SRCS:%.cpp=$(OBJSDIR)/%.o)
DEPENDS			:= $(OBJS:.o=.d);

all: $(NAME)

-include $(DEPENDS)

$(OBJSDIR)/%.o : %.cpp
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi;
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re