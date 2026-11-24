#ifndef SYSTEM_H
#define SYSTEM_H
#include "../particle/particle.h"
#include <SFML/Graphics.hpp>

using namespace std;
class System {
public:
  System();
  void Step(int command);
  int Size();
  void Draw(sf::RenderWindow &window);

private:
  vector<Particle> system;
  // sf::CircleShape shape;
  // sf::Vector2f vel;
};

#endif // SYSTEM_H
