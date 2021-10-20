#include "gshader.h"

Shader::Shader(const char* vsPath, const char* psPath)
{
	// Part 1: Read source code
	std::string _vsCode;
	std::string _psCode;

	std::ifstream vsFile;
	std::ifstream psFile;

	try
	{
		// open files
		vsFile.open(vsPath);
		psFile.open(psPath);
		std::stringstream vsStream;
		std::stringstream psStream;
		// read file buffer
		vsStream << vsFile.rdbuf();
		psStream << psFile.rdbuf();
		vsFile.close();
		psFile.close();
		// convert stream into stringh
		_vsCode = vsStream.str();
		_psCode = psStream.str();
	}
	catch (std::ifstream::failure e)
	{
		printf("ERROR: Shader not read successfully\n");
	}
	const char *vsCode = _vsCode.c_str();
	const char *psCode = _psCode.c_str();

	//printf("%s", vsCode);
	//printf("%s", psCode);

	// Part 2: Compile shaders
	unsigned int vertex, pixel;

	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vsCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	// pixel Shader
	pixel = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(pixel, 1, &psCode, NULL);
	glCompileShader(pixel);
	checkCompileErrors(pixel, "pixel");

	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, pixel);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(pixel);
}


void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}


// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			//std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			_ASSERT(0);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			//std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			_ASSERT(0);
		}
	}
}
