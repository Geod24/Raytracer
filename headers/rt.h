/*
** rt.h for raytracer in /home/lang_m/code/c/RT/part_parse
**
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
**
** Started on  Sun May  1 00:50:14 2011 Mathias Lang
** Last update Fri Jun  3 22:43:34 2011 xavier schmerber
*/
#ifndef RT_H__
# define RT_H__

#include	"struct.h"
#include	"functions_def.h"
#include	"parser.h"
#include	"calc.h"

# define UNUSED		__attribute__((unused))
# define EPSILON	0.0000000001

/*
** definitions des types d'objets
*/
# define LIGHT		-1
# define VOID		0
# define PLAN		1
# define CYLINDRE	2
# define SPHERE		3
# define CONE		4
# define TORE		5
# define CUBE		6
# define PARABOL	7
# define HYPERBOL	8
# define OBJ_MAX	8
/*
**end
*/
/* check_parse */
# define CH_TYPE	0
# define CH_SIZE	1
# define CH_POWER	2
# define CH_KAMB	3
# define CH_DIFF	4
# define CH_REFLC	5
# define CH_RTORE	6
# define CH_SATUR	7
/*
** end
*/

/*
** definition des flags de lancement
*/
# define IS_OPTION(b_flag)	((glob->option->options / (b_flag)) % 2)
/* flags name*/
# define NO_LIGHT		"-l"
# define NO_DIFF_LIGHT		"-dl"
# define NO_SPEC_LIGHT		"-sl"
# define NO_AMB_LIGHT		"-al"
# define NO_REFLECT		"-r"
# define NO_TRANSP		"-t"
# define NO_STARS		"-s"
# define NO_ANTIALIASING	"-a"
# define NO_MULTI_THREAD	"-m"

# define AV_FLAGS	{NO_LIGHT, NO_DIFF_LIGHT, NO_SPEC_LIGHT, NO_AMB_LIGHT, \
      NO_REFLECT, NO_TRANSP, NO_STARS, NO_ANTIALIASING, NO_MULTI_THREAD, NULL}
/* flags bitmap definition */
# define B_NO_LIGHT		(1 << 0)
# define B_NO_DIFF_LIGHT	(1 << 1)
# define B_NO_SPEC_LIGHT	(1 << 2)
# define B_NO_AMB_LIGHT		(1 << 3)
# define B_NO_REFLECT		(1 << 4)
# define B_NO_TRANSP		(1 << 5)
# define B_NO_STARS		(1 << 6)
# define B_NO_ANTIALIASING	(1 << 7)
# define B_NO_MULTI_THREAD	(1 << 8)
/* usage */
# define USAGE_FLAG		"\nList of the RT flags you can use:\n\n\
-l\tRun RT without lights\n\
-dl\tRun RT without diffuse light\n\
-sl\tRun RT without specular light\n\
-al\tRun RT without ambient light\n\
-r\tRun RT without reflection\n\
-t\tRun RT without transparency\n\
-s\tRun RT without stars in the sky\n\
-a\tRun RT without antialiasing\n\
-m\tRun RT without multi thread\n"
/*
** END
*/
/* http://www.dailymotion.com/video/x2cjw_concert-mr-roux-09-03-06_news */

/* Supposed to be temp */
void	init_universe(t_glob *);
void	init_methodes(t_glob *);

/* http://www.youtube.com/watch?v=U37C8h4YLuk&feature=relmfu */
#endif /* RT_H__ */
