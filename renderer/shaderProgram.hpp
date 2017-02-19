#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

GLuint CreateShader(GLenum eShaderType, const char * shaderFilePath);
GLuint CreateProgram(const std::vector<GLuint> &shaderList);

#endif //SHADERPROGRAM_HPP