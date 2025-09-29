#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

/// @brief Manages all objects idle time in the engine
class IdleManager
{
public:
    static IdleManager &get();
    static void addObject(Object *object);
    static void update(float currentTime);

    IdleManager(const IdleManager &) = delete;
    IdleManager &operator=(const IdleManager &) = delete;

private:
    IdleManager() = default;
    ~IdleManager() = default;

    static std::vector<Object *> m_objects;
};

//------------------------------------------------------------------//
