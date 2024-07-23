# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelma <m.abdelmaged@student.42abudha    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 08:57:48 by mabdelma          #+#    #+#              #
#    Updated: 2022/10/19 09:08:26 by mabdelma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 				ft_itoa.c functions.c functions2.c

OBJS = ${SRCS:.c=.o}

INCLUDES = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re