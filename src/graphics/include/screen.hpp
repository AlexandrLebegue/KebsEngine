#include <SDL.h>
#include "sprite.hpp"

class Screen {

public:
	/**
	 * Initializes a new Screen object with specified width and height.
	 * 
	 * @param width The width of the screen in pixels. If not specified, a default value is used.
	 * @param height The height of the screen in pixels. If not specified, a default value is used.
	 * 
	 * This constructor initializes the SDL_Window and SDL_Renderer for the screen. It sets the screen's
	 * dimensions to the specified width and height. If the dimensions are not specified, default values
	 * are used. The SDL_Window and SDL_Renderer are essential for rendering graphics on the screen.
	 */
	Screen(int width, int height);
	Screen();
	/**
	 * Draws a sprite on the screen at the specified coordinates and size.
	 * 
	 * @param sprite A reference to the Sprite object to be drawn.
	 * @param x The x-coordinate on the screen where the sprite's top-left corner should be placed.
	 * @param y The y-coordinate on the screen where the sprite's top-left corner should be placed.
	 * @param size The size to scale the sprite to. The sprite will be scaled uniformly.
	 * 
	 * This method places a sprite on the screen at the specified location and scales it to the specified size.
	 * It uses the SDL_Renderer to render the sprite. The sprite must be loaded and ready to be drawn.
	 */
	void draw(Sprite& sprite, int x, int y, int size);

	/**
	 * Updates the screen to display the drawn graphics.
	 * 
	 * This method should be called after all draw operations are completed for the frame. It updates the
	 * screen to display the drawn sprites and graphics. This is typically called once per frame in the
	 * main game loop.
	 */
	void display();

	/**
	 * Creates an SDL_Window and SDL_Renderer for the screen with the given dimensions.
	 * 
	 * @param width A reference to an integer that will be set to the width of the created window.
	 * @param height A reference to an integer that will be set to the height of the created window.
	 * 
	 * This method initializes the SDL_Window and SDL_Renderer with the specified dimensions. It is used
	 * internally to set up the screen for rendering. The width and height parameters are updated to reflect
	 * the actual dimensions of the created window.
	 */
	void createWindow(int& width, int& height);

	/**
	 * Clears the screen.
	 * 
	 * This method clears the screen to prepare it for the next frame's drawing operations. It should be called
	 * at the beginning of each frame before any draw operations. This ensures that the previous frame's drawings
	 * are erased and the screen is ready for the next frame.
	 */
	void clearScreen();

	void setBackgroundColor(int red, int blue, int green);

private:
	int m_ScreenWidth, m_ScreenHeight;
	SDL_Window* m_Screen;
	SDL_Renderer* m_Renderer;
};