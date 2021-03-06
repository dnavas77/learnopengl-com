#pragma once
#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_Filepath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
	ShaderProgramSource ParseShader(const std::string& filepath);

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
	unsigned int CreateShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

	// Set uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& name, int value);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
};
