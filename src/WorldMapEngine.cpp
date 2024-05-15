#include "WorldMapEngine.h"

#include <CSCI441/ShaderUtils.hpp>

// include image library
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// include GLM libraries and matrix functions
#include <glm/gtc/matrix_transform.hpp>

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <sstream>      // I don't fully love C...let's use some C++
#include <string>

WorldMapEngine::WorldMapEngine()
   : CSCI441::OpenGLEngine(4, 1, 512, 512, "A2: An Unexpected Journey") {
    for(int i = 0; i < WORLD_MAP_WIDTH; i++)
        for(int j = 0; j < WORLD_MAP_HEIGHT; j++)
            _mapHandles[i][j] = 0;
    _currMapLocation = glm::uvec2( WORLD_MAP_WIDTH / 2, WORLD_MAP_HEIGHT / 2);
    _mapShaderProgramHandle = 0;
    _mapVAO = 0;
}

// I hope you can figure out what's going on here
void WorldMapEngine::moveDown() noexcept {
    _currMapLocation.y = (_currMapLocation.y + 1) % WORLD_MAP_HEIGHT;
}

void WorldMapEngine::moveLeft() noexcept {
    _currMapLocation.x = (_currMapLocation.x - 1 + WORLD_MAP_WIDTH) % WORLD_MAP_WIDTH;
}

void WorldMapEngine::moveRight() noexcept {
    _currMapLocation.x = (_currMapLocation.x + 1) % WORLD_MAP_HEIGHT;
}

void WorldMapEngine::moveUp() noexcept {
    _currMapLocation.y = (_currMapLocation.y - 1 + WORLD_MAP_HEIGHT) % WORLD_MAP_HEIGHT;
}

void WorldMapEngine::mSetupShaders() {
    _loadMapShader();
}

void WorldMapEngine::mCleanupShaders() {
    glDeleteProgram(_mapShaderProgramHandle);
}

void WorldMapEngine::mSetupBuffers() {
    _loadMap();
    _loadMapBuffers();
    _randomizeMap();
}

void WorldMapEngine::mCleanupBuffers() {
    glDeleteVertexArrays(1, &_mapVAO);
    glDeleteTextures(WORLD_MAP_WIDTH*WORLD_MAP_HEIGHT, &_mapHandles[0][0]);
}

void WorldMapEngine::drawMap() const {
    glUseProgram(_mapShaderProgramHandle);
    glBindVertexArray(_mapVAO);
    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, _mapHandles[ _currMapLocation.x ][ _currMapLocation.y ] );
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisable( GL_TEXTURE_2D );
}

void WorldMapEngine::_loadMap() {
    printf( "[INFO]: Loading map images..." );
    fflush( stdout );

    int imageWidth, imageHeight, imageChannels;
    stbi_set_flip_vertically_on_load(true);

    GLuint defaultTexHandle;
    std::string defaultFilename = "./images/default.png";
    unsigned char *defaultData = stbi_load( defaultFilename.c_str(), &imageWidth, &imageHeight, &imageChannels, 0);

    glEnable( GL_TEXTURE_2D );
    if( !defaultData ) {
        fprintf( stderr, "Could not load default image ./images/default.png.  Be sure to update Run > Edit Configurations and set your Working Directory to be ..\n" );
        fflush( stderr );
    } else {
        glGenTextures(1, &defaultTexHandle);
        glBindTexture(GL_TEXTURE_2D, defaultTexHandle);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        const GLint STORAGE_TYPE = (imageChannels == 4 ? GL_RGBA : GL_RGB);
        glTexImage2D(GL_TEXTURE_2D, 0, STORAGE_TYPE, imageWidth, imageHeight, 0, STORAGE_TYPE, GL_UNSIGNED_BYTE, defaultData);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(defaultData);
    }

    GLuint mapTexHandle;

    for( GLint j = 0; j < WORLD_MAP_HEIGHT; j++ ) {
        for( GLint i = 0; i < WORLD_MAP_WIDTH; i++ ) {
            std::stringstream filenameSS;
            filenameSS << "./images/map" << (j*WORLD_MAP_WIDTH + i) << ".png";
            std::string filename = filenameSS.str();

            unsigned char *data = stbi_load( filename.c_str(), &imageWidth, &imageHeight, &imageChannels, 0);

            // failed to load image
            if( !data ) {
                _mapHandles[ i ][ j ] = defaultTexHandle;
            } else {
                glGenTextures(1, &mapTexHandle);
                glBindTexture(GL_TEXTURE_2D, mapTexHandle);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                _mapHandles[i][j] = mapTexHandle;

                const GLint STORAGE_TYPE = (imageChannels == 4 ? GL_RGBA : GL_RGB);
                glTexImage2D(GL_TEXTURE_2D, 0, STORAGE_TYPE, imageWidth, imageHeight, 0, STORAGE_TYPE, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);

                stbi_image_free(data);
            }
        }
        printf( "." );
        fflush( stdout );
    }
    printf( "...done!\n" );
    fflush( stdout );
    glDisable( GL_TEXTURE_2D );
}

void WorldMapEngine::_randomizeMap() {
    srand( time(nullptr) );
    printf( "[INFO]: Randomizing map locations..." );
    const GLint RAND_ITERATIONS = WORLD_MAP_HEIGHT * WORLD_MAP_WIDTH * 500;
    for( GLint k = 0; k < RAND_ITERATIONS; k++ ) {
        GLuint x1, y1, x2, y2;
        x1 = rand() % WORLD_MAP_WIDTH;
        y1 = rand() % WORLD_MAP_HEIGHT;
        x2 = rand() % WORLD_MAP_WIDTH;
        y2 = rand() % WORLD_MAP_HEIGHT;

        GLuint tempTexHandle = _mapHandles[ x1 ][ y1 ];
        _mapHandles[ x1 ][ y1 ] = _mapHandles[ x2 ][ y2 ];
        _mapHandles[ x2 ][ y2 ] = tempTexHandle;

        if( k % 2500 == 0 ) {
            printf( "." );
            fflush( stdout );
        }
    }
    printf( "...done!\n" );
    fflush( stdout );
}

