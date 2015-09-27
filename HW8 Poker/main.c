#include"header.h"

int main (void)
{
	int game = 0, money = 1000;
	system("Color 24");//Color: Background: Green, Text: Red
	welcome_screen();
	do{//while player1 has money
	/* initialize suit array */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *suits[4] = {"\3", "\4", "\5", "\6"};
	/* initialize face array */
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"};
	char faces[13] = {"A234567890JQK"};
	char raise = '\0' , ten = ' ';
	Card hand1[5];
	Card hand2[5];
	/* initalize deck array */
	int deck[4][13] = {0};
	int is_pair = 0, is_two_pair = 0, is_three = 0, is_four = 0, is_full = 0, is_flush = 0, is_straight = 0, score1 = 0, score2 = 0,
		x = 0, y = 0, i = 0, j = 0, count = 10, count1 = 0, count2 = 0, bet = 0, bet2 = 0;
	srand ((unsigned) time (NULL)); /* see random-number generator */
	
	hand1[0].is_active = 1; hand1[1].is_active = 1; hand1[2].is_active = 1; hand1[3].is_active = 1; hand1[4].is_active = 1;
	hand2[0].is_active = 1; hand2[1].is_active = 1; hand2[2].is_active = 1; hand2[3].is_active = 1; hand2[4].is_active = 1;

//0 = Black 8 = Gray
//1 = Blue 9 = Light Blue
//2 = Green a = Light Green
//3 = Aqua b = Light Aqua
//4 = Red c = Light Red
//5 = Purple d = Light Purple
//6 = Yellow e = Light Yellow
//7 = White f = Bright White
	
	do{//Places blind bet	
	printf("Money: $%d\n", money);
	printf("Place your blind: \n");
	scanf("%d", &bet);
	if(bet > money)
	{
		printf("You don't have that much money!\n");
		system("Pause");
		system("cls");
	}
	}while(bet > money);
	shuffle (deck);
	deal(deck, face, faces, suit, suits, hand1, hand2, count, count1, count2);
	//Initial Deal
	printf("\nMoney: $%d", money - bet);
	bet = raise_bet(money, bet);//First round of betting - Raise before 'draw'
	count = select_cards(hand1, count);//how many cards to redeal
	count1 = count - 10;
	//deal(deck, face, suit, hand1, hand2, count);
	//Simulates Dealer, decides which cards the dealer keeps
	sort_hand(hand2);	
	is_pair = pair(hand2, face, 0);
	is_two_pair = two_pair(hand2, face, 0);
	is_three = three_of_a_kind(hand2, face, 0);
	is_four = four_of_a_kind(hand2, face, 0);
	is_full = full_house(hand2, face, 0);
	is_flush = flush(hand2, face, 0);
	is_straight = straight(hand2, face, 0);
	for(i = 0; i < 5; i++)//Counts how many cards to redeal to dealer
	{
		if(hand2[i].is_active == 1)
		{
			count++;
			count2++;
		}
	}
	//printf("\n%d %d %d %d %d\n", hand1[0].is_active, hand1[1].is_active, hand1[2].is_active, hand1[3].is_active, hand1[4].is_active);
	//printf("\n%d %d %d %d %d\n", hand2[0].is_active, hand2[1].is_active, hand2[2].is_active, hand2[3].is_active, hand2[4].is_active);
	system("Pause");
	system("cls");	
	printf("Money: $%d\n", money - bet);
	printf("Pot: $%d", 2*bet);
	deal(deck, face, faces, suit, suits, hand1, hand2, count, count1, count2);
	//Draw and Redeal
	sort_hand(hand1);
	sort_hand(hand2);

	printf("\nHand#1\n");
	for(y = 0; y < 5; y++)//Prints hand1
	{
		if(hand1[y].face == 9)//Prints '10' instead of just '0'
		{
			ten = '1';
		}
		if(hand1[y].face != 9)
		{
			ten = ' ';
		}
		printf("Card#%d %5s of %-8s %c%c%s\n", y + 1, face[hand1[y].face], suit[hand1[y].suit], ten, faces[hand1[y].face], suits[hand1[y].suit]);
	}
	//money = money - bet;
	bet = raise_bet(money, bet);//Second round of betting - before 'showdown'
	money = money - bet;
	printf("Money: $%d\n", money);
	/*SHOWDOWN!!!*/
	printf("Pot: $%d\n", 2*bet);
	system("Pause");
	system("cls");
	printf("\nHand#1\n");
	for(y = 0; y < 5; y++)
	{
		if(hand1[y].face == 9)
		{
			ten = '1';
		}
		if(hand1[y].face != 9)
		{
			ten = ' ';
		}
		printf("Card#%d %5s of %-8s %c%c%s\n", y + 1, face[hand1[y].face], suit[hand1[y].suit], ten, faces[hand1[y].face], suits[hand1[y].suit]);
	}
	printf("\nHand#2\n");
	for(j = 0; j < 5; j++)
	{
		if(hand2[j].face == 9)
		{
			ten = '1';
		}
		if(hand2[j].face != 9)
		{
			ten = ' ';
		}
		printf("Card#%d %5s of %-8s %c%c%s\n", j + 1, face[hand2[j].face], suit[hand2[j].suit], ten, faces[hand2[j].face], suits[hand2[j].suit]);
	}
	hand1[0].high_card = hand1[4].face;//Starts by assuming 'high card' is hand[4]
	hand2[0].high_card = hand2[4].face;//'high card' is changed if there is a pair, two pair, etc. 

	printf("\nPlayer #1\t"); //Evaluates Player1's hand
	is_pair = pair(hand1, face, 1);
	is_two_pair = two_pair(hand1, face, 1);
	is_three = three_of_a_kind(hand1, face, 1);
	is_four = four_of_a_kind(hand1, face, 1);
	is_full = full_house(hand1, face, 1);
	is_flush = flush(hand1, face, 1);
	is_straight = straight(hand1, face, 1);
	//printf("\nHand #1:\nPair: %d\t\tTwo Pair: %d\tThree: %d\tFour: %d\t\tFlush: %d\tStraight: %d\n", is_pair, is_two_pair, is_three, is_four, is_flush, is_straight);
	score1 = calc_score(is_pair, is_two_pair, is_three, is_four, is_flush, is_straight, face, hand1);
	
	printf("\nPlayer#2\t");//Evaluates Dealer's hand
	is_pair = pair(hand2, face, 1);
	is_two_pair = two_pair(hand2, face, 1);
	is_three = three_of_a_kind(hand2, face, 1);
	is_four = four_of_a_kind(hand2, face, 1);
	is_full = full_house(hand2, face, 1);
	is_flush = flush(hand2, face, 1);
	is_straight = straight(hand2, face, 1);
	//printf("\nHand #2:\nPair: %d\t\tTwo Pair: %d\tThree: %d\tFour: %d\t\tFlush: %d\tStraight: %d\n", is_pair, is_two_pair, is_three, is_four, is_flush, is_straight);
	score2 = calc_score(is_pair, is_two_pair, is_three, is_four, is_flush, is_straight, face, hand2);

	if(score1 == score2)//If both hands have pair, two pair, etc.
	{
		score1 = hand1[0].high_card;//Note: If a hand has a pair, the highcard is the face value of the pair
		score2 = hand2[0].high_card;
	}
	x = 4;
	do{
	if(score1 == score2)//If both hands have the same high card
	{
		score1 = hand1[x].face;
		score2 = hand2[x].face;
		if(score1 != score2)
		{
			printf("\nPlayer #1 New High Card: %5s\n", face[hand1[x].face]);
			printf("Player #2 New High Card: %5s\n", face[hand2[x].face]);
		}
	}
	x--;
	}while((x >= 0)&&(score1 == score2));
	//printf("\n\nPlayer1 Score: %d\tPlayer2 Score: %d", score1, score2);
	if(score1 > score2)
	{
		printf("\n\nPlayer1 Wins: $%d\n", 2*bet);
		money = money + 2*bet;
	}
	if(score1 < score2)
	{
		printf("\nPlayer2 Wins: $%d\n", 2*bet);
		//money = money - 2*bet;
	}
	//printf("Money: $%d\n", money);
	system("Pause");
	system("cls");
	}while(money > 0);
	if(money <= 0)
	{
		printf("Game Over. . .\n");
	}
	return 0;
}
