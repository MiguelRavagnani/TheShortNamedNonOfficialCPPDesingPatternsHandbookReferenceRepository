#include "factory_game_objects.hpp"

int main() {
    /* So much for being afraid of using new */
    std::shared_ptr<IGameObject> object1 = FactoryGameObjects::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> object2 = FactoryGameObjects::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> object3 = FactoryGameObjects::CreateObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> object4 = FactoryGameObjects::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> object5 = FactoryGameObjects::CreateObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> object6 = FactoryGameObjects::CreateObject(ObjectType::PLANE);

    FactoryGameObjects::PrintCounts();

    return 0;
}