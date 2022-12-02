#ifndef _FACTORY_GAME_OBJECTS_
#define _FACTORY_GAME_OBJECTS_

#include <memory>
#include <iostream>

#include "plane_object.hpp"
#include "boat_object.hpp"

/**
 * @brief Defines the types known by the factory
 */
enum class ObjectType {PLANE, BOAT};

/**
 * @brief Facotry Class. A singleton class that can build and return
 *        an instance for a objects known. Keeps counts of every built
 *        instance.
 */
class FactoryGameObjects {
public:
    /**
     * @brief Object creator
     * 
     * @param type The object type known by the class (defined in enum class ObjectType)
     * @return std::shared_ptr<IGameObject> Pointer to the instance
     */
    static std::shared_ptr<IGameObject> CreateObject(ObjectType type) {
        switch (type)
        {
        case ObjectType::PLANE: {
            s_plane++;
            return std::make_shared<PlaneObject>();
            break;
        }
        case ObjectType::BOAT: {
            s_boat++;
            return std::make_shared<BoatObject>();
            break;
        } 
        default: {
            return nullptr;
            break;
        }
        }
    }

    /**
     * @brief Prints the an instance count for every object
     */
    static void PrintCounts() {
        std::cout << "planes: " << s_plane << std::endl;
        std::cout << "boats: " << s_boat << std::endl;
    }

private:
    FactoryGameObjects() {}
    ~FactoryGameObjects() {}

    /**
     * @brief Boo, copy constructors
     *        Boooooo, singletons
     * @param o Did this care you?
     */
    FactoryGameObjects(const FactoryGameObjects& o) {}

    static int s_plane;
    static int s_boat;
};

int FactoryGameObjects::s_plane = 0;
int FactoryGameObjects::s_boat = 0;

#endif // _FACTORY_GAME_OBJECTS_