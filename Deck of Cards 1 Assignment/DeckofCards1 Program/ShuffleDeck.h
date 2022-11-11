#ifndef ShuffleDeck_h
#define ShuffleDeck_h

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "dsexception.h"



namespace DS {                                  // Namespace start

    
    typedef uint16_t uintds16;                  // type defs and initialisers
    typedef uint8_t uintds8;

    constexpr const char* suitstr = "cdhs";       // suit Letters
    constexpr const char* pictcards = "ATJQK";    // Picture card letters
    constexpr uintds8 default_deck = 52;          // Default starting number of cards in deck
    constexpr uintds8 maxamm_decks = 4;          // Max ammount of Decks allowed in game
    constexpr uintds8 suitnum = 4;               // Number of suits allowed
    constexpr uintds8 ranknum = 13;              // Number of ranks A-K

    typedef struct {                            // Type def structure for suits and ranks
        uintds8 suit : 4;
        uintds8 rank : 4;
    } Card;




    class Deck {                        // starting values of Deck
        int _cards_per_deck = 0;
        int _numdecks = 0;
        int _remaining_count = 0;
        Card* _deck = nullptr;

        void _init_deck();              // Declaring methods
        void _delete_deck();
        void _create_deck();
        void _init();

        Deck(const Deck&);              // disallow copy Constructor (added after)
        Deck& operator = (Deck);        // disallow assignment operator
    public:
        Deck() : _cards_per_deck(default_deck), _numdecks(1) { _init(); }
        Deck(int n) : _cards_per_deck(default_deck), _numdecks(n) { _init(); }
        Deck(Deck&&) noexcept; // move consructor
        ~Deck();    // Slightly edited after course

        // Main core functions / methods
        void new_deck();
        void new_deck(uintds8 n);
        void shuffle_deck();
        const Card& get_card(uintds16) const;
        const Card& deal_card();

        // Meta information
       
        uintds16 remaining() const;
        uintds16 deck_size() const;
        const Card* deck() const;
       
    };

    const char * card_str(const Card &);            

    } // namespace

    #endif /* Endif for ShuffleDeck.h */