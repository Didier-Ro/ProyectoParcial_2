#include "Enemy.hh"



Enemy::Enemy(std::string textureUrl, float scale, int width, int height, int column, int row, float posX, float posY, float enemySpeed,
b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window, float maxTime, sf::Vector2f direction) :
GameObject(textureUrl, scale, width, height, column, row, posX, posY, bodyType, world, window)
{
  this->enemySpeed = enemySpeed;
  this->maxTime = maxTime;
  this->direction = direction;

  //animationEnemySystem = new AnimationSystem{};

  //animationEnemySystem->AddAnimation("idleEnemy",new Animation(sprite, "assets/animations/player/idleEnemy.anim"));
  
  

  rigidbody->FreezeRotation(true);
}

Enemy::~Enemy()
{
}

sf::Sprite* Enemy::GetEnemySprite() const
{
  return sprite;
}


void Enemy::Update(float& deltaTime)
{
  //animationEnemySystem->Update(deltaTime);
  GameObject::Update(deltaTime);
  currentTime += deltaTime;
  /*rigidbody->GetBody()->SetLinearVelocity(b2Vec2(direction.x * enemySpeed,
  direction.y * enemySpeed));*/
  if(currentTime>=maxTime){
    direction = sf::Vector2f(-direction.x,  direction.y);
    currentTime=0.f;

  }
}

void Enemy::Draw()
{
  GameObject::Draw();
}
