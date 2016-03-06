#ifndef SWAPIT_ASSETS_TEXTURE_H_
#define SWAPIT_ASSETS_TEXTURE_H_

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

class Texture {
 public:
  static bool load(const std::string& texture_ID, const std::string& path);

  static sf::Texture* get(const std::string& texture_ID);

  static void bind(const std::string& texture_ID);

 private:
  static std::map<std::string, sf::Texture*> textures_;
};

#endif  // SWAPIT_ASSETS_TEXTURE_H_
