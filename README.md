<p align="center">
  <img src="https://tse2.mm.bing.net/th?id=OIG3.BDYV6_VAWh.56SX8XNUL&pid=ImgGn" width="250" />
</p>
<p align="center">
    <h1 align="center">KEBSENGINE</h1>
</p>
<p align="center">
    <em>Graphics Perfected: KebsEngine Delivers Dynamic Visuals!</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/AlexandrLebegue/KebsEngine?style=flat&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/AlexandrLebegue/KebsEngine?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/AlexandrLebegue/KebsEngine?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/AlexandrLebegue/KebsEngine?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with the software and tools below.</em>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/PowerShell-5391FE.svg?style=flat&logo=PowerShell&logoColor=white" alt="PowerShell">
	<img src="https://img.shields.io/badge/CMake-064F8C.svg?style=flat&logo=CMake&logoColor=white" alt="CMake">
	<img src="https://img.shields.io/badge/JSON-000000.svg?style=flat&logo=JSON&logoColor=white" alt="JSON">
</p>
<hr>


##  Overview

The KebsEngine project is a game engine that simplifies game development by providing essential graphics and physics components. It offers a seamless setup process for integrating SDL and SDL Image libraries, enhancing graphic rendering functionalities like sprite management, screen setup, and animation handling. 

The engine's core focus is on simplifying game creation through efficient rendering and user interaction management, making it an ideal platform for developing 2D games with rich visual elements and interactive gameplay features.


##  Repository Structure

```sh
└── KebsEngine/
    ├── CMakeLists.txt
    ├── CMakePresets.json
    ├── CMakeSettings.json
    ├── README.md
    ├── cmake
    │   ├── FindSDL2.cmake
    │   └── FindSDL2_image.cmake
    ├── install_sdl.ps1
    └── src
        ├── components
        │   ├── CMakeLists.txt
        │   ├── include
        │   │   └── components.hpp
        │   └── src
        │       └── components.cpp
        ├── graphics
        │   ├── CMakeLists.txt
        │   ├── include
        │   │   ├── animated-sprite.hpp
        │   │   ├── graphic-world.hpp
        │   │   ├── screen.hpp
        │   │   └── sprite.hpp
        │   ├── ressources
        │   │   ├── lepruchum.png
        │   │   ├── multiple_sprite.bmp
        │   │   ├── one_sprite.bmp
        │   │   └── sprite_01_png.png
        │   └── src
        │       ├── animated-sprite.cpp
        │       ├── graphic-world.cpp
        │       ├── screen.cpp
        │       └── sprite.cpp
        ├── main.cpp
        └── physics
            ├── CMakeLists.txt
            ├── include
            │   ├── physic-object.hpp
            │   └── physic-world.hpp
            └── src
                ├── physic-object.cpp
                └── physic-world.cpp
```

---

##  Modules

<details closed><summary>.</summary>

