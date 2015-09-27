#include"header.h"

/*************************************************************
 * Function: welcome_screen()								 *
 * Description:	This function prints the welcome screen and  *
 *			the rules of 5 card draw as well as the specifics*
 *			of this version of poker.						 *
 * Input parameters: None									 * 
 * Returns: Nothing							                 *
 * Preconditions: None									     *
 * Postconditions: Allows the user to understand how this	 *
 *			version of 5 card draw works.					 *
 *************************************************************/
void welcome_screen(void)
{
	printf("\n \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 ");
	printf("\6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5\n");
	printf(" \3                                                                           \3\n");
	printf(" \4                          \3 \4 \5 \6 POKER \6 \5 \4 \3                            \4\n");	
	printf(" \5                                                                           \5\n");
	printf(" \6                    Rules of Poker (5 card draw):                          \6\n");
	printf(" \5                                                                           \5\n");
	printf(" \3  In this version of 5 card draw, you are Player#1 and the CPU is Player#2 \3\n");
	printf(" \4  For the purpose of betting, Player#2 (CPU), will ALWAYS MATCH your bet.  \4\n");
	printf(" \5  The first betting round begins with the big blind. Play begins with each \5\n");
	printf(" \6  player being dealt five cards, the remaining deck is placed aside.       \6\n"); 
	printf(" \3  Players look at their cards and then a second round of betting occurs.   \3\n");
	printf(" \4  Then the 'draw' phase begins. Each player specifies how many of their    \4\n");
	printf(" \5  cards they wish to replace and discards them. The deck is retrieved,     \5\n");
	printf(" \6  and each player is dealt in turn from the deck the same number of cards  \6\n"); 
	printf(" \3  they discarded so that each player again has five cards. A third betting \3\n");
	printf(" \4  round occurs this is followed by the showdown in which the player with   \4\n");
	printf(" \5  the best hand wins the pot.                                              \5\n");
	printf(" \6                                                                           \6\n");
	printf(" \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5 ");
	printf("\6 \3 \4 \5 \6 \3 \4 \5 \6 \3 \4 \5\n\n");
	system("Pause");
	system("cls");
}
/*************************************************************
 * Function: shuffle()										 *
 * Description:	This function shuffles the deck using a for  *
 *			loop and a random number generator for faces and *
 *			suits.											 *
 * Input parameters: Two-Dimensional Array - wDeck[][13]	 * 
 * Returns: Nothing							                 *
 * Preconditions: Must have wDeck[][13] initialized.	     *
 * Postconditions: Allows the program to deal cards randomly *
 *************************************************************/
void shuffle (int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);
		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}
/*************************************************************
 * Function: deal()											 *
 * Description:	This function deals the cards to both players*
 *			using a triple nested for loop.					 *
 * Input parameters: wDeck[][], *wFace, *wFaces, *wSuit,	 * 
 *			*wSuits, hand1[], hand2[], count, count1, count2 *
 * Returns: Nothing, just modifies hand1 and hand2           *
 * Preconditions: Must have all the parameters listed above  *
 * Postconditions: Allows the program to deal cards to both  *
 *			players initially and for the 'draw'.			 *
 *************************************************************/
