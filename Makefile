# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:32:35 by akostrik          #+#    #+#              #
#    Updated: 2022/11/25 16:53:53 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	clear
	(cd ./workspace && make)
	gcc main.c -L./workspace/ -lftprintf -L./workspace -lft -lbsd
	./a.out
