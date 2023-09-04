# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <htam@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 14:49:25 by cbadura           #+#    #+#              #
#    Updated: 2023/06/22 16:47:59 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a
SRCS 			= ft_atoi.c ft_bzero.c ft_calloc.c \
				ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c\
				ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strcat.c ft_strlcat.c \
				ft_strcpy.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				get_next_line.c \
				ft_printf.c printf_helpers.c hex.c ptr_percent.c str_char_int.c \
				ft_strcmp.c ft_strtok.c ft_strjoin_free_s1.c  ft_strjoin_free_s2.c \
				ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstlast_bonus.c

SRCS_BONUS		= ft_lstadd_front_bonus.c   \
            	ft_lstsize_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS			= ${SRCS:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

INC				= -I ./includes/\

ifdef WITH_BONUS
OBJS_LIST = $(OBJS) $(OBJS_BONUS)
else
OBJS_LIST = $(OBJS)
endif

CFLAGS		= -Wall -Wextra -Werror
CC			= cc
RM			= rm -f

all:	$(NAME)

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

$(NAME): $(OBJS_LIST)
		@ar -rcs $(NAME) $(OBJS_LIST)

bonus:
		make WITH_BONUS=1 all

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus