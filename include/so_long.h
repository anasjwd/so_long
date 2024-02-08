#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define CELL_WIDTH 50
# define CELL_HEIGHT 50
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define ESCAPE 53

# define IS_VALID_ELEMENT(c) ((c) != 'P' && (c) != 'C' && (c) != 'E' && (c) != '1' && (c) != '0' && (c) != 'N' ? 0 : 1)

typedef struct  s_image {
	int		width;
	int		height;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	char	*addr;
	void	*img;
}               t_image;

typedef struct  s_player {
    t_image player[6];
    t_image player_mv_right[6];
    t_image player_mv_left[6];
    int     dx;
    int     dy;
    int     x;
    int     y;
    int     ismoving;
    int     animation_end;
    int     animation_frame_index;
    int     animation_delay;
    void     (*mvmnt_direction)();
    int     p_current_pos[2];
    int     p_last_pos[2];
}               t_player;

typedef struct  s_enemy
{
    int number_of_enemies;
    t_image standing[5];
    int     standing_animation_frame;
    t_image right_attack[5];
    t_image left_attack[5];
    t_image back_attack[5];
    t_image front_attack[5];
    int     attack_animation_frame;
    int     enemy_attacking_pos[2];
    void    (*attack_direction)();
}               t_enemy;


typedef struct  s_game {
    void        *mlx;
    void        *win;
    char        **map;
    char        **map_copy;
    int         mapfd;
    size_t      map_height;
    size_t      map_width;
    t_player    player;
    t_enemy     enemy;
    t_image     wall[5];
    t_image     ground;
    t_image     collectible;
    t_image     exit[2];
    t_image     obstacles[2];
    int         num_of_collectibles;
    int         collected;
    int         player_isdead;
}               t_game;

/*utils*/
int destroy_window(t_game *game);
int check_file_extention(char *file_name);
void    dbl_free(char **ptr);
void	get_element_cord(char **map, int *cord, char element);
void    right_attack(t_game *game);
void    enemy_attack_direction(t_game *game, int x, int y);

//unsigned int random_number();
void    enemy_standing(t_game *game);

/*initialilze_game*/
void    initialize_game(t_game *game);
void	load_images(t_game *game);
void	draw_map(t_game *game);

/*parsing*/
void    parsing_map(t_game *game);
void    get_map(t_game *game);
void    get_map_copy(t_game *game);
void     check_map_is_valid(t_game *game);

/*player mvmnts*/
int player_movements_keydown(int keycode, t_game *game);
int player_movements_keyup(int keycode, t_game *game);
void    move_up_down_right(t_game *game);
void    move_left(t_game *game);
void    player_standing(t_game *game);

/*game loop*/
int    update_game_state(t_game *game);

#endif