void deal (const int wDeck[][13], const char *wFace[], const char *wFaces, const char *wSuit[], const char *wSuits[], Card hand1[], Card hand2[], int count, int count1, int count2)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int difference = 0;
	char ten = ' ';
	/* deal each of the 52 cards */
	for (card = 1; card <= count; card++)
	{
		if(card == 6)
		{
			//printf("\nPlayer#2 Hand\n");
		}
		if(card == 11)
		{
			//printf("\nPlayer#1 Hand\n");
		}
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				if(column == 9)
				{
					ten = '1';
				}
				if(column != 9)
				{
					ten = ' ';
				}
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					if((card <= 5)&&(count < 11))
					{		
						printf("Card#%d %5s of %-8s %c%c%s\n", card, wFace[column], wSuit[row], ten, wFaces[column], wSuits[row]);
						hand1[card - 1].card_num = card;
						hand1[card - 1].face = column;
						hand1[card - 1].suit = row;
					}		
					if((card > 5)&&(card < 11)&&(count < 11))
					{
						//printf("Card#%d %5s of %-8s %c%c%s\n", card - 5, wFace[column], wSuit[row], ten, wFaces[column], wSuits[row]);
						hand2[card - 6].card_num = card;
						hand2[card - 6].face = column;
						hand2[card - 6].suit = row;
					}
					if((card > 10)&&(hand1[card - 11].is_active == 1))
					{
						//printf("Card#%d %5s of %-8s %c%c%s\n", card - 10, wFace[column], wSuit[row], ten, wFaces[column], wSuits[row]);
						hand1[card - 11].card_num = card;
						hand1[card - 11].face = column;
						hand1[card - 11].suit = row;
					}
					if((card > (12 + count1))&&(hand2[card - (13 + count1)].is_active == 1))
					{
						//printf("Card#%d %5s of %-8s %c%c%s\n", card - (12 + count1), wFace[column], wSuit[row], ten, wFaces[column], wSuits[row]);
						hand2[card - (13 + count1)].card_num = card;
						hand2[card - (13 + count1)].face = column;
						hand2[card - (13 + count1)].suit = row;
					}
					if((card > 10)&&(hand1[card - 11].is_active == 0))
					{
						count++;
					}
					if((card > 10)&&(hand2[card - (11 + count1)].is_active == 0))
					{
						count++;
					}
				}
			}
		}
	}
}
/*************************************************************
 * Function: sort_hand()									 *
 * Description:	This function uses nested for loop to perform*
 *			a bubble sort to sort each hand.				 *
 * Input parameters: hand[]									 * 
 * Returns: Nothing just modifies hand[]	                 *
 * Preconditions: Must have cards 'dealt' to hand[]		     *
 * Postconditions: Allows the program to decide if each hand *
 *			has a pair, two pair, three of a kind, four of a *
 *			kind, full house, flush, or straight.			 *
 *************************************************************/
