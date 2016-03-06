#include "core/app.h"

#include "systems/spawn_system.h"

App::App() {
}

App::~App() {
}

void App::init() {
  systems.add<MovementSystem>();
  systems.add<SpawnSystem>();
  systems.add<RenderSystem>();
  systems.configure();
}

void App::run() {
  WindowManager::create();
  
  sf::Clock clock;
  while (WindowManager::isOpen()) {
    sf::Event event;
    while (WindowManager::pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        WindowManager::close();
      if (event.type == sf::Event::MouseButtonPressed) {
        events.emit<MouseDownEvent>(event.mouseButton.x, event.mouseButton.y);
      }
    }
    
    double dt = clock.restart().asSeconds();

    glClear(GL_COLOR_BUFFER_BIT);

    draw(dt);
    update(dt);
    
    WindowManager::display();
  }
}

void App::update(double dt) {
  systems.update<MovementSystem>(dt);
  systems.update<SpawnSystem>(dt);
}

void App::draw(double dt) {
  systems.update<RenderSystem>(dt);
}
