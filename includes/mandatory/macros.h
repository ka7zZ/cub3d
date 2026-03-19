/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 15:17:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/* Window and texture sizes */
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720
# define TEX_WIDTH			64
# define TEX_HEIGHT			64

/* Movement and camera */
# define MOVE_SPEED			3.8
# define ROT_SPEED			1.8
# define PLAYER_RADIUS		0.18
# define MIN_DELTA_TIME		0.008
# define MAX_DELTA_TIME		0.080

/* Raycast quality switch: 1 = max quality, 0 = performance */
# define RAYCAST_MAX_QUALITY	1
# if RAYCAST_MAX_QUALITY
#  define RAYCAST_COLUMN_STEP	1
# else
#  define RAYCAST_COLUMN_STEP	2
# endif

/* Limits */

#endif
