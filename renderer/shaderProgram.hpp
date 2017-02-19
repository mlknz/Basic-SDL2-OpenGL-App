#ifndef __AnimalFarm_ShaderProgram__
#define __AnimalFarm_ShaderProgram__

#include <vector>

GLuint compileShader(GLenum eShaderType, const char * shaderFilePath);
GLuint linkShaderProgram(const std::vector<GLuint> &shaderList);

#endif
