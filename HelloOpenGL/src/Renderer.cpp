#include "Renderer.h"

#include <iostream>

void GLClearError() {

	while (glGetError());
}

bool GLLogCall(const char* function, const char* file, int line) {

	while (GLenum error = glGetError()) {
	std::cout << "[OpenGL Error] (" << error << ") " << function << " " << file << " " << line << "\n";
		return false;
	}
	return true;
}

void Renderer::Clear() const
{
	GLCALL(glClearColor(0.2f,0.4f, 0.8f, 1.0f));
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const
{
	shader.Bind();
	
	va.Bind();
	ib.Bind();
	
	GLCALL(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0));
	//GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}
