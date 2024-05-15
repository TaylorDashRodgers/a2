#include "A2Engine.h"

#include <CSCI441/SimpleShader.hpp>

// include GLM libraries and matrix functions
#include <glm/gtc/matrix_transform.hpp>

A2Engine::A2Engine()
       : WorldMapEngine() {

    // initialize data members.
    shiftKeyPressed = false;

    _heroPosition  = glm::vec2(0.0,200.0);
    _heroCenter = glm::vec2(_heroPosition.x + 50.0,_heroPosition.y + 100);
    _yOffset = 0.1;

    _timeVariable = 0.0;
    _hoverAmount = 0.0;

    _drawChestVAO = 0;
    _numChestPoints = 0;

    _drawBellyVAO = 0;
    _numBellyPoints = 0;

    _drawBeltVAO = 0;
    _numBeltPoints = 0;

    _drawLeftLegVAO = 0;
    _numLeftLegPoints = 0;

    _drawLeftShoulderVAO = 0;
    _numLeftShoulderPoints = 0;

    _drawRedLeftShoulderVAO = 0;
    _numRedLeftShoulderPoints = 0;

    _drawSmallShoulderVAO = 0;
    _numSmallShoulderPoints = 0;

    _drawBicepVAO = 0;
    _numBicepPoints = 0;

    _drawElbowVAO = 0;
    _numElbowPoints = 0;

    _drawForearmVAO = 0;
    _numForearmPoints = 0;

    _drawWristVAO = 0;
    _numWristPoints = 0;

    _drawHandVAO = 0;
    _numHandPoints = 0;

    _drawKneeVAO = 0;
    _numKneePoints = 0;

    _drawCalfVAO = 0;
    _numCalfPoints = 0;

    _drawAnkleVAO = 0;
    _numAnklePoints = 0;

    _drawFootVAO = 0;
    _numFootPoints = 0;

    _darkCyanVAO = 0;
    _numDarkCyanPoints = 0;

    _darkGreyVAO = 0;
    _numDarkGreyPoints = 0;

    _blackVAO = 0;
    _numBlackPoints = 0;

    _lightGreyVAO = 0;
    _numLightGreyPoints = 0;

    _midGreyVAO = 0;
    _numMidGreyPoints = 0;

    _lowGreyVAO = 0;
    _numLowGreyPoints = 0;

    _blackTriVAO = 0;
    _numBlackTriPoints = 0;

    _blackEyeVAO = 0;
    _numBlackEyePoints = 0;

    _whiteEyeVAO = 0;
    _numWhiteEyePoints = 0;

    _earVAO = 0;
    _numEarPoints = 0;
}

//*************************************************************************************
//
// Setup Functions - register everything with OpenGL / GLFW

void A2Engine::mSetupGLFW() {
    CSCI441::OpenGLEngine::mSetupGLFW();

    // TODO Register Your Callbacks Here
    glfwSetKeyCallback( mpWindow, a2_keyboard_callback );
    glfwSetMouseButtonCallback( mpWindow, a2_mouse_button_callback );
    glfwSetCursorPosCallback( mpWindow, a2_cursor_callback);
    glfwSetKeyCallback( mpWindow, a2_keyboard_callback );
}

void A2Engine::mSetupOpenGL() {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );     // set the clear color to black
}

void A2Engine::mSetupShaders() {
    WorldMapEngine::mSetupShaders();
    CSCI441::SimpleShader2::setupSimpleShader();
}

