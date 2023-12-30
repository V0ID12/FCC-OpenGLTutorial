#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Initalize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we want to use
	// We are using version 3.3 of OpenGL for this project
	// We are also telling GLFW to use the CORE profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Uses modern functions

	// Creates a GLFWwindow object of 800 by 800 pixels, naming it "OpenGLTutorial"
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGLTutorial", NULL, NULL);
	// If the window fails to create, terminate window and exit
	if (window == NULL) 
	{
		std::cout << "Failed to create the GLFW window...Exiting." << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of OpenGL in the window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);


	// Specify the coloring of the window background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Takes care of all the GLFW events
		glfwPollEvents();

	}

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before exiting the program
	glfwTerminate();
	// Exit program
	return 0;
}