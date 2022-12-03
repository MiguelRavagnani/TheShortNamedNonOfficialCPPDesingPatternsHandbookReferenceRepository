#ifndef _GAME_OBJECTS_FACTORY_
#define _GAME_OBJECTS_FACTORY_

#include <memory>
#include <iostream>
#include <map>

/**
 * @brief Declares the class interface in a way that prevents
 *        the need for multiple includes
 */
class IGameObject;

/**
 * @brief Facotry Class. A singleton class that can build and return
 *        an instance for a objects known. Keeps counts of every built
 *        instance.
 */
class GameObjectFactory {

    /**
     * @brief Callback function. Defines how a object will be created, by
     *        allowing exported definitions
     */
    typedef IGameObject* (*CreateObjectCallback)();
public:

    /**
     * @brief Recieves a typename as an object, and takes a callback function
     *        that defines how the object should be created. This is what makes
     *        the factory extensible. Neat
     * 
     * @param type The type, as a string
     * @param cb The callback
     */
    static void RegisterObject(const std::string& type, CreateObjectCallback cb);

    /**
     * @brief Undo the registration
     * 
     * @param type The type, as a string
     */
    static void UnregisterObject(const std::string& type);

    /**
     * @brief Actually uses the factory 
     * 
     * @param type The type which we want an instance of
     * @return IGameObject* The object
     */
    static IGameObject* CreateSingleObject(const std::string& type);

private:

    /**
     * @brief Typedef to make things simple
     */
    typedef std::map<std::string, CreateObjectCallback> CallBackMap;

    /**
     * @brief Stores all of the objects we can create. It is
     *        shared between factories
     */
    static CallBackMap s_Objects;
};

#endif // _GAME_OBJECTS_FACTORY_