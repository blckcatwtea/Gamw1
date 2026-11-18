#include <stdio.h>
#define SHIFT_PAY 610
#define SAVINGS_TARGET 8000
#define DAILY_ALLOWANCE 250

struct Player
{
    char name[50];
    int gender;
    int money;
    int energy;
    int happiness;
    int totalEarnings;
    int totalExpenses;
    int isHired;
    int trainingCompleted;
    int workedToday;
};

void displayStatus(struct Player player);

void updateMoney(struct Player *player, int amount);

void updateEnergy(struct Player *player, int amount);

void updateHappiness(struct Player *player, int amount);

int spendMoney(struct Player *player, int amount);

void startGame(struct Player *player);

void day1Story(struct Player *player); // day1 story

void showDialogue(const char speaker[], const char dialogue[]);

void breakfastChoice(struct Player *player);

void transportationChoice(struct Player *player);

void day2Story(struct Player *player); // day 2 story

void orderCheckingGame(struct Player *player);

void day3Story(struct Player *player); // day 3 story

void customerServiceGame(struct Player *player);

void cashierChallenge(struct Player *player);

void cashierChallengeMedium(struct Player *player);

void cashierChallengeHard(struct Player *player);

void scamDetectiveEasy(struct Player *player);

void scamDetectiveMedium(struct Player *player);

void scamDetectiveHard(struct Player *player);

void budgetShoppingEasy(struct Player *player);

void budgetShoppingMedium(struct Player *player);

void budgetShoppingHard(struct Player *player);

void financialQuizEasy(struct Player *player);

void financialQuizMedium(struct Player *player);

void financialQuizHard(struct Player *player);

void day4Story(struct Player *player); // day 4 story

void multipleOrderGame(struct Player *player);

void day5Story(struct Player *player); // day 5 story

void day6Story(struct Player *player); // day 6 story

void weekendChoice(struct Player *player);

void day7Story(struct Player *player); // day 7 story

void weeklyReport(struct Player *player, int daysCompleted);

void day8Story(struct Player *player); // day 8 story

void completeWorkShift(struct Player *player);

void weekendWorkChoice(struct Player *player);

void day9Story(struct Player *player);

void day10Story(struct Player *player);

void day11Story(struct Player *player);

void day12Story(struct Player *player);

void day13Story(struct Player *player);

void day14Story(struct Player *player);

void day15Story(struct Player *player);

void day16Story(struct Player *player);

void day17Story(struct Player *player);

void day18Story(struct Player *player);

void day19Story(struct Player *player);

void day20Story(struct Player *player);

void day21Story(struct Player *player);

void day22Story(struct Player *player);

void day23Story(struct Player *player);

void day24Story(struct Player *player);

void day25Story(struct Player *player);

void day26Story(struct Player *player);

void day27Story(struct Player *player);

void day28Story(struct Player *player);

void day29Story(struct Player *player);

void day30Story(struct Player *player);

int main()
{
    struct Player player;
    int choice;
    int running = 1;
    player.isHired = 0;
    player.trainingCompleted = 0;
    player.workedToday = 0;

    while (running == 1)
    {
        printf("========================\n\n");
        printf("      Budget Battle\n");
        printf("   30 Days to survive\n");
        printf("\n========================\n");

        printf("\t MAIN MENU \n\n");
        printf("\t [1] Start Game\n");
        printf("\t [2] Continue Game\n");
        printf("\t [3] Quit Game\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\n================================\n");
            printf("       CHARACTER CREATION\n");
            printf("================================\n");

            printf("\nEnter your character's name: ");
            scanf("%49s", player.name);

            printf("\nChoose your gender:\n");
            printf("[1] Male\n");
            printf("[2] Female\n");

            printf("\nEnter your choice: ");
            scanf("%d", &player.gender);
            getchar();
            if (player.gender == 1)
            {

                printf("\nGender: Male\n");
                printf("Character created successfully!\n");
            }
            else if (player.gender == 2)
            {

                printf("\nGender: Female\n");
                printf("Character created successfully!\n");
            }
            else
            {

                printf("\nInvalid gender choice!\n");
            }

            if (player.gender == 1 || player.gender == 2)
            {
                player.money = 0;
                player.energy = 100;
                player.happiness = 100;
                player.totalEarnings = 0;
                player.totalExpenses = 0;
                printf("\nWelcome to Budget Battle, %s!\n", player.name);

                startGame(&player); // startgame
            }

            break;

        case 2:
            printf("\nChecking saved game...\n");
            break;

        case 3:
            printf("\nThank you for playing!\n");
            running = 0;
            break;

        default:
            printf("\nInvalid choice! Please select 1, 2, or 3.\n");
        }
        printf("\n");
    }
    return 0;
}

void displayStatus(struct Player player)
{
    printf("\n================================\n");
    printf("          PLAYER STATUS\n");
    printf("================================\n");

    printf("Money: PHP %d\n", player.money);
    printf("Energy: %d/100\n", player.energy);
    printf("Happiness: %d/100\n", player.happiness);

    printf("--------------------------------\n");
    printf("Total Earnings: PHP %d\n", player.totalEarnings);
    printf("Total Expenses: PHP %d\n", player.totalExpenses);

    printf("--------------------------------\n");
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (player.money >= SAVINGS_TARGET)
    {
        printf("Savings Progress: GOAL ACHIEVED!\n");
    }
    else
    {
        printf("Remaining: PHP %d\n",
               SAVINGS_TARGET - player.money);
    }

    printf("================================\n");
}

void updateMoney(struct Player *player, int amount)
{

    player->money += amount;

    if (amount > 0)
    {
        player->totalEarnings += amount;
    }
}

void updateEnergy(struct Player *player, int amount)
{

    player->energy += amount;
    if (player->energy > 100)
    {
        player->energy = 100;
    }

    if (player->energy < 0)
    {
        player->energy = 0;
    }
}

void updateHappiness(struct Player *player, int amount)
{
    player->happiness += amount;

    if (player->happiness > 100)
    {
        player->happiness = 100;
    }

    if (player->happiness < 0)
    {
        player->happiness = 0;
    }
}

int spendMoney(struct Player *player, int amount)
{
    if (amount <= 0)
    {
        return 0;
    }

    if (player->money < amount)
    {
        return 0;
    }

    player->money -= amount;
    player->totalExpenses += amount;

    return 1;
}

