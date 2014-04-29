/*
** get_tag_values.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:28:30 2011 Mathias Lang
** Last update Thu May 26 21:33:46 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<string.h>
#include	"rt.h"

int	get_bal_val(char *file, int *count)
{
  int	check_val;
  int	ret;

  check_val = 0;
  ret = atoi(file + count[0]);
  while (file[count[0]] && file[count[0] + 1]			\
	 && file[count[0]] != '<' && file[count[0] + 1] != '/')
    {
      if (file[count[0]] != ' ')
	check_val = 1;
      count[0]++;
    }
  if (file[count[0]] != '<' || !check_val || !file[count[0] + 1]	\
      || file[count[0] + 1] != '/')
    VAL_FLAG = 1;
  return (ret);
}

double		get_bal_val_double(char *file, int *count)
{
  int		check_val;
  double	ret;

  check_val = 0;
  ret = atof(file + count[0]);
  while (file[count[0]] && file[count[0] + 1]			\
	 && file[count[0]] != '<' && file[count[0] + 1] != '/')
    {
      if (file[count[0]] != ' ')
	check_val = 1;
      count[0]++;
    }
  if (file[count[0]] != '<' || !check_val || !file[count[0] + 1]	\
      || file[count[0] + 1] != '/')
    VAL_FLAG = 1;
  return (ret);
}

unsigned int	get_color(char *file, int *count, int base)
{
  int		check_val;
  unsigned int	ret;

  check_val = 0;
  ret = (unsigned int)strtol(file + count[0], NULL, base);
  while (file[count[0]] && file[count[0] + 1]			\
	 && file[count[0]] != '<' && file[count[0] + 1] != '/')
    {
      if (file[count[0]] != ' ')
	check_val = 1;
      count[0]++;
    }
  if (file[count[0]] != '<' || !check_val || !file[count[0] + 1]	\
      || file[count[0] + 1] != '/')
    VAL_FLAG = 1;
  return (ret);
}

char	*get_attr_value(char *str)
{
  int	i;

  i = 1;
  while (*str && *str != '"')
    str++;
  while (*str && str[i] && str[i] != '"')
    i++;
  if (*str)
    return (strndup(str, i + 1));
  return (NULL);
}
