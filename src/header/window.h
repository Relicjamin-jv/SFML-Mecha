#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
class Window {
public:
  Window();
  Window(const std::string &l_title, const sf::Vector2u &l_size);
  ~Window();

  void BeginDraw();
  void EndDraw();

  void Update();

  bool IsDone();
  bool IsFullScreen();
  sf::Vector2u GetWindowSize();

  void toggleFullScreen();

  void Draw(sf::Drawable &l_drawable);

private:
  void SetUp(const std::string &l_title, const sf::Vector2u &l_size);
  void Destroy();
  void Create();

  sf::RenderWindow m_window;
  sf::Vector2u m_windowSize;
  std::string m_windowTitle;
  bool m_isDone;
  bool m_isFullScreen;
};
