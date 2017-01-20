/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:33:39 by eliu              #+#    #+#             */
/*   Updated: 2016/12/14 19:34:37 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TY t[0]
# define TX t[1]
# define I t[2]
# define MI t[3]
# define MJ t[4]
# define GO_TO_NEXT_LINE if(temp[TY][TX]=='\0'){TX=0;TY++;}
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int					ft_mapsize(char ***str);
char				**ft_createmap(int size);
void				ft_print(char **map);
char				ft_letter(char **map);
char				**ft_addtetra(char **tetra, char **map, int t[]);
char				**ft_createmap(int size);
char				**ft_solve(char **tetra, char **map, int t[]);
int					ft_output(char ***str, char **map, char **temp, int t[]);
int					find(char **temp, char c, int temp_x);
int					*addnext(int com[4], int add);
int					check_tshape(int pos[4]);
int					check_zshape(int pos[4]);
int					check_lshape(int pos[4]);
int					fillit(char *file, int fd, char ***start, int t[]);
int					*addarray(int fir, int sec, int thr, int four);
int					check_valid_tetri(char *file);
int					find_max(int **xy_cord, int cord);
void				free_map(char **map);
char				**create_tetri_map(char *tetri);
int					**create_xycord();
char				**fill_newmap(char **newmap, int **xy_cord, int x, int y);
int					check_str(char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, char *s2, size_t n);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);

#endif
