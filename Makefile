# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 14:05:02 by ndesprez          #+#    #+#              #
#    Updated: 2023/04/04 15:28:35 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= ft_printf.c\
chartypes.c\
inttypes.c

NAME = libftprintf.a

OBJECTS	= ${SOURCES:.c=.o}

.c.o :
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME} : ${OBJECTS}
		ar rc ${NAME} ${OBJECTS}

all : ${NAME}

clean :
		rm -f ${OBJECTS}

fclean : clean
		rm -f ${NAME}

re : fclean all
