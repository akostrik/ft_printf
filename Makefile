# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:32:35 by akostrik          #+#    #+#              #
#    Updated: 2022/11/29 13:22:40 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	clear
	(cd ./workspace && make)
	gcc main.c -L./workspace/ -lftprintf -L../01_libft/workspace -lft -lbsd
	./a.out
