#ifndef PARTICLE_H
#define PARTICLE_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include "../random/random.h"


class Particle{
public:
  Particle();
  void move(sf::Vector2f vel);
  void draw(sf::RenderWindow & window);
  void apply_force();

private:
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::CircleShape shape;
  sf::Color color;
  int size;
  Random r;


};

#endif // PARTICLE_H
