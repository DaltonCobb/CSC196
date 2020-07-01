#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <deque>

class Card
{
public:
	enum class eRank
	{
		Ace,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Size
	};

	enum class eSuit
	{
		Spades,
		Hearts,
		Diamonds,
		Clubs,
		Size
	};

	typedef unsigned char id_t; // (0, 0, suit, suit, rank, rank, rank, rank)

public:
	Card() : m_rank(eRank::Ace), m_suit(eSuit::Spades) {}
	Card(eRank name, eSuit suit) : m_rank(name), m_suit(suit) {}
	Card(id_t id)
	{
		m_rank = static_cast<eRank>(id & 0xF);
		m_suit = static_cast<eSuit>(id >> 4);
	}

	bool operator == (const Card& other) const
	{
		return (this->GetValue() == other.GetValue());
	}

	bool operator != (const Card& other) const
	{
		return (!(*this == other));
	}

	bool operator < (const Card& other) const
	{
		return (this->GetValue() < other.GetValue());
	}

	bool operator > (const Card& other) const
	{
		return (this->GetValue() > other.GetValue());
	}

	bool operator == (const eSuit suit) const
	{
		return (this->m_suit == suit);
	}

	bool operator == (const eRank name) const
	{
		return (this->m_rank == name);
	}

	int GetValue() const { return s_values[static_cast<int>(m_rank)]; }

	friend std::ostream& operator << (std::ostream& stream, const Card& card)
	{
		stream << s_rankStrings[static_cast<int>(card.m_rank)] << " ";
		stream << s_suitStrings[static_cast<int>(card.m_suit)];

		return stream;
	}

private:
	eSuit m_suit;
	eRank m_rank;

	static const int s_values[];
	static const std::string s_rankStrings[];
	static const std::string s_suitStrings[];
};

using cards_t = std::deque<Card>;


