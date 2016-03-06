#include "core/window_manager.h"

#include <SFML/OpenGL.hpp>
#include "global.h"

sf::RenderWindow WindowManager::render_window_;

void WindowManager::create() {
  render_window_.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Title");
  render_window_.setFramerateLimit(30);

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

bool WindowManager::isOpen() {
  return render_window_.isOpen();
}

void WindowManager::close() {
  render_window_.close();
}

bool WindowManager::pollEvent(sf::Event &event) {
  return render_window_.pollEvent(event);
}

void WindowManager::clear() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::draw(const sf::Drawable& drawable,
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

void WindowManager::display() {
  render_window_.display();
}
