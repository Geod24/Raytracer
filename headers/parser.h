/*
** parser.h for TraceMyRay in /home/lang_m/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 23 15:31:31 2011 Mathias Lang
** Last update Fri Jun  3 22:33:01 2011 Mathias Lang
*/
#ifndef PARSER_H__
# define PARSER_H__

/* Si toi aussi tu kiffe le parsing, tape dans tes mains ! */
# define READ_VAL	1024
# define S_LIMIT	10000
# define XML_BEGINING	"<?xml version"
# define BLEN		strlen(balises[count[1]])

/* Soucis de lisibilite... */
# define BAL_RT			0
# define BAL_SCENE		1
# define BAL_OBJECT		2
# define BAL_UNIVERSE		3
# define BAL_POS		4
# define BAL_ROTATION		5
# define BAL_TYPE		6
# define BAL_RADIUS		7
# define BAL_TRANSP		8
# define BAL_REFLEC		9
# define BAL_COLOR		10
# define BAL_XSIZE		11
# define BAL_YSIZE		12
# define BAL_CAMERA		13
# define BAL_X			14
# define BAL_Y			15
# define BAL_Z			16
# define BAL_RTORE		17
# define BAL_COEFFS		18
# define BAL_CONSTANTS		19
# define BAL_GRAPH		20
# define BAL_CALC_IMG		21
# define BAL_AFF_IMG		22
# define BAL_AMBIANT_LIGHT	23
# define BAL_BRILLANCE		24
# define BAL_SPECULAR_LIGHT	25
# define BAL_DIFF_LIGHT		26
# define BAL_POWER		27
# define BAL_SIZE		28
# define BAL_ANGLE		29
# define BAL_SCREEN_DIST	30
# define BAL_COSMIC_LIGHT	31
# define BAL_TRANSP_DEEP	32
# define BAL_REFLEC_DEEP	33
# define BAL_DAM_COLOR		34
# define BAL_PROPERTIES		35
# define B_END(x)		((x) + 36)
# define BAL_NBR		72

# define META_FLAG	count[3]
# define RT_FLAG	(META_FLAG & IN_F_RT)
# define SCENE_FLAG	(META_FLAG & IN_F_SCENE)
# define UNIVERSE_FLAG	(META_FLAG & IN_F_UNI)
# define OBJECT_FLAG	(META_FLAG & IN_F_OBJ)
# define ROTATION_FLAG	(META_FLAG & IN_F_ROTATION)
# define POS_FLAG	(META_FLAG & IN_F_POS)
# define COEFFS_FLAG	(META_FLAG & IN_F_COEFFS)
# define CAMERA_FLAG	(META_FLAG & IN_F_CAMERA)
# define CONST_FLAG	(META_FLAG & IN_F_CONST)
# define GRAPH_FLAG	(META_FLAG & IN_F_GRAPH)
# define CALC_IMG_FLAG	(META_FLAG & IN_F_CALC_IMG)
# define AFF_IMG_FLAG	(META_FLAG & IN_F_AFF_IMG)

# define ID_FLAG	count[4]
# define VAL_FLAG	count[5]

# define IN_F_RT	(1 << 0)
# define F_RT_END	(1 << 1)
# define IN_F_SCENE	(1 << 2)
# define IN_F_UNI	(1 << 3)
# define IN_F_OBJ	(1 << 4)
# define IN_F_ROTATION	(1 << 5)
# define IN_F_POS	(1 << 6)
# define IN_F_COEFFS	(1 << 7)
# define IN_F_CAMERA	(1 << 8)
# define IN_F_CONST	(1 << 9)
# define IN_F_GRAPH	(1 << 10)
# define IN_F_CALC_IMG	(1 << 11)
# define IN_F_AFF_IMG	(1 << 12)

# define IS(xyz)	calc->obj->typdef.properties & (1 << (xyz))
# define P_DAMIER	(0)
# define P_NORMAL	(1)
/* !gros pave */

# define OBJ_SEGV	(!UNIVERSE_FLAG && glob->obj == NULL)

  /* ****************** Error messages ****************** */
