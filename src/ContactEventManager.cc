#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>

int score = 0;

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
    if(actorB->GetTagName().compare("orange")||actorB->GetTagName().compare("strawberry")||actorB->GetTagName().compare("cherry")||actorB->GetTagName().compare("apple"))
    {
      gameObjectsDeleteList->push_back(actorB);
      score = score + 100;
      std::cout<<score<<std::endl;
    }
    if(actorB->GetTagName().compare("Dot"))
    {
      score = score + 500;
      std::cout<<score<<std::endl;
    }   
  }
}

void ContactEventManager::EndContact(b2Contact* contact)
{

}