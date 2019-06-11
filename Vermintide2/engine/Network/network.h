#pragma once

class Network
{
public:
	char pad[0x58];
	GameSession* _session;

	/// <summary>
	/// Determines whether [is backend setup].
	/// </summary>
	/// <returns>
	///   <c>true</c> if [is backend setup]; otherwise, <c>false</c>.
	/// </returns>
	bool is_backend_setup()
	{
		return *(uintptr_t*)(this + 0x40);
	}

	/// <summary>
	/// Gets the current session.
	/// </summary>
	/// <returns></returns>
	GameSession* game_session()
	{
		return _session;
	}

	/// <summary>
	/// Shutdowns the game session.
	/// </summary>
	void shutdown_game_session()
	{
		using type = void(__thiscall*)(Network*); static type function = reinterpret_cast<type>(Memory::SigScan("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B 79 58", "Vermintide2.exe"));
		function(this);
	}


	/// <summary>
	/// Gets peer id
	/// </summary>
	/// <returns>Steam ID if on steam, random number if LAN</returns>
	std::string peer_id()
	{
		return (*(std::string(**)(void))(**(uintptr_t **)(this + 64) + 16))();
	}
};