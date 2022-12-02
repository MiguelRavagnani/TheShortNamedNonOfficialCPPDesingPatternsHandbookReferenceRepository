#ifndef _I_GAME_OBJECT_
#define _I_GAME_OBJECT_

/**
 * @brief Base class interface for our to-be-constructed objects.
 *        Defines the base methods that must be implemented 
 */
class IGameObject {
public:
    virtual ~IGameObject() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif // _I_GAME_OBJECT_