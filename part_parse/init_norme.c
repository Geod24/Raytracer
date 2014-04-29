/*
** init_norme.c for TraceMyRay in /partage/code/c/RT
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Fri Jun  3 20:07:12 2011 Mathias Lang
** Last update Fri Jun  3 22:17:40 2011 Mathias Lang
*/
#include	"rt.h"

static void	init_bal_begin_1(char **bal)
{
  bal[0] = "<RT";
  bal[1] = "<scene";
  bal[2] = "<object";
  bal[3] = "<universe";
  bal[4] = "<pos";
  bal[5] = "<rotation";
  bal[6] = "<type";
  bal[7] = "<radius";
  bal[8] = "<transparence";
  bal[9] = "<reflection";
  bal[10] = "<color";
  bal[11] = "<xsize";
  bal[12] = "<ysize";
  bal[13] = "<camera";
  bal[14] = "<x";
  bal[15] = "<y";
  bal[16] = "<z";
  bal[17] = "<torox";
  bal[18] = "<coeffs";
  bal[19] = "<constants";
  bal[20] = "<graph";
  bal[21] = "<calc_img";
  bal[22] = "<aff_img";
  bal[23] = "<ambiant_light";
  bal[24] = "<brillance";
}

static void	init_bal_begin_2(char **bal)
{
  bal[25] = "<specular_light";
  bal[26] = "<diff_light";
  bal[27] = "<power";
  bal[28] = "<size";
  bal[29] = "<angle";
  bal[30] = "<screen_dist";
  bal[31] = "<cosmic_light";
  bal[32] = "<transp_deep";
  bal[33] = "<reflec_deep";
  bal[34] = "<dam_color";
  bal[35] = "<properties";
}

static void	init_bal_end_1(char **bal)
{
  bal[36] = "</RT";
  bal[37] = "</scene";
  bal[38] = "</object";
  bal[39] = "</universe";
  bal[40] = "</pos";
  bal[41] = "</rotation";
  bal[42] = "</type";
  bal[43] = "</radius";
  bal[44] = "</transparence";
  bal[45] = "</reflection";
  bal[46] = "</color";
  bal[47] = "</xsize";
  bal[48] = "</ysize";
  bal[49] = "</camera";
  bal[50] = "</x";
  bal[51] = "</y";
  bal[52] = "</z";
  bal[53] = "</torox";
  bal[54] = "</coeffs";
  bal[55] = "</constants";
  bal[56] = "</graph";
  bal[57] = "</calc_img";
  bal[58] = "</aff_img";
  bal[59] = "</ambiant_light";
  bal[60] = "</brillance";
}

static void	init_bal_end_2(char **bal)
{
  bal[61] = "</specular_light";
  bal[62] = "</diff_light";
  bal[63] = "</power";
  bal[64] = "</size";
  bal[65] = "</angle";
  bal[66] = "</screen_dist";
  bal[67] = "</cosmic_light";
  bal[68] = "</transp_deep";
  bal[69] = "</reflec_deep";
  bal[70] = "</dam_color";
  bal[71] = "</properties";
}

char	**init_balises()
{
  char	**bal;

  bal = cx_malloc((BAL_NBR + 1) * sizeof(char *));
  init_bal_begin_1(bal);
  init_bal_begin_2(bal);
  init_bal_end_1(bal);
  init_bal_end_2(bal);
  return (bal);
}
