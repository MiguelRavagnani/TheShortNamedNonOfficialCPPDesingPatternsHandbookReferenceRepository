#ifndef _GAME_OBJECT_BOAT_
#define _GAME_OBJECT_BOAT_

#include <iostream>

#include "i_game_object.hpp"

/**
 * @brief Implementation of a object from the base class
 */
class GameObjectBoat : public IGameObject {
public:
    GameObjectBoat(int x, int y) {
        ObjectsCreated++;
        std::cout << "Boat created" << std::endl;
    }
    void Update() {}
    void Render() {}

    /**
     * @brief We can use this as a callback function. See example 1
     * 
     * @return IGameObject* 
     */
    static IGameObject* Create() {
        return new GameObjectBoat(0,0);
    }

private:
    static int ObjectsCreated;
};

#endif // _GAME_OBJECT_BOAT_