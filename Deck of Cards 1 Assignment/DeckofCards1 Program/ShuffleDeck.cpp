#include <cstdio>
#include "ShuffleDeck.h"


	// voids for construtor of deck



    void deal_hand(DS::Deck & deck, int num_cards) {
        while (num_cards--) {
            DS::Card card = deck.deal_card();
            printf("%s ", DS::card_str(card));
        }
        puts("");
    }

    int main()
    {
        try {
            DS::Deck deck;
            printf("there are %d cards currently in the deck\n", deck.remaining());

            deal_hand(deck, 9);
            deal_hand(deck, 5);
            deal_hand(deck, 13);
            deal_hand(deck, 10);

            printf("there are %d cards currently in the deck\n", deck.remaining());
        }
        catch (DS::E & e) {
            puts(e.what());
            return 1;
        }

        return 0;
    }