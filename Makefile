##
## Makefile for wolf3d in /home/schmer_x//igraph/wolf3d/test
## 
## Made by xavier schmerber
## Login   <schmer_x@epitech.net>
## 
## Started on  Sat Jan  8 23:48:40 2011 xavier schmerber
## Last update Sun Jun  5 01:14:59 2011 xavier schmerber
##

NAME=	rt

SRC=	basics/my_getnbr_base.c		\
	basics/my_pixel_put_to_image.c	\
	basics/my_put_nbr.c		\
	basics/my_strlen.c		\
	basics/my_strcmp.c		\
	basics/my_putchar.c		\
	basics/xfunctions.c		\
	\
	error_and_free/cx_malloc.c	\
	error_and_free/put_error.c	\
	error_and_free/x_foncs.c	\
	error_and_free/my_free.c	\
	\
	part_calc/calc_color.c		\
	part_calc/calc_light.c		\
	part_calc/calc_reflect_vect.c	\
	part_calc/scalaire.c		\
	part_calc/normale.c		\
	part_calc/normale2.c		\
	part_calc/rotate_3d.c		\
	part_calc/calc_reflection_transparence.c	\
	part_calc/calc_pixel_color.c	\
	part_calc/perturb_normale.c	\
	part_calc/background_color.c	\
	\
	part_struct/rt.c		\
	part_struct/make_damier.c	\
	part_struct/check_value.c	\
	part_struct/check_values.c	\
	part_struct/check_parse.c	\
	part_struct/put_in_list.c	\
	part_struct/tracemyray.c	\
	part_struct/intersections.c	\
	part_struct/inter_cylindre.c	\
	part_struct/inter_sphere.c	\
	part_struct/inter_cone.c	\
	part_struct/inter_plan.c	\
	part_struct/inter_tore.c	\
	part_struct/inter_parabol.c	\
	part_struct/inter_hyperbol.c	\
	part_struct/inter_cube_troue.c	\
	part_struct/calc_delta.c	\
	part_struct/solve_quad.c	\
	part_struct/init_view.c		\
	part_struct/my_putnbr_in_str.c	\
	part_struct/check_limit.c	\
	part_struct/calc_pixel.c	\
	part_struct/make_pixel.c	\
	part_struct/get_args.c		\
	part_struct/get_pixel.c		\
	part_struct/aff_loading.c	\
	part_struct/calc_quad.c		\
	\
	part_parse/parse_conf.c			\
	part_parse/init_norme.c			\
	part_parse/init_fptr.c			\
	part_parse/exit_functions.c		\
	part_parse/handler/handle_meta.c	\
	part_parse/error_handling.c		\
	part_parse/my_realloc.c			\
	part_parse/str_utils.c			\
	part_parse/get_tag_values.c		\
	part_parse/handler/handle_cmodif.c	\
	part_parse/handler/handle_coords.c	\
	part_parse/handler/handle_color.c	\
	part_parse/handler/handle_end.c		\
	part_parse/handler/handle_values.c	\
	part_parse/handler/handle_values2.c	\
	part_parse/handler/handle_universe.c	\
	part_parse/object_handler.c		\
	part_parse/handler/handle_coeffs.c	\
	part_parse/handler/handle_clights.c	\
	part_parse/handler/handle_consts.c	\
	\
	part_graph/resize_img.c			\
	part_graph/resize_key.c			\
	part_graph/fill_bmp.c			\
	part_graph/events.c			\
	\
	init_methodes.c

OBJ=	$(SRC:.c=.o)
COMP=	-Lminilibx -lmlx -lXext -lX11 -lm -pthread
DEBUG=	-Wunused-but-set-parameter -Wunused-but-set-variable -g
CFLAGS=	-W -Wall -Wextra -ansi -pedantic -I headers/ -D_BSD_SOURCE -Iminilibx

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(COMP)

all:	$(NAME)

clean:
	rm -f $(OBJ)
	rm -f */*~
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

save:
	rm -Rf old/save/*
	cp -Rf * old/save/
