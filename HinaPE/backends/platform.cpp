#include "glad/glad.h" // include glad before glfw
#include "GLFW/glfw3.h"
#include "platform.h"

auto Kasumi::Platform::Init() -> void
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize GLAD");
}

auto Kasumi::Platform::NewWindow(int width, int height, const std::string &title) -> int
{
	GLFWwindow *window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	WINDOWS.emplace_back(window);
	return static_cast<int>(WINDOWS.size()) - 1;
}

auto Kasumi::Platform::KillWindow(int window_id) -> void
{
	glfwDestroyWindow(WINDOWS.at(window_id));
	WINDOWS.at(window_id) = nullptr;
}

auto Kasumi::Platform::SetCurrentWindow(int window_id) -> void
{
	if (!_CheckValid(window_id))
		return;
	CURRENT_WINDOW = WINDOWS.at(window_id);
}

auto Kasumi::Platform::_CheckValid(int window_id) -> bool
{
	if (WINDOWS.size() <= window_id)
		return false;
	if (WINDOWS.at(window_id) == nullptr)
		return false;
	return true;
}