void startGame(struct Player *player)
{
    printf("\n================================\n");
    printf("       BUDGET BATTLE BEGINS\n");
    printf("================================\n");

    printf("\nWelcome, %s!\n", player->name);
    printf("Your 30-day challenge starts now!\n");

    for (int day = 1; day <= 30; day++)
    {
        player->workedToday = 0;

        // Give daily allowance
        updateMoney(player, DAILY_ALLOWANCE);

        printf("\n========== DAY %d ==========\n", day);
        printf("Daily allowance received: PHP %d\n", DAILY_ALLOWANCE);

        displayStatus(*player);

        if (day == 1)
            day1Story(player);
        if (day == 2)
            day2Story(player);
        if (day == 3)
            day3Story(player);
        if (day == 4)
            day4Story(player);
        if (day == 5)
            day5Story(player);
        if (day == 6)
            day6Story(player);
        if (day == 7)
            day7Story(player);
        if (day == 8)
            day8Story(player);
        if (day == 9)
            day9Story(player);
        if (day == 10)
            day10Story(player);
        if (day == 11)
            day11Story(player);
        if (day == 12)
            day12Story(player);
        if (day == 13)
            day13Story(player);
        if (day == 14)
            day14Story(player);
        if (day == 15)
            day15Story(player);
        if (day == 16)
            day16Story(player);
        if (day == 17)
            day17Story(player);
        if (day == 18)
            day18Story(player);
        if (day == 19)
            day19Story(player);
        if (day == 20)
            day20Story(player);
        if (day == 21)
            day21Story(player);
        if (day == 22)
            day22Story(player);
        if (day == 23)
            day23Story(player);
        if (day == 24)
            day24Story(player);
        if (day == 25)
            day25Story(player);
        if (day == 26)
            day26Story(player);
        if (day == 27)
            day27Story(player);
        if (day == 28)
            day28Story(player);
        if (day == 29)
            day29Story(player);
        if (day == 30)
            day30Story(player);

        // Check if the player can continue
        if (player->energy <= 0 || player->happiness <= 0)
        {
            printf("\n========== GAME OVER ==========\n");

            if (player->energy <= 0)
                printf("You ran out of energy!\n");

            if (player->happiness <= 0)
                printf("You lost all your happiness!\n");

            printf("Your 30-day challenge has ended.\n");
            return;
        }

        // Automatic weekend activities
        if ((day % 7 == 6 || day % 7 == 0) &&
            player->isHired == 1 &&
            player->trainingCompleted == 1 &&
            day != 6 && day != 13)
        {
            weekendChoice(player);
        }

        // Check again after weekend activities
        if (player->energy <= 0 || player->happiness <= 0)
        {
            printf("\n========== GAME OVER ==========\n");

            if (player->energy <= 0)
                printf("You ran out of energy!\n");

            if (player->happiness <= 0)
                printf("You lost all your happiness!\n");

            printf("Your 30-day challenge has ended.\n");
            return;
        }

        // Weekly report
        if (day % 7 == 0)
        {
            weeklyReport(player, day);
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    printf("\n========== FINAL RESULT ==========\n");
    printf("Final Money: PHP %d\n", player->money);
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (player->money >= SAVINGS_TARGET)
    {
        printf("\nCONGRATULATIONS! YOU WON!\n");
        printf("You successfully reached your savings goal!\n");
    }
    else
    {
        printf("\nCHALLENGE COMPLETED!\n");
        printf("You survived 30 days, but did not reach your savings goal.\n");
    }
}

void day1Story(struct Player *player)
{
    char message[100];

    printf("\n[6:30 AM - NEAR YOUR HOME]\n");

    showDialogue("Narrator",
                 "You step outside, carrying your backpack, ready for your first day at TUP Manila.");

    showDialogue("Narrator",
                 "Suddenly, someone taps your shoulder.");

    showDialogue("Player",
                 "New chapter, bagong environment. Sana naman this time, hindi puro problema.");

    showDialogue("Narrator",
                 "Suddenly, someone taps your shoulder.");

    sprintf(message, "Uy! Ikaw ba si %s? Dito ka rin ba?", player->name);
    showDialogue("Jelo", message);

    showDialogue("Player",
                 "Oo. Bakit?");

    showDialogue("Jelo",
                 "Nice! Ako si Jelo. First day mo rin?");

    showDialogue("Player",
                 "Yeah. Medyo nangangapa pa nga ako dito.");

    showDialogue("Jelo",
                 "Same! same! Anyway, tara. Kain muna tayo bago class.");

    showDialogue("Player",
                 "Ngayon agad? Kakadating ko lang.");

    showDialogue("Jelo",
                 "Omsim! importante ang breakfast. Tsaka libre mo?");

    showDialogue("Player",
                 "Ha? First day pa lang, uutangan mo na ako?");

    showDialogue("Jelo",
                 "HAHAHA! Eme lang. Wala rin akong pera.");

    showDialogue("Player", "Sige na nga. Tara, kain tayo.");
    breakfastChoice(player);

    showDialogue("Jelo", "Busog ka na? Tara na, paano tayo papunta sa school?");

    transportationChoice(player);

    showDialogue("Narrator",
                 "After choosing your transportation, you finally arrive at TUP Manila.");

    showDialogue("Narrator",
                 "Students are walking toward their classrooms.");

    showDialogue("Player", "Wait lang! First day pa lang, ayoko nang ma-late men.");

    showDialogue("Jelo", "Chill ka lang! Alam ko na mga shortcuts dito. Sundan mo 'ko!");

    showDialogue("Narrator", "You and Jelo head toward your classroom, unaware of the challenges waiting for you.");

    showDialogue("Narrator", "A few minutes later, you finally arrive at your classroom.");

    showDialogue("Jelo", "Welcome to college life! Dito, maraming activities, deadlines, at bawal matulog ng 8 hrs.");

    showDialogue("Player", "Aww, first day pa lang, tinatakot mo na ako.");

    showDialogue("Jelo", "Edni (hindi) kita tinatakot. Pinaghahanda lang kita. HAHAHA!");

    showDialogue("Narrator", "Your professor enters the room and introduces the course.");

    showDialogue("Professor", "Good morning, everyone! I hope you're ready for this semester.");

    showDialogue("Player", "Okay, this might be a challenging semester. Kailangan kong matutong mag-manage ng time at pera.");

    showDialogue("Narrator", "Your first class finally ends. You pack your things and prepare to leave.");

    showDialogue("Jelo", "So, how was your first class? Ready ka na ba sa college life?");

    showDialogue("Player", "I guess. Pero kailangan ko ring maghanap ng paraan para kumita ng pera.");

    showDialogue("Jelo", "Actually, may alam akong hiring malapit dito. Gusto mo bang subukan?");

    showDialogue("Player", "Hiring? Saan?");

    showDialogue("Jelo", "May fast-food branch malapit lang dito. Kailangan daw nila ng bagong crew.");

    showDialogue("Player", "Pwede kaya akong mag-apply kahit student ako?");

    showDialogue("Jelo", "Malay mo! At least may chance kang kumita habang nag-aaral.");

    showDialogue("Player", "Sige. Susubukan ko bukas. Kailangan ko rin talaga ng extra income.");

    showDialogue("Narrator", "After a long first day, you head home thinking about your studies, expenses, and the job opportunity.");

    showDialogue("Narrator", "Tomorrow, a new challenge awaits.");

    printf("\n================================\n");
    printf("          DAY 1 COMPLETE\n");
    printf("================================\n");
}

void showDialogue(const char speaker[], const char dialogue[])
{
    printf("\n%s\n", speaker);
    printf("%s\n", dialogue);

    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;
}

void breakfastChoice(struct Player *player)
{
    int choice;
    int completed = 0;

    printf("\n================================\n");
    printf("       BREAKFAST TIME\n");
    printf("================================\n");

    printf("\nJelo: Bro, gutom na ako. Ano'ng trip mong breakfast?\n");

    printf("\n[1] Zobel student meal - PHP 45\n");
    printf("[2] Fast-food meal - PHP 100\n");
    printf("[3] SM Manila foodcourt meal - PHP 150\n");
    printf("[4] Skip breakfast - PHP 0\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 4)
        {
            printf("\nInvalid choice! Please select 1 to 4.\n");
        }
        else
        {
            switch (choice)
            {
            case 1:
                if (spendMoney(player, 45))
                {
                    updateEnergy(player, 10);
                    updateHappiness(player, 0);

                    printf("\nYou bought a Zobel student meal.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another meal.\n");
                }
                break;

            case 2:
                if (spendMoney(player, 100))
                {
                    updateEnergy(player, 20);
                    updateHappiness(player, 5);

                    printf("\nYou bought a fast-food meal.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another meal.\n");
                }
                break;

            case 3:
                if (spendMoney(player, 150))
                {
                    updateEnergy(player, 25);
                    updateHappiness(player, 10);

                    printf("\nYou bought a SM Manila foodcourt meal.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another meal.\n");
                }
                break;

            case 4:
                updateEnergy(player, -10);
                updateHappiness(player, -10);

                printf("\nYou decided to skip breakfast.\n");
                completed = 1;
                break;
            }
        }

    } while (completed == 0);

    displayStatus(*player);
}

void transportationChoice(struct Player *player)
{
    int choice;
    int completed = 0;

    printf("\n================================\n");
    printf("       TRANSPORTATION TIME\n");
    printf("================================\n");

    printf("\nJelo: Bro, paano tayo papunta sa school?\n");

    printf("\n[1] Walk - PHP 0\n");
    printf("[2] Jeepney - PHP 15\n");
    printf("[3] Bus / Modern Jeep - PHP 25\n");
    printf("[4] Angkas - PHP 70\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 4)
        {
            printf("\nInvalid choice! Please select 1 to 4.\n");
        }
        else
        {
            switch (choice)
            {
            case 1:
                updateEnergy(player, -15);
                printf("\nYou walked to school.\n");
                completed = 1;
                break;

            case 2:
                if (spendMoney(player, 15))
                {
                    updateEnergy(player, -5);
                    printf("\nYou took a jeepney.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another option.\n");
                }
                break;

            case 3:
                if (spendMoney(player, 25))
                {
                    updateEnergy(player, -2);
                    printf("\nYou took a bus / modern jeep.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another option.\n");
                }
                break;

            case 4:
                if (spendMoney(player, 70))
                {
                    printf("\nYou booked an Angkas ride.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another option.\n");
                }
                break;
            }
        }

    } while (completed == 0);

    displayStatus(*player);
}

void day2Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 2: JOB APPLICATION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "The next afternoon, you arrive at a fast-food branch near TUP Manila.");

    showDialogue("Player",
                 "Sana matanggap ako. Kailangan ko talaga ng trabaho.");

    showDialogue("Jelo",
                 "Relax! Just be yourself. Basta huwag mong sabihin na wala kang experience sa lahat. HAHAHA!");

    showDialogue("Player",
                 "Omsim HAHAHA! Sige na, pasok na tayo.");

    showDialogue("Narrator",
                 "Inside the branch, you notice a crew member arranging orders.");

    showDialogue("Jelo",
                 "Mika! May ipapakilala ako sa'yo. Siya yung friend kong naghahanap ng work.");

    showDialogue("Mika",
                 "Oh, hello! Ikaw pala yung applicant. I'm Mika. Nice to meet you!");

    showDialogue("Player",
                 "Hi! Nice to meet you too.");

    showDialogue("Mika",
                 "Wait lang. Tawagin ko muna yung manager namin.");

    showDialogue("Narrator",
                 "A few moments later, the manager approaches you.");

    showDialogue("Sir Dante",
                 "Good afternoon. I'm Sir Dante, the branch manager. Ikaw ba yung gustong mag-apply?");

    showDialogue("Player",
                 "Yes, sir. I'm currently studying at TUP Manila, and I'm looking for a part-time job.");

    showDialogue("Sir Dante",
                 "Do you have any experience working in a fast-food restaurant?");

    showDialogue("Player",
                 "Wala pa po, sir. Pero willing po akong matuto.");

    showDialogue("Sir Dante",
                 "Good. We need someone responsible, especially during busy hours.");

    showDialogue("Mika",
                 "Don't worry! I'll help you learn the basics.");

    showDialogue("Sir Dante",
                 "Alright. We'll give you a chance. You can start your training tomorrow.");

    player->isHired = 1;

    showDialogue("Player",
                 "Thank you, sir! I'll do my best.");

    showDialogue("Jelo",
                 "Diba! Sabi ko sa'yo may chance ka! Libre mo na ako mamaya. HAHAHA!");

    showDialogue("Player",
                 "LALA! Wala pa nga akong sahod!");

    showDialogue("Narrator",
                 "After the interview, Mika takes you to the preparation area.");

    showDialogue("Mika",
                 "Since you're new here, let's start with something simple: checking customer orders.");

    showDialogue("Player",
                 "So kailangan ko lang siguraduhin na tama lahat ng items?");

    showDialogue("Mika",
                 "Exactly! Always check the receipt before giving the order.");

    showDialogue("Mika",
                 "Okay, may isang order tayo dito. Let's see if you can spot the mistake.");

    showDialogue("Narrator",
                 "Mika places a food tray in front of you.");

    orderCheckingGame(player);

    showDialogue("Mika",
                 "Not bad! Checking orders carefully is one of the most important things here.");

    showDialogue("Player",
                 "At least may natutunan ako today. Medyo nakaka-pressure din pala.");

    showDialogue("Mika",
                 "Masasanay ka din. Practice makes perfect!");

    showDialogue("Narrator",
                 "Your first training activity is complete. You head home, preparing for your first official training shift tomorrow.");
}

