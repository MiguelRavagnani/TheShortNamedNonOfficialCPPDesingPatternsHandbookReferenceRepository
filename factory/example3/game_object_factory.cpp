#include "game_object_factory.hpp"
#include "i_game_object.hpp"

/**
 * @brief Important. Instantiate the static map of objects
 */
GameObjectFactory::CallBackMap GameObjectFactory::s_Objects;

void GameObjectFactory::RegisterObject(const std::string& type, CreateObjectCallback cb) {
    s_Objects[type] = cb;
}

void GameObjectFactory::UnregisterObject(const std::string& type) {
    s_Objects.erase(type);
}

IGameObject* GameObjectFactory::CreateSingleObject(const std::string& type) {
    /* OK, I think I would not want to use an iterator here. Can be improved */
    CallBackMap::iterator it = s_Objects.find(type);
    if(it!=s_Objects.end()) {
        return (it->second)();
    }
    return nullptr;
}