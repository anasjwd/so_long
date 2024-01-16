#include <mlx.h>
#define HEIGHT 450
#define WIDTH 650

typedef	struct	s_date {
		void	*img;
		char	*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
}	t_data;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	add_shade(int color, int distance)
{
	int	transparency;
	int	new_color;

	transparency = ((color >> 24) & 0xFF) * (1.0 - distance);
	new_color = (color & 0x00FFFFFF) | (transparency << 24);
	return (new_color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	x = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
				   	&img.endian);
	while(x < HEIGHT * 0.5)
	{
			y = 50;
			while (y < WIDTH * 0.7)
					my_mlx_pixel_put(&img, y++, x, 0xFFFF0000);
			x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
