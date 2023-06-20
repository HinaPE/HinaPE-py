#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <pybind11/pybind11.h>

auto load_window(int width, int height) -> void
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "HinaPE is not a Physics Engine", NULL, NULL);
	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}

namespace py = pybind11;

PYBIND11_MODULE(HinaPE, m)
{
	m.def("load_window", &load_window, R"pbdoc(
		Load a GLFW window
    )pbdoc");

	m.attr("__version__") = "dev";
}
