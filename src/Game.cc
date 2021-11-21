#include "CommonHeaders.hh"
#include "Player.hh"
#include "TileGroup.hh"


sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
GameObject* chest1{};
GameObject* light1{};
GameObject* slime1{};
GameObject* bat1{};
GameObject* elf1{};
GameObject* apple{};
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
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 300, 450, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest");
  light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 500, 470, b2BodyType::b2_staticBody, world, window);
  light1->SetTagName("light");
  slime1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 0, 4, 200, 150, b2BodyType::b2_staticBody, world, window);
  slime1->SetTagName("slime");
  bat1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 0, 0, 700, 150, b2BodyType::b2_staticBody, world, window);
  bat1->SetTagName("bat");
  elf1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 0, 1, 205, 750, b2BodyType::b2_staticBody, world, window);
  elf1->SetTagName("elf");
  apple = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 0, 8, 450, 180, b2BodyType::b2_staticBody, world, window);
  apple->SetTagName("apple");
  orange = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 1, 8, 600, 450, b2BodyType::b2_staticBody, world, window);
  orange->SetTagName("orange");
  strawberry = new GameObject(ASSETS_SPRITES_PACMAN, 2.f, 32, 32, 2, 8, 450, 750, b2BodyType::b2_staticBody, world, window);
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
  AddGameObject(chest1);
  AddGameObject(light1);
  AddGameObject(slime1);
  AddGameObject(bat1);
  AddGameObject(elf1);
  AddGameObject(apple);
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

  textObj1->SetTextStr("Hello game engine");

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