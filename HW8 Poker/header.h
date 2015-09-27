 /****************************************************************
 * Programmer: Anthony Simmons									 *
 * Class: Cpt S 121, Spring 2011; Lab Section: 6				 *
 * Programming Assignment: #8 Poker (5 card draw)			  	 *
 * Date: April 26, 2011											 *
 *																 *
 * Description: This program is an one-player console based		 *
 *              Poker (5 card draw) game, where the CPU is the   *
 *				dealer. For the purpose of betting, you have to	 *
 *				post the 'blind' bet, and have two chances to 	 *
 *				raise your bet. The 'dealer', will always match	 *
 *				your bet.										 *
 ****************************************************************/
#ifndef header_h
#define header_h
#include<stdio.h>
#include<stdlib.h>

typedef struct card
{
	int card_num;
	int suit;
	int face;
	int high_card;
	int is_active;
}	Card; //Defines the structs associated with variable type Card

//Declares function headers - for each function description see 'function.c'
void welcome_screen(void);

void shuffle (int wDeck[][13]);

void deal (const int wDeck[][13], const char *wFace[], const char *wFaces[], const char *wSuit[], const char *wSuits[], Card hand1[], Card hand2[], int count, int count1, int count2);

void sort_hand(Card hand[]);

int pair(Card hand[], const char *wFace[], int print);

int two_pair(Card hand[], const char *wFace[], int print);

int three_of_a_kind(Card hand[], const char *wFace[], int print);

int four_of_a_kind(Card hand[], const char *wFace[], int print);

int full_house(Card hand[], const char *wFace[], int print);

int flush(Card hand[], const char *wFace[], int print);

int straight(Card hand[], const char *wFace[], int print);

int calc_score(int is_pair, int is_two_pair, int is_three, int is_four, int is_flush, int is_straight, const char *wFace[], Card hand[]);

int select_cards(Card hand[], int count);

int raise_bet(int money, int bet);

#endif