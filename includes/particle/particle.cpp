#include "particle.h"
#include "../constants.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"

Particle::Particle() {
  int r_size = r.Next(1, 15);
  shape = sf::CircleShape(r_size);
  pos = sf::Vector2f(r.Next(0, WORK_PANEL), r.Next(0, SCREEN_HEIGHT));
  vel = sf::Vector2f(r.Next(-5, 5), r.Next(-5, 5)); // random velocity
  int r_ = r.Next(0, 255);
  int g_ = r.Next(0, 255);
  int b_ = r.Next(0, 255);
  shape.setFillColor(sf::Color(r_, g_, b_));
}

void Particle::move(){
  shape.move(vel);
}
