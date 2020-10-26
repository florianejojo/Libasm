/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:52:16 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/23 15:48:40 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_write(char *str, int x, int fd, int fct_nb)
{
	int ret;
	int ft_ret;

printf(" --> errno before = %d \n", errno);
printf("nb de char a ecrire = %d\n", x);

	if (fct_nb == 0)
	{
	
		ft_ret = ft_write(fd ,str ,x);
		printf ("\nft_write_ret = %d  \n", ft_ret);

	}
	
	else
	{
		ret = write(fd, str, x);
		printf ("\nwrite_ret = %d  \n", ret);
	}
	printf(" --> errno after = %d \n", errno);
	printf ("----------------------------\n");
}

void	test_read(char *buffer, int x, char *file)
{
	int fd;
	int ret;
	int ret_ft;

	errno = 0;
	ret_ft = ft_read((fd = open(file, O_RDONLY)), buffer, x);
	buffer[ret_ft] = 0;
	printf ("buffer = '%s' | ft_ret = %d | errno = %d\n", buffer, ret_ft, errno);
	close (fd);

	printf("\n--close fd and open fd again--\n\n");
	errno = 0;
	ret = read((fd = open(file, O_RDONLY)), buffer, x);
	buffer[ret] = 0;
	printf ("buffer = '%s' | ret = %d | errno = %d \n", buffer, ret, errno);
	close (fd);

	printf ("----------------------------\n");
}

void	test_strdup(char *src)
{
	char *ft_dst;
	char *dst;

	printf("src = '%s'\n", src);
	
	dst = strdup(src);

	ft_dst = ft_strdup(src);
	printf ("ft_dst = '%s'| dst = '%s'\n", ft_dst, dst);
	printf ("----------------------------\n");
}

int		main(void)
{
	int		i = 0;
	char	buffer[100];

	while (i < 100)
		buffer[i++] = 0;

	printf("\n================================\n");
	printf("========== FT_STRLEN =============\n");
	printf("================================\n\n");
	STRLEN(test_1);
	STRLEN(test_2);
	STRLEN(test_3);
	STRLEN(test_4);
	printf("\n\n");

	printf("\n================================\n");
	printf("========== FT_READ ===============\n");
	printf("================================\n\n");	
	test_read(buffer, -1, "");
	test_read(buffer, 5, "test.txt");
	test_read(buffer, 10, "test.txt");
	test_read(buffer, 50, "test.txt");

	printf("\n================================\n");
	printf("========== FT_WRITE ==============\n");
	printf("================================\n\n");	

	printf("-wrong fd-\n");
	test_write(test_1, ft_strlen(test_1), 50, 0);
	errno = 0;
	test_write(test_1, ft_strlen(test_1), 50, 1);
	errno = 0;
	printf("-wrong nb of char-\n");
	test_write(test_2, -ft_strlen(test_2), 1, 0);
	errno = 0;
	test_write(test_2, -ft_strlen(test_2), 1, 1);
	errno = 0;
	printf("write = %zd & errno = %d\n", write(-1, "C'est pas un fd correct\n", 14), errno);
	errno = 0;
    printf("ft_write = %zd & errno = %d\n\n", ft_write(-1, "C'est pas un fd correct\n", 14), errno);
	//test_write(test_3, ft_strlen(test_3), 1, 0);
	errno = 0;
	//test_write(test_3, ft_strlen(test_3), 1, 1);

	//test_write(test_4, ft_strlen(test_4), 1, 0);
	//test_write(test_4, ft_strlen(test_4), 1, 1);

	printf("\n================================\n");
	printf("========== FT_STRCPY =============\n");
	printf("================================\n\n");	

	STRCPY(buffer, test_1);
	STRCPY(buffer, test_2);
	STRCPY(buffer, test_3);
	STRCPY(buffer, test_4);

	printf("\n================================\n");
	printf("========== FT_STRDUP =============\n");
	printf("================================\n\n");	

	test_strdup(test_1);
	test_strdup(test_2);
	test_strdup(test_3);
	test_strdup(test_4);

	printf("\n================================\n");
	printf("========== FT_STRCMP =============\n");
	printf("================================\n\n");

	char *s1 = test_1;
	char *s2 = test_2;
	char *s3 = test_3;
	char *s4 = test_4;

	STRCMP(s1, s2);
	STRCMP(s2, s3);
	STRCMP(s3, s4);
	STRCMP(s4, s2);


	return (0);
}
