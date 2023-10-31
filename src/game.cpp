#include "../header/game.h"
#include <SFML/System/Vector2.hpp>

Game::Game() : m_window("Second Chapter", sf::Vector2u(800, 400)) {
  m_mushroomTexture.loadFromFile(
      "/home/collin/Projects/SFML/mecha/sfml-mecha/resources/mushroom.png");
  m_mushroom.setTexture(m_mushroomTexture);
  m_increment = sf::Vector2i(4, 4);
}

Game::~Game() {}

void Game::Update() {
  m_window.Update();
  Move();
}

void Game::Move() {
  sf::Vector2u l_windowSize = m_window.GetWindowSize();
  sf::Vector2u l_textSize = m_mushroomTexture.getSize();

  if ((m_mushroom.getPosition().x > l_windowSize.x - l_textSize.x &&
       m_increment.x > 0) ||
      (m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
    m_increment.x = -m_increment.x;
  }

  if ((m_mushroom.getPosition().y > l_windowSize.y - l_textSize.y &&
           m_increment.y > 0 ||
       m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
    m_increment.y = -m_increment.y;
  }

  m_mushroom.setPosition(m_mushroom.getPosition().x + m_increment.x,
                         m_mushroom.getPosition().y + m_increment.y);
}

void Game::Render() {
  m_window.BeginDraw(); // clears the window
  m_window.Draw(m_mushroom);
  m_window.EndDraw(); // Show
}

Window *Game::GetWindow() { return &m_window; }

void Game::HandleInput() {}