| File                                                                                               | Summary                                                                                                                                                                                                                                   |
| ---                                                                                                | ---                                                                                                                                                                                                                                       |
| [install_sdl.ps1](https://github.com/AlexandrLebegue/KebsEngine/blob/master/install_sdl.ps1)       | Code snippet in `install_sdl.ps1` automates downloading and setup of SDL and SDL Image libraries. Simplifies initial setup for Graphics module in `KebsEngine` repository, ensuring seamless integration.                                 |
| [CMakeSettings.json](https://github.com/AlexandrLebegue/KebsEngine/blob/master/CMakeSettings.json) | Code snippet in `physic-object.hpp` declares physics object properties. It defines physics attributes crucial for simulation accuracy in the KebsEngine repository.                                                                       |
| [CMakePresets.json](https://github.com/AlexandrLebegue/KebsEngine/blob/master/CMakePresets.json)   | Code snippet in `CMakePresets.json` configures MSVC17 build for Release mode with SDL2 and SDL2_image paths. Enhances build process in `KebsEngine` repository, focusing on graphics components.                                          |
| [CMakeLists.txt](https://github.com/AlexandrLebegue/KebsEngine/blob/master/CMakeLists.txt)         | Code Summary:**The `CMakeLists.txt` file sets up the build logic for the KebsEngine project, configuring dependencies, target linking, and resource copying operations post-build. It organizes graphics, physics, and component modules. |

</details>

<details closed><summary>cmake</summary>

| File                                                                                                         | Summary                                                                                                                                                                                                                                      |
| ---                                                                                                          | ---                                                                                                                                                                                                                                          |
| [FindSDL2.cmake](https://github.com/AlexandrLebegue/KebsEngine/blob/master/cmake/FindSDL2.cmake)             | Code snippet summary:**This `FindSDL2.cmake` module locates SDL libraries for linking and includes proper search paths, especially for different OS versions and frameworks, enhancing dependency management in the repository architecture. |
| [FindSDL2_image.cmake](https://github.com/AlexandrLebegue/KebsEngine/blob/master/cmake/FindSDL2_image.cmake) | Code Summary:**`FindSDL2_image.cmake` locates SDL2_image library, setting variables for linking. Requires SDL2. Enables custom paths, error handling, version reading, and target creation.                                                  |

</details>

<details closed><summary>src</summary>

| File                                                                               | Summary                                                                                                                                                                                                                      |
| ---                                                                                | ---                                                                                                                                                                                                                          |
| [main.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/main.cpp) | Code Summary:**Main.cpp controls SDL graphic rendering and user input, enabling sprites' movement. Manages graphic objects within GraphicWorld using Screen dimensions. Coordinates user interactivity and object animation. |

</details>

<details closed><summary>src.components</summary>

| File                                                                                                      | Summary                                                                                                                                                                                                                                                                      |
| ---                                                                                                       | ---                                                                                                                                                                                                                                                                          |
| [CMakeLists.txt](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/components/CMakeLists.txt) | Code Summary:** The code snippet in `src/components/CMakeLists.txt` creates a library for components with specific logic. It includes `components.cpp` and `components.hpp`, ensuring proper compilation and project structure alignment within the repository architecture. |

</details>

<details closed><summary>src.components.include</summary>

| File                                                                                                              | Summary                                                                                                                                |
| ---                                                                                                               | ---                                                                                                                                    |
| [components.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/components/include/components.hpp) | This code snippet in components.hpp defines a placeholder function `toto()` within the components module of the KebsEngine repository. |

</details>

<details closed><summary>src.components.src</summary>

| File                                                                                                          | Summary                                                                                                                                                                 |
| ---                                                                                                           | ---                                                                                                                                                                     |
| [components.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/components/src/components.cpp) | Code Summary:**Located in **src/components/src/components.cpp**, this codebase file defines an empty function named toto within the KebsEngine repository architecture. |

</details>

<details closed><summary>src.physics</summary>

| File                                                                                                   | Summary                                                                                                                                                                                     |
| ---                                                                                                    | ---                                                                                                                                                                                         |
| [CMakeLists.txt](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/physics/CMakeLists.txt) | Physics Component Setup**Located at `src/physics/CMakeLists.txt`, this configures the build system for the physics component in the `KebsEngine` repository, defining sources and includes. |

</details>

<details closed><summary>src.physics.include</summary>

| File                                                                                                                 | Summary                                                                                                                                                    |
| ---                                                                                                                  | ---                                                                                                                                                        |
| [physic-world.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/physics/include/physic-world.hpp)   | Code in `physic-world.hpp` defines a placeholder function `toto` without implementation. Likely part of the physics module in the `KebsEngine` repository. |
| [physic-object.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/physics/include/physic-object.hpp) | Code snippet in `physic-object.hpp` defines an empty function `toto`. It plays a role in the physics component of the KebsEngine repository.               |

</details>

<details closed><summary>src.physics.src</summary>

| File                                                                                                             | Summary                                                                                                                                                                    |
| ---                                                                                                              | ---                                                                                                                                                                        |
| [physic-object.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/physics/src/physic-object.cpp) | Summary:** `physic-object.cpp` in `KebsEngine` repository's `physics` module defines a placeholder function `toto`. It contributes to the physics component of the engine. |
| [physic-world.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/physics/src/physic-world.cpp)   | Code Summary:**physic-world.cpp in KebsEngine repo defines an entry point, containing a function toto for managing physics aspects.                                        |

</details>

<details closed><summary>src.graphics</summary>

| File                                                                                                    | Summary                                                                                                                                                     |
| ---                                                                                                     | ---                                                                                                                                                         |
| [CMakeLists.txt](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/CMakeLists.txt) | Code in src/graphics/CMakeLists.txt organizes graphic components: sprite, graphic world, screen & animated sprite. Sets project structure and dependencies. |

</details>

<details closed><summary>src.graphics.include</summary>

| File                                                                                                                      | Summary                                                                                                                                                                                                                                               |
| ---                                                                                                                       | ---                                                                                                                                                                                                                                                   |
| [sprite.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/include/sprite.hpp)                   | Role**: `Sprite` class for graphics rendering in `KebsEngine`.**Features**: Creates and renders sprites on screen.**Purpose**: Manage sprite visualization.                                                                                           |
| [graphic-world.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/include/graphic-world.hpp)     | This code snippet defines the GraphicWorld class, managing and rendering sprites using SDL in the parent repository's graphics module. It handles adding, updating, drawing, and removing sprites within the GraphicWorld.                            |
| [animated-sprite.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/include/animated-sprite.hpp) | Code summary:** `AnimatedSprite` class in `graphics` module manages animated sprites with frame-based rendering, enhancing visual appeal in the game engine.                                                                                          |
| [screen.hpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/include/screen.hpp)                   | Summary: `screen.hpp` defines the `Screen` class managing screen setup, rendering, and clearing for graphics display in the `KebsEngine` repository. It provides methods to control screen dimensions, update display, and handle rendering elements. |

</details>

<details closed><summary>src.graphics.src</summary>

| File                                                                                                                  | Summary                                                                                                                                                                                                                                |
| ---                                                                                                                   | ---                                                                                                                                                                                                                                    |
| [animated-sprite.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/src/animated-sprite.cpp) | Code Summary:****Role:** Renders animated sprites in a game using SDL and manages frame updates and rendering.**Description:** Handles sprite animation frames based on set parameters and renders them using SDL rendering functions. |
| [screen.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/src/screen.cpp)                   | Screen Class in Graphics Module**: Manages SDL window creation, rendering, and display. Sets background color and clears screen efficiently, crucial for the display aspect of the application.                                        |
| [graphic-world.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/src/graphic-world.cpp)     | Summary: `graphic-world.cpp` in `KebsEngine` manages rendering of Sprite objects on a Screen with methods for adding, updating, and removing Sprites in the graphical world.                                                           |
| [sprite.cpp](https://github.com/AlexandrLebegue/KebsEngine/blob/master/src/graphics/src/sprite.cpp)                   | Code Summary:**The code snippet in `src/graphics/src/sprite.cpp` initializes and renders sprites using SDL_image, enabling straightforward integration with the graphics subsystem of the parent `KebsEngine` repository.              |

</details>

---

##  Getting Started

***Requirements***

Ensure you have the following dependencies installed on your system:

* **CPP**: `version x.y.z`

###  Installation

1. Clone the KebsEngine repository:

```sh
git clone https://github.com/AlexandrLebegue/KebsEngine
```

2. Change to the project directory:

```sh
cd KebsEngine
```

3. Install the dependencies:

```sh
.\install_sdl.ps1
```


4. Configure:

```sh
cmake --preset msvc17
```

5. Compile:

```sh
cmake --build --preset msvc17 --config Debug
```

###  Running KebsEngine

Use the following command to run KebsEngine:

```sh
cd build/bin/<config>
./KebsEngine.exe
```
