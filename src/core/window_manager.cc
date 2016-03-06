#include "core/window_manager.h"

#include <SFML/OpenGL.hpp>
#include "global.h"

sf::RenderWindow WindowManager::render_window_;

void WindowManager::Create() {
  render_window_.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Title");
  render_window_.setFramerateLimit(30);

  // OpenGl gluposti
  glClearColor(0, 0, 0, 0);
  glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, WIN_WIDTH, WIN_HEIGHT, 0, -10, 10);

  glDisable(GL_LIGHTING);
  glDisable(GL_POLYGON_SMOOTH);
  glDisable(GL_LINE_SMOOTH);
  glDisable(GL_POINT_SMOOTH);
  glDisable(GL_ALPHA_TEST);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_SCISSOR_TEST);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClear(GL_COLOR_BUFFER_BIT);
}

bool WindowManager::IsOpen() {
  return render_window_.isOpen();
}

void WindowManager::Close() {
  render_window_.close();
}

bool WindowManager::PollEvent(sf::Event &event) {
  return render_window_.pollEvent(event);
}

void WindowManager::Clear() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::Draw(const sf::Drawable& drawable,
                         const sf::RenderStates& states,
                         sf::Shader *shader) {
  glPushMatrix();
  render_window_.pushGLStates();
  render_window_.setActive(true);
  glEnable(GL_TEXTURE_2D);
  render_window_.draw(drawable, states);
  render_window_.popGLStates();
  glPopMatrix();
}

void WindowManager::Display() {
  render_window_.display();
}
