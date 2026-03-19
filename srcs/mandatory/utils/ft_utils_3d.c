/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:52:41 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

// STARTUP CONTROL TEXT UTILS

// PRINT INPUT CONTROLS TO TERMINAL
void	ft_print_controls(void)
{
	ft_printf("\n=== SO_LONG 3D - CONTROLS ===\n");
	ft_printf("W/S         - Move Forward/Backward\n");
	ft_printf("A/D         - Strafe Left/Right\n");
	ft_printf("LEFT/RIGHT  - Rotate\n");
	ft_printf("ESC         - Exit Game\n");
	ft_printf("============================\n\n");
}
