#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static constexpr uint16_t WINDOW_WIDTH = 800;

static constexpr uint16_t WINDOW_HEIGHT = 600;

static const char *WINDOW_TITLE = "Learning OpenGL";

void error_callback(int, const char *);

int main(void) {
  if (!glfwInit()) {
    return EXIT_FAILURE;
  }

  if (!glewInit()) {
    glfwTerminate();

    return EXIT_FAILURE;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwSetErrorCallback(error_callback);

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
                                        WINDOW_TITLE, nullptr, nullptr);

  if (!window) {
    glfwTerminate();

    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(10.F / 255.F, 10.F / 255.F, 10.F / 255.F, 1.F);

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();

    int32_t state = glfwGetKey(window, GLFW_KEY_ESCAPE);

    if (state == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }

  glfwDestroyWindow(window);

  glfwTerminate();

  return EXIT_SUCCESS;
}

void error_callback(int _, const char *description) {
  fprintf(stderr, "%s\n", description);
}
