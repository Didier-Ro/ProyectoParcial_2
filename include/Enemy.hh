#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Rigidbody.hh"
#include "GameObject.hh"
#include "AnimationSystem.hh"

class Enemy : public GameObject
{
private:
  float enemySpeed{};
  float currentTime{};
  float maxTime{};

  sf::Vector2f direction{};

  void FlipSprite();
  AnimationSystem* animationSystem{};

public:
  Enemy(std::string textureUrl, float scale, int width, int height, int column, int row, float posX, float posY, float enemySpeed,
  b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window, float maxTime, sf::Vector2f direction);
  ~Enemy();
  sf::Sprite* GetSprite() const;

  void Update(float& deltaTime) override;
  void Draw() override;
};
