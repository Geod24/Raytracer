/*
** bmp_header.h for rt in /home/klein_e//Project/tek1/igraph/RT_final/TraceMyRay/part_graph
**
** Made by eric klein
** Login   <klein_e@epitech.net>
**
** Started on  Wed May 25 11:44:00 2011 eric klein
** Last update Sun Jun  5 01:19:46 2011 xavier schmerber
*/

#ifndef			__BMP_HEADER_H__
#define			__BMP_HEADER_H__

#define BI_RGB 0x0

typedef struct	__attribute__((__packed__))	bitmapfileheader
{
  unsigned short int	bftype;
  unsigned int		bfsize;
  unsigned short int	bfreserved1;
  unsigned short int	bfreserved2;
  unsigned int		bfoffbits;
}			bmphead;

typedef struct	__attribute__((__packed__))	bitmapinfoheader
{

  unsigned int		bisize;
  int			biwidth;
  int			biheight;
  unsigned short int	biplanes;
  unsigned short int	bibitcount;
  unsigned int		bicompression;
  unsigned int		bisizeimage;
  int			bixpelspermeter;
  int			biypelspermeter;
  unsigned int		biclrused;
  unsigned int		biclrimportant;
}			bmpheadinfo;

#endif