void WorldMapEngine::_loadMapShader() {
    std::string vertex_shader_src = "#version 410 core\n \
                                    \n \
                                    uniform mat4 model;\n \
                                    uniform mat4 view;\n \
                                    uniform mat4 projection;\n \
                                    \n \
                                    layout(location=0) in vec2 vPos;\n \
                                    layout(location=1) in vec2 vTexCoord;\n \
                                    \n \
                                    layout(location=0) out vec2 texCoord;\n \
                                    \n \
                                    void main() {\n \
                                        gl_Position = projection * view * model * vec4(vPos, 0.0, 1.0);\n \
                                        texCoord = vTexCoord;\n \
                                    }";
    const char* vertexShaders[1] = { vertex_shader_src.c_str() };

    std::string fragment_shader_src = "#version 410 core\n \
                                      \n \
                                      uniform sampler2D mapTex;\n \
                                      \n \
                                      layout(location=0) in vec2 texCoord;\n \
                                      \n \
                                      layout(location=0) out vec4 fragColorOut;\n \
                                      \n \
                                      void main() {\n \
                                          fragColorOut = texture(mapTex, texCoord);\n \
                                      }";
    const char* fragmentShaders[1] = { fragment_shader_src.c_str() };

    printf( "[INFO]: /--------------------------------------------------------\\\n" );

    GLuint vertexShaderHandle = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource(vertexShaderHandle, 1, vertexShaders, nullptr);
    glCompileShader(vertexShaderHandle);
    CSCI441_INTERNAL::ShaderUtils::printShaderLog(vertexShaderHandle);

    GLuint fragmentShaderHandle = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource(fragmentShaderHandle, 1, fragmentShaders, nullptr);
    glCompileShader(fragmentShaderHandle);
    CSCI441_INTERNAL::ShaderUtils::printShaderLog(fragmentShaderHandle);

    _mapShaderProgramHandle = glCreateProgram();
    glAttachShader(_mapShaderProgramHandle, vertexShaderHandle);
    glAttachShader(_mapShaderProgramHandle, fragmentShaderHandle);
    glLinkProgram(_mapShaderProgramHandle);
    CSCI441_INTERNAL::ShaderUtils::printProgramLog(_mapShaderProgramHandle);

    glDetachShader(_mapShaderProgramHandle, vertexShaderHandle);
    glDeleteShader(vertexShaderHandle);

    glDetachShader(_mapShaderProgramHandle, fragmentShaderHandle);
    glDeleteShader(fragmentShaderHandle);

    CSCI441_INTERNAL::ShaderUtils::printShaderProgramInfo(_mapShaderProgramHandle, true, false, false, false, true, false);

    GLint modelLocation       = glGetUniformLocation(_mapShaderProgramHandle, "model");
    GLint viewLocation        = glGetUniformLocation(_mapShaderProgramHandle, "view");
    GLint projectionLocation  = glGetUniformLocation(_mapShaderProgramHandle, "projection");

    glm::mat4 identity(1.0);
    glProgramUniformMatrix4fv(_mapShaderProgramHandle, modelLocation, 1, GL_FALSE, &identity[0][0]);
    glProgramUniformMatrix4fv(_mapShaderProgramHandle, viewLocation, 1, GL_FALSE, &identity[0][0]);

    glm::mat4 projMtx = glm::ortho( 0.0f, (GLfloat)getWindowWidth(), 0.0f, (GLfloat)getWindowHeight() );
    glProgramUniformMatrix4fv(_mapShaderProgramHandle, projectionLocation, 1, GL_FALSE, &projMtx[0][0]);

    GLint mapTexLocation    = glGetUniformLocation(_mapShaderProgramHandle, "mapTex");
    glProgramUniform1i(_mapShaderProgramHandle, mapTexLocation, 0);
    glActiveTexture(GL_TEXTURE0);

    printf( "[INFO]: Map shader loaded!\n\n" );
    fflush( stdout );
}

void WorldMapEngine::_loadMapBuffers() {
    glm::vec2 vertices[4] = { glm::vec2(0.0f, 0.0f),
                              glm::vec2(0.0f, (GLfloat)getWindowHeight()),
                              glm::vec2((GLfloat)getWindowWidth(), 0.0f),
                              glm::vec2((GLfloat)getWindowWidth(), (GLfloat)getWindowHeight()) };
    glm::vec2 texCoords[4] = { glm::vec2(0.0f, 0.0f),
                               glm::vec2(0.0f, 1.0f),
                               glm::vec2(1.0f, 0.0f),
                               glm::vec2(1.0f, 1.0f) };

    glGenVertexArrays(1, &_mapVAO);
    glBindVertexArray(_mapVAO);

    GLuint mapVBO;
    glGenBuffers(1, &mapVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mapVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*8, nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec2)*4, &vertices[0]);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*4, sizeof(glm::vec2)*4, &texCoords[0]);

    GLuint vertexLocation      = glGetAttribLocation(_mapShaderProgramHandle, "vPos");
    GLuint textureLocation     = glGetAttribLocation(_mapShaderProgramHandle, "vTexCoord");

    glEnableVertexAttribArray(vertexLocation);
    glVertexAttribPointer(vertexLocation, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(textureLocation);
    glVertexAttribPointer(textureLocation, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(glm::vec2)*4));

    printf( "[INFO]: Map buffers registered!\n" );
    fflush( stdout );
}