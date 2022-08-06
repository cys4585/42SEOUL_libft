# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 17:37:39 by youngcho          #+#    #+#              #
#    Updated: 2022/08/06 16:55:22 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = rcs
BON_ARFLAGS = $(ARFLAGS)u
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/
INCS_DIR = ./incs/

INCS_FLAGS	= -I $(INCS_DIR)

SRCS_NAME = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c

BON_SRCS_NAME = ft_lstnew.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstadd_back.c \
		   ft_lstdelone.c \
		   ft_lstclear.c \
		   ft_lstiter.c \
		   ft_lstmap.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_NAME:.c=.o))
BON_OBJS = $(addprefix $(OBJS_DIR), $(BON_SRCS_NAME:.c=.o))


.PHONY : all clean fclean re bonus
all : $(NAME)
clean :
	rm -rf $(OBJS_DIR)
fclean : clean
	rm -f $(NAME)
re : fclean 
	make all
bonus : all $(BON_OBJS)
	$(AR) $(BON_ARFLAGS) $(NAME) $(BON_OBJS)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS_FLAGS) -c $< -o $@

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)