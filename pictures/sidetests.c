#include <mlx.h>
#include <stdlib.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}           t_data;
typedef struct s_vars {
    void    *mlx;
    void    *nwin;
    void    *char_img; // Character image
    int     char_width; // Width of the character image
    int     char_height; // Height of the character image
}           t_vars;

int	quit(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->nwin);
		exit(0);
	}
	return (0);
}

void    my_mlx_pixel(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    draw_frame(t_data *data, int win_width, int win_height, int frame_width, int frame_height, int color)
{
    int x;
    int y;
    int start_x;
    int start_y;

    // Calculate the top-left corner of the frame to center it
    start_x = (win_width - frame_width) / 2;
    start_y = (win_height - frame_height) / 2;

    // Fill the entire rectangle
    y = 0;
    while (y < frame_height)
    {
        x = 0;
        while (x < frame_width)
        {
            my_mlx_pixel(data, start_x + x, start_y + y, color);
            x++;
        }
        y++;
    }
}

int main(void)
{
    t_vars	vars;
    t_data  img;

    int win_width = 1080;
    int win_height = 720;
    int frame_width = 1080;
    int frame_height = 720;

    vars.mlx = mlx_init();
    vars.nwin = mlx_new_window(vars.mlx, win_width, win_height, "this is a test");

    img.img = mlx_new_image(vars.mlx, win_width, win_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    draw_frame(&img, win_width, win_height, frame_width, frame_height, 0x00FF0000);

    vars.char_img = mlx_xpm_file_to_image(vars.mlx, "/mnt/homes/yaboukir/Desktop/ms2/my2dgame/textures/frame_01.xpm", &vars.char_width, &vars.char_height);
    if (!vars.char_img)
    {
        mlx_destroy_window(vars.mlx, vars.nwin);
        return (1); // Exit if the character image can't be loaded
    }
    int char_x = (win_width - vars.char_width) / 2;
    int char_y = (win_height - vars.char_height) / 2;
    mlx_put_image_to_window(vars.mlx, vars.nwin, vars.char_img, char_x, char_y);

	mlx_hook(vars.nwin, 2, 1L << 0, quit, &vars);

    mlx_loop(vars.mlx);

    return (0);
}




// #include <mlx.h>
// #include <stdlib.h>

// typedef struct s_vars {
//     void    *mlx;
//     void    *nwin;
//     void    *frames[3]; // Array to hold the 3 frames (standing, shooting, reloading)
//     int     char_width; // Width of the character image
//     int     char_height; // Height of the character image
//     int     current_frame; // Current frame index (0: standing, 1: shooting, 2: reloading)
// }           t_vars;

// int quit(int keycode, t_vars *vars)
// {
//     if (keycode == 53) // ESC key to quit
//     {
//         mlx_destroy_window(vars->mlx, vars->nwin);
//         exit(0);
//     }
//     return (0);
// }

// int key_handler(int keycode, t_vars *vars)
// {
//     if (keycode == 15) // R key for reload
//     {
//         vars->current_frame = 2; // Set to reload frame
//     }
//     else if (keycode == 53) // ESC key to quit
//     {
//         quit(keycode, vars);
//     }

//     // Refresh the window with the new frame
//     int char_x = (1080 - vars->char_width) / 2;
//     int char_y = (720 - vars->char_height) / 2;
//     mlx_clear_window(vars->mlx, vars->nwin); // Clear window
//     mlx_put_image_to_window(vars->mlx, vars->nwin, vars->frames[vars->current_frame], char_x, char_y);

//     return (0);
// }

// int mouse_handler(int button, int x, int y, t_vars *vars)
// {
//     (void)x;
//     (void)y;

//     if (button == 1) // Left mouse click
//     {
//         vars->current_frame = 1; // Set to shooting frame

//         // Refresh the window with the new frame
//         int char_x = (1080 - vars->char_width) / 2;
//         int char_y = (720 - vars->char_height) / 2;
//         mlx_clear_window(vars->mlx, vars->nwin); // Clear window
//         mlx_put_image_to_window(vars->mlx, vars->nwin, vars->frames[vars->current_frame], char_x, char_y);
//     }

//     return (0);
// }

// int main(void)
// {
//     t_vars vars;

//     int win_width = 1080;
//     int win_height = 720;

//     // Initialize MiniLibX
//     vars.mlx = mlx_init();
//     vars.nwin = mlx_new_window(vars.mlx, win_width, win_height, "Character Animation");

//     // Load frames into the frames array (replace with separated XPM paths)
//     char *frame_paths[3] = {
//         "/mnt/homes/yaboukir/Desktop/ms2/my2dgame/textures/frame_01.xpm",   // Standing
//         "/mnt/homes/yaboukir/Desktop/ms2/my2dgame/textures/reload/reload01.xpm/reload02.xpm/reload03.xpm", // Shooting
//         "/mnt/homes/yaboukir/Desktop/ms2/my2dgame/textures/frame_03.xpm"  // Reloading
//     };

//     for (int i = 0; i < 3; i++)
//     {
//         vars.frames[i] = mlx_xpm_file_to_image(vars.mlx, frame_paths[i], &vars.char_width, &vars.char_height);
//         if (!vars.frames[i])
//         {
//             mlx_destroy_window(vars.mlx, vars.nwin);
//             return (1); // Exit if any frame can't be loaded
//         }
//     }

//     vars.current_frame = 0; // Default frame is standing

//     // Display the initial frame
//     int char_x = (win_width - vars.char_width) / 2;
//     int char_y = (win_height - vars.char_height) / 2;
//     mlx_put_image_to_window(vars.mlx, vars.nwin, vars.frames[vars.current_frame], char_x, char_y);

//     // Hook for key events
//     mlx_hook(vars.nwin, 2, 1L << 0, key_handler, &vars);

//     // Hook for mouse events
//     mlx_mouse_hook(vars.nwin, mouse_handler, &vars);

//     // Hook for quitting the application
//     mlx_hook(vars.nwin, 17, 1L << 17, quit, &vars);

//     // Start the MiniLibX loop
//     mlx_loop(vars.mlx);

//     return (0);
// }