void A2Engine::mSetupBuffers() {
    WorldMapEngine::mSetupBuffers();

    // TODO Add Your Vertex Registration Here

    // Creates all the points and colors that correspond to each part of the sign.
    glm::vec2 chestPoints[8] = {glm::vec2(0,0),
                                glm::vec2(125,0),
                                glm::vec2(130,15),
                                glm::vec2(120,60),
                                glm::vec2(90,75),
                                glm::vec2(35,75),
                                glm::vec2(5,60),
                                glm::vec2(-5,15)};
    glm::vec3 chestColors[8] = {glm::vec3(0.125f,0.698f,0.666f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.125f,0.698f,0.666f)};

    glm::vec2 bellyPoints[10] = {glm::vec2(0,0),
                                glm::vec2(125,0),
                                glm::vec2(127.5,-30),
                                glm::vec2(115,-90),
                                glm::vec2(110,-120),
                                 glm::vec2(90,-127.5),
                                 glm::vec2(35,-127.5),
                                glm::vec2(15,-120),
                                glm::vec2(10,-90),
                                glm::vec2(-2.5,-30)};
    glm::vec3 bellyColors[10] = {glm::vec3(0.125f,0.698f,0.666f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.125f,0.698f,0.666f)};

    glm::vec2 beltPoints[8] = {glm::vec2(15,-120),
                                glm::vec2(35,-127.5),
                                glm::vec2(90,-127.5),
                                glm::vec2(110,-120),
                                glm::vec2(115,-135),
                                glm::vec2(90,-142.5),
                                glm::vec2(35,-142.5),
                                glm::vec2(10,-135)};
    glm::vec3 beltColors[8] = {glm::vec3(227.0/255,66.0/255,52.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(227.0/255,66.0/255,52.0/255)};

    glm::vec2 leftLegPoints[14] = {glm::vec2(10,-135),
                                 glm::vec2(5,-150),
                                 glm::vec2(5,-165),
                                 glm::vec2(0,-195),
                                 glm::vec2(5,-225),
                                 glm::vec2(12.5,-225),
                                 glm::vec2(20,-240),
                                 glm::vec2(35,-240),
                                 glm::vec2(42.5,-225),
                                 glm::vec2(50,-225),
                                 glm::vec2(57.5,-195),
                                 glm::vec2(60,-180),
                                 glm::vec2(60,-142.5),
                                 glm::vec2(35,-142.5)};
    glm::vec3 leftLegColors[14] = {glm::vec3(0.125f,0.698f,0.666f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.0f,0.5451f,0.5451f),
                                 glm::vec3(0.125f,0.698f,0.666f)};

    glm::vec2 leftShoulderPoints[12] = {glm::vec2(12.5,37.5),
                                        glm::vec2(20,37.5),
                                        glm::vec2(27.5,52.5),
                                        glm::vec2(12.5,75),
                                        glm::vec2(-10,75),
                                        glm::vec2(-25,70),
                                        glm::vec2(-40,60),
                                        glm::vec2(-47.5,37.5),
                                        glm::vec2(-47.5,30),
                                        glm::vec2(-40,20),
                                        glm::vec2(-25,15),
                                        glm::vec2(5,15)};
    glm::vec3 leftShoulderColors[12] = {glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(54.0/255,69.0/255,79.0/255),
                                        glm::vec3(54.0/255,69.0/255,79.0/255),
                                        glm::vec3(54.0/255,69.0/255,79.0/255),
                                        glm::vec3(54.0/255,69.0/255,79.0/255),
                                        glm::vec3(54.0/255,69.0/255,79.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255)};

    glm::vec2 redLeftShoulderPoints[12] = {glm::vec2(-22.5,57.5),
                                        glm::vec2(-10,67.5),
                                        glm::vec2(17.5,67.5),
                                        glm::vec2(12.5,75),
                                        glm::vec2(-10,75),
                                        glm::vec2(-25,70),
                                        glm::vec2(-40,60),
                                        glm::vec2(-47.5,37.5),
                                        glm::vec2(-47.5,30),
                                        glm::vec2(-42.5,22.5),
                                        glm::vec2(-40,37.5),
                                        glm::vec2(-32.5,55)};
    glm::vec3 redLeftShoulderColors[12] = {glm::vec3(227.0/255,66.0/255,52.0/255),
                                           glm::vec3(227.0/255,66.0/255,52.0/255),
                                           glm::vec3(227.0/255,66.0/255,52.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(164.0/255,42.0/255,4.0/255),
                                           glm::vec3(227.0/255,66.0/255,52.0/255),
                                           glm::vec3(227.0/255,66.0/255,52.0/255)};

    glm::vec2 smallShoulderPoints[6] = {glm::vec2(-40,20),
                                           glm::vec2(-45,7.5),
                                           glm::vec2(-35,7.5),
                                           glm::vec2(-10,9),
                                           glm::vec2(5,15),
                                           glm::vec2(-25,15)};
    glm::vec3 smallShoulderColors[6] = {glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255),
                                        glm::vec3(74.0/255,89.0/255,99.0/255)};

    glm::vec2 bicepPoints[7] = {glm::vec2(130,15),
                                        glm::vec2(135,-15),
                                        glm::vec2(140,-30),
                                        glm::vec2(170,-35),
                                        glm::vec2(170,-30),
                                        glm::vec2(165,-15),
                                        glm::vec2(160,7.5)};
    glm::vec3 bicepColors[7] = {glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f),
                                glm::vec3(0.0f,0.5451f,0.5451f)};

    glm::vec2 elbowPoints[10] = {glm::vec2(150,-27.5),
                                 glm::vec2(140,-30),
                                glm::vec2(135,-45),
                                glm::vec2(135,-52.5),
                                glm::vec2(150,-55.5),
                                 glm::vec2(160,-55.5),
                                 glm::vec2(170,-52.5),
                                 glm::vec2(172.5,-45),
                                 glm::vec2(170,-35),
                                glm::vec2(167.5,-30)};
    glm::vec3 elbowColors[10] = {glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f),
                                 glm::vec3(0.0f,0.0f,0.0f)};

    glm::vec2 forearmPoints[9] = {glm::vec2(135,-52.5),
                                 glm::vec2(130,-60),
                                 glm::vec2(127.5,-75),
                                 glm::vec2(128.5,-90),
                                 glm::vec2(130,-100),
                                 glm::vec2(157.5,-105),
                                 glm::vec2(170,-72.5),
                                 glm::vec2(172.5,-60),
                                 glm::vec2(170,-52.5)};
    glm::vec3 forearmColors[9] = {glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f),
                                 glm::vec3(0.8f,0.8f,0.8f)};

    glm::vec2 wristPoints[8] = {glm::vec2(130,-100),
                                  glm::vec2(125,-105),
                                  glm::vec2(125,-112.5),
                                  glm::vec2(132.5,-120),
                                  glm::vec2(147.5,-120),
                                  glm::vec2(160,-115),
                                  glm::vec2(160,-107.5),
                                glm::vec2(157.5,-100)};
    glm::vec3 wristColors[8] = {glm::vec3(0.8f,0.8f,0.8f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.8f,0.8f,0.8f)};

    glm::vec2 handPoints[7] = {glm::vec2(130,-117.5),
                                glm::vec2(122.5,-125),
                                glm::vec2(122.5,-137.5),
                                glm::vec2(127.5,-142.5),
                                glm::vec2(152.5,-142.5),
                                glm::vec2(157.5,-130),
                                glm::vec2(155,-117.5)};
    glm::vec3 handColors[7] = {glm::vec3(0.8f,0.8f,0.8f),
                                glm::vec3(0.7f,0.7f,0.7f),
                                glm::vec3(0.7f,0.7f,0.7f),
                                glm::vec3(0.7f,0.7f,0.7f),
                                glm::vec3(0.7f,0.7f,0.7f),
                                glm::vec3(0.7f,0.7f,0.7f),
                                glm::vec3(0.8f,0.8f,0.8f)};

    glm::vec2 kneePoints[5] = {glm::vec2(5,-225),
                               glm::vec2(2.5,-225),
                               glm::vec2(5,-255),
                               glm::vec2(50,-255),
                               glm::vec2(52.5,-225)};
    glm::vec3 kneeColors[5] = {glm::vec3(0.1f,0.1f,0.1f),
                               glm::vec3(0.1f,0.1f,0.1f),
                               glm::vec3(0.1f,0.1f,0.1f),
                               glm::vec3(0.1f,0.1f,0.1f),
                               glm::vec3(0.1f,0.1f,0.1f)};

    glm::vec2 calfPoints[6] = {glm::vec2(7.5,-255),
                               glm::vec2(7.5,-285),
                               glm::vec2(12.5,-300),
                               glm::vec2(42.5,-300),
                               glm::vec2(47.5,-285),
                               glm::vec2(47.5,-255)};
    glm::vec3 calfColors[6] = {glm::vec3(0.2f,0.2f,0.2f),
                               glm::vec3(0.2f,0.2f,0.2f),
                               glm::vec3(0.2f,0.2f,0.2f),
                               glm::vec3(0.2f,0.2f,0.2f),
                               glm::vec3(0.2f,0.2f,0.2f),
                               glm::vec3(0.2f,0.2f,0.2f)};

    glm::vec2 anklePoints[10] = {glm::vec2(12.5,-300),
                                 glm::vec2(10,-302.5),
                                 glm::vec2(12.5,-330),
                                 glm::vec2(12.5,-345),
                                 glm::vec2(15,-360),
                                 glm::vec2(40,-360),
                                 glm::vec2(42.5,-345),
                                 glm::vec2(42.5,-330),
                                 glm::vec2(45,-302.5),
                                 glm::vec2(42.5,-300)};
    glm::vec3 ankleColors[10] = {glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f),
                                 glm::vec3(0.3f,0.3f,0.3f)};

    glm::vec2 footPoints[7] = {glm::vec2(15,-360),
                                 glm::vec2(12.5,-385),
                                 glm::vec2(-2.5,-400),
                                 glm::vec2(5,-415),
                                 glm::vec2(40,-400),
                                 glm::vec2(42.5,-385),
                                 glm::vec2(40,-360)};
    glm::vec3 footColors[7] = {glm::vec3(227.0/255,66.0/255,52.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(164.0/255,42.0/255,4.0/255),
                               glm::vec3(227.0/255,66.0/255,52.0/255)};

    glm::vec2 darkCyanPoints[12] = {glm::vec2(412.5,250),
                                    glm::vec2(470,275),
                                    glm::vec2(470,300),
                                    glm::vec2(460,320),
                                    glm::vec2(442.5,335),
                                    glm::vec2(425,340),
                                    glm::vec2(412.5,340),
                                    glm::vec2(400,340),
                                    glm::vec2(382.5,335),
                                    glm::vec2(365,320),
                                    glm::vec2(355,300),
                                    glm::vec2(355,275)};
    glm::vec3 darkCyanColors[12] = {glm::vec3(0.125f,0.698f,0.666f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.0f,0.5451f,0.5451f),
                                    glm::vec3(0.125f,0.698f,0.666f)};

    glm::vec2 darkGreyPoints[8] = {glm::vec2(412.5,210),
                                   glm::vec2(432.5,220),
                                   glm::vec2(442.5,245),
                                   glm::vec2(437.5,265),
                                   glm::vec2(412.5,285),
                                   glm::vec2(387.5,265),
                                   glm::vec2(382.5,245),
                                   glm::vec2(392.5,220)};
    glm::vec3 darkGreyColors[8] = {glm::vec3(0.5f,0.5f,0.5f),
                                   glm::vec3(0.5f,0.5f,0.5f),
                                   glm::vec3(0.5f,0.5f,0.5f),
                                   glm::vec3(0.7f,0.7f,0.7f),
                                   glm::vec3(0.7f,0.7f,0.7f),
                                   glm::vec3(0.7f,0.7f,0.7f),
                                   glm::vec3(0.5f,0.5f,0.5f),
                                   glm::vec3(0.5f,0.5f,0.5f)};

    glm::vec2 blackPoints[5] = {glm::vec2(412.5,212),
                                glm::vec2(450,230),
                                glm::vec2(465,255),
                                glm::vec2(360,255),
                                glm::vec2(375,230)};
    glm::vec3 blackColors[5] = {glm::vec3(0.3f,0.3f,0.3f),
                                glm::vec3(0.3f,0.3f,0.3f),
                                glm::vec3(0.3f,0.3f,0.3f),
                                glm::vec3(0.3f,0.3f,0.3f),
                                glm::vec3(0.3f,0.3f,0.3f)};

    glm::vec2 lightGreyPoints[8] = {glm::vec2(412.5,235),
                                    glm::vec2(468,255),
                                    glm::vec2(472,262),
                                    glm::vec2(470,275),
                                    glm::vec2(412.5,255),
                                    glm::vec2(355,275),
                                    glm::vec2(353,262),
                                    glm::vec2(357,255)};
    glm::vec3 lightGreyColors[8] = {glm::vec3(0.7f,0.7f,0.7f),
                                    glm::vec3(0.7f,0.7f,0.7f),
                                    glm::vec3(0.7f,0.7f,0.7f),
                                    glm::vec3(0.9f,0.9f,0.9f),
                                    glm::vec3(0.9f,0.9f,0.9f),
                                    glm::vec3(0.9f,0.9f,0.9f),
                                    glm::vec3(0.7f,0.7f,0.7f),
                                    glm::vec3(0.7f,0.7f,0.7f)};

    glm::vec2 midGreyPoints[6] = {glm::vec2(412.5,225),
                                  glm::vec2(445,235),
                                  glm::vec2(455,252),
                                  glm::vec2(412.5,235),
                                  glm::vec2(370,252),
                                  glm::vec2(380,235)};
    glm::vec3 midGreyColors[6] = {glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f)};

    glm::vec2 lowGreyPoints[6] = {glm::vec2(412.5,215),
                                  glm::vec2(437,223),
                                  glm::vec2(445,242),
                                  glm::vec2(412.5,225),
                                  glm::vec2(380,242),
                                  glm::vec2(388,223)};
    glm::vec3 lowGreyColors[6] = {glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f),
                                  glm::vec3(0.7f,0.7f,0.7f)};

    glm::vec2 blackTriPoints[6] = {glm::vec2(405,260),
                                   glm::vec2(405,255),
                                   glm::vec2(410,260),
                                   glm::vec2(410,260),
                                   glm::vec2(410,255),
                                   glm::vec2(405,255)};
    glm::vec3 blackTriColors[6] = {glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f)};

    glm::vec2 blackEyePoints[6] = {glm::vec2(327.5,285),
                                   glm::vec2(352.5,295),
                                   glm::vec2(337.5,315),
                                   glm::vec2(301,348),
                                   glm::vec2(294,321),
                                   glm::vec2(307.5,295)};
    glm::vec3 blackEyeColors[6] = {glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f),
                                   glm::vec3(0.0f,0.0f,0.0f)};

    glm::vec2 whiteEyePoints[6] = {glm::vec2(327.5,285),
                                   glm::vec2(352.5,295),
                                   glm::vec2(327.5,315),
                                   glm::vec2(310,330),
                                   glm::vec2(305,310),
                                   glm::vec2(310,295)};
    glm::vec3 whiteEyeColors[6] = {glm::vec3(1.0f,1.0f,1.0f),
                                   glm::vec3(1.0f,1.0f,1.0f),
                                   glm::vec3(1.0f,1.0f,1.0f),
                                   glm::vec3(1.0f,1.0f,1.0f),
                                   glm::vec3(1.0f,1.0f,1.0f),
                                   glm::vec3(1.0f,1.0f,1.0f)};

    glm::vec2 earPoints[6] = {glm::vec2(377.5,285),
                              glm::vec2(402.5,295),
                              glm::vec2(387.5,315),
                              glm::vec2(351,348),
                              glm::vec2(344,321),
                              glm::vec2(357.5,295)};
    glm::vec3 earColors[6] = {glm::vec3(0.125f,0.698f,0.666f),
                              glm::vec3(0.0f,0.5451f,0.5451f),
                              glm::vec3(0.0f,0.5451f,0.5451f),
                              glm::vec3(0.0f,0.5451f,0.5451f),
                              glm::vec3(0.0f,0.5451f,0.5451f),
                              glm::vec3(0.125f,0.698f,0.666f)};

    // transfer data to the GPU
    _drawChestVAO = CSCI441::SimpleShader2::registerVertexArray(_numChestPoints=8,
                                                                chestPoints,
                                                                chestColors);

    _drawBellyVAO = CSCI441::SimpleShader2::registerVertexArray(_numBellyPoints=10,
                                                                bellyPoints,
                                                                bellyColors);

    _drawBeltVAO = CSCI441::SimpleShader2::registerVertexArray(_numBeltPoints=8,
                                                               beltPoints,
                                                               beltColors);

    _drawLeftLegVAO = CSCI441::SimpleShader2::registerVertexArray(_numLeftLegPoints=14,
                                                                  leftLegPoints,
                                                                  leftLegColors);

    _drawLeftShoulderVAO = CSCI441::SimpleShader2::registerVertexArray(_numLeftShoulderPoints=12,
                                                                       leftShoulderPoints,
                                                                       leftShoulderColors);

    _drawRedLeftShoulderVAO = CSCI441::SimpleShader2::registerVertexArray(_numRedLeftShoulderPoints=12,
                                                                          redLeftShoulderPoints,
                                                                          redLeftShoulderColors);

    _drawSmallShoulderVAO = CSCI441::SimpleShader2::registerVertexArray(_numSmallShoulderPoints=6,
                                                                        smallShoulderPoints,
                                                                        smallShoulderColors);

    _drawBicepVAO = CSCI441::SimpleShader2::registerVertexArray(_numBicepPoints=7,
                                                                bicepPoints,
                                                                bicepColors);

    _drawElbowVAO = CSCI441::SimpleShader2::registerVertexArray(_numElbowPoints=10,
                                                                elbowPoints,
                                                                elbowColors);

    _drawForearmVAO = CSCI441::SimpleShader2::registerVertexArray(_numForearmPoints=9,
                                                                  forearmPoints,
                                                                  forearmColors);

    _drawWristVAO = CSCI441::SimpleShader2::registerVertexArray(_numWristPoints=8,
                                                                wristPoints,
                                                                wristColors);

    _drawHandVAO = CSCI441::SimpleShader2::registerVertexArray(_numHandPoints=7,
                                                               handPoints,
                                                               handColors);

    _drawKneeVAO = CSCI441::SimpleShader2::registerVertexArray(_numKneePoints=5,
                                                               kneePoints,
                                                               kneeColors);

    _drawCalfVAO = CSCI441::SimpleShader2::registerVertexArray(_numCalfPoints=6,
                                                               calfPoints,
                                                               calfColors);

    _drawAnkleVAO = CSCI441::SimpleShader2::registerVertexArray(_numAnklePoints=10,
                                                                anklePoints,
                                                                ankleColors);

    _drawFootVAO = CSCI441::SimpleShader2::registerVertexArray(_numFootPoints=7,
                                                               footPoints,
                                                               footColors);

    _darkCyanVAO = CSCI441::SimpleShader2::registerVertexArray(_numDarkCyanPoints=12,
                                                               darkCyanPoints,
                                                               darkCyanColors);

    _darkGreyVAO = CSCI441::SimpleShader2::registerVertexArray(_numDarkGreyPoints=8,
                                                               darkGreyPoints,
                                                               darkGreyColors);

    _blackVAO = CSCI441::SimpleShader2::registerVertexArray(_numBlackPoints=5,
                                                            blackPoints,
                                                            blackColors);

    _lightGreyVAO = CSCI441::SimpleShader2::registerVertexArray(_numLightGreyPoints=8,
                                                                lightGreyPoints,
                                                                lightGreyColors);

    _midGreyVAO = CSCI441::SimpleShader2::registerVertexArray(_numMidGreyPoints=6,
                                                              midGreyPoints,
                                                              midGreyColors);

    _lowGreyVAO = CSCI441::SimpleShader2::registerVertexArray(_numLowGreyPoints=6,
                                                              lowGreyPoints,
                                                              lowGreyColors);

    _blackTriVAO = CSCI441::SimpleShader2::registerVertexArray(_numBlackTriPoints=6,
                                                               blackTriPoints,
                                                               blackTriColors);

    _blackEyeVAO = CSCI441::SimpleShader2::registerVertexArray(_numBlackEyePoints=6,
                                                               blackEyePoints,
                                                               blackEyeColors);

    _whiteEyeVAO = CSCI441::SimpleShader2::registerVertexArray(_numWhiteEyePoints=6,
                                                               whiteEyePoints,
                                                               whiteEyeColors);

    _earVAO = CSCI441::SimpleShader2::registerVertexArray(_numEarPoints=6,
                                                          earPoints,
                                                          earColors);
}

