/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /_seams/_main.cpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights
reserved (R). This Source Code Form is subject to the terms of the Mozilla
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */

//#include <_config.h>
// using namespace _;

#include <fstream>
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

const GLint cWidth = 800, cHeight = 600;

const GLchar* cVertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main() {\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}";

const GLchar* cFragmentShaderSource =
    "#version 330 core\n"
    "out vec4 color;\n"
    "void main() {\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}";

int main(const char** args, int arg_count) {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* window = glfwCreateWindow(cWidth, cHeight, "Kabuki Toolkit demo.",
                                        nullptr, nullptr);
  int screen_width, screen_height;

  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &cVertexShaderSource, NULL);
  glCompileShader(vertex_shader);

  GLint success;
  const GLint cInfoLogSize = 512;
  GLchar info_log[512];

  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex_shader, cInfoLogSize, NULL, info_log);
    std::cout << "\nERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << info_log << '\n';
  }

  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &cFragmentShaderSource, NULL);
  glCompileShader(fragment_shader);

  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment_shader, cInfoLogSize, NULL, info_log);
    std::cout << "\nERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log;
  }

  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);
  glLinkProgram(shader_program);

  glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

  if (!success) {
    glGetProgramInfoLog(shader_program, cInfoLogSize, NULL, info_log);
    std::cout << "\nERROR::SHAADER::PROGRAM"
                 "LINKING_FAILED\n"
              << info_log;
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  GLfloat verticies[] = {-0.5f, -0.5f, 0.0f,  // bottom left
                         0.5,   -0.5,  0.0,   //
                         0.0f,  0.5f,  0.0f};

  glfwGetFramebufferSize(window, &screen_width, &screen_height);

  if (!window) {
    std::cout << "\n\nFailed to create GLFW window.\n\n";

    glfwTerminate();

    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    std::cout << "\n\nFailed to initialize GLEW.\n\n";
  }

  glViewport(0, 0, screen_width, screen_height);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  std::cout << "\n\nCompleted successfully.\n\n";

  return EXIT_SUCCESS;
}
