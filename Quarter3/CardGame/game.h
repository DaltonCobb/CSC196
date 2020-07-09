#pragma once
#include "deck.h"
#include "player.h"
#include <vector>

class Game
{
public:
	Game() {}

	void StartGame();
	void StartRound();

	void AddPlayer(const Player& player) { m_players.push_back(player); }
	bool IsGameOver() { return m_gameOver; }

private:
	bool m_gameOver{ false };
	Deck m_deck;
	std::vector<Player> m_players;
};