//*************************************************************************************
//
// Rendering / Drawing Functions - this is where the magic happens!

// void _renderScene()
//   This method will contain the draw call for all objects to be drawn.
void A2Engine::_renderScene() const {
    // TODO Add Your Drawing Here
    // translates and scales down the whole body to draw to the screen.
    glm::mat4 transMtx = glm::translate(glm::mat4(1.0), glm::vec3(_heroPosition.x,_heroPosition.y,0.0));
    CSCI441::SimpleShader2::pushTransformation(transMtx);
    glm::mat4 scaleMtx = glm::scale(glm::mat4(1.0), glm::vec3(0.75,0.75,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx);
    A2Engine::_drawBody();
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

// void _updateScene()
//   This method will update any parameters used to draw an object
//   and thus create animation over time
void A2Engine::_updateScene() {
    //**********************************
    // TODO Add Your Idle Animation Here
    //**********************************
    _hoverAmount = _yOffset * std::sin(3.14159265359/180 * _timeVariable);

    _heroPosition.y += _hoverAmount;

    setHeroCenter(_heroPosition);

    _timeVariable += 1;
}

// void run()
//   Responsible for running the draw loop and keeping our engine open
void A2Engine::run() {
    //  This is our draw loop - all rendering is done here.  We use a loop to keep the window open
    //  until the user decides to close the window and quit the program.  Without a loop, the
    //  window will display once and then the program exits.
    while( !glfwWindowShouldClose(mpWindow) ) {  // check if the window was instructed to be closed
        glClear( GL_COLOR_BUFFER_BIT ); // clear the current color contents in the window

        WorldMapEngine::drawMap();     // draw the world map first - it appears behind anything we else we draw

        // update the projection matrix based on the window size
        // the GL_PROJECTION matrix governs properties of the view coordinates;
        // i.e. what gets seen - use an Orthographic projection that ranges
        // from [0, windowWidth] in X and [0, windowHeight] in Y. (0,0) is the lower left.
        glm::mat4 projMtx = glm::ortho( 0.0f, (GLfloat)getWindowWidth(), 0.0f, (GLfloat)getWindowHeight() );
        CSCI441::SimpleShader2::setProjectionMatrix(projMtx);

        // Get the size of our framebuffer.  Ideally this should be the same dimensions as our window, but
        // when using a Retina display the actual window can be larger than the requested window.  Therefore,
        // query what the actual size of the window we are rendering to is.
        GLint framebufferWidth, framebufferHeight;
        glfwGetFramebufferSize( mpWindow, &framebufferWidth, &framebufferHeight );

        // update the viewport - tell OpenGL we want to render to the whole window
        glViewport( 0, 0, framebufferWidth, framebufferHeight );

        // ensure the model matrix is reset to the identity to start drawing
        CSCI441::SimpleShader2::resetTransformationMatrix();

        _renderScene();                                 // draw everything to the window

        glfwSwapBuffers(mpWindow);               // flush the OpenGL commands and make sure they get rendered!
        glfwPollEvents();                               // check for any events and signal to redraw screen

        _updateScene();                 // update everything in the window
    }
}

//*************************************************************************************
//
// Callbacks

// TODO Define Your Callbacks Here
// Defines the keyboard callback for teh movement and also the left shift key press to change background.
void a2_keyboard_callback( GLFWwindow *window, int key, int scancode, int action, int mods ) {
    auto engine = (A2Engine*) glfwGetWindowUserPointer(window);

    if( action == GLFW_PRESS || action == GLFW_REPEAT || action == GLFW_RELEASE) {
        switch( key ) {
            // close the window to quit the program
            case GLFW_KEY_ESCAPE:
            case GLFW_KEY_Q:
                engine->setWindowShouldClose();
                break;
            case GLFW_KEY_W:
                engine->_heroPosition.y += 5.0;
                if(engine->_heroCenter.y > 512.0){
                    engine->_heroPosition.y = -50.0;
                    engine->moveUp();
                }
                engine->setHeroCenter(engine->_heroPosition);
                break;
            case GLFW_KEY_A:
                engine->_heroPosition.x -= 5.0;
                if(engine->_heroCenter.x < 0.0){
                    engine->_heroPosition.x = 197.0;
                    engine->moveLeft();
                }
                engine->setHeroCenter(engine->_heroPosition);
                break;
            case GLFW_KEY_S:
                engine->_heroPosition.y -= 5.0;
                if(engine->_heroCenter.y < 0.0){
                    engine->_heroPosition.y = 512.0;
                    engine->moveDown();
                }
                engine->setHeroCenter(engine->_heroPosition);
                break;
            case GLFW_KEY_D:
                engine->_heroPosition.x += 5.0;
                if(engine->_heroCenter.x > 512.0){
                    engine->_heroPosition.x = -315.0;
                    engine->moveRight();
                }
                engine->setHeroCenter(engine->_heroPosition);
                break;
            case GLFW_KEY_LEFT_SHIFT:
                // Set a flag when the Shift key is pressed or released
                if (action == GLFW_PRESS) {
                    engine->shiftKeyPressed = true;
                } else if (action == GLFW_RELEASE) {
                    engine->shiftKeyPressed = false;
                }
            default: break; // to remove CLion warning
        }
    }
}

// Defines the cursor callback so we can get where the cursor is so we can move our hero with the mouse.
void a2_cursor_callback( GLFWwindow *window, double x, double y ) {
    auto engine = (A2Engine*) glfwGetWindowUserPointer(window);
    glm::vec2 currMousePosition = glm::vec2((GLfloat)x, (GLfloat)y);

    // update the last mouse position
    engine->setMousePosition(currMousePosition);
}

// Defines the mouse button callback so we can tell when we click the mouse to move our character and change the background.
void a2_mouse_button_callback( GLFWwindow *window, int button, int action, int mods ) {
    auto engine = (A2Engine*) glfwGetWindowUserPointer(window);

    // if the event is for the left mouse button
    if( button == GLFW_MOUSE_BUTTON_LEFT ) {
        // update the left mouse button's state within the engine
        engine->_heroPosition.x = engine->getMousePosition().x - 310.0;
        engine->_heroPosition.y = 512.0 - engine->getMousePosition().y - 25.0;
    }

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && engine->shiftKeyPressed) {
        engine->moveUp();
    }
}

// This function is responsible for drawing all the individual body parts to be one together to move the whole body.
void A2Engine::_drawBody() const {
    A2Engine::_drawCalf();
    A2Engine::_drawAnkle();
    A2Engine::_drawFoot();
    A2Engine::_drawKnee();
    A2Engine::_drawRightLeg();
    A2Engine::_drawLeftLeg();
    A2Engine::_drawBelt();
    A2Engine::_drawBelly();
    A2Engine::_drawChest();
    A2Engine::_drawBicep();
    A2Engine::_drawForearm();
    A2Engine::_drawElbow();
    A2Engine::_drawHand();
    A2Engine::_drawWrist();
    A2Engine::_drawRightShoulder();
    A2Engine::_drawLeftShoulder();
    A2Engine::_drawSmallShoulder();
    A2Engine::_drawHead();
}

// The following functions create the individual body parts used to create the whole body.
void A2Engine::_drawChest() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawChestVAO, _numChestPoints);
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawBelly() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawBellyVAO, _numBellyPoints);
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawBelt() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawBeltVAO, _numBeltPoints);
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawLeftLeg() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawLeftLegVAO, _numLeftLegPoints);
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawRightLeg() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawLeftLegVAO, _numLeftLegPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawLeftShoulder() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawLeftShoulderVAO, _numLeftShoulderPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawRedLeftShoulderVAO, _numRedLeftShoulderPoints);
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawRightShoulder() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawLeftShoulderVAO, _numLeftShoulderPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx2 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx2);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawRedLeftShoulderVAO, _numRedLeftShoulderPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawSmallShoulder() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawSmallShoulderVAO, _numSmallShoulderPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawSmallShoulderVAO, _numSmallShoulderPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawBicep() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawBicepVAO, _numBicepPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawBicepVAO, _numBicepPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawElbow() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawElbowVAO, _numElbowPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawElbowVAO, _numElbowPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawForearm() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawForearmVAO, _numForearmPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawForearmVAO, _numForearmPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawWrist() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawWristVAO, _numWristPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawWristVAO, _numWristPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawHand() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawHandVAO, _numHandPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawHandVAO, _numHandPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawKnee() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawKneeVAO, _numKneePoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawKneeVAO, _numKneePoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawCalf() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawCalfVAO, _numCalfPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawCalfVAO, _numCalfPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawAnkle() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawAnkleVAO, _numAnklePoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawAnkleVAO, _numAnklePoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

