/*This is a program that will analyze players based on the users input. The user will input the stats of the player and then the program will analyze the player based on a PER model that I crafted myself. This PER number will then be tested by the program and place it in a category that tells the user how good the player is. */
#include <iostream>
#include<string>
using namespace std ;

//Creating a class that will hold data for the player

class BasketballPlayer {
 public:
    string name;
    int Points;
    int Assists;
    int Rebounds;
    int Steals;
    int Blocks;
    int Turnovers;
    int FieldGoalsMade;
    int FieldGoalsAttempted;
    int FreeThrowsMade;
    int FreeThrowsAttempted;
    int ThreePointersMade;
    int ThreePointersAttempted;
    int FoulsCommitted;
    int GamesPlayed;

// Function to calculate field goal percentage
    double CalculateFieldGoalPercentage() {
        if (FieldGoalsAttempted != 0) {
            return static_cast<double>(FieldGoalsMade) / FieldGoalsAttempted;
        } else {
            return 0.0;
        }
    }

    // Function to calculate free throw percentage
    double CalculateFreeThrowPercentage() {
        if (FreeThrowsAttempted != 0) {
            return static_cast<double>(FreeThrowsMade) / FreeThrowsAttempted;
        } else {
            return 0.0;
        }
    }

    // Function to calculate three-point percentage
    double CalculateThreePointPercentage() {
        if (ThreePointersAttempted != 0) {
            return static_cast<double>(ThreePointersMade) / ThreePointersAttempted;
        } else {
            return 0.0;
        }
    }

    // Function to calculate Player Efficiency Rating (PER) for the season
    double CalculatePER() {
        // Calculate percentages
        double FGPercentage = CalculateFieldGoalPercentage();
        double FTPercentage = CalculateFreeThrowPercentage();
        double ThreePointPercentage = CalculateThreePointPercentage();

        // Calculate efficiency using your custom PER formula
        double PER = (Points + (Assists * 1.5) + (Rebounds * 1.2) + (Steals * 2) + (Blocks * 2) - (Turnovers * 2) - FoulsCommitted)
                     * ((FGPercentage * 0.4) + (FTPercentage * 0.3) + (ThreePointPercentage * 0.3));

        return PER;
    }

    // Function to analyze PER and provide feedback
    string AnalyzePER(double PER) {
        if (PER >= 35) {
            return "Excellent Efficiency Rating";
        } else if (PER >= 25) {
            return "Good Efficiency Rating";
        } else if (PER >= 15) {
            return "Average Efficiency Rating";
        } else if (PER >= 5) {
            return "Below Average Efficiency Rating";
        } else {
            return "Poor Efficiency Rating";
        }
    }
};

int main() {
    BasketballPlayer Player;

    // Input from the user for the season-long statistics
    cout << "Enter the player's name: ";
    getline(cin, Player.name);

    cout << "Enter the total number of points scored for the season: ";
    cin >> Player.Points;

    cout << "Enter the total number of assists for the season: ";
    cin >> Player.Assists;

    cout << "Enter the total number of rebounds for the season: ";
    cin >> Player.Rebounds;

    cout << "Enter the total number of steals for the season: ";
    cin >> Player.Steals;

    cout << "Enter the total number of blocks for the season: ";
    cin >> Player.Blocks;

    cout << "Enter the total number of turnovers for the season: ";
    cin >> Player.Turnovers;

    cout << "Enter the total number of field goals made for the season: ";
    cin >> Player.FieldGoalsMade;

    cout << "Enter the total number of field goals attempted for the season: ";
    cin >> Player.FieldGoalsAttempted;

    cout << "Enter the total number of free throws made for the season: ";
    cin >> Player.FreeThrowsMade;

    cout << "Enter the total number of free throws attempted for the season: ";
    cin >> Player.FreeThrowsAttempted;

    cout << "Enter the total number of three-pointers made for the season: ";
    cin >> Player.ThreePointersMade;

    cout << "Enter the total number of three-pointers attempted for the season: ";
    cin >> Player.ThreePointersAttempted;

    cout << "Enter the total number of fouls committed for the season: ";
    cin >> Player.FoulsCommitted;

    cout << "Enter the total number of games played for the season: ";
    cin >> Player.GamesPlayed;

    // Calculate PER for the player
    double PER = Player.CalculatePER();

    // Determine the category of the player based on the PER
    string Feedback = Player.AnalyzePER(PER);

    // Output the PER and category of the player
    cout << "The PER for " << Player.name << " is " << PER << endl;
    cout << Player.name << " has " << Feedback << endl;

    return 0;
}