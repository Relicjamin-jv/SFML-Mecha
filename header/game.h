#include "../header/window.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Game {
public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();
  Window *GetWindow();

  sf::Texture m_mushroomTexture;
  sf::Sprite m_mushroom;
  sf::Vector2i m_increment;

private:
  void Move();
  Window m_window;
};
