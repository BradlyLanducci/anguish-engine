#include <physics/physics_manager.h>
#include <physics/physics_object.h>

#include <glog/logging.h>

constexpr float PHYSICS_INTERVAL = 1.f / 60.f;

//------------------------------------------------------------------//

std::vector<std::shared_ptr<Object>> PhysicsManager::m_objects;

//------------------------------------------------------------------//

void PhysicsManager::destroy()
{
	m_objects.clear();
}

//------------------------------------------------------------------//

PhysicsManager& PhysicsManager::get()
{
	static PhysicsManager p;
	return p;
}

//------------------------------------------------------------------//

void PhysicsManager::addObject(std::shared_ptr<Object> object)
{
	m_objects.push_back(object);
	LOG(INFO) << "Added object now we have " << m_objects.size() << " objects";
}

//------------------------------------------------------------------//

void PhysicsManager::update(float currentTime)
{
	static float lastTime = 0.f;

	if (currentTime - lastTime >= PHYSICS_INTERVAL)
	{
		lastTime = currentTime;
		for (const auto& o : m_objects)
		{
			std::shared_ptr<PhysicsObject> po = std::dynamic_pointer_cast<PhysicsObject>(o);
			if (po)
			{
				po->physicsUpdate();
			}
		}
	}
}

//------------------------------------------------------------------//
