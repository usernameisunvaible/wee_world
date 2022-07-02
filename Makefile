##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	myWorld_two
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
		sources/main.c	\
		sources/keys.c	\
		sources/ope.c	\
		sources/load_map.c	\
		sources/map.c	\
		sources/init_map_textures.c	\
		sources/perlin_noise.c	\
		sources/itoa.c	\
		sources/load_chunks.c	\


OBJ	=	$(SRC:.c=.o)


$(NAME):	$(OBJ)
	gcc $(OBJ) $(FLAGS) -o $(NAME)
	
all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