void A2Engine::_drawFoot() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(350.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawFootVAO, _numFootPoints);
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(475.0f,150.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    glm::mat4 scaleMtx1 = glm::scale(glm::mat4(1.0), glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(scaleMtx1);
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _drawFootVAO, _numFootPoints);
    CSCI441::SimpleShader2::popTransformation();
    CSCI441::SimpleShader2::popTransformation();
}

// This function creates the head of Deku.
void A2Engine::_drawDarkCyan() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _darkCyanVAO, _numDarkCyanPoints);
}

// The following five functions are used to create the different parts of Deku's mask.
void A2Engine::_drawDarkGrey() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _darkGreyVAO, _numDarkGreyPoints);
}

void A2Engine::_drawBlack() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _blackVAO, _numBlackPoints);
}

void A2Engine::_drawLightGrey() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _lightGreyVAO, _numLightGreyPoints);
}

void A2Engine::_drawMidGrey() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _midGreyVAO, _numMidGreyPoints);
}

void A2Engine::_drawLowGrey() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _lowGreyVAO, _numLowGreyPoints);
}

// These functions are used to create the spots in Deku's mask while using the primitive GL_TRIANGLES.
void A2Engine::_drawBlackTriangle() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLES, _blackTriVAO, _numBlackTriPoints);
}

