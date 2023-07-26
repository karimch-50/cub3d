/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:53:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/07/26 20:17:01 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/cub3d.h"

void ft_count(t_cub3d *_cub3d, int *width, int *height)
{
	int i;
	int j;

	i = 6;
	*width = 0;
	*height = 0;
	while (_cub3d->map[i])
	{
		j = 0;
		while (_cub3d->map[i][j])
		{
			if ((_cub3d->map[i][j] == 'W' || _cub3d->map[i][j] == 'N'
				|| _cub3d->map[i][j] == 'E' || _cub3d->map[i][j] == 'S'))
			{
				_cub3d->px = (j * PIXEL) + (PIXEL / 2);
				_cub3d->py = ((i - 6) * PIXEL) + (PIXEL / 2);
			}
			j++;
		}
		if (*width < j)
			*width = j;
		(*height)++;
		i++;
	}
}

// void	img_pix_put(t_cub3d *_cub3d, int x, int y, int color)
// {
// 	char    *pixel;

//     pixel = _cub3d->img.addr + (y * _cub3d->img.line_len + x * (_cub3d->img.bpp / 8));
// 	*(int *)pixel = color;
// }

// void ft_draw_ray(int x1, int y1, int targetX, int targetY)
// {
// 	// int y;
// 	// int x;

// 	(void)x1;
// 	(void)y1;
// 	(void)targetX;
// 	(void)targetY;


// 	// while ();

// }


void ft_put_pixle(t_cub3d *_cub3d, char c, int x1, int y1)
{
	int y;
	int x;

	y = 0;
	y1 = y1 - 6;
	while (y < PIXEL)
	{
		x = 0;
		while (x < PIXEL)
		{
			if (c == '1')
				img_pix_put(_cub3d, (x1 * PIXEL) + (x ), (y1 * PIXEL) + (y), 0x808080);
			img_pix_put(_cub3d, (x1 * PIXEL) + x, y1 * PIXEL, 0x0000FF);
			if (y1 == _cub3d->height - 1)
				img_pix_put(_cub3d, (x1 * PIXEL) + x, y1 * PIXEL + PIXEL, 0x0000FF);
			x++;
		}
		img_pix_put(_cub3d, (x1 * PIXEL), (y1 * PIXEL) + y, 0x0000FF);
		if (x1 == _cub3d->width - 1)
			img_pix_put(_cub3d, (x1 * PIXEL) + PIXEL, (y1 * PIXEL) + y, 0x0000FF);
		y++;
	}
}

void draw_map(t_cub3d *_cub3d)
{
	int y;
	int x;

	y = 6;
	while (y < _cub3d->height + 6)
	{
		x = 0;
		while (x < _cub3d->width)
		{
			if (_cub3d->map[y][x] == '1' && x <= (int)ft_strlen(_cub3d->map[y]))
				ft_put_pixle(_cub3d, '1', x, y);
			ft_put_pixle(_cub3d, '0', x, y);
			x++;
		}
		y++;
	}
}

// void	ft_update_player(t_cub3d *_cub3d)
// {
// 	(void)_cub3d;
// 	_cub3d->px -= 3; 
// }

// void left(t_cub3d *_cub3d)
// {
// 	// ft_update_player(_cub3d);
// }

// void up(t_cub3d *_cub3d)
// {
// 	_cub3d->py -= 5;
// }

// int	quit(void)
// {
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }

// int	key_hook(int keyCode, t_cub3d *_cub3d)
// {
// 	(void)_cub3d;
// 	if (keyCode == 123)
// 	{
// 		_cub3d->turn_direction = -1;
// 		printf("left\n");
// 	}
// 	if (keyCode == 124)
// 	{
// 		_cub3d->turn_direction = 1;
// 		printf("right\n");
// 	}
// 	if (keyCode == 125)
// 	{
// 		printf("down\n");
// 	}
// 	if (keyCode == 126)
// 	{
// 		// up(_cub3d);
// 		printf("up\n");
// 	}
// 	if (keyCode == 53)
// 		quit();
// 	return (0);
// }

void	line_rotation(t_cub3d *_cub3d, t_point *point, int line_lenth)
{
	point->x += cos(_cub3d->rotation_angle * M_PI / 180) * line_lenth;
	point->y += sin(_cub3d->rotation_angle * M_PI / 180) * line_lenth;
// (double)
}

void	draw_player(t_cub3d *_cub3d, t_scale scale)
{
	t_point	dest;
	int		line_lenth;
	int x;
	int y;

	// printf("PPOS(%d,%d)\n", _cub3d->px, _cub3d->py);
	line_lenth = 50;
	// printf("value is: %c\n", _cub3d->map[(int)(_cub3d->px + scale.right_left) / PIXEL][(int)(_cub3d->py + scale.up_down) / PIXEL]);
	// printf("value is: %c\n", _cub3d->map[0][1]);
	// int i = 0;
	// int j = 0;
	// while ( i < _cub3d->width)
	// {
		
	// }
	printf("-------------------\n");
	printf("%d    %d\n", _cub3d->px + scale.right_left, _cub3d->width);
	printf("%d    %d\n", _cub3d->py + scale.up_down,  _cub3d->height);
	// printf("-------------------\n");
	// printf("%d    %d\n", _cub3d->py / 50,  scale.up_down);
	// printf("%d    %d\n", _cub3d->px / 50,  scale.right_left);
	// exit (1);
	// if (_cub3d->map[(_cub3d->py + scale.up_down) / PIXEL][(_cub3d->px + scale.right_left) / PIXEL] != 1)
	// {
	// 	_cub3d->px += scale.right_left;
	// 	_cub3d->py += scale.up_down;
	// }
	if ((_cub3d->px + scale.right_left - PLAYER_SIZE / 2) > 0 && (_cub3d->px + scale.right_left + PLAYER_SIZE / 2) < _cub3d->width * PIXEL
		&& (_cub3d->py + scale.up_down - PLAYER_SIZE / 2) > 0 && (_cub3d->py + scale.up_down + PLAYER_SIZE / 2) < _cub3d->height * PIXEL)
	{
		_cub3d->px += scale.right_left;
		_cub3d->py += scale.up_down;
	}
	y =  -PLAYER_SIZE / 2;
	dest.x = _cub3d->px;
	dest.y = _cub3d->py;
	while (y < PLAYER_SIZE / 2)
	{
		x = -PLAYER_SIZE / 2;
		while (x < PLAYER_SIZE / 2)
		{
			img_pix_put(_cub3d, _cub3d->px + x, _cub3d->py + y, 0xFF0000);
			x++;
		}
		y++;
	}
	line_rotation(_cub3d, &dest, line_lenth);
	draw_line(_cub3d , dest);
}

void cub3d(t_cub3d *_cub3d)
{
	int width = 0;
	int height = 0;
	t_scale	scale;

	scale.up_down = 0;
	scale.right_left = 0;
	ft_count(_cub3d, &_cub3d->width, &_cub3d->height);
	_cub3d->rotation_angle = 0;
	_cub3d->step_size = 4;
	_cub3d->mlx_ptr = mlx_init();
	_cub3d->mlx_win = mlx_new_window(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2, "cub3d");
	_cub3d->img.mlx_img = mlx_new_image(_cub3d->mlx_ptr, (_cub3d->width * PIXEL) + 2, (_cub3d->height * PIXEL) + 2);
	_cub3d->img.addr = mlx_get_data_addr(_cub3d->img.mlx_img, &_cub3d->img.bpp, &_cub3d->img.line_len, &_cub3d->img.endian);
	draw_map(_cub3d);
	draw_player(_cub3d, scale);
	mlx_put_image_to_window(_cub3d->mlx_ptr, _cub3d->mlx_win, _cub3d->img.mlx_img, width, height);
	
	mlx_hook(_cub3d->mlx_win, 2, 0, &key_hook, _cub3d);
	mlx_hook(_cub3d->mlx_win, ON_DESTROY, 0, ft_close, _cub3d);
	mlx_loop(_cub3d->mlx_ptr);
}
