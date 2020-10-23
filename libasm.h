/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:47:06 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/23 16:01:53 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define errno (*__error())
#define O_RDONLY 0x0000

# define test_1 ""
# define test_2 "hey"
# define test_3 "mamie"
# define test_4 "j'ai perdu ma pelotte de laine"

# define STRLEN(x)			printf("Input = '%s' | ft_strlen = %d | strlen = %d\n", x, ft_strlen(x), (int)strlen(x));
# define STRCPY(buffer,str) printf("Input = '%s' | ft_dest = '%s' | dest = '%s'\n", str, ft_strcpy(buffer, str), strcpy(buffer, str));
# define STRCMP(s1, s2)		printf(" S1 = '%s' | s2 = '%s' | ft_ret = '%d'|  ret = '%d' \n", s1, s2, ft_strcmp(s1,s2), strcmp(s1,s2));

int		ft_strlen(char const *str);
ssize_t	ft_read(int fd, void *buf, int nbyte);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(const char *s1, const char *s2);