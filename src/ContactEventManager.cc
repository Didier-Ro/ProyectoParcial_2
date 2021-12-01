#include "ContactEventManager.hh"
#include "GameObject.hh"
#include <iostream>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& gameObjects, std::vector<GameObject*>*& gameObjectsDeleteList)
{
  this->gameObjects = gameObjects;
  this->gameObjectsDeleteList = gameObjectsDeleteList;
}

ContactEventManager::~ContactEventManager()
{
  
}

void ContactEventManager::BeginContact(b2Contact* contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(actorA && actorB)
  {
    std::cout << "Collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    if(actorB->GetTagName().compare("Ghost") == 0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout<<"Game Over"<<std::endl;
    }  
    if(actorB->GetTagName().compare("Strawberry") == 0)
    {
      score = score + 500;
      std::cout<<score<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }

    if(actorB->GetTagName().compare("Orange") == 1)
    {
      score = score + 500;
      std::cout<<score<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }

    if(actorB->GetTagName().compare("Apple") == 0)
    {
      score = score + 500;
      std::cout<<score<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }

    if(actorB->GetTagName().compare("Cherry") == 0)
    {
      score = score + 500;
      std::cout<<score<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }

    if(actorB->GetTagName().compare("Dot") == 0)
    {
      score = score + 100;
      std::cout<<score<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }

    if(score >= 3700)
    {
      std::cout<<"You Win"<<std::endl;
    }
  }
}

void ContactEventManager::EndContact(b2Contact* contact)
{
}