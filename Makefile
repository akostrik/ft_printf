# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:32:35 by akostrik          #+#    #+#              #
#    Updated: 2022/11/29 17:38:41 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	clear
	(cd ./workspace && make)
	cc main.c -L./workspace/ -lftprintf -L./workspace/libft -lft -lbsd
	./a.out
