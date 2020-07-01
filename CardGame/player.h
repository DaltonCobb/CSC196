#pragma once
#include "deck.h"
#include <string>

class Player
{
public:
	Player() {}
	Player(const std::string& name) : m_name(name) {}

	void AddCard(const Card& card) { m_cards.push_back(card); }
	void SetCards(const cards_t& cards) { m_cards = cards; }
	void RemoveAllCards() { m_cards.clear(); }
	size_t GetCardCount() { return m_cards.size(); }

	Deck& GetDeck() { return m_deck; }
	void SetDeck(const Deck& deck) { m_deck = deck; }

	friend std::ostream& operator << (std::ostream& stream, const Player& player)
	{
		stream << "Player: " << player.m_name;

		return stream;
	}

private:
	std::string m_name;
	Deck m_deck;
	cards_t m_cards;
};

