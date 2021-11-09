#include "ContactEventManager.hh"
#include "GameObject.hh"
#include "Animation.hh"
#include<iostream>

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
    if(actorB->GetTagName().compare("slime") == 0)
    {
      gameObjectsDeleteList->push_back(actorA);
    }
    if(actorB->GetTagName().compare("bat") == 0)
    {
      gameObjectsDeleteList->push_back(actorA);
    }
    if(actorB->GetTagName().compare("elf") == 0)
    {
      gameObjectsDeleteList->push_back(actorA);
    }
    if(actorB->GetTagName().compare("apple") == 0)
    {
      std::cout<<"+1"<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }
    if(actorB->GetTagName().compare("orange") == 0)
    {
      std::cout<<"+1"<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }
    if(actorB->GetTagName().compare("strawberry") == 0)
    {
      std::cout<<"+1"<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }
    if(actorB->GetTagName().compare("cherry") == 0)
    {
      std::cout<<"+1"<<std::endl;
      gameObjectsDeleteList->push_back(actorB);
    }
  }
}
void ContactEventManager::EndContact(b2Contact* contact)
{

}