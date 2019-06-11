#pragma once

class GameSession
{
public:
	
	/// <summary>
	/// Makes localent the game session host.
	/// </summary>
	void make_game_session_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 16))(this);
	}
	
	/// <summary>
	/// Shutdowns the game session host.
	/// </summary>
	void shutdown_game_session_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 24))(this);
	}

	/// <summary>
	/// Gets error state.
	/// </summary>
	/// <returns></returns>
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

	/// <summary>
	/// Disconnects from host.
	/// </summary>
	void disconnect_from_host()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 48))(this);
	}

	/// <summary>
	/// Adds the peer.
	/// </summary>
	/// <param name="peer_id">The peer identifier.</param>
	void add_peer(int peer_id)
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*, int)>(*reinterpret_cast<uintptr_t*>(this) + 56))(this, peer_id);
	}
	
	/// <summary>
	/// Removes the peer.
	/// </summary>
	/// <param name="peer_id">The peer identifier.</param>
	void remove_peer(int peer_id)
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*, int, void* /*callback*/)>(*reinterpret_cast<uintptr_t*>(this) +
			64))(this, peer_id, (void*)(Memory::SigScan("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 54 41 55 41 56 41 57 48 83 EC 50 48 8B 31 4C 8B F1", "Vermintide2.exe")));
	}

	/// <summary>
	/// Leaves this instance.
	/// </summary>
	void leave()
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 72))(this);
	}

	/// <summary>
	/// Numbers the peers.
	/// </summary>
	/// <returns></returns>
	int num_peers()
	{
		return (*reinterpret_cast<int(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 88))(this);
	}

	/// <summary>
	/// Gets the peer.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns></returns>
	int get_peer(int id)
	{
		return (*reinterpret_cast<int(__fastcall **)(GameSession*, int)>(*reinterpret_cast<uintptr_t*>(this) + 96))(this, id);
	}

	/// <summary>
	/// Gets the local peer.
	/// </summary>
	/// <returns></returns>
	int get_local_peer()
	{
		return (*reinterpret_cast<int(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 80))(this);
	}

	/// <summary>
	/// Gets all peers.
	/// </summary>
	/// <returns></returns>
	std::vector<int> peers()
	{
		std::vector<int> ret;
		for(int i = 0; i < this->num_peers(); i++)
		{
			ret.push_back(this->get_peer(i));
		}
		return ret;
	}

	/// <summary>
	/// Gets the network unit synchronizer.
	/// </summary>
	/// <returns></returns>
	UnitSynchronizer* unit_synchronizer()
	{
		return (*reinterpret_cast<UnitSynchronizer*(__fastcall **)(GameSession*)>(*reinterpret_cast<uintptr_t*>(this) + 272))(this);
	}

	/// <summary>
	/// Sets the interpolation lag compensation.
	/// </summary>
	/// <param name="interp">The interp.</param>
	void set_interpolation_lag_compensation(float interp) // Backtrack inbound tm
	{
		(*reinterpret_cast<void(__fastcall **)(GameSession*, float)>(*reinterpret_cast<uintptr_t*>(this) + 280))(this, interp);
	}
};