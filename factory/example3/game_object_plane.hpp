#ifndef _GAME_OBJECT_PLANE_
#define _GAME_OBJECT_PLANE_

#include <iostream>

#include "i_game_object.hpp"

/**
 * @brief Implementation of a object from the base class
 */
class GameObjectPlane : public IGameObject {
public:
    GameObjectPlane(int x, int y, int z) {
        ObjectsCreated++;
        std::cout << "Plane created" << std::endl;
    }
    void Update() {}
    void Render() {}

    /**
     * @brief We can use this as a callback function. See example 1
     * 
     * @return IGameObject* 
     */
    static IGameObject* Create() {
        return new GameObjectPlane(0,0,0);
    }

private:
    static int ObjectsCreated;
};

#endif // _GAME_OBJECT_PLANE_