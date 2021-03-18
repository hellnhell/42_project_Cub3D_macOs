# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:34:43 by emartin-          #+#    #+#              #
#    Updated: 2020/07/07 18:54:20 by emartin-         ###   ########.fr        #
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


LIBFT   =   libft/libft.a

OBJS    =   $(SRCS:.c=.o)

CFLAGS  = -O3 -Wall -Wextra -Werror -I.

MLX    = -lmlx -lm -framework OpenGL -framework AppKit


$(NAME):	$(OBJS)
		@$(MAKE) -C libft
		@gcc $(OBJS) -I./includes -I./usr/include ${CFLAGS} ${LIBFT} ${MLX} -o $(NAME)
			
			
all		: $(NAME)


clean   :
		rm -rf $(OBJS)
		@$(MAKE) -C libft clean

fclean  :   clean
		rm -rf $(NAME) $(LIBFT)

re      :   fclean all

.PHONY  :   all clean fclean re