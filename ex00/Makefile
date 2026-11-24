#Makefile____________________
NAME		:=	btc
CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98 -MMD -MP

BUILD_DIR	:=	obj/
SRC			:=	main.cpp\
				BitcoinExchange.cpp

OBJ			:=	$(SRC:%.cpp=$(BUILD_DIR)%.o)
DEPS		:=	$(SRC:%.cpp=$(BUILD_DIR)%.d)
OBJ_DIR		:=	$(sort $(dir $(OBJ)))

#Color_______________________

COLOR		:=	\033[1;38;5;12m
NC			:=	\033[0m

#____________________________
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $^  -o $(NAME)
	@echo "Linking Bitcoin Exchange"

$(BUILD_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o: %.cpp | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) $< -c -o $@
	@echo "$(COLOR)[$(CXX)]$(NC) $<"

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
