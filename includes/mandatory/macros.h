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
# define RAYCAST_MAX_QUALITY	0
# if RAYCAST_MAX_QUALITY
#  define RAYCAST_COLUMN_STEP	1
# else
#  define RAYCAST_COLUMN_STEP	2
# endif

/* Memory & Rendering Optimization Macros */
# define IMG_ADDR(img, y)		((img)->addr + (y) * (img)->line_len)
# define IMG_PIXEL_SIZE(img)	((img)->bpp / 8)
# define IMG_OFFSET(x, ps)		((x) * (ps))
# define PIXEL_AT(addr, off)	(*(unsigned int *)((addr) + (off)))

/* Game State Access */
# define G_FRAME(g)				(&(g)->graphics.frame)
# define G_WIDTH(g)				((g)->graphics.win_width)
# define G_HEIGHT(g)			((g)->graphics.win_height)
# define G_MAP_W(g)				((g)->map.map_width)
# define G_MAP_H(g)				((g)->map.map_height)
# define G_MAP_DATA(g)			((g)->map.map)
# define G_CEIL_C(g)			((g)->render.ceiling_color)
# define G_FLOOR_C(g)			((g)->render.floor_color)
# define G_MLX(g)				((g)->graphics.mlx)
# define G_WIN(g)				((g)->graphics.win)

/* Limits */

#endif