void sort_hand(Card hand[])
{
	int x = 0, y = 0, face_temp = 0, suit_temp = 0;
	for(y = 0; y < 5 - 1; y++)
	{
		for(x = 0; x < 5 - (y + 1); x++)
		{
			if(hand[x].face > hand[x+1].face)
			{
				face_temp = hand[x].face;
				hand[x].face = hand[x+1].face;
				hand[x+1].face = face_temp;
			
				suit_temp = hand[x].suit;
				hand[x].suit = hand[x+1].suit;
				hand[x+1].suit = suit_temp;
			}
		}
	}
}
/*************************************************************
 * Function: pair()											 *
 * Description:	This function decides if a given hand has a  *
 *			pair.											 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: is_pair							                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int pair(Card hand[], const char *wFace[], int print)
{
	int is_pair = 0;
	if(hand[0].face == hand[1].face)
	{
		is_pair = 1;
		hand[0].high_card = hand[1].face;
		hand[0].is_active = 0;
		hand[1].is_active = 0;
	}
	if(hand[1].face == hand[2].face)
	{
		is_pair = 1;
		hand[0].high_card = hand[1].face;
		hand[1].is_active = 0;
		hand[2].is_active = 0;
	}
	if(hand[2].face == hand[3].face)
	{
		is_pair = 1;
		hand[0].high_card = hand[3].face;
		hand[2].is_active = 0;
		hand[3].is_active = 0;
	}
	if(hand[3].face == hand[4].face)
	{
		is_pair = 1;
		hand[0].high_card = hand[3].face;
		hand[3].is_active = 0;
		hand[4].is_active = 0;
	}
	if((is_pair == 1)&&(print == 1))
	{
		if(hand[0].high_card != 5)
		{
			printf("Pair of %5ss", wFace[hand[0].high_card]);
		}
		if(hand[0].high_card == 5)
		{
			printf("Pair of %5ses", wFace[hand[0].high_card]);
		}
	}
	return is_pair;
}
/*************************************************************
 * Function: two_pair()										 *
 * Description:	This function decides if a given hand has    *
 *			two pairs.										 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: is_two_pair						                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int two_pair(Card hand[], const char *wFace[], int print)
{
	int is_two_pair = 0;
	if(((hand[0].face == hand[1].face)&&((hand[2].face == hand[3].face)||(hand[3].face == hand[4].face))))
	{
		is_two_pair = 1;
		hand[0].high_card = hand[3].face;
	}
	if((hand[1].face == hand[2].face)&&(hand[3].face == hand[4].face))
	{
		is_two_pair = 1;
		hand[0].high_card = hand[4].face;
	}
	if((is_two_pair == 1)&&(print == 1))
	{
		printf("\tTwo Pair %5s High", wFace[hand[0].high_card]);
	}
	return is_two_pair;
}
/*************************************************************
 * Function: three_of_a_kind()								 *
 * Description:	This function decides if a given hand has    *
 *			three of a kind									 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: is_three						                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int three_of_a_kind(Card hand[], const char *wFace[], int print)
{
	int is_three = 0;
	if(((hand[0].face == hand[1].face)&&(hand[0].face == hand[2].face))
	 ||((hand[1].face == hand[2].face)&&(hand[1].face == hand[3].face))
	 ||((hand[2].face == hand[3].face)&&(hand[2].face == hand[4].face)))	
	{
		is_three = 1;
		hand[0].high_card = hand[2].face;
		if(print == 1)
		{
			printf("\tThree %5ss", wFace[hand[0].high_card]);
		}
	}	
	return is_three;
}
/*************************************************************
 * Function: four_of_a_kind()								 *
 * Description:	This function decides if a given hand has    *
 *			four of a kind									 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: is_four							                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int four_of_a_kind(Card hand[], const char *wFace[], int print)
{
	int is_four = 0;
	if(((hand[0].face == hand[1].face)&&(hand[0].face == hand[2].face)&&(hand[0].face == hand[3].face))
	 ||((hand[1].face == hand[2].face)&&(hand[1].face == hand[3].face)&&(hand[1].face == hand[4].face)))
	{
		is_four = 1;
		hand[0].high_card = hand[2].face;
		if(print == 1)
		{
			printf("\tFour %5s", wFace[hand[0].high_card]);
		}
	}
	return is_four;
}
/*************************************************************
 * Function: full_house()									 *
 * Description:	This function decides if a given hand has a  *
 *			full house										 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: full							                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int full_house(Card hand[], const char *wFace[], int print)
{
	int full = 0;
	if(((hand[0].face == hand[1].face)&&(hand[2].face == hand[3].face)&&(hand[2].face == hand[4].face))
	 ||((hand[3].face == hand[4].face)&&(hand[0].face == hand[1].face)&&(hand[0].face == hand[2].face)))
	{
		full = 1;
		hand[0].high_card = hand[2].face;
		if(print == 1)
		{
			printf("\tFull House %5s - High", wFace[hand[0].high_card]);
		}
	}
	return full;
}
/*************************************************************
 * Function: flush()										 *
 * Description:	This function decides if a given hand has a  *
 *			flush											 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: is_flush						                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int flush(Card hand[], const char *wFace[], int print)
{
	int is_flush = 0;
	if((hand[0].suit == hand[1].suit)&&(hand[0].suit == hand[2].suit)&&(hand[0].suit == hand[3].suit)&&(hand[0].suit == hand[4].suit))
	{
		is_flush = 1;
		hand[0].high_card = hand[4].face;
		if(print == 1)
		{
			printf("\t%5s High Flush", wFace[hand[0].high_card]);
		}
		hand[0].is_active = 0;
		hand[1].is_active = 0;
		hand[2].is_active = 0;
		hand[3].is_active = 0;
		hand[4].is_active = 0;
	}
	return is_flush;
}
/*************************************************************
 * Function: straight()										 *
 * Description:	This function decides if a given hand has a  *
 *			straight										 *
 * Input parameters: hand[], *wFace[], print				 * 
 * Returns: is_straight						                 *
 * Preconditions: Must have hand[] sorted				     *
 * Postconditions: Allows the program to compute the score of*
 *			each hand.										 *
 *************************************************************/
