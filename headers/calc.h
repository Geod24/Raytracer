/*
** calc.h for rt in /home/schmer_x//igraph/rt
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Thu May 12 13:53:25 2011 xavier schmerber
** Last update Fri Jun  3 22:27:48 2011 xavier schmerber
*/

#ifndef __CALC_H__
# define __CALC_H__

# define PERTURB_NORMAL_COEFF	(70.0)

/*
** math utils
*/
# define ABS(x)			(((x) >= 0)?(x):(-(x)))
# define SQ(x)			((x) * (x))
# define NORME(v)		(double)(sqrt(SQ((v).x) + SQ((v).y) + SQ((v).z)))
# define PI			3.14159265358979323846264338329
# define RAD(x)			(x) / 180.0 * PI
/*
** end
*/

# define POS(x)			(((x) >= 0)?(x):(0))
# define MAJ1(x)		(((x) > 1)?(1):(x))

# define GET_R(x)		(double)((x) % 0x100) / (double)0x100
# define GET_G(x)		(double)(((x) >> 8) % 0x100) / (double)0x100
# define GET_B(x)		(double)(((x) >> 16) % 0x100) / (double)0x100

/*
** calc_light defines
*/
# define LIGHT_POW		light->typdef.power
# define LIGHT_COLOR		light->stddef.color
# define OBJ_COLOR		calc->obj->stddef.color
# define OBJ_POWER		calc->obj->typdef.power
# define OBJ_DAM_COLOR		calc->obj->typdef.dam_color

# define COEFF_DIF		calc->obj->typdef.coeff.k_dif
# define COEFF_SPE		calc->obj->typdef.coeff.k_spe
# define COEFF_AMB		calc->obj->typdef.coeff.k_amb
# define COEFF_BRILL		calc->obj->typdef.coeff.brill
# define COEFF_REFLC		calc->obj->typdef.coeff.reflc
# define COEFF_TRANS		calc->obj->typdef.coeff.trans

# define COSMIC_LIGHT		glob->universe->cosmic_light

# define SCALAIRE_L_N		(double)scalaire(light_vect, &(calc->normale))
# define SCALAIRE_R_L		(double)scalaire(&(calc->reflect), light_vect)

# define DIST_COEFF		((log1p(NORME(*light_vect) / 100.0) / 2) + 1)
# define DIFF_LIGHT		(COEFF_DIF * teta_diff / DIST_COEFF)
# define SPEC_LIGHT		(COEFF_SPE * pow(teta_spec, COEFF_BRILL))

/*
** end calc_light
** http://www.youtube.com/watch?v=b_KdJPs7EPY
*/

#endif /* !__CALC_H__ */