void orderCheckingGame(struct Player *player)
{

    int choice;

    printf("\n================================\n");
    printf("       ORDER CHECKING GAME\n");
    printf("================================\n");

    printf("\nCUSTOMER RECEIPT\n");
    printf("Burger: 1\n");
    printf("Fries: 1\n");
    printf("Drink: 1\n");

    printf("\nACTUAL FOOD TRAY\n");
    printf("Burger: 1\n");
    printf("Fries: 1\n");
    printf("Drink: 2\n");

    printf("\nWhich item has an incorrect quantity?\n");
    printf("[1] Burger\n");
    printf("[2] Fries\n");
    printf("[3] Drink\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Please select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 3)
    {
        printf("\nCorrect! You spotted the extra drink.\n");

        updateHappiness(player, 5);
        updateEnergy(player, -5);
    }
    else
    {
        printf("\nIncorrect! The drink quantity was wrong.\n");

        updateHappiness(player, -5);
        updateEnergy(player, -10);
    }

    printf("\nMika: Always double-check the receipt before serving!\n");

    displayStatus(*player);
}

void day3Story(struct Player *player)
{
    printf("\n================================\n");
    printf("    DAY 3: FIRST TRAINING SHIFT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "The next afternoon, you arrive at the fast-food branch for your first official training shift.");

    showDialogue("Player",
                 "First day ko sa actual work. Sana hindi ako magkamali.");

    showDialogue("Mika",
                 "Good aftie! Ready ka na ba? Today, tuturuan kita kung paano mag-handle ng customer orders.");

    showDialogue("Player",
                 "Ready na! I'll do my best.");

    showDialogue("Sir Dante",
                 "Remember, customer satisfaction is important. Always be polite and attentive.");

    showDialogue("Player",
                 "Understood, sir!");

    showDialogue("Narrator",
                 "Mika brings you to the counter and prepares your first customer order.");

    showDialogue("Mika",
                 "Okay, let's see how you handle your first customer!");

    customerServiceGame(player);

    showDialogue("Mika",
                 "Good job! Remember, always stay polite when dealing with customers.");

    showDialogue("Player",
                 "Got it! I'll keep that in mind.");

    showDialogue("Narrator",
                 "You finish your first customer-service activity and continue your training.");
    showDialogue("Mika",
                 "That's enough for today. You're getting the hang of it!");

    showDialogue("Player",
                 "Thank you for guiding me. Marami pa akong kailangang matutunan.");

    showDialogue("Mika",
                 "Don't worry. Tomorrow, you'll get to try something new.");

    showDialogue("Narrator",
                 "After your first training shift, you head home to rest and prepare for tomorrow.");

    printf("\n================================\n");
    printf("          DAY 3 COMPLETE\n");
    printf("================================\n");
}

void customerServiceGame(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("      CUSTOMER SERVICE GAME\n");
    printf("================================\n");

    printf("\nA customer approaches the counter.\n");
    printf("\"Excuse me, my order is taking too long!\"\n");

    printf("\nHow will you respond?\n");
    printf("[1] Apologize and politely check the order.\n");
    printf("[2] Ignore the customer.\n");
    printf("[3] Tell the customer to wait impatiently.\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 1)
    {
        printf("\nCorrect! The customer appreciates your politeness.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nThe customer becomes more frustrated.\n");
        updateHappiness(player, -5);
    }

    updateEnergy(player, -5);

    displayStatus(*player);
}

void cashierChallenge(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        CASHIER CHALLENGE\n");
    printf("================================\n");

    printf("\nCUSTOMER ORDER\n");
    printf("Burger: PHP 50\n");
    printf("Fries: PHP 30\n");
    printf("Total: PHP 80\n");

    printf("\nCustomer payment: PHP 100\n");

    printf("\nHow much change should you give?\n");
    printf("[1] PHP 10\n");
    printf("[2] PHP 20\n");
    printf("[3] PHP 30\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 2)
    {
        printf("\nCorrect! You gave the customer the correct change.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nIncorrect! The correct change was PHP 20.\n");
        updateHappiness(player, -5);
    }

    updateEnergy(player, -5);

    displayStatus(*player);
}

void day4Story(struct Player *player)
{
    printf("\n================================\n");
    printf(" DAY 4: HANDLING ORDERS\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "The next afternoon, you arrive at work. The branch is unusually busy.");

    showDialogue("Mika",
                 "Good timing! Lunch rush is about to start. Are you ready?");

    showDialogue("Player",
                 "Wait, ang daming customers! Ganito ba lagi kapag lunch break?");

    showDialogue("Mika",
                 "Sometimes! Just stay calm and focus on one order at a time.");

    showDialogue("Sir Dante",
                 "We need everyone's help today. Please work carefully and avoid mistakes.");

    showDialogue("Player",
                 "Understood, sir. I'll do my best.");

    showDialogue("Narrator",
                 "You take your position at the counter. Several customers are waiting for their orders.");

    showDialogue("Mika",
                 "Alright! Let's see how you handle the pressure.");

    showDialogue("Narrator",
                 "Your next training challenge is about to begin.");

    multipleOrderGame(player);

    showDialogue("Mika",
                 "Good job! Always compare the receipt with the prepared order.");

    showDialogue("Player",
                 "That was stressful! But I think I'm getting better.");

    showDialogue("Narrator",
                 "You successfully complete another training challenge.");

    showDialogue("Mika",
                 "Not bad! You're becoming more confident with every shift.");

    showDialogue("Player",
                 "Thanks! I just need more practice.");

    showDialogue("Sir Dante",
                 "Good work today. Keep improving, and you'll be ready for regular shifts.");

    showDialogue("Narrator",
                 "Your shift ends. You head home, tired but proud of your progress.");

    printf("\n================================\n");
    printf("          DAY 4 COMPLETE\n");
    printf("================================\n");
}

void multipleOrderGame(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("      MULTIPLE ORDER CHALLENGE\n");
    printf("================================\n");

    printf("\nCUSTOMER RECEIPT\n");
    printf("Burger: 2\n");
    printf("Fries: 2\n");
    printf("Drinks: 1\n");

    printf("\nPREPARED ORDER\n");
    printf("Burger: 2\n");
    printf("Fries: 1\n");
    printf("Drinks: 1\n");

    printf("\nWhich item is missing?\n");
    printf("[1] Burger\n");
    printf("[2] Fries\n");
    printf("[3] Drinks\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 2)
    {
        printf("\nCorrect! One order of fries is missing.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nIncorrect! You missed the missing fries.\n");
        updateHappiness(player, -5);
    }

    updateEnergy(player, -10);

    displayStatus(*player);
}

void day5Story(struct Player *player)
{
    printf("\n================================\n");
    printf("     DAY 5: SALARY DISCUSSION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "You arrive at the branch for another shift. Sir Dante asks to speak with you.");

    showDialogue("Sir Dante",
                 "Good afternoon! You've been doing well during your training.");

    showDialogue("Player",
                 "Thank you, sir! I'm still learning, but I'll keep improving.");

    showDialogue("Sir Dante",
                 "Since you've completed several training shifts, let's discuss your work schedule and salary.");

    showDialogue("Player",
                 "Really, sir? That's great news!");

    showDialogue("Sir Dante",
                 "Your salary will be based on your agreed working schedule. We'll explain the payment details before your regular shifts begin.");

    showDialogue("Player",
                 "Understood, sir. This will really help me with my school expenses.");

    showDialogue("Mika",
                 "See? Your hard work is starting to pay off!");

    showDialogue("Player",
                 "Hopefully! Tuition and daily expenses won't pay themselves. HAHAHA!");

    showDialogue("Narrator",
                 "You feel more motivated knowing that your job can help support your studies.");

    player->trainingCompleted = 1;

    printf("\n================================\n");
    printf("          DAY 5 COMPLETE\n");
    printf("================================\n");
}

void day6Story(struct Player *player)
{
    printf("\n================================\n");
    printf("     DAY 6: WEEKEND OPPORTUNITY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "It's Saturday. You wake up without worrying about your morning classes.");

    showDialogue("Player",
                 "Finally, weekend! At least wala na'kong classes today.");

    showDialogue("Jelo",
                 "Bro! May plans ka ba today? Gimik tayo!");

    showDialogue("Player",
                 "Gusto ko sana, pero kailangan ko rin mag-ipon.");

    showDialogue("Narrator",
                 "Your phone suddenly receives a message from Mika.");

    showDialogue("Mika",
                 "Hey! We're a little short-staffed today. Would you be interested in taking an extra shift?");

    showDialogue("Player",
                 "An extra shift? That could help with my expenses.");

    showDialogue("Jelo",
                 "Grabe, trabaho na naman? Enjoy your weekend din minsan!");

    showDialogue("Player",
                 "HAHAHA! Kailangan nating maging responsible. I'll think about it.");

    showDialogue("Narrator",
                 "You realize that weekends can be an opportunity to earn more, but you also need time to rest.");

    weekendChoice(player);

    printf("\n================================\n");
    printf("          DAY 6 COMPLETE\n");
    printf("================================\n");
}

void weekendChoice(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       WEEKEND ACTIVITIES\n");
    printf("================================\n");

    printf("\nWhat would you like to do today?\n");
    printf("[1] Take an extra 8-hour shift (+PHP 610)\n");
    printf("[2] Rest at home\n");
    printf("[3] Hang out with Jelo\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    switch (choice)
    {

    case 1:
        if (player->isHired == 1 && player->trainingCompleted == 1)
        {
            if (player->workedToday == 0)
            {
                completeWorkShift(player);
                updateHappiness(player, 5);
                printf("\nYou earned money while gaining work experience!\n");
            }
            else
            {
                printf("\nYou have already completed a shift today!\n");
            }
        }
        else
        {
            printf("\nYou are not yet qualified for a regular shift.\n");
        }
        break;

    case 2:
        printf("\nYou spend the day resting at home.\n");
        updateEnergy(player, 15);
        updateHappiness(player, 5);
        break;

    case 3:
        printf("\nYou spend the afternoon hanging out with Jelo.\n");
        updateEnergy(player, 5);
        updateHappiness(player, 15);
        break;
    }

    displayStatus(*player);
}

void day7Story(struct Player *player)
{
    printf("\n================================\n");
    printf("      DAY 7: FIRST WEEK\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "It's Sunday. After a busy week of classes and training, you finally have time to reflect.");

    showDialogue("Player",
                 "One week na agad! Ang dami nang nangyari.");

    showDialogue("Jelo",
                 "Kamusta naman ang first week mo sa work? Buhay ka pa ba? HAHAHA!");

    showDialogue("Player",
                 "Medyo nakakapagod, pero at least may extra money ako.");

    showDialogue("Jelo",
                 "Good! pero tandaan mo, hindi puro trabaho. Take care of yourself too.");

    showDialogue("Player",
                 "Tama ka. Kailangan ko rin ng pahinga.");

    showDialogue("Narrator",
                 "You spend the rest of the day preparing for another week of school and work.");

    printf("\n================================\n");
    printf("          DAY 7 COMPLETE\n");
    printf("================================\n");
}

void weeklyReport(struct Player *player, int daysCompleted)
{
    printf("\n================================\n");
    printf("         WEEKLY REPORT\n");
    printf("================================\n");

    printf("\nDays Completed: %d / 30\n", daysCompleted);
    printf("Total Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);

    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (player->money < SAVINGS_TARGET)
    {
        printf("Remaining to Goal: PHP %d\n",
               SAVINGS_TARGET - player->money);
    }
    else
    {
        printf("Savings Goal: ACHIEVED!\n");
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("       END OF WEEK %d\n", daysCompleted / 7);
    printf("================================\n");
}

void day8Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 8: FIRST PAYDAY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "A new week begins. You arrive at the restaurant for your first regular shift.");

    showDialogue("Mika",
                 "Good morning! Ready for another busy day?");

    showDialogue("Player",
                 "Ready! Hopefully, today goes smoothly.");

    showDialogue("Sir Dante",
                 "You've completed your training. Starting today, you'll receive your regular shift pay.");

    cashierChallenge(player);

    showDialogue("Player",
                 "Thank you, sir! This will really help with my expenses.");

    showDialogue("Narrator",
                 "You complete your eight-hour shift and prepare to receive your first salary.");

    completeWorkShift(player);

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 8 COMPLETE\n");
    printf("================================\n");
}

void completeWorkShift(struct Player *player)
{
    if (player->isHired != 1 || player->trainingCompleted != 1)
    {
        printf("\nYou are not yet qualified for a regular shift!\n");
        return;
    }

    if (player->workedToday == 1)
    {
        printf("\nYou have already completed a shift today!\n");
        return;
    }

    updateMoney(player, SHIFT_PAY);
    player->workedToday = 1;

    printf("\n================================\n");
    printf("       WORK SHIFT COMPLETED\n");
    printf("================================\n");

    printf("You completed an 8-hour shift!\n");
    printf("Salary received: PHP %d\n", SHIFT_PAY);

    updateEnergy(player, -20);
}

void cashierChallengeMedium(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("     CASHIER CHALLENGE\n");
    printf("         MEDIUM LEVEL\n");
    printf("================================\n");

    printf("\nCUSTOMER ORDER\n");
    printf("Burger: 2 x PHP 50\n");
    printf("Fries: 1 x PHP 30\n");
    printf("Drinks: 2 x PHP 20\n");

    printf("\nCustomer payment: PHP 200\n");

    printf("\nHow much change should you give?\n");
    printf("[1] PHP 20\n");
    printf("[2] PHP 30\n");
    printf("[3] PHP 40\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 2)
    {
        printf("\nCorrect! The total was PHP 170.\n");
        printf("You gave the correct PHP 30 change.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nIncorrect! The correct change was PHP 30.\n");
        updateHappiness(player, -8);
    }

    updateEnergy(player, -10);

    displayStatus(*player);
}

void cashierChallengeHard(struct Player *player)
{
    int choice1, choice2;

    printf("\n================================\n");
    printf("     CASHIER CHALLENGE\n");
    printf("         HARD LEVEL\n");
    printf("================================\n");

    printf("\nCUSTOMER 1 ORDER\n");
    printf("Burger: 3 x PHP 50\n");
    printf("Drinks: 2 x PHP 20\n");
    printf("Payment: PHP 200\n");

    printf("\nHow much change should you give?\n");
    printf("[1] PHP 10\n");
    printf("[2] PHP 20\n");
    printf("[3] PHP 30\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice1);
        getchar();

        if (choice1 < 1 || choice1 > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice1 < 1 || choice1 > 3);

    printf("\nCUSTOMER 2 ORDER\n");
    printf("Fries: 2 x PHP 30\n");
    printf("Burger: 1 x PHP 50\n");
    printf("Payment: PHP 200\n");

    printf("\nHow much change should you give?\n");
    printf("[1] PHP 80\n");
    printf("[2] PHP 90\n");
    printf("[3] PHP 100\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice2);
        getchar();

        if (choice2 < 1 || choice2 > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice2 < 1 || choice2 > 3);

    if (choice1 == 1 && choice2 == 2)
    {
        printf("\nExcellent! Both customers received the correct change.\n");
        updateHappiness(player, 10);
    }
    else if (choice1 == 1 || choice2 == 2)
    {
        printf("\nYou got one transaction correct!\n");
        updateHappiness(player, 3);
    }
    else
    {
        printf("\nBoth transactions were incorrect.\n");
        updateHappiness(player, -10);
    }

    updateEnergy(player, -15);

    displayStatus(*player);
}

void scamDetectiveEasy(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("         SCAM DETECTIVE\n");
    printf("           EASY LEVEL\n");
    printf("================================\n");

    printf("\nYou receive a text message:\n");

    printf("\n\"CONGRATULATIONS! Your number was selected!\n");
    printf("Claim your PHP 50,000 prize today.\n");
    printf("Pay PHP 500 processing fee to release your winnings.\"\n");

    printf("\nWhat should you do?\n");
    printf("[1] Send PHP 500 immediately.\n");
    printf("[2] Ignore and report the message.\n");
    printf("[3] Give them your bank password.\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 2)
    {
        printf("\nCorrect! This is a suspicious prize message.\n");
        printf("Never pay fees or share sensitive information to claim an unexpected prize.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nIncorrect! This message shows common scam warning signs.\n");
        updateHappiness(player, -5);
    }

    updateEnergy(player, -5);

    displayStatus(*player);
}

void scamDetectiveMedium(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("         SCAM DETECTIVE\n");
    printf("          MEDIUM LEVEL\n");
    printf("================================\n");

    printf("\nYou receive a message from an unknown number:\n");

    printf("\n\"Pre! Join our exclusive betting group.\n");
    printf("Deposit PHP 500 and get a guaranteed\n");
    printf("PHP 1,000 return tomorrow!\n");
    printf("Limited slots. Send your payment now!\"\n");

    printf("\nWhat is the biggest warning sign?\n");
    printf("[1] It promises guaranteed profit from betting.\n");
    printf("[2] It uses a mobile phone.\n");
    printf("[3] It asks you to join a group.\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 1)
    {
        printf("\nCorrect! Betting involves risk, so profit cannot be guaranteed.\n");
        printf("Be cautious of anyone promising guaranteed returns.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nIncorrect! You missed the biggest warning sign.\n");
        printf("Be careful with guaranteed-profit promises.\n");
        updateHappiness(player, -8);
    }

    updateEnergy(player, -10);

    displayStatus(*player);
}

void scamDetectiveHard(struct Player *player)
{
    int choice1, choice2;

    printf("\n================================\n");
    printf("         SCAM DETECTIVE\n");
    printf("           HARD LEVEL\n");
    printf("================================\n");

    printf("\nYou receive an online investment offer:\n");

    printf("\n\"Earn PHP 5,000 daily!\n");
    printf("Deposit PHP 1,000 to activate your account.\n");
    printf("Guaranteed returns, no risk!\n");
    printf("Invite three friends to unlock your withdrawal.\n");
    printf("Offer expires in 10 minutes!\"\n");

    printf("\nQUESTION 1:\n");
    printf("Which is a warning sign?\n");
    printf("[1] Guaranteed returns and pressure to deposit.\n");
    printf("[2] The message contains numbers.\n");
    printf("[3] The person uses an online account.\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice1);
        getchar();

        if (choice1 < 1 || choice1 > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice1 < 1 || choice1 > 3);

    printf("\nQUESTION 2:\n");
    printf("What is another serious warning sign?\n");
    printf("[1] The offer has a company name.\n");
    printf("[2] You must invite friends before withdrawing.\n");
    printf("[3] The message has a greeting.\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice2);
        getchar();

        if (choice2 < 1 || choice2 > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice2 < 1 || choice2 > 3);

    if (choice1 == 1 && choice2 == 2)
    {
        printf("\nExcellent! You identified both warning signs.\n");
        printf("You avoided a suspicious financial offer.\n");
        updateHappiness(player, 10);
    }
    else if (choice1 == 1 || choice2 == 2)
    {
        printf("\nYou identified one warning sign correctly.\n");
        updateHappiness(player, 3);
    }
    else
    {
        printf("\nYou missed both warning signs.\n");
        updateHappiness(player, -10);
    }

    updateEnergy(player, -15);

    displayStatus(*player);
}

void budgetShoppingEasy(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        BUDGET SHOPPING\n");
    printf("          EASY LEVEL\n");
    printf("================================\n");

    printf("\nYou have PHP 150 to buy food.\n");

    printf("\nAVAILABLE ITEMS\n");
    printf("Rice: PHP 50\n");
    printf("Eggs: PHP 40\n");
    printf("Bread: PHP 30\n");
    printf("Soft drink: PHP 40\n");

    printf("\nWhich combination costs exactly PHP 120?\n");
    printf("[1] Rice + Eggs + Bread\n");
    printf("[2] Rice + Soft drink\n");
    printf("[3] Eggs + Bread + Soft drink\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 1)
    {
        printf("\nThe combination costs PHP 120. You stayed within the budget.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nIncorrect! The correct combination costs PHP 120.\n");
        updateHappiness(player, -5);
    }

    updateEnergy(player, -5);

    displayStatus(*player);
}

void budgetShoppingMedium(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        BUDGET SHOPPING\n");
    printf("         MEDIUM LEVEL\n");
    printf("================================\n");

    printf("\nYou have PHP 200 for groceries.\n");

    printf("\nAVAILABLE ITEMS\n");
    printf("Rice: PHP 60\n");
    printf("Eggs: PHP 50\n");
    printf("Vegetables: PHP 40\n");
    printf("Canned sardines: PHP 30\n");
    printf("Soft drink: PHP 35\n");

    printf("\nWhich combination includes rice, protein, and vegetables\n");
    printf("while staying within your PHP 200 budget?\n");

    printf("\n[1] Rice + Eggs + Vegetables + Sardines (PHP 180)\n");
    printf("[2] Rice + Eggs + Soft drink + Sardines (PHP 175)\n");
    printf("[3] Rice + Vegetables + Soft drink (PHP 135)\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 1)
    {
        printf("\nExcellent! You prioritized essential groceries.\n");
        printf("The combination costs PHP 180. You have PHP 20 remaining.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nYou stayed within budget, but your selection\n");
        printf("could have provided more essential food.\n");
        updateHappiness(player, -3);
    }

    updateEnergy(player, -10);

    displayStatus(*player);
}

void budgetShoppingHard(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        BUDGET SHOPPING\n");
    printf("          HARD LEVEL\n");
    printf("================================\n");

    printf("\nYou have PHP 250 for the day.\n");

    printf("\nAVAILABLE ITEMS\n");
    printf("Rice and viand: PHP 80\n");
    printf("Transportation: PHP 30\n");
    printf("School printing: PHP 40\n");
    printf("Drinking water: PHP 15\n");
    printf("Milk tea: PHP 90\n");
    printf("Snacks: PHP 50\n");

    printf("\nYour priorities are food, transportation,\n");
    printf("school printing, and drinking water.\n");

    printf("\nWhich combination covers all four necessities\n");
    printf("without exceeding PHP 250?\n");

    printf("\n[1] Food + Transportation + Printing + Water (PHP 165)\n");
    printf("[2] Food + Transportation + Milk tea + Snacks (PHP 250)\n");
    printf("[3] Food + Printing + Milk tea + Water (PHP 225)\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 1)
    {
        printf("\nExcellent! You covered all your necessities.\n");
        printf("The combination costs PHP 165. You have PHP 85 remaining.\n");
        updateHappiness(player, 10);
    }
    else
    {
        printf("\nYou failed to cover all your daily necessities.\n");
        printf("Remember to prioritize essential expenses.\n");
        updateHappiness(player, -10);
    }

    updateEnergy(player, -15);

    displayStatus(*player);
}

void financialQuizEasy(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        FINANCIAL QUIZ\n");
    printf("          EASY LEVEL\n");
    printf("================================\n");

    printf("\nYou receive PHP 1,000 for the week.\n");
    printf("Transportation costs PHP 250.\n");
    printf("Meals cost PHP 400.\n");
    printf("A school activity requires PHP 200.\n");
    printf("You see an accessory worth PHP 150 on sale.\n");

    printf("\nWhat is the most responsible decision?\n");

    printf("[1] Buy the accessory and reduce your food expenses.\n");
    printf("[2] Set aside money for necessities before considering the accessory.\n");
    printf("[3] Buy the accessory and earn extra money to cover your expenses.\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 2)
    {
        printf("\nCorrect! Prioritize your essential expenses before buying wants.\n");
        updateHappiness(player, 10);
    }
    else
    {
        printf("\nIncorrect! Protect your necessities before making optional purchases.\n");
        updateHappiness(player, -5);
    }

    updateEnergy(player, -5);
    displayStatus(*player);
}

void financialQuizMedium(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        FINANCIAL QUIZ\n");
    printf("         MEDIUM LEVEL\n");
    printf("================================\n");

    printf("\nYou have PHP 2,500 in savings.\n");
    printf("Your school project requires PHP 700 in three days.\n");
    printf("Your phone needs an PHP 800 repair.\n");
    printf("Your next salary arrives in five days.\n");
    printf("You can temporarily borrow a phone from a relative.\n");

    printf("\nWhat is the most responsible decision?\n");

    printf("[1] Repair your phone immediately and find a way to pay for the project.\n");
    printf("[2] Reserve the project money and postpone the repair if possible.\n");
    printf("[3] Spend PHP 400 on a temporary repair and reserve PHP 700 for the project.\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 2)
    {
        printf("\nCorrect! Prioritize urgent expenses and consider temporary alternatives.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nIncorrect! Consider the urgency of your expenses before spending.\n");
        updateHappiness(player, -8);
    }

    updateEnergy(player, -10);
    displayStatus(*player);
}

void financialQuizHard(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        FINANCIAL QUIZ\n");
    printf("          HARD LEVEL\n");
    printf("================================\n");

    printf("\nYou have PHP 3,000 in savings.\n");
    printf("You need PHP 1,000 for school expenses next week.\n");
    printf("You want to maintain PHP 1,000 as emergency savings.\n");

    printf("\nA friend offers an online investment promising\n");
    printf("a 20 percent return every week.\n");
    printf("However, you have not verified the company or its risks.\n");

    printf("\nWhat is the most responsible decision?\n");

    printf("[1] Invest PHP 1,000 because the promised return could increase your savings.\n");
    printf("[2] Borrow PHP 1,000 to invest without using your existing savings.\n");
    printf("[3] Verify the investment and its risks before considering investing money you can afford to lose.\n");

    do
    {
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 3)
    {
        printf("\nExcellent decision! Always verify an investment before risking your money.\n");
        updateHappiness(player, 10);
    }
    else
    {
        printf("\nIncorrect! Never risk money without understanding and verifying an investment.\n");
        updateHappiness(player, -10);
    }

    updateEnergy(player, -15);
    displayStatus(*player);
}

void weekendWorkChoice(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       WEEKEND ACTIVITIES\n");
    printf("================================\n");

    printf("\n[1] Work an 8-hour shift (+PHP 610)");
    printf("\n[2] Rest and recover energy");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        completeWorkShift(player);
        printf("\nYou feel tired after your shift.\n");
        break;

    case 2:
        updateEnergy(player, 20);
        printf("\nYou decided to rest today.\n");
        break;

    default:
        printf("\nInvalid choice! You spent the day resting.\n");
        updateEnergy(player, 20);
        break;
    }

    displayStatus(*player);
}

void day9Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("     DAY 9: SCHOOL EXPENSES\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "After class, your professor announces an upcoming group activity.");

    showDialogue("Jelo",
                 "Bro, kailangan daw natin bumili ng school supplies para sa next activity.");

    showDialogue("Player",
                 "Again? Kakabili ko lang ng supplies last week!");

    printf("\n[1] Buy complete supplies - PHP 100\n");
    printf("[2] Buy basic supplies - PHP 50\n");

    do
    {
        printf("\nYour choice: ");
        scanf("%d", &choice);
        getchar();
    } while (choice < 1 || choice > 2);

    if (choice == 1 && spendMoney(player, 100))
    {
        updateHappiness(player, 10);
        printf("\nYou bought complete school supplies.\n");
    }
    else if (choice == 2 && spendMoney(player, 50))
    {
        updateHappiness(player, 5);
        printf("\nYou bought basic school supplies.\n");
    }
    else
    {
        printf("\nNot enough money! You couldn't buy the supplies.\n");
        updateHappiness(player, -10);
    }

    displayStatus(*player);
}

void day10Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 10: BUSY SHIFT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "You arrive at work and discover that the restaurant is crowded.");

    showDialogue("Mika",
                 "Grabe, ang daming customers today! We need to work faster.");

    showDialogue("Player",
                 "Kaya natin 'to. One order at a time!");

    showDialogue("Sir Dante",
                 "Good work today. Your performance is improving.");

    showDialogue("Narrator",
                 "After a tiring shift, you finally get some time to rest.");

    updateEnergy(player, -15);
    updateHappiness(player, 5);

    printf("\nYou completed a busy workday.\n");

    financialQuizEasy(player);

    printf("\n================================\n");
    printf("          DAY 10 COMPLETE\n");
    printf("================================\n");
}

void day11Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("   DAY 11: GROUP PROJECT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Your classmates approach you about an upcoming group project.");

    showDialogue("Jelo",
                 "Bro, kailangan natin mag-contribute para sa project materials.");

    printf("\n[1] Contribute PHP 100\n");
    printf("[2] Contribute PHP 50\n");
    printf("[3] Explain that your budget is limited\n");

    do
    {
        printf("\nYour choice: ");
        scanf("%d", &choice);
        getchar();
    } while (choice < 1 || choice > 3);

    if (choice == 1 && spendMoney(player, 100))
    {
        updateHappiness(player, 10);
        printf("\nYou contributed PHP 100.\n");
    }
    else if (choice == 2 && spendMoney(player, 50))
    {
        updateHappiness(player, 5);
        printf("\nYou contributed PHP 50.\n");
    }
    else if (choice == 3)
    {
        updateHappiness(player, -5);
        printf("\nYou explained your financial situation to your group.\n");
    }
    else
    {
        printf("\nNot enough money! You couldn't contribute.\n");
        updateHappiness(player, -5);
    }

    displayStatus(*player);
}

void day12Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("      DAY 12: FOOD BUDGET\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "After a long day of classes, you and Jelo decide to grab something to eat.");

    showDialogue("Jelo",
                 "Bro, treat yourself naman! Anong kakainin natin?");

    printf("\n[1] Budget meal - PHP 50 (+10 Energy)\n");
    printf("[2] Special meal - PHP 100 (+20 Energy, +5 Happiness)\n");
    printf("[3] Save money and skip the meal\n");

    do
    {
        printf("\nYour choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    if (choice == 1 && spendMoney(player, 50))
    {
        updateEnergy(player, 10);
        printf("\nYou bought a budget meal.\n");
    }
    else if (choice == 2 && spendMoney(player, 100))
    {
        updateEnergy(player, 20);
        updateHappiness(player, 5);
        printf("\nYou bought a special meal.\n");
    }
    else if (choice == 3)
    {
        updateEnergy(player, -10);
        updateHappiness(player, -5);
        printf("\nYou decided to save your money.\n");
    }
    else
    {
        printf("\nNot enough money! You couldn't buy the meal.\n");
        updateEnergy(player, -10);
    }

    showDialogue("Narrator",
                 "While checking your phone, you notice a suspicious message claiming that you won a cash prize.");

    scamDetectiveEasy(player);

    printf("\n================================\n");
    printf("          DAY 12 COMPLETE\n");
    printf("================================\n");
}

void day13Story(struct Player *player)
{
    printf("\n================================\n");
    printf("    DAY 13: SECOND WEEKEND\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "It's Saturday. Mika sends you a message asking if you can help at the restaurant.");

    showDialogue("Mika",
                 "Hey! We need extra crew today. Are you available?");

    showDialogue("Player",
                 "Another shift? Kailangan ko ring mag-ipon.");

    showDialogue("Narrator",
                 "You decide how to spend your Saturday.");

    weekendChoice(player);

    printf("\n================================\n");
    printf("          DAY 13 COMPLETE\n");
    printf("================================\n");
}

void day14Story(struct Player *player)
{
    printf("\n================================\n");
    printf("     DAY 14: SUNDAY RESET\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "It's Sunday. You finally have time to relax after a busy week.");

    showDialogue("Jelo",
                 "Bro, pahinga muna tayo. Deserve natin 'to!");

    showDialogue("Player",
                 "Tama ka. Hindi pwedeng puro trabaho at school.");

    showDialogue("Narrator",
                 "Before the week begins, you help plan a small grocery budget.");

    showDialogue("Jelo",
                 "May PHP 150 tayo para sa food. Let's make sure we spend it wisely.");

    budgetShoppingEasy(player);

    showDialogue("Narrator",
                 "After planning the groceries, you spend the rest of the day recovering.");

    updateEnergy(player, 20);
    updateHappiness(player, 10);

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 14 COMPLETE\n");
    printf("================================\n");
}

void day15Story(struct Player *player)
{
    printf("\n================================\n");
    printf("    DAY 15: MID-MONTH REPORT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Half of your 30-day challenge is complete. You decide to review your finances.");

    showDialogue("Player",
                 "Fifteen days na. Sana enough na yung naipon ko.");

    printf("\n========== FINANCIAL CHECK ==========\n");
    printf("Current Money: PHP %d\n", player->money);
    printf("Total Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    showDialogue("Jelo",
                 "Halfway na tayo! Kaya pa ba ang budget mo?");

    showDialogue("Player",
                 "Kailangan kong maging mas maingat sa spending. May fifteen days pa ako.");

    printf("\n================================\n");
    printf("          DAY 15 COMPLETE\n");
    printf("================================\n");
}

void day16Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 16: GROUP PROJECT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Your group project is due soon. Your classmates begin discussing the materials you need.");

    showDialogue("Jelo",
                 "Bro, we need to buy some materials. Everyone has to contribute.");

    printf("\nChoose how much you can contribute:\n");
    printf("[1] Complete contribution - PHP 100\n");
    printf("[2] Basic contribution - PHP 50\n");
    printf("[3] Explain your financial situation\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        if (spendMoney(player, 100))
        {
            updateHappiness(player, 10);
            printf("\nYou contributed PHP 100 to the project.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money. Your group understands, but you feel disappointed.\n");
        }
        break;

    case 2:
        if (spendMoney(player, 50))
        {
            updateHappiness(player, 5);
            printf("\nYou contributed PHP 50 to the project.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money to contribute.\n");
        }
        break;

    case 3:
        updateHappiness(player, -5);
        printf("\nYou explain that your budget is limited because you are also working.\n");
        break;
    }

    showDialogue("Narrator",
                 "You realize that managing your money is becoming just as important as finishing your schoolwork.");

    displayStatus(*player);
}

void day17Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 17: BUSY SHIFT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "After your classes, you head to the fast-food branch for your scheduled shift.");

    showDialogue("Mika",
                 "It's pretty busy today. We have a lot of customers, so let's do our best.");

    showDialogue("Sir Dante",
                 "Good work showing up on time. Let's get started.");

    showDialogue("Mika",
                 "Can you handle the cashier for a while? We have several orders waiting.");

    cashierChallengeMedium(player);

    completeWorkShift(player);

    showDialogue("Narrator",
                 "The shift was exhausting, but earning money helps you stay on track with your savings goal.");

    displayStatus(*player);
}

void day18Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 18: SCHOOL ACTIVITY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Your class announces an upcoming school activity. Your friends invite you to participate.");

    showDialogue("Jelo",
                 "Tara! We should join. It might be fun to take a break from our usual routine.");

    printf("\nWhat will you do?\n");
    printf("[1] Join and contribute PHP 100\n");
    printf("[2] Join with a smaller contribution of PHP 50\n");
    printf("[3] Skip the activity\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        if (spendMoney(player, 100))
        {
            updateHappiness(player, 15);
            printf("\nYou joined the activity and enjoyed spending time with your classmates.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money for the contribution.\n");
        }
        break;

    case 2:
        if (spendMoney(player, 50))
        {
            updateHappiness(player, 8);
            printf("\nYou joined the activity while keeping your expenses low.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money for the contribution.\n");
        }
        break;

    case 3:
        updateHappiness(player, -5);
        printf("\nYou decide to save your money and focus on your responsibilities.\n");
        break;
    }

    financialQuizMedium(player);

    printf("\n================================\n");
    printf("          DAY 18 COMPLETE\n");
    printf("================================\n");
}

void day19Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 19: UNEXPECTED EXPENSE\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "On your way home, you notice that your school bag is damaged. Some of your things might fall out.");

    showDialogue("Jelo",
                 "Bro, that bag looks like it's about to give up. You should probably fix it.");

    if (spendMoney(player, 150))
    {
        printf("\nYou spend PHP 150 repairing your school bag.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nYou don't have enough money to repair your bag right now.\n");
        updateHappiness(player, -5);
    }

    showDialogue("Narrator",
                 "Later that evening, you receive an unexpected message inviting you to join an online betting group.");

    scamDetectiveMedium(player);

    printf("\n================================\n");
    printf("          DAY 19 COMPLETE\n");
    printf("================================\n");
}

void day20Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 20: SATURDAY RESET\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "It's Saturday. After another demanding week, you finally have some time to decide how to spend your day.");

    showDialogue("Mika",
                 "Don't forget to take care of yourself. You can't work properly if you're always exhausted.");

    showDialogue("Narrator",
                 "You think about your remaining money, your energy, and your savings goal.");

    displayStatus(*player);
}

void day21Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 21: SUNDAY REFLECTION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "It's Sunday. You spend the morning at home, thinking about how much has changed since the challenge began.");

    showDialogue("Jelo",
                 "Three weeks already! Konti na lang, bro. Keep going!");

    updateEnergy(player, 15);
    updateHappiness(player, 5);

    showDialogue("Narrator",
                 "You take the day to recover and prepare for another week.");

    displayStatus(*player);
}

void day22Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 22: EXAM PREPARATION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Your instructor announces that an examination is approaching. You need to prepare while keeping up with your work schedule.");

    showDialogue("Jelo",
                 "Have you started reviewing? We can study together after class.");

    printf("\nHow will you prepare?\n");
    printf("[1] Buy review materials - PHP 100\n");
    printf("[2] Use free notes and study with Jelo\n");
    printf("[3] Rest first and study later\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Select 1, 2, or 3.\n");
        }

    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        if (spendMoney(player, 100))
        {
            updateEnergy(player, -5);
            updateHappiness(player, 5);
            printf("\nYou buy review materials and spend time studying.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money for the review materials. You decide to use your free notes instead.\n");
        }
        break;

    case 2:
        updateEnergy(player, -5);
        updateHappiness(player, 10);
        printf("\nYou study with Jelo using free notes. You save money and learn together.\n");
        break;

    case 3:
        updateEnergy(player, 10);
        printf("\nYou take some time to rest before preparing for the examination.\n");
        break;
    }

    showDialogue("Narrator",
                 "After studying, you help Jelo plan a grocery budget for the remaining days.");

    budgetShoppingMedium(player);

    printf("\n================================\n");
    printf("          DAY 22 COMPLETE\n");
    printf("================================\n");
}

void day23Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 23: BUSY WORKDAY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Tuesday. The fast-food branch is unusually busy, and the manager asks everyone to help.");

    showDialogue("Sir Dante",
                 "We have many customers today. I need everyone to give their best.");

    showDialogue("Player",
                 "Kaya ko ito. Malapit na matapos ang challenge.");

    if (player->isHired == 1 && player->trainingCompleted == 1)
    {
        showDialogue("Mika",
                     "You're handling the cashier today. Let's see how well you can manage multiple transactions.");

        cashierChallengeHard(player);

        completeWorkShift(player);
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nYou are not yet qualified for a regular shift.\n");
    }

    showDialogue("Narrator",
                 "You remind yourself that every completed shift brings you closer to your savings goal.");

    displayStatus(*player);
}

void day24Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 24: SCHOOL DEADLINE\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Wednesday. Your group project is almost due, and your classmates need to finalize the presentation.");

    showDialogue("Jelo",
                 "Bro, kailangan na nating tapusin. May kulang pa tayong presentation materials.");

    printf("\nWhat will you do?\n");
    printf("[1] Buy presentation materials - PHP 100\n");
    printf("[2] Use available materials - PHP 0\n");
    printf("[3] Help by organizing the presentation - PHP 0\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
            printf("Invalid choice! Select 1, 2, or 3.\n");

    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        if (spendMoney(player, 100))
        {
            updateHappiness(player, 10);
            printf("\nYou bought the materials needed for the presentation.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money for the materials.\n");
        }
        break;

    case 2:
        updateHappiness(player, 5);
        printf("\nYour group uses available materials and saves money.\n");
        break;

    case 3:
        updateEnergy(player, -5);
        updateHappiness(player, 8);
        printf("\nYou organize the presentation and help your group finish on time.\n");
        break;
    }

    displayStatus(*player);
}

void day25Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 25: SAVINGS CHECK\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Thursday. You take a moment to review your finances as the final days approach.");

    showDialogue("Player",
                 "Five days na lang. Kailangan kong malaman kung malapit na ako sa goal ko.");

    printf("\n========== FINANCIAL UPDATE ==========\n");
    printf("Current Money: PHP %d\n", player->money);
    printf("Total Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (player->money >= SAVINGS_TARGET)
    {
        printf("\nYou have already reached your savings target!\n");
    }
    else
    {
        printf("\nRemaining amount needed: PHP %d\n",
               SAVINGS_TARGET - player->money);
    }

    showDialogue("Narrator",
                 "You realize that the final few days will require careful decisions.");

    financialQuizHard(player);

    printf("\n================================\n");
    printf("          DAY 25 COMPLETE\n");
    printf("================================\n");
}

void day26Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 26: TEMPTING PURCHASE\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Friday. While browsing online, you see a gadget accessory that catches your attention.");

    showDialogue("Jelo",
                 "Bro, bilhin mo na! Deserve mo naman yan after all your hard work.");

    printf("\nWhat will you do?\n");
    printf("[1] Buy the accessory - PHP 300\n");
    printf("[2] Save your money - PHP 0\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 2)
            printf("Invalid choice! Select 1 or 2.\n");

    } while (choice < 1 || choice > 2);

    switch (choice)
    {
    case 1:
        if (spendMoney(player, 300))
        {
            updateHappiness(player, 10);
            printf("\nYou bought the accessory. It feels good to reward yourself.\n");
        }
        else
        {
            updateHappiness(player, -5);
            printf("\nYou don't have enough money for the accessory.\n");
        }
        break;

    case 2:
        updateHappiness(player, 5);
        printf("\nYou decide to prioritize your savings goal.\n");
        break;
    }

    displayStatus(*player);
}

void day27Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 27: SATURDAY OPPORTUNITY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Saturday arrives. You remember that you can take an extra shift or spend time recovering.");

    showDialogue("Mika",
                 "We could use some extra help today. Let me know if you're interested.");

    showDialogue("Player",
                 "I need to think about my money and my energy.");

    showDialogue("Narrator",
                 "Later, you receive an online investment offer promising unusually high daily returns.");

    scamDetectiveHard(player);

    printf("\n================================\n");
    printf("          DAY 27 COMPLETE\n");
    printf("================================\n");
}

void day28Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 28: SUNDAY RECOVERY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Sunday. You finally get a quiet morning after balancing school and work.");

    showDialogue("Jelo",
                 "Rest ka muna, bro. Two days na lang after today!");

    updateEnergy(player, 15);
    updateHappiness(player, 10);

    showDialogue("Narrator",
                 "You use the day to recover and prepare for the final two days.");

    displayStatus(*player);
}

void day29Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 29: FINAL PREPARATIONS\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Monday. Only one more day remains after today. You think about how to finish the challenge.");

    showDialogue("Sir Dante",
                 "You've worked hard this month. Keep your focus until the end.");

    printf("\nHow will you spend your remaining time?\n");
    printf("[1] Review your finances and rest\n");
    printf("[2] Prepare for tomorrow's final day\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 2)
            printf("Invalid choice! Select 1 or 2.\n");

    } while (choice < 1 || choice > 2);

    switch (choice)
    {
    case 1:
        updateEnergy(player, 10);
        updateHappiness(player, 5);
        printf("\nYou review your finances and get some rest.\n");
        break;

    case 2:
        updateEnergy(player, -5);
        updateHappiness(player, 10);
        printf("\nYou prepare everything for the final day.\n");
        break;
    }

    showDialogue("Narrator",
                 "Before the day ends, you face one final budgeting challenge. You must decide how to cover your essential daily expenses with PHP 250.");

    budgetShoppingHard(player);

    printf("\n================================\n");
    printf("          DAY 29 COMPLETE\n");
    printf("================================\n");
}

void day30Story(struct Player *player)
{
    printf("\n================================\n");
    printf("       DAY 30: THE FINAL DAY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "The final day has arrived. Thirty days ago, you started this challenge with a limited budget and a difficult goal.");

    showDialogue("Jelo",
                 "Bro, we made it to Day 30! Can you believe it?");

    showDialogue("Mika",
                 "You've balanced school, work, and your personal life. That's something to be proud of.");

    showDialogue("Player",
                 "Hindi naging madali, pero natutunan kong maging mas responsable sa pera at oras ko.");

    showDialogue("Sir Dante",
                 "Whatever your final savings may be, remember that discipline and wise decisions matter more than quick results.");

    showDialogue("Narrator",
                 "Your 30-day journey is complete. You have learned the importance of managing your money, energy, and happiness.");

    printf("\n================================\n");
    printf("         YOUR FINAL STATUS\n");
    printf("================================\n");

    displayStatus(*player);

    printf("\nTotal Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);
}
