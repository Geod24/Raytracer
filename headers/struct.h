/*
** struct.h for rt in /home/schmer_x//igraph/rt/headers
**
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
**
** Started on  Sat Apr  2 13:31:18 2011 xavier schmerber
** Last update Fri Jun  3 20:02:21 2011 Mathias Lang
*/

#ifndef __STRUCT_H__
# define __STRUCT_H__

# define VIEW_X	tmp_view.x
# define VIEW_Y	tmp_view.y
# define VIEW_Z	tmp_view.z
# define EYE_X	tmp_eye.x
# define EYE_Y	tmp_eye.y
# define EYE_Z	tmp_eye.z
/*
** compile me :o
*/
# define MAX_PTR	7
# define MAX_ERRORS	15
# define MAX_TYPE_ERROR	10

typedef struct		s_error
{
  int			type;
  int			fatal;
  int			nb;
  char			**errors;
  double		type_errors[10];
  struct s_error	*prev;
  struct s_error	*next;
}			t_error;

/*
** graph part
*/
typedef struct		s_img
{
  void			*img;
  char			*data;
  int			bpp;
  int			sizeline;
  int			sizex;
  int			sizey;
}			t_img;

typedef struct		s_graph
{
  void			*mlx_ptr;
  void			*win_ptr;
  int			endian;
  t_img			calc_img;
  t_img			aff_img;
  t_img			loader;
  t_img			bmp_ask;
}			t_graph;

/*
** options part
*/
typedef struct		s_option
{
  int			options;
  char			*author;
  char			*desc;
  float			vers;
  char			export[2048];
}			t_option;

/*
** objects part
*/
typedef struct		s_poly
{
  double		tmp;
  double		tmpa;
  double		tmpb;
  double		tmpc;
  double		tmpd;
  double		tmpe;
  double		a;
  double		b;
  double		c;
  double		d;
  double		e;
  double		f;
  double		*res;
  double		*res_done;
}			t_poly;

typedef struct		s_coord
{
  double		x;
  double		y;
  double		z;
}			t_coord;

typedef struct		s_stddef
{
  t_coord               pos;
  unsigned int          color;
}			t_stddef;

typedef struct		s_coeff
{
  double		k_amb;
  double		k_dif;
  double		k_spe;
  int                   brill;
  double		trans;
  double		reflc;
}			t_coeff;

typedef struct		s_typdef
{
  t_coord               rot;
  t_coeff		coeff;
  double       		power;
  int			dam_color;
  int			properties;
  int			size;
  int			rayon_tore;
  int			angle;
  int			size_x;
  int			size_y;
}			t_typdef;

struct	s_methode;

typedef struct          s_obj
{
  int			type;
  t_stddef		stddef;
  t_typdef		typdef;
  struct s_methode	*methode;
  struct s_obj          *next;
  struct s_obj		*prev;
}                       t_obj;

/*
** universe part
*/
typedef struct		s_uni
{
  t_coord		eye;
  t_coord		view_rot;
  int			screen_dist;
  int			cosmic_light;
  int			reflec_deep;
  int			transp_deep;
}			t_uni;

/*
**calcul part
*/
typedef struct		s_calc
{
  double	       	dist;
  t_obj			*obj;
  t_coord		inter;
  t_coord		eye;
  t_coord		view;
  t_coord		normale;
  t_coord		reflect;
  int			reflect_deep;
  int			transp_deep;
  int			r;
  int			g;
  int			b;
  t_coord		light_dif;
  t_coord		light_spe;
}			t_calc;

/*
**thread part
*/
typedef struct		s_thread
{
  int			thread;
  void			*glob;
}			t_thread;

/*
**global part
*/
typedef struct		s_glob
{
  t_graph		*graph;
  t_obj			*obj;
  t_uni			*universe;
  t_option		*option;
}			t_glob;

typedef struct		s_methode
{
  double		(*find_dist)(t_obj *, t_calc *);
  void			(*calc_normale)(t_calc *);
  void			(*calc_color)(t_calc *);
  void			(*calc_light)(t_glob *, t_calc *);
  void			(*calc_reflec)(t_glob *, t_calc *);
  void			(*calc_transp)(t_glob *, t_calc *);
}			t_methode;

typedef struct		s_ptr_err
{
  int			err;
  void			(*f)(t_error *, t_obj *);
}			t_ptr_err;

#endif /* !__STRUCT_H__ */
