#include "deck.h"
#include <algorithm>

Deck::Deck()
{
    // add all cards of the deck
    // for loop (suit)
        // for loop (rank)
            // push back card using id_t for the constructor
    for (Card::id_t i = 0; i < static_cast<Card::id_t>(Card::eSuit::Size); i++)
    {
        for (Card::id_t j = 0; j < static_cast<Card::id_t>(Card::eRank::Size); j++)
        {
            m_cards.push_back(Card{ static_cast<Card::id_t>((i << 4) | j) });
        }
    }
}

void Deck::Shuffle()
{
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

Card Deck::DealCard()
{
    assert(!m_cards.empty());

    Card card = m_cards.back();
    m_cards.pop_back();

    return card;
}
