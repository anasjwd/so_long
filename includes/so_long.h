#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "../utils/gnl/get_next_line.h"
# include "../utils/lib/libft.h"

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx {
	void	*ptr;
	void	*win;
}				t_mlx;

/*parsing the map*/

# define	INVALID_MAP 1
# define ERR_START 2
# define ERR_COLLECTIBLES 3
# define ERR_EXIT 4
# define INVALID_ELEMENT 5
char	**parsing_map(int);
int	check_if_rectangle(char **);
void	parsing_error();
int	check_elements(char **, int);
int	check_for_path(char **);
int	check_walls(char **, int);
int		map_lines(char **);
void	dbl_free(char **);
void	rendering(char **, t_mlx *);


#endif
