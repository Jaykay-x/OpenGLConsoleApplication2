#include "Shader_Loader.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace Core;

Shader_Loader::Shader_Loader(void) {}
Shader_Loader::~Shader_Loader£¨void){}

std::string Shader_Loader::ReadShader(char *filename) 
{
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);

	if (£¡file.good())
	{
		std::cout << "Can't read file " << filename << std::endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();
	return shaderCode;
}

GLuint Shader_Loader::CreateShader(GLenum shaderType, std::string source, char* shaderName)
{
	int compile_result = 0;
	CLuint shader = glCreateShader(shaderType);
	const char *shader_code_ptr = source.c_str();
	const int shader_code_size = source.size();

	glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMILE_STATUS, &compile_result);

	//check for errors
	if (compile_result==GL_FALSE)
	{
		int info_log_longth = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_longth);
		std::vector<char> shader_log(info_log_longth);
		glGetShaderInfoLog(shader, info_log_longth, NULL, &shader_log);
		std::cout << "Error compile shader: " << shaderName << std::endl << &shader_log[0] << std::endl;
		return 0;
	}
	return shader;
}

GLuint Shader_Loader::CreateProgram(char* verterShaderFilename,
	char* fragmentShaderFilename) 
{
	std::string verter_shader_code = ReadShader(verterShaderFilename);
	std::string fragment_shader_code = ReadShader(fragmentShaderFilename);

	GLuint verter_shader = CreateShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
	GLuint fragment_shader = CreateShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

	int link_result = 0;
	GLuint program = glCreateProgram();
	glAttachShader(program, verter_shader);
	glAttachShader(program, fragment_shader);

	if (link_result == GL_FALSE)
	{
		int info_log_length = 0;
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		std::cout << "Shader Loader : LINK Error" << std::endl << &program_log[0] << std::endl;
		return 0;
	}
	return program;
}