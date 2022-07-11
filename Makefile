##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	WeeWorld
CFLAGS	+=	-g
FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm



SRC	=	engine/sprite.c	\
		engine/sprite_infos.c	\
		engine/textures.c	\
		engine/my_strlen.c	\
		engine/time.c	\
		engine/define_rect.c	\
		engine/init.c	\
		engine/button.c	\
		engine/define_vector.c	\
		engine/button_infos.c	\
		engine/str_comp.c	\
		engine/slide_bar.c	\
		engine/slide_bar_infos.c	\
		engine/text.c	\
		engine/framebuffer.c	\
		engine/drawing.c	\
		engine/define_vertex.c	\
		engine/square.c	\
		engine/text_infos.c	\
		engine/collision.c	\
		sources/main.c	\
		sources/keys.c	\
		sources/utils/ope.c	\
		sources/map/load_map.c	\
		sources/map/map.c	\
		sources/map/init_map_textures.c	\
		sources/map/perlin_noise.c	\
		sources/utils/itoa.c	\
		sources/map/load_chunks.c	\
		sources/player/init_player.c	\
		sources/player/player.c	\
		sources/map/chunk.c	\
		sources/player/player_collision.c	\
		sources/player/character/init_character.c	\
		sources/player/character/left_leg.c	\
		sources/player/character/right_leg.c	\
		sources/player/character/body.c	\
		sources/player/character/left_arm.c	\
		sources/player/character/right_arm.c	\
		sources/player/character/head.c	\
		sources/player/character/display_character.c	\


OBJ	=	$(SRC:.c=.o)


$(NAME):	$(OBJ)
	gcc $(OBJ) $(FLAGS) -o $(NAME)
	
all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
