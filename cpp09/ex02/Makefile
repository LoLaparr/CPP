# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:52:45 by lolaparr          #+#    #+#              #
#    Updated: 2024/09/25 10:39:00 by lolaparr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Green=\033[0;32m

NAME = PmergeMe

CC = c++

SRC =	main.cpp \
		PmergeMe.cpp

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
