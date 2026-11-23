#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Sidebar {
public:
  Sidebar();
  Sidebar(float left, float width);
  void draw(sf::RenderWindow &window);
  std::string &operator[](int index);

private:
  sf::RectangleShape rect;        // sidebar rectagle
  std::vector<std::string> items; // strings to place on side bar
  sf::Font font;                  // used to draw text
  sf::Text sb_text;               // used to draw strings on the window object

  float _left;
  float _width;
};

#endif // !SIDEBAR_H