int straight(Card hand[], const char *wFace[], int print)
{
	int is_straight = 0, temp = 0, x = 0, y = 0;
	if((hand[4].face == hand[3].face + 1)&&(hand[3].face == hand[2].face + 1)&&(hand[2].face == hand[1].face + 1)
	 &&(hand[1].face == hand[0].face + 1))
	{
		hand[0].high_card = hand[4].face;
		is_straight = 1;
		if(print == 1)
		{
			printf("\t%5s High Straight", wFace[hand[0].high_card]);
		}
		hand[0].is_active = 0;
		hand[1].is_active = 0;
		hand[2].is_active = 0;
		hand[3].is_active = 0;
		hand[4].is_active = 0;
	}
	return is_straight;
}
/*************************************************************
 * Function: calc_score()									 *
 * Description:	This function assigns a score to each hand   *
 *			based on the combination of cards.				 *
 * Input parameters: is_pair, is_two_pair, is_three, is_four * 
 *			is_flush, is_straight, *wFace[], hand[]			 *
 * Returns: score							                 *
 * Preconditions: Must have the poker hand evaluated	     *
 * Postconditions: Allows the program to decide the winner	 *
 *************************************************************/
int calc_score(int is_pair, int is_two_pair, int is_three, int is_four, int is_flush, int is_straight, const char *wFace[], Card hand[])
{//Straight - Flush - Four - Three - Two Pair - Pair
	int score = 0;
	if(is_pair == 1)
	{
		score = 1;
	}
	if(is_two_pair == 1)
	{
		score = 2;
	}
	if(is_three == 1)
	{
		score = 3;
	}
	if(is_four == 1)
	{
		score = 4;
	}
	if(is_flush == 1)
	{
		score = 5;
	}
	if(is_straight == 1)
	{
		score = 6;
	}
	if(score == 0)
	{
		printf("\t%5s High", wFace[hand[0].high_card]);
	}
	return score;
}
/*************************************************************
 * Function: select_cards()									 *
 * Description:	This function prompts the user to select	 *
 *			which cards to keep.							 *
 * Input parameters: hand[], count							 * 
 * Returns: count (of cards not kept)		                 *
 * Preconditions: Must have cards dealt					     *
 * Postconditions: Allows the program to decide which cards  *
 *			to take away from hand[], and how many cards to	 *
 *			deal to player 1.								 *
 *************************************************************/
int select_cards(Card hand[], int count)
{
	int suit = 0, face = 0, card = 0, x = 0;
	char keep = '\0';
	for(x = 0; x < 5; x++)
	{
	do{
	printf("Keep card #%d?(Y/N): ", x + 1);
	scanf(" %c", &keep);
	}while((keep != 'y')&&(keep != 'n'));
	if(keep == 'y')
	{
		hand[x].is_active = 0;
	}
	if(keep == 'n')
	{
		hand[x].is_active = 1;
		count++;
	}
	}
	return count;
}
/*************************************************************
 * Function: raise_bet()									 *
 * Description:	This function prompts the user to raise the  *
 *			bet, and by how much.							 *
 * Input parameters: money, bet								 * 
 * Returns: bet								                 *
 * Preconditions: Must have blind bet entered.			     *
 * Postconditions: Allows the program to compute player1's	 *
 *			money total depending on the 'showdown'.		 *
 *************************************************************/
int raise_bet(int money, int bet)
{
	int bet2 = 0;
	char raise = '\0';
	printf("\nRaise your bet?(Y/N): \n");
	scanf(" %c", &raise);
	if((raise == 'y')&&(money > 0))
	{
		do{
			printf("How much?: ");
			scanf("%d", &bet2);
		}while((bet2 > money)||(money - (bet + bet2) < 0));
		bet = bet + bet2;
	}
	if(money == 0)
	{
		printf("\nYou don't have enough money!\n");
	}
	return bet;
}