/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:09:02 by sharnvon          #+#    #+#             */
/*   Updated: 2022/03/11 23:28:22 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct read
{
	int		file;
	char	*cont;
}	t_read;

char	*get_next_line(int fd);
char	*ft_info_tranfer(char *temp, char *info, int len);
char	*ft_checknread_temp(int fd, char *temp, t_read *brain);
char	*ft_checknstore_brain(char *result, char *temp, int index, int len);
char	*ft_read_file(int fd, char *temp, int len);
char	*ft_calloc(int size);
char	*ft_result_assign(char *temp, char *result, t_read *brain);
int		ft_strlen(char *str, int index);
int		ft_check_newline(char *temp);
int		ft_check_fd(int fd, t_read *brain);

#endif
