#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "shaderProgram.hpp"

//#include <glload/gl_3_2_comp.h>
//#include <GL/freeglut.h>

// #include <glfw3.h>

#include <glm/glm.hpp>
using namespace glm;

GLuint compileShader(GLenum eShaderType, const char * shaderFilePath)
{
	GLuint shader = glCreateShader(eShaderType);

	std::string shaderCode;
	std::ifstream shaderStream(shaderFilePath, std::ios::in);
	if (shaderStream.is_open()){
		std::string Line = "";
		while (getline(shaderStream, Line))
			shaderCode += "\n" + Line;
		shaderStream.close();
	}
	else{
		printf("Impossible to open %s.", shaderFilePath);
		getchar();
		return 0;
	}

	const char *shaderCodeChar = shaderCode.c_str();

	glShaderSource(shader, 1, &shaderCodeChar, NULL);

	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE){
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0){
			std::vector<char> ShaderErrorMessage(infoLogLength + 1);
			glGetShaderInfoLog(shader, infoLogLength, NULL, &ShaderErrorMessage[0]);
            printf("%s - shader error msg.\n", &ShaderErrorMessage[0]);
		}
	}

	return shader;
}

GLuint linkShaderProgram(const std::vector<GLuint> &shaderList)
{
	GLuint program = glCreateProgram();

	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glAttachShader(program, shaderList[iLoop]);

	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glDetachShader(program, shaderList[iLoop]);

	return program;
}
