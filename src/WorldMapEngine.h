/*
 *  CSCI 441, Computer Graphics, Fall 2023
 *
 *  Project: A2
 *  File: WorldMapEngine.hpp
 *
 *      Author: Dr. Jeffrey Paone
 *
 *  Description:
 *      Engine extension that draws a world map to the window and changes the map image when
 *      the move methods are called.
 *
 *      WorldMapEngine extends CSCI441::OpenGLEngine, implements some virtual methods
 *      but is still an abstract class that needs to be further extended and implemented.
 */

#ifndef A2_WORLD_MAP_ENGINE_H
#define A2_WORLD_MAP_ENGINE_H

#include <CSCI441/OpenGLEngine.hpp>

#include <glm/glm.hpp>

class WorldMapEngine : public CSCI441::OpenGLEngine {
public:
    WorldMapEngine();

    // renders the textured quad with current map image
    void drawMap() const;

    // these next four methods update the current location and loads the correct map.  they will wrap
    // around the edges, so the Hero can move through an infinite world

    // moves our world map down one square
    void moveDown() noexcept;
    // moves our world map left one square
    void moveLeft() noexcept;
    // moves our world map right one square
    void moveRight() noexcept;
    // moves our world map up one square
    void moveUp() noexcept;

protected:
    void mSetupShaders() override;                              // registers the map shader
    void mSetupBuffers() override;                              // loads the map images & textured quad, then randomizes the map

private:
    static const GLuint WORLD_MAP_WIDTH = 7;                    // sets the width and height of our 2D map array
    static const GLuint WORLD_MAP_HEIGHT = 7;
    GLuint _mapHandles[ WORLD_MAP_WIDTH ][ WORLD_MAP_HEIGHT ];  // a 2D storing the texture handles of our world map backgrounds
    glm::uvec2 _currMapLocation;                                // our current location within the map
    GLuint _mapShaderProgramHandle;                             // our shader program that draws the map
    GLuint _mapVAO;                                             // our VAO that draws a textured quad to the screen

    void mCleanupShaders() final;                               // deletes the map shader
    void mCleanupBuffers() final;                               // deletes the map images and quad

    void _loadMap();                                            // loads the images/ in to memory and builds the array
    void _randomizeMap();                                       // shuffles the images placed at each map location
    void _loadMapShader();                                      // sets up the map drawing shader program
    void _loadMapBuffers();                                     // registers a textured quad
};

#endif // A2_WORLD_MAP_ENGINE_H