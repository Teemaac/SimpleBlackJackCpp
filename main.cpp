#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

//validate monies
    bool isValidBet(int bet, int playerMoney) {
        return(bet > 0 && bet <= playerMoney);
    };

int main()
{
    srand(time(0)); // Seed the random number generator with the current time
    int playerTotal = 0;
    int dealerTotal = 0;
    int playerMoney = 100; // Starting amount of money
    int playerBet = 0;
    int numAces = 0;
    char playAgain = 'y';
    int hand1Total;
    int hand2Total;
    char choice;
    int hand1Bet = playerBet;
    int hand2Bet = playerBet;
    char splitChoice = 'n';

    cout << "Welcome to Retro BlackJack ®️" << endl;

    while (playerMoney > 0 && playAgain == 'y') {

        numAces = 0;
       cout << "You have $" << playerMoney << ". How much would you like to wager? ";
        cin >> playerBet;

    while (!isValidBet(playerBet, playerMoney)) {
        cout << "Invalid bet. Please enter a valid amount between 1 and " << playerMoney << ": ";
        cin >> playerBet;
    }


        // Deal the first two cards to the player
        int card1 = rand() % 10 + 1;
        int card2 = rand() % 10 + 1;
        playerTotal = card1 + card2;

        // Check for aces
        int numAces = 0;
        if (card1 == 1) {
            numAces++;
            playerTotal += 10; // Ace is worth 11
        }
        if (card2 == 1) {
            numAces++;
            playerTotal += 10; // Ace is worth 11
        }

        //Your card displayed
        cout << "Your cards: " << card1 << ", " << card2 << endl;

        if (card1 == card2) {
            cout << "You have been dealt two cards of the same value. Do you want to split your hand? (y/n): ";
            cin >> splitChoice;

            if (splitChoice == 'y') {
                // Create two new hands
                hand1Total = card1;
                hand2Total = card2;
                int hand1Card = rand() % 10 + 1;
                    if (hand1Card == 1) {
                        numAces++;
                        hand1Total += 10; // Ace is worth 11
                    }
                int hand2Card = rand() % 10 + 1;
                    if (hand2Card == 1) {
                        numAces++;
                        hand2Total += 10; // Ace is worth 11
                    }
                hand1Total += hand1Card;
                hand2Total += hand2Card;

            // Display each hand
                cout << "Hand 1: " << card1 << ", " << hand1Card << endl;
                cout << "Hand 1 total: " << hand1Total << endl;
                cout << "Hand 2: " << card2 << ", " << hand2Card << endl;
                cout << "Hand 2 total: " << hand2Total << endl;

            // Play out each hand separately
                while (hand1Total < 21) {
                    cout << "Hand 1: Do you want to hit or stand? (h/s): ";
                    cin >> choice;
                    if (choice == 'h') {
                        int newCard = rand() % 10 + 1;
                            if (newCard == 1) {
                                numAces++;
                                hand1Total += 10; // Ace is worth 11
                            }
                        hand1Total += newCard;
                        cout << "Hand 1: Your new card: " << newCard << endl;
                        cout << "Hand 1: Your current hand total: " << hand1Total << endl;
                        if (hand1Total > 21) {
                            cout << "Hand 1: Bust! You lose." << endl;
                            playerMoney -= hand1Bet;
                            break;
                        }
                    } else if (choice == 's') {
                        break;
                    }
                }

                while (hand2Total < 21) {
                    char choice;
                    cout << "Hand 2: Do you want to hit or stand? (h/s): ";
                    cin >> choice;
                    if (choice == 'h') {
                        int newCard = rand() % 10 + 1;
                        if (newCard == 1) {
                            numAces++;
                            hand2Total += 10; // Ace is worth 11
                        }
                        hand2Total += newCard;
                        cout << "Hand 2: Your new card: " << newCard << endl;
                        cout << "Hand 2: Your current hand total: " << hand2Total << endl;
                        if (hand2Total > 21) {
                            cout << "Hand 2: Bust! You lose." << endl;
                            playerMoney -= hand2Bet;
                            break;
                        }
                    } else if (choice == 's') {
                        break;
                    }
                }
            }
                
        } 
           
        

        // Deal the first two cards to the dealer
        card1 = rand() % 10 + 1;
            if (card1 == 1) {
                numAces++;
                dealerTotal += 10; // Ace is worth 11
            }
        card2 = rand() % 10 + 1;
            if (card2 == 1) {
                numAces++;
                dealerTotal += 10; // Ace is worth 11
            }
        dealerTotal = card1 + card2;

        // Show the dealer's first card
        cout << "Dealer's first card: " << card1 << endl;

        // Ask the player if they want to hit or stay
        if(splitChoice == 'n'){
            char choice;
            cout << "Do you want to hit or stand or double down? (h/s/d): ";
            cin >> choice;

            if(choice == 'd'){
                // Player wants to double down
                if (playerMoney >= playerBet * 2) {
                    playerBet *= 2;
                    int newCard = rand() % 10 + 1;
                    playerTotal += newCard;

                    // Check for aces and adjust total if necessary
                    if (newCard == 1) {
                        numAces++;
                        playerTotal += 10; // Ace is worth 11
                    }

                    cout << "Your new card: " << newCard << endl;
                    cout << "Your total: " << playerTotal << endl;

                } else {
                    cout << "You don't have enough money to double down. Choose hit or stand." << endl;
                    cout << "Do you want to hit or stand? (h/s): ";
                    cin >> choice;
                }
            }

            while (choice == 'h') {
                int newCard = rand() % 10 + 1;
                    if (newCard == 1) {
                        numAces++;
                        playerTotal += 10; // Ace is worth 11
                    }
                playerTotal += newCard;

                cout << "Your current hand total: " << playerTotal << endl;

                cout << "Your new card: " << newCard << endl;
                cout << "Your total: " << playerTotal << endl;

                if (playerTotal > 21) {
                    if(numAces > 0){
                        playerTotal -= 10;
                        numAces -= 1;
                    }else{
                        cout << "Bust! You lose." << endl;
                        playerMoney -= playerBet;
                        cout << "You now have $" << playerMoney << "." << endl;
                        break;
                    }              
                }
                cout << "Do you want to hit or stay? (h/s): ";
                cin >> choice;
            }
        }
        

    // Dealer's turn
        cout << "Dealer's second card: " << card2 << endl;
        while (dealerTotal < 17) {
            int newCard = rand() % 10 + 1;
            dealerTotal += newCard;

            // Check for aces
            if (newCard == 1 && dealerTotal + 10 <= 21) {
                dealerTotal += 10;
            }

            cout << "Dealer's new card: " << newCard << endl;
            cout << "Dealer's total: " << dealerTotal << endl;
            if (dealerTotal > 21) {
                cout << "Dealer busts! You win." << endl;
                playerMoney += playerBet;
                cout << "You now have $" << playerMoney << "." << endl;
                break;
            }
        }

    // Compare hands
    if (splitChoice == 'y') {
        if (hand1Total > dealerTotal && hand1Total <= 21) {
            cout << "Hand 1: You win!" << endl;
            playerMoney += hand1Bet;
        } else if (hand1Total < dealerTotal && dealerTotal <= 21) {
            cout << "Hand 1: Dealer wins." << endl;
            playerMoney -= hand1Bet;
        } else if (hand1Total == dealerTotal && hand1Total <= 21 && dealerTotal <= 21) {
            cout << "Hand 1: Push." << endl;
        }

        if (hand2Total > dealerTotal && hand2Total <= 21) {
            cout << "Hand 2: You win!" << endl;
            playerMoney += hand2Bet;
        } else if (hand2Total < dealerTotal && dealerTotal <= 21) {
            cout << "Hand 2: Dealer wins." << endl;
            playerMoney -= hand2Bet;
        } else if (hand2Total == dealerTotal && hand2Total <= 21 && dealerTotal <= 21) {
            cout << "Hand 2: Push." << endl;
        }
    } else {
         if (playerTotal > dealerTotal && playerTotal <= 21) {
            cout << "You win!" << endl;
            playerMoney += playerBet;
        } else if (playerTotal < dealerTotal && dealerTotal <= 21) {
            cout << "Dealer wins." << endl;
            playerMoney -= playerBet;
        } else if (playerTotal == dealerTotal && playerTotal <= 21 && dealerTotal <= 21) {
            cout << "Push." << endl;
        }
    }


        

        cout << "You now have $" << playerMoney << "." << endl;

        if (playerMoney > 0) {
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
        } else {
            cout << "Sorry, you're out of money. Better luck next time!" << endl;
        }
    

    }
    return 0;
}


