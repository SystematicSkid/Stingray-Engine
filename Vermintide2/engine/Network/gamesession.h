#pragma once

class GameSession
{
public:
	
	void make_game_session_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 16))(this);
	}
	
	void shutdown_game_session_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 24))(this);
	}

	bool host_error()
	{
		return (*reinterpret_cast<bool(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 32))(this);
	}

	/// <summary>
	/// Makes local the host, only if host_error() returns true
	/// </summary>
	void migrate_game_session_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 40))(this); 
	}

	void disconnect_from_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 48))(this);
	}

	void add_peer(int peer_id)
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*, int)>(*reinterpret_cast<uintptr_t*>(this) + 56))(this, peer_id);
	}
	
	void remove_peer(int peer_id)
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*, int, void* /*callback*/)>(*reinterpret_cast<uintptr_t*>(this) +
			64))(this, peer_id, (void*)(Memory::SigScan("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 54 41 55 41 56 41 57 48 83 EC 50 48 8B 31 4C 8B F1", "Vermintide2.exe")));
	}

	void leave()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 72))(this);
	}

	int num_peers()
	{
		return (*reinterpret_cast<int(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 88))(this);
	}

	int get_peer(int id)
	{
		return (*reinterpret_cast<int(__fastcall **)(GameSession*, int)>(*reinterpret_cast<uintptr_t*>(this) + 96))(this, id);
	}

	int get_local_peer()
	{
		return (*reinterpret_cast<int(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 80))(this);
	}

	std::vector<int> peers()
	{
		std::vector<int> ret;
		for(int i = 0; i < this->num_peers(); i++)
		{
			ret.push_back(this->get_peer(i));
		}
		return ret;
	}

	UnitSynchronizer* unit_synchronizer()
	{
		return (*reinterpret_cast<UnitSynchronizer*(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 272))(this);
	}

	void set_interpolation_lag_compensation(float interp) // Backtrack inbound tm
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*, float)>(*reinterpret_cast<uintptr_t*>(this) + 280))(this, interp);
	}
};