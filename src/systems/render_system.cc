#include "systems/render_system.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "core/window_manager.h"

RenderSystem::RenderSystem() {
}

void RenderSystem::update(ex::EntityManager &entities,
                          ex::EventManager &events, double dt) {
  entities.each<Position, MVP>([dt](
      ex::Entity, Position &pos, MVP &mvp) {
    /*sf::CircleShape shape;
    shape.setPosition(pos.x, pos.y);
    shape.setRadius(mvp.r);
    shape.setFillColor(sf::Color(mvp.col.r*255, mvp.col.g*255,mvp.col.b*255));
    WindowManager::Draw(shape);*/
    glPushMatrix();
      glTranslatef(pos.x, pos.y, 0);
      glColor3f(mvp.col.r, mvp.col.g, mvp.col.b);
      glBegin(GL_QUADS);
        glVertex2f(-mvp.r, -mvp.r);
        glVertex2f( mvp.r, -mvp.r);
        glVertex2f( mvp.r,  mvp.r);
        glVertex2f(-mvp.r,  mvp.r);
      glEnd();
    glPopMatrix();
  });
}
