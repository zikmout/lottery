#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "libft.h"

void		give_sorted_grid(int *grid, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		grid[i] = i + 1;
		i++;
	}
	srand(time(NULL));
	grid[i] = rand() % 50;

}

void		give_sorted_grid_star(int *grid, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		grid[i] = i + 1;
		i++;
	}
}

void		print_grid(int *grid, size_t n)
{
	size_t	i;

	printf("---------------- GRID ------------------\n");
	for (i = 0; i < n; i++) {
		printf("-> Grille %d: |%d %d %d %d %d|\n", i + 1, grid[i * 5], grid[i * 5 + 1], grid[i * 5 + 2], grid[i * 5 + 3], grid[i * 5 + 4]);
	}
	printf("----------------------------------------\n");
}

void		print_grid_star(int *grid, size_t n)
{
	size_t	i;

	printf("------------- GRID STAR ----------------\n");
	for (i = 0; i < n; i++) {
		printf("-> Grille %d: |%d|\n", i + 1, grid[i]);
	}
	printf("----------------------------------------\n");
}

void		print_paper(int *grid, int *grid_star, size_t grid_size, size_t grid_star_size)
{
	print_grid(grid, grid_size);
	print_grid_star(grid_star, grid_star_size);
}

void		shuffle_grid(int *grid, size_t size)
{
	size_t	i;
	int		tmp;
	int		random_index;

	tmp = 0;
	i = 0;
	while (i < size)
	{
		tmp = grid[i];
		random_index = rand() % size;
		grid[i] = grid[random_index];
		grid[random_index] = tmp;
		i++;
	}
}

int			main(int ac, char *av[])
{
	int		fd;
	int		*grid;
	int		*grid_star;
	char	*line;
	char	**split = NULL;
	int		first;

	first = 1;
	if (ac == 1)
	{
		if (!(grid = (int *)malloc(sizeof(int) * 5 * 49)))
		{
			printf("Malloc grid failed. Exit\n");
			return (0);
		}
		else if (!(grid_star = (int *)malloc(sizeof(int) * 5 * 10)))
		{
			printf("Malloc grid_start failed. Exit\n");
			return (0);
		}
		else
		{
			/*
			printf("This is it\n\n\n");
			fd = open("historic_loto/nouveau_loto.csv", O_RDONLY);
			while (get_next_line(fd, &line) > 0)
			{
				if (first)
					first = 0;
				else {
					//printf("line -> %s\n", line);
					split = ft_strsplit((char const *)line, ';');
					printf("line -> %d\n", ft_atoi(split[4]));
					printf("line -> %d\n", ft_atoi(split[5]));
					printf("line -> %d\n", ft_atoi(split[6]));
					printf("line -> %d\n", ft_atoi(split[7]));
					printf("line -> %d\n", ft_atoi(split[8]));
					printf("line -> %d\n", ft_atoi(split[9]));
				}
			}
			*/
			give_sorted_grid(grid, 49);
			give_sorted_grid_star(grid_star, 10);
			//write(1, "-->debug grid before\n", 22);
			//print_paper(grid, grid_star, 10, 10);
			shuffle_grid(grid, 49);
			shuffle_grid(grid_star, 10);
			//write(1, "\n\n-->debug grid after\n", 22);
			print_paper(grid, grid_star, 10, 10);
		}
		free(grid);
		free(grid_star);
		return (1);
	}
	else
	{
		printf("<Usage: ./loto>\n");
		return (0);
	}
	return (0);
}
