#ifndef PARTICLE_H
#define PARTICLE_H
#include "../random/random.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

class Particle {
public:
  Particle();
  void move();
  void apply_force();
  void draw(sf::RenderWindow &window);

private:
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::CircleShape shape;
  sf::Color color;
  int size;
  Random r;
};

#endif // PARTICLE_H
