#include <idle/idle_manager.h>
#include <objects/object.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

std::vector<Object*> IdleManager::m_objects;

//------------------------------------------------------------------//

void IdleManager::destroy()
{
	m_objects.clear();
}

//------------------------------------------------------------------//

IdleManager& IdleManager::get()
{
	static IdleManager p;
	return p;
}

//------------------------------------------------------------------//

void IdleManager::addObject(Object* object)
{
	m_objects.push_back(object);
	LOG(INFO) << "Added object " << object << " now we have " << m_objects.size() << " objects";
}

//------------------------------------------------------------------//

void IdleManager::update(float currentTime)
{
	static float lastTime = 0.f;

	const float delta{currentTime - lastTime};
	lastTime = currentTime;
	for (const auto& o : m_objects)
	{
		o->idleUpdate(delta);
	}
}

//------------------------------------------------------------------//
