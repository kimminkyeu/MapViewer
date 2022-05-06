# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 21:06:42 by minkyeki          #+#    #+#              #
#    Updated: 2022/05/06 21:11:22 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C ./source
	cp ./source/fdf .

clean:
	make fclean -C ./source


fclean: clean
	rm -f ./fdf


re: fclean all

.PHONY: all clean fclean re
