/*
** check_parse.c for rt in /home/oliver_f//Teck/Igraph/RT/raytracer/SVN/TraceMyRay
**
** Made by florian oliver
** Login   <oliver_f@epitech.net>
**
** Started on  Thu Jun  2 16:14:01 2011 florian oliver
** Last update Fri Jun  3 19:24:06 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	"rt.h"

static const t_ptr_err	tab[] =
  {
    {CH_TYPE, &check_type},
    {CH_SIZE, &check_size},
    {CH_POWER, &check_power},
    {CH_KAMB, &check_kamb},
    {CH_DIFF, &check_diff},
    {CH_REFLC, &check_reflc},
    {CH_RTORE, &check_rtore},
    {CH_SATUR, &check_satur},
  };

static void	free_error(t_error *error)
{
  t_error	*save;
  int		i;

  save = error;
  while (error)
    {
      i = -1;
      while (error->errors[++i])
	free(error->errors[i]);
      free(error->errors);
      save = error->next;
      free(error);
      error = save;
    }
}

static void	my_aff_error(t_error *error, t_glob *glob)
{
  t_error	*tmp;
  int		texit = 0, i;
  int		nb = -1;

  tmp = error;
  while (tmp)
    {
      i = -1;
      nb++;
      if (tmp->fatal == 1)
	texit = 1;
      if (tmp->errors[i + 1]){
	fprintf(stderr, "In object: %d, Warnings & errors: number %d\n\n",
		(int)tmp->type, nb);
      }
      while (tmp->errors[++i])
	fprintf(stderr, "\t%s : %f\n", tmp->errors[i], tmp->type_errors[i]);
      tmp = tmp->next;
    }
  free_error(error);
  if (texit == 1)
    {
      free_glob(glob);
      exit(EXIT_FAILURE);
    }
}

static t_error	*built_list(t_obj *obj)
{
  t_obj		*save;
  t_obj		*tmp;
  t_error	*error;
  char		dowhile;

  tmp = obj;
  save = tmp;
  error = NULL;
  dowhile = 0;
  while (tmp != save || dowhile == 0)
    {
      error = put_in_list(error);
      dowhile = 1;
      tmp = tmp->next;
    }
  while (error && error->prev)
    error = error->prev;
  return (error);
}

static void	check_obj(t_error *error, t_obj *obj)
{
  int		i;

  error->nb = -1;
  error->fatal = 0;
  error->errors = cx_malloc(sizeof(char *) * MAX_ERRORS);
  error->type = obj->type;
  i = 0;
  while (i < MAX_PTR)
    {
      if (obj->type != TORE && i == CH_RTORE);
      else
	tab[i].f(error, obj);
      i++;
    }
}

void		check_parse(t_glob *glob)
{
  t_obj		*tmp;
  t_obj		*save;
  char		dowhile;
  t_error	*error;
  t_error	*tmper;

  tmp = glob->obj;
  save = tmp;
  dowhile = 0;
  error = built_list(save);
  tmper = error;
  while (tmp != save || dowhile == 0)
    {
      check_obj(tmper, tmp);
      dowhile = 1;
      tmper = tmper->next;
      tmp = tmp->next;
    }
  if (error)
    my_aff_error(error, glob);
}
