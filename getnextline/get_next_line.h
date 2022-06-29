/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:09:02 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/18 23:50:33 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_info_tranfer(char *temp, char *info, int len);
char	*ft_read_file(int fd, char *temp, int len);
char	*ft_checknread_temp(int fd, char *temp, char *brain);
char	*ft_checknstore_brain(char *result, char *temp, int i, int len);
char	*gl_calloc(int size);
int		gl_strlen(char *str, int i);
int		ft_check_newline(char *temp);

#endif
