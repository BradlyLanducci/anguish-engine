#pragma once

#include <objects/item.h>
#include <utilities/data_structures.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>

#include <functional>

//------------------------------------------------------------------//

class Object : public Item
{
public:
	Object();
	~Object();

	void addChild(Object* child);
	Object* getParent() const;

	void idleUpdate(float delta);
	void physicsUpdate(float delta);

	Rect rect() const;
	Vector2 globalPosition() const;
	Vector2 size() const;
	Vector2 scale() const;

	void setRect(Rect rect);
	void setGlobalPosition(Vector2 globalPosition);
	void setSize(Vector2 size);
	void setScale(Vector2 scale);

protected:
	void addIdleCb(std::function<void(float)> cb);
	void addPhysicsCb(std::function<void(float)> cb);
	void setParent(Object* parent);

	Object* m_parent{nullptr};
	Rect m_rect;

private:
	std::vector<Object*> m_children;
	std::vector<std::function<void(float)>> m_idleCbs;
	std::vector<std::function<void(float)>> m_physicsCbs;
};

//------------------------------------------------------------------//
