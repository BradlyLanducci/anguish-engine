#pragma once

#include <functional>

//------------------------------------------------------------------//

struct Signal
{
	void connect(const std::function<void()> &slot)
	{
		m_slots.push_back(slot);
	}

	void emit() const
	{
		for (const auto& slot : m_slots)
		{
			slot();
		}
	}

private:
	using Slot = std::function<void()>;
	std::vector<Slot> m_slots;
};

//------------------------------------------------------------------//
