/*
** fill_bmp.c for rt in /home/klein_e//Project/tek1/igraph/RT_final/TraceMyRay/part_graph
**
** Made by eric klein
** Login   <klein_e@epitech.net>
**
** Started on  Wed May 25 13:20:20 2011 eric klein
** Last update Sun Jun  5 17:20:44 2011 xavier schmerber
*/
#include	<errno.h>
#include	<strings.h>
#include	<string.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"rt.h"
#include	"bmp_header.h"

static void		create_header(bmphead *ptr, bmpheadinfo *ptr2, t_img *img)
{

  ptr->bfsize = sizeof(*ptr);
  ptr->bftype = 0x4d42;
  ptr->bfreserved1 = 0;
  ptr->bfreserved2 = 0;
  ptr->bfoffbits = sizeof(*ptr) + sizeof(*ptr2);
  ptr2->bisize = sizeof(*ptr2);
  ptr2->biplanes = 1;
  ptr2->bibitcount = 24;
  ptr2->bicompression = BI_RGB;
  ptr2->bisizeimage = img->sizex * abs(img->sizey) * 4;
  ptr2->bixpelspermeter = 0;
  ptr2->biypelspermeter = 0;
  ptr2->biclrused = 0;
  ptr2->biclrimportant = 0;
  ptr2->biwidth = img->sizex;
  ptr2->biheight = img->sizey;
}

static void		put_img_in_file(int fd, t_img *img)
{
  int			line;
  int			col;

  my_putstr("\nProccessing ... Please wait.\n");
  line = img->sizey - 1;
  while (line >= 0)
    {
      col = 0;
      while (col < img->sizex)
	if (-1 == write(fd, &(img->data[(col++ * 4)
					+ (line * img->sizeline)]), 3))
	  put_error(strerror(errno), 1);
      line--;
    }
  my_putstr("\nExportation Succed !\n");
}

static char		*set_export_name(char *bmp)
{
  char			*buffer;
  int			i;

  i = 0;
  buffer = cx_malloc(sizeof(char) * 4096);
  bzero(buffer, 4096);
  xread(0, buffer, 4095);
  while (buffer[0] == '\n')
    {
      bzero(buffer, 4096);
      my_putstr("Enter the name of your BMP exportation: ");
      xread(0, buffer, 4095);
    }
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	buffer[i] = '\0';
      i++;
    }
  bmp = cx_malloc(sizeof(char) * (strlen(buffer) + 5));
  bmp = strcat(bmp, buffer);
  bmp = strcat(bmp, ".bmp");
  return (bmp);
}

void			fill_bmp(t_img *img)
{
  int			fd;
  bmphead		ptr;
  bmpheadinfo		ptr2;
  char			*bmp;

  bmp = NULL;
  my_putstr("Enter the name of your BMP exportation: ");
  bmp = set_export_name(bmp);
  create_header(&ptr, &ptr2, img);
  fd = open(bmp, O_CREAT | O_WRONLY, 0666);
  if ((access(bmp, W_OK)) != -1)
    {
      if (-1 == write(fd, &ptr, sizeof(ptr)))
	put_error(strerror(errno), 1);
      if (-1 == write(fd, &ptr2, sizeof(ptr2)))
	put_error(strerror(errno), 1);
      if (fd > 0)
	put_img_in_file(fd, img);
      else
	fprintf(stderr, "Failed to create the exportation .bmp, \
please try again.");
    }
  else
    fprintf(stderr, "Wrong right to write on this file");
}
