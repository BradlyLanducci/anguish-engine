#include <physics/physics_manager.h>
#include <objects/collision_object.h>
#include <physics/aabb.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

constexpr float PHYSICS_INTERVAL = 1.f / 60.f;

//------------------------------------------------------------------//

std::vector<std::shared_ptr<Object>> PhysicsManager::m_objects;
std::vector<std::shared_ptr<CollisionObject>> PhysicsManager::m_collisionObjects;

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

const std::vector<std::shared_ptr<CollisionObject>>& PhysicsManager::getCollisionObjects()
{
	return m_collisionObjects;
}

//------------------------------------------------------------------//

void PhysicsManager::addCollisionObject(std::shared_ptr<CollisionObject> collisionObject)
{
	m_collisionObjects.push_back(collisionObject);
	LOG(INFO) << "Added collision object now we have " << m_collisionObjects.size() << " objects";
}

//------------------------------------------------------------------//

void PhysicsManager::addObject(std::shared_ptr<Object> object)
{
	m_objects.push_back(object);
	LOG(INFO) << "Added object " << object << " now we have " << m_objects.size() << " objects";
}

//------------------------------------------------------------------//

void PhysicsManager::update(float currentTime)
{
	static float lastTime = 0.f;

	if (currentTime - lastTime >= PHYSICS_INTERVAL)
	{
		const float delta{currentTime - lastTime};
		lastTime = currentTime;

		// Call physics update
		for (const auto& o : m_objects)
		{
			o->physicsUpdate(delta);
		}

		// Collect collisions
		// std::vector<Collision> collisions;
		for (const auto& co1 : m_collisionObjects)
		{
			for (const auto& co2 : m_collisionObjects)
			{
				if (co1 != co2)
				{
					Rect r1 = co1->rect();
					Rect r2 = co2->rect();
					if (AABB::aabb(r1, r2))
					{
						LOG(INFO) << "A collison has occurred!";
						// collisions.push_back(co1, co2);
						Rect r1 = co1->rect();
						Rect r2 = co2->rect();
						if (AABB::aabb(r1, r2))
						{
							Vector2 offset = AABB::collide(r1, r2);
							co1->setGlobalPosition(co1->globalPosition() + offset);
							co1->setGlobalPosition(Vector2(std::round(co1->globalPosition().x), std::round(co1->globalPosition().y)));
						}
					}
				}
			}
		}

		// for (const auto& collision : collisions)
		// {
		// handle collisions
		// }
	}
}

//------------------------------------------------------------------//
