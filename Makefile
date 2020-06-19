# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:34:43 by emartin-          #+#    #+#              #
#    Updated: 2020/06/19 10:01:44 by hellnhell        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   Cub3D

SRCS    =   src/main.c              \
            src/ray_casting.c       \
            src/readmap.c           \
            src/move.c              \
            src/make_textures.c     \
            src/help.c              \
            src/draw.c              \
            src/ray_casting_bmp.c   \
            src/save_bmp.c          \
            src/readmap2.c          \
            src/check_map.c         \
            src/sprites.c           \

MLX     =   -lmxl -lm -framework OpenGL -framework AppKit

LIBFT   =   libft/libft.a

OBJS    =   $(SRCS:.c=.o)

CFLAGS  = -O3 -Wall -Wextra -Werror -I.


$(NAME):    $(OBJS)
		@$(MAKE) -C libft
        @gcc $(OBJS) -I./includes -I./usr/include ${CFLAGS} ${MLX} ${LIBFT} -o $(NAME) 
			 
all		: $(NAME)


clean   :
		rm -rf $(OBJS)
		@$(MAKE) clean -C libft

fclean  :   clean
        @$(MAKE) clean -C libft 
		rm -rf $(NAME)

re      :   fclean all

.PHONY  :   all clean fclean re




