#include "particle.h"
#include "../constants.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

Particle::Particle() {
  int r_size = r.Next(5, 25);
  shape = sf::CircleShape(r_size);
  pos = sf::Vector2f(r.Next(0, WORK_PANEL), r.Next(0, SCREEN_HEIGHT));
  shape.setPosition(pos);
  vel = sf::Vector2f(r.Next(-15, 15), r.Next(-15, 15)); // random velocity
  int r_ = r.Next(0, 255);
  int g_ = r.Next(0, 255);
  int b_ = r.Next(0, 255);
  shape.setFillColor(sf::Color(r_, g_, b_));
}

void Particle::move() { shape.move(vel); }

void Particle::apply_force() {
  sf::Vector2f pos = shape.getPosition();
  if ((pos.x) >= WORK_PANEL - 20)
    vel = sf::Vector2f(-1 * vel.x, 1 * vel.y);
  if (pos.x <= 0)
    vel = sf::Vector2f(-1 * vel.x, 1 * vel.y);
  if ((pos.y) >= SCREEN_HEIGHT - 20)
    vel = sf::Vector2f(1 * vel.x, -1 * vel.y);
  if (pos.y <= 0)
    vel = sf::Vector2f(1 * vel.x, -1 * vel.y);
}

void Particle::draw(sf::RenderWindow &window) { window.draw(shape); }
