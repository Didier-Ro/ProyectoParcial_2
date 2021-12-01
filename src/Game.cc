#include "CommonHeaders.hh"
#include "Player.hh"
#include "TileGroup.hh"
#include "Enemy.hh"

sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 30, sf::Color::Yellow, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
Enemy* enemy{};
Enemy* enemy2{};
Enemy* enemy3{};
Enemy* enemy4{};
GameObject* apple{};
GameObject* apple2{};
GameObject* orange{};
GameObject* strawberry{};
GameObject* cherry{};
GameObject* dot1{};
GameObject* dot2{};
GameObject* dot3{};
GameObject* dot4{};
GameObject* dot5{};
GameObject* dot6{};
GameObject* dot7{};
GameObject* dot8{};
GameObject* dot9{};
GameObject* dot10{};
GameObject* dot11{};
GameObject* dot12{};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();

  player1 = new Player(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 0, 450, 560, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");
  enemy = new Enemy(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 2, 360, 750, 200.f, b2BodyType::b2_dynamicBody, world, window, 2.4f,sf::Vector2f(1,0));
  enemy->SetTagName("Ghost");
  enemy2 = new Enemy(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 3, 180, 180, 200.f, b2BodyType::b2_dynamicBody, world, window, 4.f,sf::Vector2f(1,0));
  enemy2->SetTagName("Ghost");
  enemy3 = new Enemy(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 4, 205, 390, 200.f, b2BodyType::b2_dynamicBody, world, window, 2.f,sf::Vector2f(0,1));
  enemy3->SetTagName("Ghost");
  enemy4 = new Enemy(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 5, 685, 390, 200.f, b2BodyType::b2_dynamicBody, world, window, 2.f,sf::Vector2f(0,1));
  enemy4->SetTagName("Ghost");
  apple = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 8, 500, 50, b2BodyType::b2_staticBody, world, window);
  apple->SetTagName("apple");
  apple2 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 8, 400, 50, b2BodyType::b2_staticBody, world, window);
  apple2->SetTagName("apple");
  orange = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 1, 8, 600, 450, b2BodyType::b2_staticBody, world, window);
  orange->SetTagName("orange");
  strawberry = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 2, 8, 450, 940, b2BodyType::b2_staticBody, world, window);
  strawberry->SetTagName("strawberry");
  cherry = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 3, 8, 700, 850, b2BodyType::b2_staticBody, world, window);
  cherry->SetTagName("cherry");
  dot1 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 600, 355, b2BodyType::b2_staticBody, world, window);
  dot1->SetTagName("Dot");
  dot2 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 300, 355, b2BodyType::b2_staticBody, world, window);
  dot2->SetTagName("Dot");
  dot3 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 485, 650, b2BodyType::b2_staticBody, world, window);
  dot3->SetTagName("Dot");
  dot4 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 410, 650, b2BodyType::b2_staticBody, world, window);
  dot4->SetTagName("Dot");
  dot5 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 600, 285, b2BodyType::b2_staticBody, world, window);
  dot5->SetTagName("Dot");
  dot6 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 300, 285, b2BodyType::b2_staticBody, world, window);
  dot6->SetTagName("Dot");
  dot7 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 860, 285, b2BodyType::b2_staticBody, world, window);
  dot7->SetTagName("Dot");
  dot8 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 35, 285, b2BodyType::b2_staticBody, world, window);
  dot8->SetTagName("Dot");
  dot9 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 35, 650, b2BodyType::b2_staticBody, world, window);
  dot9->SetTagName("Dot");
  dot10 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 860, 650, b2BodyType::b2_staticBody, world, window);
  dot10->SetTagName("Dot");
  dot11 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 600, 855, b2BodyType::b2_staticBody, world, window);
  dot11->SetTagName("Dot");
  dot12 = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 9, 300, 855, b2BodyType::b2_staticBody, world, window);
  dot12->SetTagName("Dot");

  
  tileGroup = new TileGroup(window, 30, 31, ASSETS_MAPS, 2.f, 16, 16, ASSETS_MAP_PACMAN);

  contactEventManager = new ContactEventManager(gameObjects, gameObjectsDeleteList);
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);

  AddGameObject(player1);
  AddGameObject(enemy);
  AddGameObject(enemy2);
  AddGameObject(enemy3);
  AddGameObject(enemy4);
  AddGameObject(apple);
  AddGameObject(apple2);
  AddGameObject(orange);
  AddGameObject(strawberry);
  AddGameObject(cherry);
  AddGameObject(dot1);
  AddGameObject(dot2);
  AddGameObject(dot3);
  AddGameObject(dot4);
  AddGameObject(dot5);
  AddGameObject(dot6);
  AddGameObject(dot7);
  AddGameObject(dot8);
  AddGameObject(dot9);
  AddGameObject(dot10);
  AddGameObject(dot11);
  AddGameObject(dot12);

  textObj1->SetTextStr("The Amazing PacMan");

  /*circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);*/
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

  //circle->setPosition(player1->GetSprite()->getPosition());

  //lightIdle->Play(deltaTime);

  /*if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }*/
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  for(auto& gameobject: *gameObjectsDeleteList)
  {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameobject), gameObjects->end());
      delete gameobject;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  //player1->Draw();
  //window->draw(*circle);

  tileGroup->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
  //world->DebugDraw();
}

//Keyboard, joysticks, etc.
void Game::Input()
{
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}