# define COMMENT_ERR	"Error: Ending tag for comment not fund.\n"
# define FILE_OVERSIZE	"Erreur. Le fichier fait plus de 100Mos, \
c'est bien trop pour moi!\n"
# define NO_XML_VERSION "Error: File must begin with the xml \
version number\n"
# define WARN_VERSION	"Warning: Supported xml version is 1.0. Your's \
is %s. That can lead to parse error and random scene rendering.\n"
# define WARN_ATTR	"Warning: Attributes not allowed for tag \"%s>\". \
Skipping.\n"
# define GLOB_FAIL	"Fatal error: Memory not allocated.\n"
# define OUT_RT		"Error: Invalid use of <rt> tag.\n"
# define OUT_SCENE	"Error: %s tag outside a <scene> tag.\n"
# define OUT_OBJ	"Error: %s tag outside an <object> tag.\n"
# define OUT_UNI	"Error: %s tag outside an <universe> tag.\n"
# define OUT_GRAPH	"Error: %s tag outside an <graph> tag.\n"
# define ID_EXPECTED	"Error: Unexpected tag.\n"
# define SCN_IN_UNI	"Error: Scene description inside an universe \
description.\n"
# define SCN_IN_SCN	"Error: Scene description inside a scene \
description.\n"
# define SCN_OUT_RT	"Error: Scene description must be in a \
\"<RT>\" tag.\n"
# define UNI_XOR_SCENE	"Error: %s tag must be in an <universe> or in a \
<scene> tag.\n"
# define NO_VALUE	"Error: No value in %s tag, or tag not terminated.\n"
/* ****************** !Error messages ****************** */
# define ERR_IN_OBJ	(!RT_FLAG) ? (OUT_RT) : ((!SCENE_FLAG)		\
						 ? (OUT_SCENE) : ((OUT_OBJ)))
# define PCHAR(stri)	((stri) == ' ' || stri == '\t' || stri == '\n')
# define NO_NXT(ths)	(ths && ths != ' ' && ths != '=')
# define IS_NBR(str)	(str >= '0' && str <= '9')

typedef int (*func_handler)(t_glob *, char *, int *);

char		**init_balises();
func_handler	*init_fptr();
char		*clean_str(char *);
void		free_and_quit(t_glob *, char *, int *);
int		check_xml_begining(char *, int *, t_glob *);
void		invalid_tag(int *, char *, t_glob *);
void		gere_args(t_glob *, int *, char *);
int		handle_scene(t_glob *, char *, int *);
int		handle_rt(t_glob *, char *, int *);
int		handle_object(t_glob *, char *, int *);
int		handle_type(t_glob *, char *, int *);
int		handle_universe(t_glob *, char *, int *);
int		handle_radius(t_glob *, char *, int *);
int		handle_end(t_glob *, char *, int *);
int		handle_pos(t_glob *, char *, int *);
int		handle_transparence(t_glob *, char *, int *);
int		handle_reflection(t_glob *, char *, int *);
int		handle_color(t_glob *, char *, int *);
int		handle_rotation(t_glob *, char *, int *);
int		handle_xsize(t_glob *, char *, int *);
int		handle_ysize(t_glob *, char *, int *);
int		handle_x(t_glob *, char *, int *);
int		handle_y(t_glob *, char *, int *);
int		handle_z(t_glob *, char *, int *);
int		handle_coeff(t_glob *, char *, int *);
int		handle_const(t_glob *, char *, int *);
int		handle_graph(t_glob *, char *, int *);
int		handle_calc_img(t_glob *, char *, int *);
int		handle_aff_img(t_glob *, char *, int *);
int		handle_ambiant_light(t_glob *, char *, int *);
int		handle_diff_light(t_glob *, char *, int *);
int		handle_specular_light(t_glob *, char *, int *);
int		handle_brillance(t_glob *, char *, int *);
int		handle_angle(t_glob *, char *, int *);
int		handle_power(t_glob *, char *, int *);
int		handle_size(t_glob *, char *, int *);
int		handle_camera(t_glob *, char *, int *);
int		handle_transp_deep(t_glob *, char *, int *);
int		handle_reflec_deep(t_glob *, char *, int *);
int		handle_screen_dist(t_glob *, char *, int *);
int		handle_cosmic_light(t_glob *, char *, int *);
int		handle_dam_color(t_glob *, char *, int *);
int		handle_prop(t_glob *, char *, int *);
int		handle_rtore(t_glob *, char *, int *);
int		get_bal_val(char *, int *);
double		get_bal_val_double(char *, int *);
unsigned int	get_color(char *, int *, int);
char		*get_attr_value(char *);

#endif /* !PARSER_H__ */
