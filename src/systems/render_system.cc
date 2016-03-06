#include "systems/render_system.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "assets/texture.h"
#include "core/window_manager.h"

RenderSystem::RenderSystem() {
  Texture::load("BLINK", "data/images/blink.png");
}

void RenderSystem::update(ex::EntityManager &entities,
                          ex::EventManager &events, double dt) {
  Texture::bind("BLINK");
  glEnable(GL_TEXTURE_2D);
  entities.each<Position, MVP>([dt](
      ex::Entity, Position &pos, MVP &mvp) {
    glPushMatrix();
      glTranslatef(pos.x, pos.y, 0);
      glColor3f(mvp.col.r, mvp.col.g, mvp.col.b); 
      glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(-mvp.r, -mvp.r);
        glTexCoord2f(1, 0); glVertex2f( mvp.r, -mvp.r);
        glTexCoord2f(1, 1); glVertex2f( mvp.r,  mvp.r);
        glTexCoord2f(0, 1); glVertex2f(-mvp.r,  mvp.r);
      glEnd();
    glPopMatrix();
  });
}
