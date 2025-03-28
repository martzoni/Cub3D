# Cub3D

A 3D maze game using raycasting technique, inspired by the iconic Wolfenstein 3D.

## 📸 Demo

![Cub3D Demo](.github/assets/demo.gif)

## 🚀 Features

- Raycasting rendering engine
- Textured walls
- Player movement and collision detection
- Mouse look controls
- Minimap display
- Custom map parser

## 🛠 Tech Stack

- C language
- MinilibX graphics library
- Mathematical algorithms for raycasting
- File parsing for custom maps

## 📦 Project Structure

```
Cub3D/
├── sources/         # Source files
├── includes/        # Header files
├── maps/            # Map files (.cub)
├── textures/        # Wall textures (.xpm)
└── Makefile         # Build configuration
```

## 🚦 Getting Started

### Prerequisites
- macOS system
- GCC compiler
- MinilibX library
- Make utility

### Installation

1. Clone the repository
```bash
git clone <repository-url>
cd Cub3D
```

2. Compile the project
```bash
make
```

3. Run with a map
```bash
./cub3d maps/example.cub
```

## 🎮 Controls

- `W` : Move forward
- `S` : Move backward
- `A` : Strafe left
- `D` : Strafe right
- `←` : Rotate camera left
- `→` : Rotate camera right
- `Mouse` : Look around
- `ESC` : Exit game

## 🗺️ Map Format (.cub)

```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0    # Floor RGB color
C 225,30,0     # Ceiling RGB color

# Map layout
1111111
1000001
1000N01
1111111
```

## 📝 License

This project is part of the 42 school curriculum.
