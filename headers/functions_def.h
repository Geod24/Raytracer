/*
** functions_def.h for RT in /partage/code/c/RT/working_dir/part_parse
** 
** Made by mathias lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon Apr  4 16:26:58 2011 mathias lang
** Last update Sat Jun  4 00:49:31 2011 Mathias Lang
*/

#ifndef FUNCTIONS_DEF_H__
# define FUNCTIONS_DEF_H__

void	*my_realloc(char *, int);
t_error	*put_in_list(t_error *);
void	check_reflc(t_error *, t_obj *);
void	check_rtore(t_error *, t_obj *);
void	check_type(t_error *, t_obj *);
void	check_size(t_error *, t_obj *);
void	check_power(t_error *, t_obj *);
void	check_kamb(t_error *, t_obj *);
void	check_diff(t_error *, t_obj *);
void	check_satur(t_error *, t_obj *);
void	*cx_malloc(int);
void	intersections(t_glob *, t_calc *);
void    rotate_3d(t_coord *, t_coord *, int);
char    *my_putnbr_in_str(int);
void	tracemyray(t_glob *);
double	calc_delta(t_coord *, double);
double	inter_sphere(t_obj *, t_calc *);
double	inter_cylindre(t_obj *, t_calc *);
double	inter_cone(t_obj *, t_calc *);
double	inter_tore(t_obj *, t_calc *);
double	inter_plan(t_obj *, t_calc *);
double	inter_cube_troue(t_obj *, t_calc *);
double	inter_parabol(t_obj *, t_calc *);
double	inter_hyperbol(t_obj *, t_calc *);
double	inter_cercle(t_obj *, t_calc *);
double	check_limit(t_obj *, double, t_coord *, t_coord *);
void	solve_cubic(t_poly *);
void	solve_quad(t_poly *);
double	search_mino(t_poly *);
double	search_min(t_poly *);
void	resolve_last(t_poly *, double, t_coord *);
void    parse_conf(char *, t_glob *);
void	put_error(char *, int);
void	init_view(t_coord *, t_coord *, t_obj *, t_calc *);
double  scalaire(t_coord *, t_coord *);
void	resize_img(t_img *, t_img *);
void	calc_reflection(t_glob *, t_calc *);
void	calc_transparency(t_glob *, t_calc *);
int	my_putstr(char *);
int	xread(int, char *, int);
int	my_strlen(const char *);
int	my_putchar(char);
void	xexit(char *);
void	xclose(int);
int	xwrite(int, char *);
void	my_free(void *, ...);
void	calc_pixel(t_glob *, t_calc *);
int	make_pixel(t_calc *, t_calc *, t_calc *, t_calc *);
void	my_pixel_put_to_image(int, int, t_glob *, int);
void	calc_color(t_calc *);
void	normale_plan(t_calc *);
void	normale_cone(t_calc *);
void	normale_sphere(t_calc *);
void	normale_tore(t_calc *);
void	normale_hyperbol(t_calc *);
void	normale_parabol(t_calc *);
void	normale_cylindre(t_calc *);
void	normale_cube_troue(t_calc *);
void	calc_light(t_glob *, t_calc *);
void	calc_reflect_vect(t_calc *, t_coord *);
void	fill_bmp(t_img *);
void	free_glob(t_glob *);
int	make_damier(t_calc *, int, int, int);
void	calc_pixel_color(t_calc *);
int	background_color(t_glob *);
void	resize_window(t_glob *, int);
void	get_args(t_glob *, int, char **);
int	key_hook(int, t_glob *);
int	expose(t_glob *);
void	check_parse(t_glob *);
int	with_antialiasing(t_glob *, int, int);
int	without_antialiasing(t_glob *, int, int);
void	advance_indice(t_glob *, int);
void	calc_quad(t_coord *, t_poly *, t_poly *);
void	perturb_normal(t_coord *, t_coord *);

/* WTF ? */
char	*strdup(const char *);
char	*strndup(const char *, int);

#endif /* !FUNCTIONS_DEF_H__ */
