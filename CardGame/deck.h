#pragma once
#include "card.h"
#include <cassert>

class Deck
{
public:
	friend class Game;

public:
	Deck();
	Deck(const cards_t& cards) : m_cards(cards) {}

	void Shuffle();

	void AddCard(const Card& card) { m_cards.push_back(card); }
	Card DealCard();

	const Card& operator[] (size_t index)
	{
		assert(index < m_cards.size());

		return m_cards[index];
	}

	const Card& GetCard(size_t index)
	{
		assert(index < m_cards.size());

		return m_cards[index];
	}

	size_t GetCount() { return m_cards.size(); }

private:
	cards_t m_cards;
};

