#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void	give_sorted_grid(int *grid, size_t n)
{
	size_t i;

	printf("grid size = %zu\n", n);
	i = 0;
	while (i < n)
	{
		//write(1, "***-->debug\n", 12);
		grid[i] = i + 1;
		i++;
	}
	srand(time(NULL));
	grid[i] = rand() % 49;

}

void	print_grid(int *grid, size_t n)
{
	size_t i;

	printf("---------------- GRID ------------------\n");
	for (i = 0; i < n; i++) {
		//write(1, "loop\n", 5);
		printf("-> Grille %d: |%d %d %d %d %d|\n", i + 1, grid[i * 5], grid[i * 5 + 1], grid[i * 5 + 2], grid[i * 5 + 3], grid[i * 5 + 4]);
	}
	printf("----------------------------------------\n");
}

void	print_grid_star(int *grid, size_t n)
{
	size_t i;

	printf("------------- GRID STAR ----------------\n");
	for (i = 0; i < n; i++) {
		//write(1, "loop\n", 5);
		printf("-> Grille %d: |%d|\n", i + 1, grid[i]);
	}
	printf("----------------------------------------\n");
}

int main(int ac, char *av[])
{
	int *grid;
	int	*grid_star;

	if (ac == 2)
	{
		if (!(grid = (int *)malloc(sizeof(int) * atoi(av[1]) * 5 * 49)))
		{
			printf("Malloc grid failed. Exit\n");
			return (0);
		}
		else if (!(grid_star = (int *)malloc(sizeof(int) * atoi(av[1]) * 5 * 10)))
		{
			printf("Malloc grid_start failed. Exit\n");
			return (0);
		}
		else
		{
			give_sorted_grid(grid, 49);
			give_sorted_grid(grid_star, 10);
			//generate_rand_array(grid, (size_t)atoi(av[1]));
			write(1, "-->debug\n", 9);
			print_grid(grid, 10);
			print_grid_star(grid, 10);
		}
		free(grid);
		return (1);
	}
	else
	{
		printf("<Usage: ./loto NB_GRILLES>\n");
		return (0);
	}
	return (0);
}
