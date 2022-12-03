#include <vector>
#include <fstream>

#include "game_object_factory.hpp"
#include "game_object_boat.hpp"
#include "game_object_plane.hpp"

class GameObjectCar : public IGameObject {
public:
    GameObjectCar(int x, int y) {
        ObjectsCreated++;
        std::cout << "Car created" << std::endl;
    }
    void Update() {}
    void Render() {}

    /**
     * @brief We can use this as a callback function. See example 1
     * 
     * @return IGameObject* 
     */
    static IGameObject* Create() {
        return new GameObjectCar(0,0);
    }

private:
    static int ObjectsCreated;
};

int GameObjectCar::ObjectsCreated = 0;

int main() {

    /* Register new types in the factory, and the callback that must be used to create them */
    GameObjectFactory::RegisterObject("plane", GameObjectPlane::Create);
    GameObjectFactory::RegisterObject("boat", GameObjectBoat::Create);
    GameObjectFactory::RegisterObject("car", GameObjectCar::Create);

    /* Vectors to store the game objects */
    std::vector<IGameObject*> gameObjectCollection;

    std::string line;
    std::ifstream myFile("../level_file.txt");

    if (myFile.is_open()) {
        while (std::getline(myFile, line)) {
            /* Looks for a object type in the file. If one is found in a line, calls the factory to
               create an instance from the registered callback */
            IGameObject* object = GameObjectFactory::CreateSingleObject(line);

            /* Adds it to the vector */
            gameObjectCollection.push_back(object);
        }
    }

    while (true) {
        for (auto& gameObject: gameObjectCollection) {
            gameObject->Update();
            gameObject->Render();
        }
    }

    return 0;
}