# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:52:45 by lolaparr          #+#    #+#              #
#    Updated: 2024/03/25 18:28:01 by lolaparr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\033[0;32m

NAME = Animal

CC = c++

SRC =	main.cpp \
		AAnimal.cpp \
		Brain.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp


OBJ = ${SRC:.cpp=.o}
DEPS = ${SRC:.cpp=.d}

INC = ./includes

CPPFLAGS = -Wall -Wextra -Werror -g3 -MMD -std=c++98

.cpp.o:
	${CC} ${CPPFLAGS} -I${INC} -c $< -o ${<:.cpp=.o}

all:	${NAME}

${NAME}:	${OBJ}

	@${CC} ${CPPFLAGS} -I${INC} ${OBJ} -o ${NAME}
	@echo "${Green}- ${NAME} is ready."

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME} ${DEPS}

aclean: all clean

re: fclean all

-include : ${DEPS}

.PHONY: all clean fclean re bonus aclean
.SILENT:
