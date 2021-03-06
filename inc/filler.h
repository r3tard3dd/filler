/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:12:04 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/10 20:55:47 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"
# include "../inc/filler.h"

# define BUFF_SIZE	1
# define COND1	y + stji[2] < env->b_coord.y && x + stji[3] < env->b_coord.x
# define COND_OP	env->board[y + stji[2]][x + stji[3]] == env->opponent
# define COND_PLAY	env->board[y + stji[2]][x + stji[3]] == env->player
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_env
{
	int		p_num;
	int		**board;
	int		**piece;
	int		player;
	int		opponent;
	int		hm_with;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	int		best_score;
	int		best_x;
	int		best_y;
	t_coord	b_coord;
	t_coord	p_coord;
}				t_env;

int				get_next_line(const int fd, char **line);
void			get_board(t_env *env);
void			get_player_num(int *p_num);
void			get_token_dim(t_env *env, char b_p);
void			heatmap_trig(t_env *env);
void			get_piece(t_env *env);
int				assign_char(char current);
void			create_token(t_env *env, char b_p);
void			score(t_env *env);
void			reinit_all(t_env *env);
void			free_token(int ***token, int j);

#endif
