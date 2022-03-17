DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
TESTCOL = \033[1;35m

# NAME =====================================================================================
NAME	=	container

# SOURCES ==================================================================================
SRCS = main.cpp 
SRCS_DIR = ./

# COMPILATION ==============================================================================
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

# OBJECTS ==================================================================================
OBJS_DIR = objects/
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

# EXEC =====================================================================================
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo  "♻  Compiling: $<  ♻"
	@sleep 0.3
	@c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@c++ $(FLAGS) -o $(NAME) $(OBJS)
	@echo "♻   Compilation Done   ♻"

all: $(NAME)

clean:
	
	@echo  "♻  Cleaning: $(OBJS_DIR)  ♻"
	@sleep 0.3
	@rm -rf $(OBJS_DIR)
	@rm -rf numbers
	@echo  "♻  Cleaned objects  ♻"

fclean: clean
		
		@echo  "♻  Cleaning: $(NAME)  ♻"
		@sleep 0.3
		@rm -f $(NAME)
		@echo  "♻  Cleaned everything  ♻"

re: fclean all

.PHONY: all clean fclean re