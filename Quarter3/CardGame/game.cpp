#include "game.h"
using namespace std;

void Game::StartGame()
{
	m_deck.Shuffle();

	// split deck
	cards_t cards = m_deck.m_cards;

	std::size_t const half_size = cards.size() / 2;
	cards_t split_lo(cards.begin(), cards.begin() + half_size);
	cards_t split_hi(cards.begin() + half_size, cards.end());

	// give each player half
	m_players[0].SetDeck(Deck{ split_lo });
	m_players[1].SetDeck(Deck{ split_hi });
}

void Game::StartRound()
{
	system("cls");

	cards_t cards;
	int winner = -1;

	while (winner == -1)
	{
		cards.push_front(m_players[1].GetDeck().DealCard()); // cards = p2card
		cards.push_front(m_players[0].GetDeck().DealCard()); // cards = p1card, p2card

		cout << m_players[0] << " " << cards[0] << endl;
		cout << m_players[1] << " " << cards[1] << endl;

		if (cards[0] == cards[1])
		{
			cout << "!!! War !!!\n\n";
			cards.push_back(m_players[0].GetDeck().DealCard());
			cards.push_back(m_players[1].GetDeck().DealCard());
		}
		if (cards[0] > cards[1])
		{
			winner = 0; // 0 = player 1
		}
		else if (cards[1] > cards[0])
		{
			winner = 1; // 1 = player 2
		}
	}

	// show winner
	cout << m_players[winner] << " Won!!!\n";

	// add cards to winner
	for (size_t i = 0; i < cards.size(); i++)
	{
		m_players[winner].AddCard(cards[i]);
	}

	// show player card count
	for (size_t i = 0; i < m_players.size(); i++)
	{
		cout << m_players[i] << " " << m_players[i].GetCardCount() << endl;
	}

	// check for game over
	for (size_t i = 0; i < m_players.size(); i++)
	{
		if (m_players[i].GetCardCount() == 0 && m_players[i].GetDeck().GetCount() == 0)
		{
			m_gameOver = true;
		}
	}

	cout << "\n\npress enter to continue...";
	cin.ignore();

}

