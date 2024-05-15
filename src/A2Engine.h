/*
 *  CSCI 441, Computer Graphics, Fall 2023
 *
 *  Project: A2
 *  File: A2Engine.hpp
 *
 *      Original Author: Dr. Jeffrey Paone
 *
 *  Description:
 *      Engine implementation that draws a world map to the window, changes the map image when
 *      the move methods are called, and draws an animated hero to the window.  The hero is
 *      passively and actively animated.  As the hero wraps around the window edges, the world
 *      map is updated.
 */

#ifndef A2_A2_ENGINE_H
#define A2_A2_ENGINE_H

#include "WorldMapEngine.h"

class A2Engine final : public WorldMapEngine {
public:
    A2Engine();

    void run() final;

    // initialize a function to set and get our mouse position.
    void setMousePosition(glm::vec2 mousePos) { _mousePosition = mousePos; }
    [[nodiscard]] glm::vec2 getMousePosition() const { return _mousePosition; }

    // initialize a function to set the center of our hero for moving and resetting.
    void setHeroCenter(glm::vec2 heroPos) { _heroCenter = glm::vec2(heroPos.x + 315.0,heroPos.y + 100.0); }

    glm::vec2 _heroPosition;
    glm::vec2 _heroCenter;
    bool shiftKeyPressed;

private:
    void mSetupGLFW() final;
    void mSetupOpenGL() final;
    void mSetupShaders() final;
    void mSetupBuffers() final;

    void _renderScene() const;
    void _updateScene();

    // This is where I initialize all of my member variables.
    glm::vec2 _mousePosition;

    GLfloat _yOffset;

    GLfloat _timeVariable;
    GLfloat _hoverAmount;

    GLuint _drawChestVAO;
    GLuint _numChestPoints;

    GLuint _drawBellyVAO;
    GLuint _numBellyPoints;

    GLuint _drawBeltVAO;
    GLuint _numBeltPoints;

    GLuint _drawLeftLegVAO;
    GLuint _numLeftLegPoints;

    GLuint _drawLeftShoulderVAO;
    GLuint _numLeftShoulderPoints;

    GLuint _drawRedLeftShoulderVAO;
    GLuint _numRedLeftShoulderPoints;

    GLuint _drawSmallShoulderVAO;
    GLuint _numSmallShoulderPoints;

    GLuint _drawBicepVAO;
    GLuint _numBicepPoints;

    GLuint _drawElbowVAO;
    GLuint _numElbowPoints;

    GLuint _drawForearmVAO;
    GLuint _numForearmPoints;

    GLuint _drawWristVAO;
    GLuint _numWristPoints;

    GLuint _drawHandVAO;
    GLuint _numHandPoints;

    GLuint _drawKneeVAO;
    GLuint _numKneePoints;

    GLuint _drawCalfVAO;
    GLuint _numCalfPoints;

    GLuint _drawAnkleVAO;
    GLuint _numAnklePoints;

    GLuint _drawFootVAO;
    GLuint _numFootPoints;

    GLuint _darkCyanVAO;
    GLuint _numDarkCyanPoints;

    GLuint _darkGreyVAO;
    GLuint _numDarkGreyPoints;

    GLuint _blackVAO;
    GLuint _numBlackPoints;

    GLuint _lightGreyVAO;
    GLuint _numLightGreyPoints;

    GLuint _midGreyVAO;
    GLuint _numMidGreyPoints;

    GLuint _lowGreyVAO;
    GLuint _numLowGreyPoints;

    GLuint _blackTriVAO;
    GLuint _numBlackTriPoints;

    GLuint _blackEyeVAO;
    GLuint _numBlackEyePoints;

    GLuint _whiteEyeVAO;
    GLuint _numWhiteEyePoints;

    GLuint _earVAO;
    GLuint _numEarPoints;

    // This is where I initialize all of my functions for drawing.
    void _drawBody() const;

    void _drawChest() const;

    void _drawBelly() const;

    void _drawBelt() const;

    void _drawLeftLeg() const;

    void _drawRightLeg() const;

    void _drawLeftShoulder() const;

    void _drawRightShoulder() const;

    void _drawSmallShoulder() const;

    void _drawBicep() const;

    void _drawElbow() const;

    void _drawForearm() const;

    void _drawWrist() const;

    void _drawHand() const;

    void _drawKnee()const;

    void _drawCalf() const;

    void _drawAnkle() const;

    void _drawFoot() const;

    void _drawDarkCyan() const;

    void _drawDarkGrey() const;

    void _drawBlack() const;

    void _drawLightGrey() const;

    void _drawMidGrey() const;

    void _drawLowGrey() const;

    void _drawBlackTriangle() const;

    void _drawBlackTriangles() const;

    void _drawBlackEye() const;

    void _drawBlackEyes() const;

    void _drawWhiteEye() const;

    void _drawWhiteEyes() const;

    void _drawEar() const;

    void _drawEars() const;

    void _drawHead() const;
};

// TODO Declare Your Callbacks Here
static void a2_keyboard_callback( GLFWwindow *window, int key, int scancode, int action, int mods );
static void a2_cursor_callback( GLFWwindow *window, double x, double y );
static void a2_mouse_button_callback( GLFWwindow *window, int button, int action, int mods );
#endif //A2_A2_ENGINE_H