void A2Engine::_drawBlackTriangles() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(0.0f,0.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(0.0f,10.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx3 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(10.0f,10.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx3);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx4 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(10.0f,0.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx4);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();


    glm::mat4 transMtx5 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(0.0f,-30.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx5);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx6 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(0.0f,-20.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx6);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx7 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(10.0f,-20.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx7);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx8 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(10.0f,-30.0f,0.0f));
    CSCI441::SimpleShader2::pushTransformation(transMtx8);
    A2Engine::_drawBlackTriangle();
    CSCI441::SimpleShader2::popTransformation();
}

// These two functions create the black parts of the eyes.
void A2Engine::_drawBlackEye() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _blackEyeVAO, _numBlackEyePoints);
}

void A2Engine::_drawBlackEyes() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(130.0f,40.0f,0.0f));
    transMtx1 = glm::scale(transMtx1, glm::vec3(0.8,0.8,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    A2Engine::_drawBlackEye();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(694.5f,40.0f,0.0f));
    transMtx2 = glm::scale(transMtx2, glm::vec3(0.8,0.8,1));
    transMtx2 = glm::scale(transMtx2, glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    A2Engine::_drawBlackEye();
    CSCI441::SimpleShader2::popTransformation();
}

// These two functions create the white parts of the eyes.
void A2Engine::_drawWhiteEye() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _whiteEyeVAO, _numWhiteEyePoints);
}

