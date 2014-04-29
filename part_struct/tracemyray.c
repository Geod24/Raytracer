/*
** tracemyray.c for RT in /home/fische_s//dossier/projets/SVN/TraceMyRay
**
** Made by sylvain fischer
** Login   <fische_s@epitech.net>
**
** Started on  Thu Apr 28 19:07:08 2011 sylvain fischer
** Last update Sat Jun  4 00:53:16 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<pthread.h>
#include	<mlx.h>
#include	<errno.h>
#include	<string.h>
#include	"rt.h"

#define AFF_SIZEX	glob->graph->aff_img.sizex
#define AFF_SIZEY	glob->graph->aff_img.sizey
#define CALC_SIZEX	glob->graph->calc_img.sizex
#define CALC_SIZEY	glob->graph->calc_img.sizey

void		*line_executer(void *param)
{
  t_thread	*thread;
  t_glob	*glob;
  int		x;
  int		y;

  thread = param;
  glob = thread->glob;
  y = 0;
  while (y < CALC_SIZEY)
    {
      x = 0;
      if (thread->thread == 1)
	advance_indice(glob, y);
      while ((y % thread->thread == 0) && x < CALC_SIZEX)
	{
	  if (!(IS_OPTION(B_NO_ANTIALIASING)))
	    my_pixel_put_to_image(x, y, glob, with_antialiasing(glob, x, y));
	  else
	    my_pixel_put_to_image(x, y, glob, without_antialiasing(glob, x, y));
	  x++;
	}
      y++;
    }
  return (NULL);
}

void	unthreaded_executer(t_glob *glob)
{
  int	x;
  int  	y;

  y = 0;
  while (y < CALC_SIZEY)
    {
      x = 0;
      advance_indice(glob, y);
      while (x < CALC_SIZEX)
	{
	  if (!(IS_OPTION(B_NO_ANTIALIASING)))
	    my_pixel_put_to_image(x, y, glob, with_antialiasing(glob, x, y));
	  else
	    my_pixel_put_to_image(x, y, glob, without_antialiasing(glob, x, y));
	  x++;
	}
      y++;
    }
}

static void	exec_thread(t_thread *thread1, t_thread *thread2,
			    t_thread *thread3, t_thread *thread4)
{
  pthread_t	thr[4];

  if (-1 == pthread_create(&thr[0], NULL, &line_executer, thread1))
    put_error(strerror(errno), 1);
  if (-1 == pthread_create(&thr[1], NULL, &line_executer, thread2))
    put_error(strerror(errno), 1);
  if (-1 == pthread_create(&thr[2], NULL, &line_executer, thread3))
    put_error(strerror(errno), 1);
  if (-1 == pthread_create(&thr[3], NULL, &line_executer, thread4))
    put_error(strerror(errno), 1);
  if (-1 == pthread_join(thr[0], NULL))
    put_error(strerror(errno), 1);
  if (-1 == pthread_join(thr[1], NULL))
    put_error(strerror(errno), 1);
  if (-1 == pthread_join(thr[2], NULL))
    put_error(strerror(errno), 1);
  if (-1 == pthread_join(thr[3], NULL))
    put_error(strerror(errno), 1);
}

void		tracemyray(t_glob *glob)
{
  t_thread	thread1;
  t_thread	thread2;
  t_thread	thread3;
  t_thread	thread4;

  if (!(IS_OPTION(B_NO_MULTI_THREAD)))
    {
      thread1.thread = 1;
      thread1.glob = glob;
      thread2.thread = 2;
      thread2.glob = glob;
      thread3.thread = 3;
      thread3.glob = glob;
      thread4.thread = 4;
      thread4.glob = glob;
      exec_thread(&thread1, &thread2, &thread3, &thread4);
    }
  else
    unthreaded_executer(glob);
  resize_img(&(glob->graph->calc_img), &(glob->graph->aff_img));
}
