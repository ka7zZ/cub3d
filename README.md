*This project has been created as part of the 42 curriculum by aghergut.*

# cub3D Subject-Compliant Refactor

## Description
This version is a refactor of the original repository focused on matching the mandatory requirements from `en.subject.pdf`.
It renders a first-person maze using raycasting with MiniLibX, supports `.cub` scene files, directional wall textures (`NO/SO/WE/EA`), floor and ceiling colors (`F/C`), and mandatory controls.

## Instructions

### Build
```bash
make
```

### Run
```bash
./cub3d path/to/scene.cub
```

### Cleanup
```bash
make clean
make fclean
make re
```

## Resources
- 42 cub3D subject (`en.subject.pdf`)
- MiniLibX documentation and source in `import/mlx`
- Lode's Computer Graphics Tutorial (raycasting concepts)
- Harm Smits 42 docs for MiniLibX/X11 events
- We would like to extend our gratitude to the following creators for their excellent assets:
    - **Wall Textures**: [gravendusk](https://gravendusk.itch.io/) - Thank you for the high-quality wall textures that      bring our environment to life.
    - **Shotgun Asset**: [rekkimaru](https://rekkimaru.itch.io/) - Thank you for the detailed shotgun model used in our game.

AI usage in this project:
- Used to accelerate refactor planning and repetitive code transformations.
- Used for parser edge-case review and requirement mapping against the subject.
- Every generated/refactored section was manually reviewed and tested by running the project build.