void A2Engine::_drawWhiteEyes() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(130.0f,40.0f,0.0f));
    transMtx1 = glm::scale(transMtx1, glm::vec3(0.8,0.8,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    A2Engine::_drawWhiteEye();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(694.5f,40.0f,0.0f));
    transMtx2 = glm::scale(transMtx2, glm::vec3(0.8,0.8,1));
    transMtx2 = glm::scale(transMtx2, glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    A2Engine::_drawWhiteEye();
    CSCI441::SimpleShader2::popTransformation();
}

// These two functions create the four ears that are apart of the Deku head.
void A2Engine::_drawEar() const {
    CSCI441::SimpleShader2::draw(GL_TRIANGLE_FAN, _earVAO, _numEarPoints);
}

void A2Engine::_drawEars() const {
    glm::mat4 transMtx1 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(60.0f,70.0f,0.0f));
    transMtx1 = glm::scale(transMtx1, glm::vec3(0.8,0.8,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx1);
    A2Engine::_drawEar();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx2 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(764.5f,70.0f,0.0f));
    transMtx2 = glm::scale(transMtx2, glm::vec3(0.8,0.8,1));
    transMtx2 = glm::scale(transMtx2, glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx2);
    A2Engine::_drawEar();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx3 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(5.0f,30.0f,0.0f));
    transMtx3 = glm::scale(transMtx3, glm::vec3(1,1,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx3);
    A2Engine::_drawEar();
    CSCI441::SimpleShader2::popTransformation();

    glm::mat4 transMtx4 = glm::translate(glm::mat4(1.0f),
                                         glm::vec3(820.5f,30.0f,0.0f));
    transMtx4 = glm::scale(transMtx4, glm::vec3(1,1,1));
    transMtx4 = glm::scale(transMtx4, glm::vec3(-1,1,1));
    CSCI441::SimpleShader2::pushTransformation(transMtx4);
    A2Engine::_drawEar();
    CSCI441::SimpleShader2::popTransformation();
}

// This is where we actually define the function that is responsible for drawing all of the Deku Head.
void A2Engine::_drawHead() const {
    A2Engine::_drawEars();
    A2Engine::_drawDarkCyan();
    A2Engine::_drawBlackEyes();
    A2Engine::_drawWhiteEyes();
    A2Engine::_drawBlack();
    A2Engine::_drawLightGrey();
    A2Engine::_drawMidGrey();
    A2Engine::_drawLowGrey();
    A2Engine::_drawDarkGrey();
    A2Engine::_drawBlackTriangles();
}