#include <stdio.h>
#define SHIFT_PAY 610
#define SAVINGS_TARGET 8000
#define DAILY_ALLOWANCE 250
#define DAILY_UPKEEP 120
#define MIN_SHIFT_ENERGY 30

struct Player
{
    char name[50];
    int money;
    int energy;
    int happiness;
    int totalEarnings;
    int totalExpenses;
    int isHired;
    int trainingCompleted;
    int workedToday;
    int friendship; // Jelo
    int loanedToJelo;
    int mikaBond;    // romance
    int bossTrust;   // Sir Dante respects honesty
    int drawerShort; // total money lost from cashier mistakes
    int repaidMika;    // 1 = Mika's covered errors were paid back (or never existed)
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

int completeWorkShift(struct Player *player);

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

int getChoice(int min, int max);

void loseMoney(struct Player *player, int amount);

void showEnding(struct Player *player);

int main()
{
    struct Player player;
    int choice;
    int running = 1;

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
        choice = getChoice(1, 3);

        switch (choice)
        {
        case 1:
            printf("\n================================\n");
            printf("       CHARACTER CREATION\n");
            printf("================================\n");

            printf("\nEnter your character's name: ");
            scanf("%49s", player.name);
            while (getchar() != '\n')
                ; // clear leftover Enter so the first dialogue doesn't skip

            player.money = 0;
            player.energy = 80;
            player.happiness = 80;
            player.totalEarnings = 0;
            player.totalExpenses = 0;
            player.isHired = 0;
            player.trainingCompleted = 0;
            player.workedToday = 0;
            player.friendship = 0;
            player.loanedToJelo = 0;
            player.mikaBond = 0;
            player.bossTrust = 0;
            player.drawerShort = 0;
            player.repaidMika = 0;

            printf("\nWelcome to Budget Battle, %s!\n", player.name);
            startGame(&player);
            break;

        case 2:
            printf("\nNo saved game yet. Coming soon!\n");
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

int getChoice(int min, int max)
{
    int n;
    int valid = 0;

    while (valid == 0)
    {
        printf("\nEnter your choice: ");

        if (scanf("%d", &n) != 1)
        {
            n = min - 1; // typed a letter, so make it invalid
        }

        while (getchar() != '\n')
            ; // clear leftover input

        if (n >= min && n <= max)
        {
            valid = 1;
        }
        else
        {
            printf("Invalid choice! Select %d to %d.\n", min, max);
        }
    }
    return n;
}

void loseMoney(struct Player *player, int amount)
{
    if (player->money < amount)
    {
        amount = player->money; // can't lose more than you have
    }
    player->money -= amount;
    player->totalExpenses += amount;
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

        // Daily living costs (day 1 already has meal and fare choices)
        if (day > 1)
        {
            if (spendMoney(player, DAILY_UPKEEP))
            {
                printf("\nDaily meals and fare: -PHP %d\n", DAILY_UPKEEP);
                updateEnergy(player, 8); // sleep
            }
            else
            {
                printf("\nYou couldn't afford proper meals today...\n");
                updateEnergy(player, -10);
                updateHappiness(player, -10);
            }
        }
        updateHappiness(player, -3); // daily grind

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
    showEnding(player);
}

void day1Story(struct Player *player)
{
    char message[100];

    printf("\n[6:30 AM - NEAR YOUR HOME]\n");

    showDialogue("Narrator",
                 "Naka-uniform ka, naka-backpack, at may PHP 250 sa bulsa na galing pa sa tinda ni nanay. Hindi 'yan baon. Pang-survive 'yan.");

    showDialogue(player->name,
                 "First day sa TUP Manila. Sana this time hindi puro problema. Kasi kapag may problema, wala akong pang-solve.");

    showDialogue("Narrator",
                 "May biglang umakbay sa'yo. Amoy pabango. Mahal na pabango.");

    snprintf(message, sizeof(message),
             "Uy uy uy! Ikaw si %s, diba? Nakita ko pangalan mo sa group chat. Same block tayo, sheesh!", player->name);
    showDialogue("Jelo", message);

    showDialogue(player->name,
                 "Ah... oo? Sino ka ulit?");

    showDialogue("Jelo",
                 "Jelo. Ngl, lowkey kinakabahan ako today pero fake it till we make it, diba? Tara, kain muna tayo before class.");

    showDialogue(player->name,
                 "Ngayon agad? Kakababa ko lang ng jeep, pawis pa 'ko.");

    showDialogue("Jelo",
                 "Breakfast is the most important meal of the day, bro. Tsaka libre mo?");

    showDialogue(player->name,
                 "Pare, first day pa lang, uutang ka na agad?");

    showDialogue("Jelo",
                 "HAHAHA charot! Wala rin akong pera. Pang-porma lang 'to. Walang laman 'tong wallet, puro resibo.");

    showDialogue(player->name,
                 "Grabe ka. Sige na nga. Tara, kain.");

    breakfastChoice(player);

    showDialogue("Jelo",
                 "Busog ka na? Ayun. Ngayon, paano tayo papunta sa school? Bet ko sana Angkas pero, you know, wallet things.");

    transportationChoice(player);

    showDialogue("Narrator",
                 "Pagdating sa TUP Manila, siksikan na ang mga estudyante papunta sa kani-kanilang room.");

    showDialogue(player->name,
                 "Pare, 'wag tayong ma-late. Baka ako pa ang unang ma-bad shot sa prof.");

    showDialogue("Jelo",
                 "Chill! Kabisado ko na shortcuts dito. Main character energy lang, sundan mo 'ko.");

    showDialogue("Narrator",
                 "Pagdating sa classroom, pumasok ang professor at nagsimula ang first class ng semester.");

    showDialogue("Professor",
                 "Good morning. This semester, projects, deadlines, and expenses will test you. Choose your priorities wisely.");

    showDialogue(player->name,
                 "'Expenses will test you'. Sir, parang may nakakaalam ng bank account ko.");

    showDialogue("Narrator",
                 "Natapos ang unang klase. Pagod ka na agad, at hindi pa nagsisimula ang totoong laban.");

    showDialogue("Jelo",
                 "Bro, may alam akong hiring malapit dito. Fast-food branch. Suki ako doon. May conyo na crew doon, si Mika. Mabait 'yon, ngl, pero lowkey scary kapag nagagalit.");

    showDialogue(player->name,
                 "Hiring? Kahit student?");

    showDialogue("Jelo",
                 "Bet na bet 'yan, diba? Part-time. At least may sariling pera ka, hindi puro tinda ni nanay.");

    showDialogue(player->name,
                 "Sige. Bukas, subukan ko. Kailangan ko rin talagang kumita.");

    showDialogue("Narrator",
                 "Pauwi ka na, iniisip ang tuition, pamasahe, at ang trabahong baka magbago ng lahat.");

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

    printf("\nYour money: PHP %d\n", player->money);

    printf("\n[1] Zobel student meal - PHP 45\n");
    printf("[2] Fast-food meal - PHP 100\n");
    printf("[3] SM Manila foodcourt meal - PHP 150\n");
    printf("[4] Skip breakfast - PHP 0\n");

    while (completed == 0)
    {
        choice = getChoice(1, 4);

        switch (choice)
        {
        case 1:
            if (spendMoney(player, 45))
            {
                updateEnergy(player, 10);

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

    printf("\nYour money: PHP %d\n", player->money);

    printf("\n[1] Walk - PHP 0 (tipid, pero pagod)\n");
    printf("[2] Jeepney - PHP 15\n");
    printf("[3] Bus / Modern Jeep - PHP 25 (aircon!)\n");
    printf("[4] Angkas - PHP 70 (presko)\n");

    while (completed == 0)
    {
        choice = getChoice(1, 4);

        switch (choice)
        {
        case 1:
            updateEnergy(player, -10);
            updateHappiness(player, -3);

            printf("\nNaglakad ka. Pawis, pero buo pa ang pera mo.\n");
            completed = 1;
            break;

        case 2:
            if (spendMoney(player, 15))
            {
                updateEnergy(player, -5);

                printf("\nSumakay ka ng jeep. 'Bayad po!' moment.\n");
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

                printf("\nSumakay ka ng bus. Malamig, kumportable.\n");
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
                updateHappiness(player, 3);

                printf("\nNag-Angkas ka. Mahal, pero ang bilis at ang lamig ng hangin.\n");
                completed = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
            break;
        }
    }

    displayStatus(*player);
}

void day2Story(struct Player *player)
{
    int choice;
    char message[120];

    printf("\n================================\n");
    printf("       DAY 2: JOB APPLICATION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Hapon na. Nakatayo ka sa harap ng fast-food branch, hawak ang resume na pinrint mo sa computer shop. PHP 5 per page. Dalawa 'yon, kasi nagkamali ka sa una.");

    showDialogue(player->name,
                 "Sana matanggap ako. Kasi kung hindi, ako na ang susunod na papasok sa 'budget meal' lifestyle.");

    showDialogue("Jelo",
                 "Chill lang, bro. Just be yourself. Basta 'wag mong sabihin na wala kang experience sa lahat. HAHAHA!");

    showDialogue(player->name,
                 "Loko ka. Sige, pasok na tayo.");

    showDialogue("Narrator",
                 "Sa loob, may babaeng crew na nag-aayos ng mga tray. Naka-uniform, naka-ponytail. Pero ang sapatos niya, bagong-bago at mukhang mamahalin. Bago mo pa matanong, itinago niya ang paa niya sa likod ng counter.");

    showDialogue("Jelo",
                 "Mika! May ipapakilala ako sa'yo. Siya 'yung friend kong naghahanap ng work.");

    snprintf(message, sizeof(message),
             "Oh my gosh, hi! You must be %s! Like, Jelo told me all about you. Okay, not all, he only said 'pogi' and 'tipid'. I'm Mika!", player->name);
    showDialogue("Mika", message);

    showDialogue(player->name,
                 "Hi! Ma'am Mika, nice to meet you.");

    showDialogue("Mika",
                 "Ew, no. Just Mika, please. Hindi pa ako matanda. And no 'Ma'am', okay? Ang awkward ng vibe.");

    showDialogue("Jelo",
                 "Wala siyang binibigay na last name, bro. Mysterious. Parang may hidden past.");

    showDialogue("Mika",
                 "Jelo, stop. Wait lang, tawagin ko si Sir Dante. Wag kayong maingay, strict 'yon.");

    showDialogue("Narrator",
                 "Dumating ang manager. Matangkad, seryoso, may naka-clip-on na ID. Tumingin siya sa resume mo ng limang segundo. Parang limang taon.");

    showDialogue("Sir Dante",
                 "Ikaw ba 'yung applicant? Dante. Sir Dante. May tanong ako, at gusto ko ng totoo.");

    showDialogue("Sir Dante",
                 "May experience ka na ba sa fast-food?");

    printf("\n[1] \"Wala po, sir. Pero hindi po ako marunong magsinungaling.\"\n");
    printf("[2] \"Meron po, sir. Dalawang taon na po ako sa ibang branch.\"\n");
    printf("[3] \"Wala po, sir, pero mabilis po akong matuto.\"\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->bossTrust += 2;
        showDialogue("Sir Dante",
                     "Tapat ka. Bihira 'yan. Hindi ko kailangan ng perpekto, ang kailangan ko ay totoo. Tanggap ka.");
    }
    else if (choice == 2)
    {
        player->bossTrust -= 1;
        showDialogue("Sir Dante",
                     "Dalawang taon. Hmm. Sige. Pero tandaan mo, nakikita ko lahat. Tanggap ka, pero nakamasid ako.");
    }
    else
    {
        player->bossTrust += 1;
        showDialogue("Sir Dante",
                     "Mabilis matuto. Sige, patunayan mo bukas. Tanggap ka.");
    }

    player->isHired = 1;

    showDialogue(player->name,
                 "Salamat po, sir! Hindi ko po kayo bibiguin.");

    showDialogue("Jelo",
                 "Sheesh! Sabi ko sa'yo eh. Libre mo na ako mamaya, bro! HAHAHA!");

    showDialogue(player->name,
                 "Wala pa nga akong sahod, Jelo. Wala pa nga akong uniform.");

    showDialogue("Narrator",
                 "Dinala ka ni Mika sa prep area. Sa isang sulok, may maliit na mesa kung saan inilalagay ang mga order bago ibigay sa customer.");

    showDialogue("Mika",
                 "Okay, first lesson. Always check the receipt before giving the order. Kasi if mali, ikaw ang uulit, hindi ang customer.");

    showDialogue(player->name,
                 "So kailangan ko lang tingnan kung tama lahat ng items?");

    showDialogue("Mika",
                 "Exactly. Simple lang, but like, you'd be surprised kung ilang tao ang nagkakamali dito. Try mo!");

    showDialogue("Narrator",
                 "Naglagay si Mika ng tray sa harap mo.");

    orderCheckingGame(player);

    showDialogue("Mika",
                 "Not bad for a first-timer. Wait, may GCash ka ba? Kailangan ko ng numbers mo for the group chat ng crew.");

    printf("\nPaano ka sasagot?\n");
    printf("[1] \"Meron, pero 'yung laman, pamasahe lang.\"\n");
    printf("[2] \"Hindi ko alam kung may laman. Pero sige, kunin mo.\"\n");
    printf("[3] Ibigay lang ang number, walang biro.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->mikaBond += 1;
        updateHappiness(player, 3);
        showDialogue("Mika",
                     "HAHAHA! Okay, that was actually funny. Wait, I like you na. Not in a weird way. In a coworker way. Probably.");
    }
    else if (choice == 2)
    {
        player->mikaBond += 1;
        showDialogue("Mika",
                     "Ay, relatable. Okay, I'll text you na lang. Don't worry, libre lang ang pag-text.");
    }
    else
    {
        showDialogue("Mika",
                     "Okay, noted! Professional. Very 'I have my life together'. Sure.");
    }

    showDialogue("Narrator",
                 "Tapos na ang unang araw ng training. Pauwi ka, may bagong trabaho, bagong kakilala, at bagong dahilan para mag-ipon.");

    printf("\n================================\n");
    printf("          DAY 2 COMPLETE\n");
    printf("================================\n");
}

void orderCheckingGame(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       ORDER CHECKING GAME\n");
    printf("================================\n");

    printf("\nCUSTOMER RECEIPT\n");
    printf("Burger: 2\n");
    printf("Fries: 1\n");
    printf("Drink: 1\n");

    printf("\nACTUAL FOOD TRAY\n");
    printf("Burger: 1\n");
    printf("Fries: 1\n");
    printf("Drink: 1\n");

    printf("\nWhich item has an incorrect quantity?\n");
    printf("[1] Burger\n");
    printf("[2] Fries\n");
    printf("[3] Drink\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        printf("\nCorrect! Kulang ng isang burger sa tray.\n");
        printf("Mika: Ayan! Sharp ka. Isang burger lang ang kulang, pero for a customer, that's the whole meal.\n");

        updateHappiness(player, 5);
        updateEnergy(player, -5);
    }
    else
    {
        printf("\nIncorrect! Ang kulang ay ang burger.\n");
        printf("Mika: Okay lang, training pa naman. Pero sa totoong shift, reklamo agad 'yan.\n");

        updateHappiness(player, -5);
        updateEnergy(player, -10);
    }

    displayStatus(*player);
}

void day3Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("    DAY 3: FIRST TRAINING SHIFT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Hapon. Unang training shift mo. Binigyan ka ng uniform na size L. XS ka. Para kang batang nagsuot ng damit ni tatay.");

    showDialogue(player->name,
                 "Okay. Walang pressure. Sana lang hindi ako madapa habang may hawak na tray.");

    showDialogue("Mika",
                 "Good aftie! Okay, today customers na. Real people, real reklamo. Ready ka na ba?");

    showDialogue(player->name,
                 "Hindi. Pero sige.");

    showDialogue("Mika",
                 "HAHAHA honest. I like that.");

    showDialogue("Sir Dante",
                 "Customer satisfaction. Ngumiti ka. Hindi ko sinasabing peke. Sinasabi kong ngumiti ka.");

    showDialogue(player->name,
                 "Yes, sir.");

    showDialogue("Narrator",
                 "Pumunta ka sa counter. May lalaking naka-polo na paulit-ulit tumitingin sa relo niya. Mukhang hindi masaya.");

    customerServiceGame(player);

    showDialogue("Narrator",
                 "Pagkatapos ng huling customer, binigyan kayo ng 10-minute break. Umupo kayo ni Mika sa likod.");

    showDialogue("Mika",
                 "Okay, you survived your first customer. Wait, libre ko drinks. May promo kasi sa GCash. Ano sa'yo?");

    printf("\nPaano ka sasagot?\n");
    printf("[1] \"Sige, salamat! Libre eh, hindi ako tatanggi.\"\n");
    printf("[2] \"Hindi, ako na. Nakakahiya, PHP 20 lang naman.\" (-PHP 20)\n");
    printf("[3] \"Ikaw na lang. Tubig lang ako sa gripo.\"\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->mikaBond += 1;
        updateEnergy(player, 5);
        updateHappiness(player, 3);
        showDialogue("Mika",
                     "See? Easy. Minsan okay lang tumanggap. Hindi ka naman nangungutang, diba?");
    }
    else if (choice == 2)
    {
        if (spendMoney(player, 20))
        {
            player->mikaBond += 2;
            updateEnergy(player, 5);
            updateHappiness(player, 3);
            showDialogue("Mika",
                         "Wait, seriously? You paid for your own? Okay, that's actually... refreshing. Most people would've said yes agad.");
            showDialogue(player->name,
                         "Kanal humor ko lang 'yon. Pride lang 'to. Hindi nakakain.");
        }
        else
        {
            player->mikaBond += 1;
            showDialogue("Mika",
                         "Hala, wala kang pambayad no? Okay lang. Sige, libre na lang.");
        }
    }
    else
    {
        player->mikaBond += 1;
        updateHappiness(player, 2);
        showDialogue("Mika",
                     "Gripo? HAHAHA stop. Okay, I'll buy you iced tea. Wag ka nang kumontra, ang kulit mo.");
    }

    showDialogue("Narrator",
                 "Nag-vibrate ang phone ni Mika sa mesa. Nakita mo ang screen: 'Papa - 12 missed calls'. Mabilis niya itong tinalikuran.");

    showDialogue(player->name,
                 "Ay, may tumatawag sa'yo. Labindalawa.");

    showDialogue("Mika",
                 "Ah. Wala 'yan. Spam. Very persistent spam.");

    showDialogue("Narrator",
                 "Hindi mo siya pinilit magsabi. Pero hindi mo rin nakalimutan.");

    showDialogue("Narrator",
                 "Natapos ang shift. Pauwi ka, pagod, pero may konting ngiti. Ngayon ka lang nakipag-usap sa isang tao na parang hindi mo kailangang umarte.");

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

    printf("\nCustomer: \"Excuse me! Twenty minutes na 'yung order ko!\n");
    printf("Hindi pa rin dumarating. Ano ba 'to?\"\n");

    printf("\nHow will you respond?\n");
    printf("[1] \"Sir, wait lang po, marami pa pong nauna sa inyo.\"\n");
    printf("[2] \"Pasensya na po, sir. Titingnan ko po agad sa kusina.\"\n");
    printf("[3] \"Sir, hindi po 'twenty minutes'. Sampu lang po.\"\n");

    choice = getChoice(1, 3);

    if (choice == 2)
    {
        printf("\nCorrect! Nag-sorry ka at kumilos ka agad.\n");
        printf("Mika: Ayan! 'Yan ang customer service. Hindi mo kailangang magaling, kailangan mo lang mag-care.\n");
        printf("Sir Dante nods once from behind the counter.\n");

        updateHappiness(player, 5);
        player->bossTrust += 1;
    }
    else if (choice == 1)
    {
        printf("\nHindi siya nagalit, pero hindi rin siya natuwa.\n");
        printf("Mika: Okay lang, pero next time, mag-sorry ka muna. 'Yung 'wait lang po' alone, parang walang pakialam.\n");

        updateHappiness(player, -2);
    }
    else
    {
        printf("\nMas lalo siyang nagalit. Napatingin ang ibang customer.\n");
        printf("Sir Dante: Hindi tayo nanalo sa argument. Customer ang nagbabayad ng sahod natin.\n");

        updateHappiness(player, -5);
        player->bossTrust -= 1;
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
    printf("[1] PHP 30\n");
    printf("[2] PHP 10\n");
    printf("[3] PHP 20\n");

    choice = getChoice(1, 3);

    if (choice == 3)
    {
        printf("\nCorrect! 100 - 80 = PHP 20.\n");
        printf("Mika: Smooth! Walang kaba, walang kulang.\n");
        updateHappiness(player, 5);
    }
    else
    {
        if (choice == 1)
        {
            printf("\nIncorrect! Sobra ang naibigay mong sukli.\n");
        }
        else
        {
            printf("\nIncorrect! Kulang ang sukli mo. Bumalik ang customer.\n");
        }

        printf("The correct change was PHP 20.\n");
        printf("Error fee deducted from your pay: PHP 30.\n");

        loseMoney(player, 30);
        player->drawerShort += 30;
        updateHappiness(player, -5);
    }

    updateEnergy(player, -3);

    displayStatus(*player);
}

void day4Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("      DAY 4: HANDLING ORDERS\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Tanghali na. Pagdating mo sa branch, parang may concert. Puno ang pila hanggang labas ng pinto.");

    showDialogue("Mika",
                 "Good timing! Lunch rush na. Welcome to the real world, bestie.");

    showDialogue(player->name,
                 "Bestie? Isang araw pa lang tayo magkakilala.");

    showDialogue("Mika",
                 "Day 3 na. It counts. Basta focus, one order at a time. Don't panic. Panic is expensive.");

    showDialogue("Sir Dante",
                 "Lahat tayo kailangan ngayon. Walang magkakamali. Hindi ako nagbibiro.");

    showDialogue("Narrator",
                 "Pumuwesto ka sa counter. Sunod-sunod ang order. Parang sinasabuyan ka ng resibo.");

    multipleOrderGame(player);

    showDialogue("Narrator",
                 "Pagkatapos ng rush, bumukas ang pinto. Si Jelo. Naka-sunglasses, kahit hapon na.");

    showDialogue("Jelo",
                 "Bro! Sheesh, ang bango dito. Gutom na gutom na ako. Pa-fries naman, libre na lang. Free sample, ganon.");

    showDialogue("Narrator",
                 "Nakatingin sa'yo ang kaibigan mo. Sa kabilang dulo, nakatingin din si Sir Dante.");

    printf("\nWhat will you do?\n");
    printf("[1] Palihim na bigyan si Jelo ng libreng fries.\n");
    printf("[2] \"Pare, hindi pwede. Trabaho 'to.\" (walang libre)\n");
    printf("[3] Bayaran ang fries ni Jelo gamit ang pera mo. (-PHP 30)\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->friendship += 1;
        player->bossTrust -= 1;
        updateHappiness(player, 3);
        showDialogue("Sir Dante",
                     "Nakita ko 'yon. Hindi ako nagsalita ngayon. Pero nakita ko.");
    }
    else if (choice == 2)
    {
        player->bossTrust += 1;
        updateHappiness(player, -2);
        showDialogue("Jelo",
                     "Grabe, bro. Pero sige, respeto. Trabaho 'yan. Susubukan ko na lang mag-ayuno. Charot.");
    }
    else
    {
        if (spendMoney(player, 30))
        {
            player->friendship += 1;
            player->bossTrust += 1;
            updateHappiness(player, 3);
            showDialogue("Jelo",
                         "Bro... seryoso? Babawi ako, promise. Hindi ko 'to makakalimutan.");
            showDialogue("Sir Dante",
                         "Binayaran mo. Tama. Hindi mo ginamit ang pwesto mo.");
        }
        else
        {
            player->bossTrust += 1;
            showDialogue("Jelo",
                         "Wala kang pera? Same, bro. Same.");
        }
    }

    showDialogue("Mika",
                 "Wow, drama. Anyway, you survived the rush. Proud of you, ha.");

    showDialogue("Narrator",
                 "Natapos ang shift. Pagod ka, pero may nabuong tiwala. Kay Sir Dante, kay Mika, at kay Jelo.");

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
    printf("Drinks: 3\n");

    printf("\nPREPARED ORDER\n");
    printf("Burger: 2\n");
    printf("Fries: 1\n");
    printf("Drinks: 3\n");

    printf("\nWhich item is missing?\n");
    printf("[1] Burger\n");
    printf("[2] Fries\n");
    printf("[3] Drinks\n");

    choice = getChoice(1, 3);

    if (choice == 2)
    {
        printf("\nCorrect! Kulang ng isang fries.\n");
        printf("Mika: Nice catch! Kapag nag-rush, 'yung maliit na item ang nakakalimutan.\n");

        updateHappiness(player, 5);
        updateEnergy(player, -8);
    }
    else
    {
        printf("\nIncorrect! Ang kulang ay ang fries.\n");
        printf("Mika: Hindi pa naman real shift, pero sa susunod, kapag ganito, reklamo na 'yan.\n");

        updateHappiness(player, -5);
        updateEnergy(player, -12);
    }

    displayStatus(*player);
}

void day5Story(struct Player *player)
{
    int choice;
    char message[250];

    printf("\n================================\n");
    printf("     DAY 5: SALARY DISCUSSION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Hapon. May nakapaskil na schedule sa bulletin board. Nandoon ang pangalan mo. Mali lang ang spelling, pero okay na 'yon. Opisyal na.");

    showDialogue("Sir Dante",
                 "Ikaw. Sa opisina ko. Isara mo ang pinto.");

    showDialogue(player->name,
                 "Sir, may kasalanan po ba ako?");

    showDialogue("Sir Dante",
                 "Wala. Kaya nga nakakapagtaka. Umupo ka.");

    snprintf(message, sizeof(message),
             "Tapos na ang training mo. Simula ngayon, PHP %d kada 8-hour shift. Cash, same day. Walang paligoy-ligoy.",
             SHIFT_PAY);
    showDialogue("Sir Dante", message);

    snprintf(message, sizeof(message),
             "May isang patakaran. Kapag mas mababa sa %d ang energy mo, uuwi ka. Hindi ako nagpapa-duty ng zombie. Magkakamali ka lang, tapos ako ang haharap sa customer.",
             MIN_SHIFT_ENERGY);
    showDialogue("Sir Dante", message);

    printf("\nPaano ka sasagot?\n");
    printf("[1] \"Salamat po, sir. Malaking tulong po ito sa tuition ko.\"\n");
    printf("[2] \"Sir, may chance po bang tumaas 'yan balang araw?\"\n");
    printf("[3] \"Sir, PHP 610 lang? Ang liit naman po.\"\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->bossTrust += 2;
        updateHappiness(player, 5);
        showDialogue("Sir Dante",
                     "Hindi ko hinihingi ang pasasalamat. Pero tinatanggap ko. Ituloy mo 'yan.");
    }
    else if (choice == 2)
    {
        player->bossTrust += 1;
        showDialogue("Sir Dante",
                     "Magandang tanong. Hindi ako nagbibigay ng pangako. Patunayan mo muna, tapos pag-usapan natin.");
    }
    else
    {
        player->bossTrust -= 2;
        updateHappiness(player, -5);
        showDialogue("Sir Dante",
                     "Ang liit? Sige. Maraming nakapila sa labas na papayag sa ganyang liit. Lumabas ka, pag-isipan mo kung bakit ka nandito.");
        showDialogue(player->name,
                     "Sir... sorry po. Hindi ko po sinasadya. Nag-joke lang po ako. Hindi po pala bagay.");
    }

    showDialogue("Narrator",
                 "Paglabas mo ng opisina, nakasandal si Mika sa pader, nagkukunwaring nag-aayos ng sachet ng ketchup.");

    if (choice == 3)
    {
        showDialogue("Mika",
                     "Oh my gosh. Bakit mo sinabi 'yon? Don't worry, ganyan lang talaga si Sir Dante kapag may tinamaan. Pero next time, bawas-bawas sa kanal, ha?");
    }
    else
    {
        player->mikaBond += 1;
        showDialogue("Mika",
                     "Narinig ko 'yung sagot mo. Hindi ka nag-demand, hindi ka nag-flex. Honestly? Refreshing. Congrats, bestie!");
    }

    showDialogue(player->name,
                 "Salamat. Wala pa nga akong sahod, pero feeling ko mayaman na ako. Kahit PHP 250 lang laman ng wallet.");

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
                 "Sabado. Walang class. Gising ka na ng 6 AM pa rin, kasi ang katawan mo ay hindi marunong mag-weekend.");

    showDialogue(player->name,
                 "Wala akong pasok. Pero ang bulsa ko, may pasok pa rin.");

    showDialogue("Narrator",
                 "Nag-vibrate ang phone mo. Group chat. Pangalan ng group: 'BLOCK 3 PROGRAMMERS'. Si Jelo ang unang nag-message.");

    showDialogue("Jelo",
                 "Bro! Gimik tayo today! Ngl, lowkey stressed ako sa buhay. May bago akong spot, super aesthetic. Puro vibes.");

    showDialogue(player->name,
                 "Aesthetic ba o mahal?");

    showDialogue("Jelo",
                 "...Both. Pero libre naman tumingin, diba? Window shopping lang!");

    showDialogue("Narrator",
                 "Makalipas ang ilang minuto, may bagong message. Galing kay Mika.");

    showDialogue("Mika",
                 "Hiii! So, like, we're short-staffed today. Sir Dante didn't say it, pero halata naman. Gusto mo ng extra shift? PHP 610 'yan, ha.");

    showDialogue(player->name,
                 "Para sa PHP 610, hindi lang ako papasok, tatakbo pa ako papunta.");

    showDialogue("Narrator",
                 "Nasa harap mo ang dalawang gusto: kumita o magpahinga. Pero sa huli, ikaw lang ang makakapili.");

    weekendChoice(player);

    showDialogue("Narrator",
                 "Natapos ang Sabado. Habang nakahiga ka, napansin mong ang tagal mo nang hindi nakahinga nang ganito.");

    printf("\n================================\n");
    printf("          DAY 6 COMPLETE\n");
    printf("================================\n");
}

void weekendChoice(struct Player *player)
{
    int choice;
    int maxChoice = 3;
    int done = 0;

    printf("\n================================\n");
    printf("       WEEKEND ACTIVITIES\n");
    printf("================================\n");

    printf("\nMoney: PHP %d | Energy: %d/100 | Happiness: %d/100\n",
           player->money, player->energy, player->happiness);

    printf("\nWhat would you like to do today?\n");
    printf("[1] Take an extra 8-hour shift (+PHP %d, -25 energy)\n", SHIFT_PAY);
    printf("[2] Rest at home (+15 energy)\n");
    printf("[3] Hang out with Jelo (-PHP 80)\n");

    if (player->mikaBond >= 4)
    {
        printf("[4] Hang out with Mika (-PHP 100)\n");
        maxChoice = 4;
    }

    if (player->energy < MIN_SHIFT_ENERGY)
    {
        printf("\n(Warning: you are too tired to work a shift today.)\n");
    }

    while (done == 0)
    {
        choice = getChoice(1, maxChoice);

        switch (choice)
        {
        case 1:
            if (completeWorkShift(player))
            {
                updateHappiness(player, 5);
                printf("\nPagod ka, pero may laman na ulit ang bulsa mo.\n");
                done = 1;
            }
            else
            {
                printf("\nPumili ng ibang gagawin.\n");
            }
            break;

        case 2:
            printf("\nNatulog ka, nag-scroll, natulog ulit. Perfect na Sabado.\n");
            updateEnergy(player, 15);
            updateHappiness(player, 5);
            done = 1;
            break;

        case 3:
            if (spendMoney(player, 80))
            {
                printf("\nNag-gala kayo ni Jelo. Siya ang nag-flex, ikaw ang nagbayad ng fishball.\n");
                updateEnergy(player, 5);
                updateHappiness(player, 15);
            }
            else
            {
                printf("\nWala kayong pera pareho, kaya tumambay na lang kayo sa kanto at nagkwentuhan.\n");
                updateHappiness(player, 8);
            }
            done = 1;
            break;

        case 4:
            if (spendMoney(player, 100))
            {
                printf("\nPumili si Mika ng simpleng turo-turo. 'Mas masarap dito,' sabi niya. Hindi mo alam kung totoo, pero ang saya.\n");
                player->mikaBond += 1;
                updateEnergy(player, -5);
                updateHappiness(player, 15);
                done = 1;
            }
            else
            {
                printf("\nHindi sapat ang pera mo. Pumili ng iba.\n");
            }
            break;
        }
    }

    displayStatus(*player);
}

void day7Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("      DAY 7: FIRST WEEK\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Linggo. Isang linggo ka nang estudyante at empleyado. Hindi mo alam kung nag-level up ka o nag-bayad lang ng utang sa tulog.");

    showDialogue("Jelo",
                 "Bro! Kumusta first week? Buhay ka pa ba? HAHAHA. Ako, buhay pero tuyo ang wallet.");

    showDialogue(player->name,
                 "Buhay pa. Pero parang ang katawan ko ay naka-airplane mode.");

    showDialogue("Narrator",
                 "Nag-ring ang phone mo. 'Nanay'. Sinagot mo agad.");

    showDialogue("Nanay",
                 "Anak, kumain ka na ba? Maraming benta kanina, ubos ang pandesal. Mag-ingat ka diyan, ha.");

    showDialogue(player->name,
                 "Opo, ma. Kumain na po ako.");

    showDialogue("Narrator",
                 "Hindi mo sinabi na ang almusal mo ay tubig at pag-asa. Alam mong ang allowance mo ay galing sa tinda ni nanay.");

    printf("\nAno ang gagawin mo?\n");
    printf("[1] Magpadala ng PHP 100 kay nanay via GCash.\n");
    printf("[2] Mag-reply lang ng \"Opo ma, ingat ka rin.\"\n");

    choice = getChoice(1, 2);

    if (choice == 1)
    {
        if (spendMoney(player, 100))
        {
            updateHappiness(player, 10);
            showDialogue("Nanay",
                         "Anak, hindi mo kailangang magpadala. Pero salamat. Tapusin mo lang ang pag-aaral mo, 'yan ang bayad.");
        }
        else
        {
            updateHappiness(player, -2);
            showDialogue("Narrator",
                         "Binuksan mo ang GCash. Hindi sapat ang laman. Isinara mo na lang. Babawi ka.");
        }
    }
    else
    {
        updateHappiness(player, 2);
        showDialogue("Nanay",
                     "Sige, anak. Ingat ka palagi.");
    }

    showDialogue("Narrator",
                 "Linggo ng hapon. Wala kang pasok, pero may kailangan kang pagpasyahan.");

    showDialogue(player->name,
                 "Pahinga o pera? Ang hirap pumili kapag pareho kong kailangan.");
}

void weeklyReport(struct Player *player, int daysCompleted)
{
    int daysLeft = 30 - daysCompleted;
    int remaining = SAVINGS_TARGET - player->money;

    printf("\n================================\n");
    printf("         WEEKLY REPORT\n");
    printf("================================\n");

    printf("\nDays Completed: %d / 30\n", daysCompleted);
    printf("Total Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);

    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (remaining > 0)
    {
        printf("Remaining to Goal: PHP %d\n", remaining);
        printf("You need about PHP %d per day for the next %d days.\n",
               remaining / daysLeft, daysLeft);
        printf("(Allowance minus daily costs is only PHP %d. Shifts make the difference!)\n",
               DAILY_ALLOWANCE - DAILY_UPKEEP);
    }
    else
    {
        printf("Savings Goal: ACHIEVED!\n");
    }

    if (player->energy < 40)
    {
        printf("\nWarning: You are very tired. Rest before your next shift.\n");
    }

    if (player->happiness < 40)
    {
        printf("Warning: You are burning out. Do something fun soon.\n");
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("       END OF WEEK %d\n", daysCompleted / 7);
    printf("================================\n");
}

void day8Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("      DAY 8: CASHIER DEBUT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Lunes. Pinalitan na ni Mika ang uniform mo sa stockroom. Hindi ka na XS na nakasuot ng damit ni tatay.");

    showDialogue("Mika",
                 "Good morning! Today, ikaw na sa cashier. Like, the real one. May totoong pera.");

    showDialogue(player->name,
                 "Totoong pera. Bilang taong may kaunting pera, nanginginig ako.");

    showDialogue("Mika",
                 "HAHAHA breathe. Compute, check, tapos ibigay. In that order.");

    showDialogue("Sir Dante",
                 "Ang cashier ang pinakamahalagang pwesto. Kapag kulang ang drawer, kulang din ang sahod mo. Hindi ako nagbibiro.");

    cashierChallenge(player);

    if (player->drawerShort > 0)
    {
        showDialogue("Narrator",
                     "Pagsara ng shift, binilang ni Sir Dante ang drawer. Tumigil siya. Binilang ulit.");

        showDialogue("Sir Dante",
                     "May error sa transaction. Kinaltasan ka na ng PHP 30.");

        showDialogue("Mika",
                     "Sir, ako po ang nag-assist sa counter kanina. Ako po ang may kasalanan.");

        showDialogue("Narrator",
                     "Hindi totoo 'yon. Alam mo. Alam din ni Mika na alam mo.");

        printf("\nAno ang gagawin mo?\n");
        printf("[1] \"Hindi po, sir. Ako po ang nagkamali.\"\n");
        printf("[2] Tumahimik na lang.\n");

        choice = getChoice(1, 2);

        if (choice == 1)
        {
            player->bossTrust += 2;
            player->mikaBond += 1;
            showDialogue("Sir Dante",
                         "Hindi ko tinanong kung sino ang nagkamali. Gusto ko lang malaman kung sino ang magsasabi ng totoo. Ikaw 'yon.");
            showDialogue("Mika",
                         "Why would you do that? Ang corny mo. Pero, like... thank you.");
        }
        else
        {
            player->bossTrust -= 1;
            updateHappiness(player, -3);
            showDialogue("Sir Dante",
                         "Mika, hindi ikaw ang nasa counter. Pero sige. Ikaw ang magsasara ng drawer buong linggo.");
            showDialogue("Narrator",
                         "Hindi ka komportable. Mas mabigat pala ang kunsensya kaysa sa PHP 30.");
        }
    }
    else
    {
        showDialogue("Sir Dante",
                     "Walang kulang. Ayos.");

        showDialogue("Narrator",
                     "Ngumiti si Sir Dante. Halos hindi mo napansin, pero meron.");
    }

    showDialogue("Narrator",
                 "Natapos ang walong oras. Nag-abot si Sir Dante ng sobre.");

    if (completeWorkShift(player))
    {
        showDialogue(player->name,
                     "PHP 610. Kung kailangan ko pa ng ulam, ito na 'yon.");
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 8 COMPLETE\n");
    printf("================================\n");
}

int completeWorkShift(struct Player *player)
{
    if (player->isHired != 1 || player->trainingCompleted != 1)
    {
        printf("\nYou are not yet qualified for a regular shift!\n");
        return 0;
    }

    if (player->workedToday == 1)
    {
        printf("\nYou have already completed a shift today!\n");
        return 0;
    }

    if (player->energy < MIN_SHIFT_ENERGY)
    {
        printf("\nSir Dante takes one look at you.\n");
        printf("\"Umuwi ka muna. Hindi kita papayagang mag-duty nang ganyan.\"\n");
        printf("You were too exhausted to work. No pay today.\n");
        return 0;
    }

    updateMoney(player, SHIFT_PAY);
    player->workedToday = 1;

    printf("\n================================\n");
    printf("       WORK SHIFT COMPLETED\n");
    printf("================================\n");

    printf("You completed an 8-hour shift!\n");
    printf("Salary received: PHP %d\n", SHIFT_PAY);

    updateEnergy(player, -25);
    updateHappiness(player, -5);
    return 1;
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
    printf("[1] PHP 30\n");
    printf("[2] PHP 40\n");
    printf("[3] PHP 20\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        printf("\nCorrect! 100 + 30 + 40 = PHP 170. 200 - 170 = PHP 30.\n");
        printf("Mika: Clean! Kahit mahaba ang order, hindi ka nalito.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nIncorrect! The total was PHP 170, so the change was PHP 30.\n");
        printf("Mika: Hala... bumalik 'yung customer. Kailangan nating punan 'yung kulang.\n");
        printf("Error fee deducted from your pay: PHP 40.\n");

        loseMoney(player, 40);
        player->drawerShort += 40;
        updateHappiness(player, -8);
    }

    updateEnergy(player, -5);

    displayStatus(*player);
}

void cashierChallengeHard(struct Player *player)
{
    int choice1, choice2;

    printf("\n================================\n");
    printf("     CASHIER CHALLENGE\n");
    printf("         HARD LEVEL\n");
    printf("================================\n");

    printf("\nMika: Rush hour! Dalawang customer, sunod-sunod. Walang calculator, bestie.\n");

    printf("\nCUSTOMER 1 ORDER\n");
    printf("Burger: 3 x PHP 50\n");
    printf("Drinks: 2 x PHP 20\n");
    printf("Payment: PHP 200\n");

    printf("\nHow much change should you give?\n");
    printf("[1] PHP 20\n");
    printf("[2] PHP 30\n");
    printf("[3] PHP 10\n");

    choice1 = getChoice(1, 3);

    printf("\nCUSTOMER 2 ORDER\n");
    printf("Fries: 2 x PHP 30\n");
    printf("Burger: 1 x PHP 50\n");
    printf("Payment: PHP 200\n");

    printf("\nHow much change should you give?\n");
    printf("[1] PHP 90\n");
    printf("[2] PHP 80\n");
    printf("[3] PHP 100\n");

    choice2 = getChoice(1, 3);

    if (choice1 == 3 && choice2 == 1)
    {
        printf("\nExcellent! Customer 1: 190, change 10. Customer 2: 110, change 90.\n");
        printf("Sir Dante: Walang kulang. Ayos.\n");
        player->bossTrust += 1;
        updateHappiness(player, 10);
    }
    else if (choice1 == 3 || choice2 == 1)
    {
        printf("\nOne transaction was correct, one was wrong.\n");
        printf("Customer 1 change was PHP 10. Customer 2 change was PHP 90.\n");
        printf("Error fee deducted from your pay: PHP 30.\n");

        loseMoney(player, 30);
        player->drawerShort += 30;
        updateHappiness(player, -2);
    }
    else
    {
        printf("\nBoth transactions were wrong.\n");
        printf("Customer 1 change was PHP 10. Customer 2 change was PHP 90.\n");
        printf("Error fee deducted from your pay: PHP 60.\n");

        loseMoney(player, 60);
        player->drawerShort += 60;
        updateHappiness(player, -10);
    }

    updateEnergy(player, -8);

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
    printf("Pay PHP 300 processing fee to release your winnings.\"\n");

    printf("\nWhat should you do?\n");
    printf("[1] Reply with your bank password to 'verify' your account.\n");
    printf("[2] Send PHP 300 immediately before the prize expires.\n");
    printf("[3] Ignore, block, and report the number.\n");

    choice = getChoice(1, 3);

    if (choice == 3)
    {
        printf("\nCorrect! Walang nanalo sa contest na hindi mo sinalihan.\n");
        printf("Never pay fees or share passwords to claim an unexpected prize.\n");
        updateHappiness(player, 5);
    }
    else if (choice == 2)
    {
        printf("\nYou got scammed! The 'prize' never came. You lost PHP 300.\n");
        loseMoney(player, 300);
        updateHappiness(player, -8);
    }
    else
    {
        printf("\nYou got scammed! They drained your e-wallet. You lost PHP 300.\n");
        loseMoney(player, 300);
        updateHappiness(player, -10);
    }

    updateEnergy(player, -3);

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
    printf("[1] The message was sent through text.\n");
    printf("[2] It promises guaranteed profit from betting.\n");
    printf("[3] The message calls you 'Pre'.\n");

    choice = getChoice(1, 3);

    if (choice == 2)
    {
        printf("\nCorrect! Betting involves risk, so profit can never be guaranteed.\n");
        printf("Anyone promising guaranteed returns is hiding something.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nYou missed the biggest warning sign and sent the deposit.\n");
        printf("The 'guaranteed return' never came. You lost PHP 500.\n");
        loseMoney(player, 500);
        updateHappiness(player, -8);
    }

    updateEnergy(player, -5);

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
    printf("[1] The message contains numbers.\n");
    printf("[2] Guaranteed returns and pressure to deposit fast.\n");
    printf("[3] The person uses an online account.\n");

    choice1 = getChoice(1, 3);

    printf("\nQUESTION 2:\n");
    printf("What is another serious warning sign?\n");
    printf("[1] The offer has a company name.\n");
    printf("[2] The message has a greeting.\n");
    printf("[3] You must invite friends before you can withdraw.\n");

    choice2 = getChoice(1, 3);

    if (choice1 == 2 && choice2 == 3)
    {
        printf("\nExcellent! You spotted both warning signs.\n");
        printf("You take screenshots as proof, so Jelo can report the group.\n");
        player->friendship += 1;
        updateHappiness(player, 10);
    }
    else if (choice1 == 2 || choice2 == 3)
    {
        printf("\nYou spotted one warning sign, but missed the other.\n");
        printf("You still lost PHP 300 before you could stop the payment.\n");
        loseMoney(player, 300);
        updateHappiness(player, -2);
    }
    else
    {
        printf("\nYou missed both warning signs and lost PHP 800!\n");
        loseMoney(player, 800);
        updateHappiness(player, -10);
    }

    updateEnergy(player, -8);

    displayStatus(*player);
}

void budgetShoppingEasy(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        BUDGET SHOPPING\n");
    printf("          EASY LEVEL\n");
    printf("================================\n");

    printf("\nYou and Jelo have PHP 150 to buy food.\n");

    printf("\nAVAILABLE ITEMS\n");
    printf("Rice: PHP 50\n");
    printf("Eggs: PHP 40\n");
    printf("Bread: PHP 30\n");
    printf("Soft drink: PHP 40\n");

    printf("\nWhich combination costs exactly PHP 120?\n");
    printf("[1] Rice + Soft drink\n");
    printf("[2] Eggs + Bread + Soft drink\n");
    printf("[3] Rice + Eggs + Bread\n");

    choice = getChoice(1, 3);

    if (choice == 3)
    {
        printf("\nCorrect! 50 + 40 + 30 = PHP 120. May natira ka pang PHP 30.\n");
        updateHappiness(player, 5);
    }
    else
    {
        printf("\nIncorrect! Rice + Eggs + Bread is the one that costs PHP 120.\n");
        printf("Nagkamali kayo ng bili, kaya nag-top up ka ng PHP 30 sa kahera.\n");
        loseMoney(player, 30);
        updateHappiness(player, -5);
    }

    updateEnergy(player, -3);

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

    printf("\n[1] Rice + Eggs + Soft drink + Sardines (PHP 175)\n");
    printf("[2] Rice + Eggs + Vegetables + Sardines (PHP 180)\n");
    printf("[3] Rice + Vegetables + Soft drink (PHP 135)\n");

    choice = getChoice(1, 3);

    if (choice == 2)
    {
        printf("\nExcellent! You prioritized essential groceries.\n");
        printf("The combination costs PHP 180. You have PHP 20 remaining.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nYou stayed within budget, but you missed a food group.\n");
        printf("Kinulang ka sa sustansya, kaya bumili ka ulit ng PHP 30 na pagkain.\n");
        loseMoney(player, 30);
        updateHappiness(player, -3);
    }

    updateEnergy(player, -5);

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

    printf("\n[1] Food + Transportation + Milk tea + Snacks (PHP 250)\n");
    printf("[2] Food + Printing + Milk tea + Water (PHP 225)\n");
    printf("[3] Food + Transportation + Printing + Water (PHP 165)\n");

    choice = getChoice(1, 3);

    if (choice == 3)
    {
        printf("\nExcellent! You covered all your necessities.\n");
        printf("80 + 30 + 40 + 15 = PHP 165. You have PHP 85 remaining.\n");
        updateHappiness(player, 10);
    }
    else
    {
        if (choice == 1)
        {
            printf("\nWala kang pang-print at walang tubig. Pang-milk tea lang ang pinaghandaan mo.\n");
        }
        else
        {
            printf("\nWala kang pamasahe. Napilitan kang mag-Angkas pauwi.\n");
        }

        printf("Remember to prioritize essential expenses.\n");
        printf("Emergency expense: PHP 50.\n");
        loseMoney(player, 50);
        updateHappiness(player, -8);
    }

    updateEnergy(player, -5);

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

    printf("[1] Buy the accessory first. Sayang ang sale!\n");
    printf("[2] Buy the accessory and earn extra money later to cover your expenses.\n");
    printf("[3] Set aside money for necessities before considering the accessory.\n");

    choice = getChoice(1, 3);

    if (choice == 3)
    {
        printf("\nCorrect! 250 + 400 + 200 = PHP 850. Tira: PHP 150.\n");
        printf("Necessities first, wants last. Pwede mo pang bilhin ang accessory kung sobra.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nIncorrect! Protect your necessities before optional purchases.\n");
        printf("Binili mo agad ang accessory (PHP 100 na ang nawala sa'yo).\n");
        loseMoney(player, 100);
        updateHappiness(player, -4);
    }

    updateEnergy(player, -3);
    displayStatus(*player);
}

void financialQuizMedium(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("        FINANCIAL QUIZ\n");
    printf("         MEDIUM LEVEL\n");
    printf("================================\n");

    printf("\nYou have PHP 1,200 in savings.\n");
    printf("Your school project requires PHP 700 in three days.\n");
    printf("Your phone needs a PHP 800 repair.\n");
    printf("Your next salary arrives in five days.\n");
    printf("You can temporarily borrow a phone from a relative.\n");

    printf("\nWhat is the most responsible decision?\n");

    printf("[1] Reserve the project money and borrow a phone until payday.\n");
    printf("[2] Repair your phone immediately and find a way to pay for the project.\n");
    printf("[3] Pay for the repair and ask for an extension on the project.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        printf("\nCorrect! The project has a deadline, but the phone can wait.\n");
        printf("1,200 - 700 = PHP 500 left. Repair it after payday.\n");
        updateHappiness(player, 8);
    }
    else
    {
        printf("\nIncorrect! 1,200 can't cover both 700 and 800.\n");
        printf("Nagmadali ka, kaya may rush fee at late fee. PHP 150 ang nawala.\n");
        loseMoney(player, 150);
        updateHappiness(player, -6);
    }

    updateEnergy(player, -3);
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
    printf("[2] Verify the company and its risks first. Invest only what you can afford to lose.\n");
    printf("[3] Borrow PHP 1,000 to invest without touching your savings.\n");

    choice = getChoice(1, 3);

    if (choice == 2)
    {
        printf("\nExcellent decision! 20 percent every week is not realistic.\n");
        printf("Verify first, and never invest money you need.\n");
        updateHappiness(player, 10);
    }
    else
    {
        printf("\nIncorrect! The company disappeared three days later.\n");
        printf("You lost PHP 400.\n");
        loseMoney(player, 400);
        updateHappiness(player, -10);
    }

    updateEnergy(player, -5);
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
    int done = 0;

    printf("\n================================\n");
    printf("     DAY 9: SCHOOL EXPENSES\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Martes. Pagpasok ng professor, nag-abot siya ng listahan: printed materials, folder, at project supplies. Parang bill ng Meralco, pero academic.");

    showDialogue(player->name,
                 "Sir, pwede po bang PDF na lang? Hindi PDF ang pinapakain ko sa sarili ko.");

    showDialogue("Professor",
                 "Printed. Next meeting.");

    showDialogue("Jelo",
                 "Bro, sheesh, PHP 5 per page tapos twenty pages? Lowkey masakit sa bulsa. Share na lang tayo sa isang set?");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Buy complete supplies - PHP 100\n");
    printf("[2] Buy basic supplies - PHP 50\n");
    printf("[3] Split one set with Jelo - PHP 30\n");
    printf("[4] Borrow a classmate's notes - PHP 0\n");

    while (done == 0)
    {
        choice = getChoice(1, 4);

        if (choice == 1)
        {
            if (spendMoney(player, 100))
            {
                updateHappiness(player, 8);
                printf("\nKumpleto ang gamit mo. Pakiramdam mo, dean's lister ka na.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            if (spendMoney(player, 50))
            {
                updateHappiness(player, 3);
                printf("\nBasic lang ang gamit mo, pero pasok na 'to sa budget.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 3)
        {
            if (spendMoney(player, 30))
            {
                player->friendship += 1;
                updateHappiness(player, 5);
                showDialogue("Jelo",
                             "Bro, ikaw na best friend ko forever. Libre na kita next time. Charot, hindi ako makakalibre.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else
        {
            updateHappiness(player, -5);
            updateEnergy(player, -5);
            printf("\nNag-photocopy ka ng notes ng classmate mo sa mismong kamay. Libre, pero masakit sa kamay at sa pride.\n");
            done = 1;
        }
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 9 COMPLETE\n");
    printf("================================\n");
}

void day10Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 10: BUSY SHIFT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Miyerkules. Pagbukas ng branch, parang may sale ng libreng pagkain. Puno ang pila.");

    showDialogue("Mika",
                 "Okay, so like, today is not the day to have feelings. Ang daming customers. Let's gooo.");

    showDialogue(player->name,
                 "Wala akong feelings. Wala akong pera. Kaya ko 'to.");

    showDialogue("Sir Dante",
                 "Isang order sa isang pagkakataon. Magaling ka kung walang reklamo.");

    if (completeWorkShift(player))
    {
        showDialogue("Narrator",
                     "Bago magsara, may matandang customer na nag-abot ng PHP 50. 'Para sa'yo 'yan, iho. Ang bilis mo kasi.'");

        showDialogue("Mika",
                     "Wait, sa branch natin, tip jar rule: lahat ng tip, para sa buong crew. Pero like, ikaw ang nag-abot ng order, so ikaw ang bahala.");

        printf("\n[1] Ilagay sa tip jar para sa buong crew.\n");
        printf("[2] Itago sa bulsa. (+PHP 50)\n");

        choice = getChoice(1, 2);

        if (choice == 1)
        {
            player->bossTrust += 1;
            player->mikaBond += 1;
            updateHappiness(player, 3);
            showDialogue("Mika",
                         "Hala, ikaw lang yata ang nag-drop ng tip na hindi ko pinilit. Honestly? Parang... ang cute. Ang weird nito.");
        }
        else
        {
            updateMoney(player, 50);
            player->bossTrust -= 1;
            updateHappiness(player, -2);
            showDialogue("Narrator",
                         "Walang nakakita. Siguro. Pero may CCTV sa kisame, at mas nakakatakot si Sir Dante kaysa sa CCTV.");
        }
    }
    else
    {
        showDialogue("Narrator",
                     "Umuwi kang pagod at walang sahod. Nag-text si Mika: 'Rest ka muna, bestie. Walang judgment.'");
    }

    showDialogue("Mika",
                 "Anyway! Para sa break natin, nag-quiz ako. Budget or Bust. Gawa ko 'to for myself, pero sige, you try.");

    showDialogue(player->name,
                 "Quiz sa budget? Eh 'yung budget ko nga, hindi ko pa nahahanap.");

    financialQuizEasy(player);

    printf("\n================================\n");
    printf("          DAY 10 COMPLETE\n");
    printf("================================\n");
}

void day11Story(struct Player *player)
{
    int choice;
    int done = 0;

    printf("\n================================\n");
    printf("      DAY 11: GROUP PROJECT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Huwebes. Nag-ping ang group chat nang labing-apat na beses. Pare-pareho ang laman: pera.");

    showDialogue("Renz",
                 "Guys, contribution for project materials. PHP 100 each. Deadline today. No hulugan.");

    showDialogue("Narrator",
                 "Pagkatapos ng class, hinila ka ni Jelo sa gilid ng hallway.");

    showDialogue("Jelo",
                 "Bro... wala akong PHP 100 ngayon. Pwede mo ba akong i-cover? Babawi ako, promise sa Diyos.");

    showDialogue(player->name,
                 "Pare, kahapon pa kita nakikitang naka-sunglasses. Saan napunta ang pera mo?");

    showDialogue("Jelo",
                 "Lowkey may pinagkakakitaan ako. Online. Basta, pera-pera lang. Ikukuwento ko later.");

    showDialogue("Narrator",
                 "Hindi mo alam kung maniniwala ka o kakabahan ka.");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Pay your share only - PHP 100\n");
    printf("[2] Pay your share and Jelo's - PHP 200\n");
    printf("[3] Pay half and promise the rest tomorrow - PHP 50\n");
    printf("[4] Offer to make the slides instead - PHP 0\n");

    while (done == 0)
    {
        choice = getChoice(1, 4);

        if (choice == 1)
        {
            if (spendMoney(player, 100))
            {
                updateHappiness(player, 3);
                showDialogue("Jelo",
                             "Okay lang, bro. Ako na bahala sa share ko. Pramis.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            if (spendMoney(player, 200))
            {
                player->friendship += 1;
                updateHappiness(player, 5);
                showDialogue("Jelo",
                             "Bro... seryoso? Utang na loob ko 'to. Hindi ko 'to makakalimutan.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 3)
        {
            if (spendMoney(player, 50))
            {
                updateHappiness(player, -3);
                showDialogue("Renz",
                             "Okay, pero bukas na ang kalahati. Hindi pwedeng wala.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else
        {
            updateEnergy(player, -10);
            updateHappiness(player, 2);
            showDialogue("Renz",
                         "Sige, ikaw ang gagawa ng slides. Pero perfect ha, hindi pwedeng may typo.");
            done = 1;
        }
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 11 COMPLETE\n");
    printf("================================\n");
}

void day12Story(struct Player *player)
{
    int choice;
    int done = 0;

    printf("\n================================\n");
    printf("      DAY 12: TREAT YOURSELF\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Biyernes. Pagkalabas ng school, amoy fishball ang buong kalsada. Mas malakas pa 'yon sa self-control mo.");

    showDialogue("Jelo",
                 "Bro, treat yourself! Self-care is not selfish. Lowkey lifestyle 'yan.");

    showDialogue(player->name,
                 "Ang self-care ko, matulog nang walang alarm. Hindi fishball.");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Street food - PHP 40 (+5 energy, +5 happiness)\n");
    printf("[2] Milk tea and fried chicken - PHP 120 (+8 energy, +12 happiness)\n");
    printf("[3] Save your money - PHP 0\n");

    while (done == 0)
    {
        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, 40))
            {
                updateEnergy(player, 5);
                updateHappiness(player, 5);
                printf("\nIsaw, fishball, kikiam. Mura, masarap, at medyo delikado sa tiyan.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            if (spendMoney(player, 120))
            {
                updateEnergy(player, 8);
                updateHappiness(player, 12);
                printf("\nMilk tea, fried chicken, at isang oras na walang iniisip. Priceless. Pero PHP 120 din.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else
        {
            showDialogue("Jelo",
                         "Wow. Discipline arc. Respect. Pero lowkey nakakatakot ka.");
            done = 1;
        }
    }

    showDialogue("Jelo",
                 "Sige, hindi ko na kayo gigisingin. May bago kasi akong sideline, 'pera-pera online'. Kapag lumago, ililibre kita ng kahit ano.");

    showDialogue("Narrator",
                 "Nag-vibrate ang phone mo. Text mula sa unknown number. Parang ginawa ng taong hindi marunong mag-spell ng 'congratulations'.");

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
                 "Sabado. Nag-vibrate ang phone mo habang nakahiga ka pa.");

    showDialogue("Mika",
                 "Hiii! Sorry, early, pero like, need namin ng extra crew today. PHP 610 ulit. Ikaw ang first na naisip ko, promise.");

    showDialogue(player->name,
                 "'Ako ang first na naisip.' Alam mo bang ang mahal ng tatlong salitang 'yan?");

    showDialogue("Narrator",
                 "Isang linggo na naman. Trabaho o pahinga? Pareho mong kailangan.");

    weekendChoice(player);

    if (player->workedToday == 1)
    {
        showDialogue("Narrator",
                     "Pagkatapos ng shift, may itim na SUV na pumarada sa labas ng branch. May driver na naka-polo. Biglang yumuko si Mika sa likod ng counter.");

        showDialogue("Mika",
                     "Don't look! Don't look! Please. Isipin mo, wala kang nakita.");

        showDialogue(player->name,
                     "Mika, ang laki ng SUV. Anong order 'yan, bulk?");

        showDialogue("Mika",
                     "Wrong branch lang siya. Wrong person. Wrong everything. Anyway, ang saya ng shift!");

        showDialogue("Narrator",
                     "Sa gilid, hinihilot ni Sir Dante ang parehong malinis na counter sa loob ng limang minuto. Wala siyang sinabi, pero hindi niya inalis ang tingin sa SUV.");
    }
    else
    {
        showDialogue("Narrator",
                     "Habang nagpapahinga ka, nag-text si Mika: 'Ang tahimik dito, ngl. Wait, 'wag mong i-take ng weird, ha.'");
    }

    printf("\n================================\n");
    printf("          DAY 13 COMPLETE\n");
    printf("================================\n");
}

void day14Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("     DAY 14: SUNDAY RESET\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Linggo. Namili kayo ni Jelo sa palengke dahil may nag-text sa kanya: 'Tipid week, bro.'");

    showDialogue("Jelo",
                 "Bro, may PHP 150 tayo para sa pagkain. Spend wisely. Charot, ako lang yata ang hindi marunong.");

    budgetShoppingEasy(player);

    showDialogue("Narrator",
                 "Habang nakapila sa tindahan ng itlog, itinaas ni Jelo ang phone niya. Nakangiti siya nang sobrang laki.");

    showDialogue("Jelo",
                 "Bro, tingnan mo! PHP 800 ang kita ko today sa app. Hindi ako nagpapatawa. Invite kita, madali lang.");

    printf("\n[1] \"Pare, ingat ka. Kapag sobrang bilis ng pera, may kapalit 'yan.\"\n");
    printf("[2] \"Patingin nga. Paano 'yan gumagana?\"\n");
    printf("[3] \"PHP 800? Ako, PHP 800 ang sahod ko sa isang araw. Pero pagod.\"\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->friendship += 1;
        showDialogue("Jelo",
                     "Haha, ang corny mo, bro. Pero sige, maingat ako. Pramis.");
    }
    else if (choice == 2)
    {
        showDialogue("Jelo",
                     "Basta mag-deposit ka lang tapos mag-invite ng tatlong friends. Boom, kita agad!");
        showDialogue("Narrator",
                     "Parang may pamilyar kang naririnig na kwento sa isang scam awareness seminar.");
    }
    else
    {
        updateHappiness(player, 3);
        showDialogue("Jelo",
                     "HAHAHA! Fair point. Pero lowkey, mas sulit ako. Wala akong pagod.");
    }

    showDialogue("Narrator",
                 "Natapos ang gala. Ngayon, kailangan mong pagpasyahan kung paano mo gagamitin ang natitirang Linggo.");

    displayStatus(*player);
}
void day15Story(struct Player *player)
{
    int choice;
    int done = 0;

    printf("\n================================\n");
    printf("    DAY 15: MID-MONTH REPORT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Lunes. Kalahati na ng 30-day challenge. Binuksan mo ang notebook kung saan mo isinusulat ang lahat ng gastos mo.");

    showDialogue(player->name,
                 "Fifteen days na. Sana hindi pa ako nakakalimutan ng pera ko.");

    printf("\n========== FINANCIAL CHECK ==========\n");
    printf("Current Money: PHP %d\n", player->money);
    printf("Total Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (player->money >= SAVINGS_TARGET / 2)
    {
        printf("\nYou are on pace. Keep working and protect your savings.\n");
    }
    else
    {
        printf("\nYou are behind pace. You will need more weekend shifts.\n");
    }

    showDialogue("Mika",
                 "Halfway na tayo! Like, I'm proud of you. Hindi ko alam kung bakit proud ako. Basta proud.");

    showDialogue("Narrator",
                 "Habang nagre-ready ka umuwi, nakatayo si Jelo sa labas ng gate. Hindi siya naka-sunglasses. Ngayon lang.");

    if (player->friendship >= 2)
    {
        showDialogue("Jelo",
                     "Bro... nahihiya na ako sa'yo. Ang dami mo nang naitulong. Pero kulang pa rin ng PHP 500 ang tuition ko. Babayaran kita, promise sa Diyos.");
    }
    else
    {
        showDialogue("Jelo",
                     "Bro... may favor sana ako. Kulang ng PHP 500 ang tuition ko. Babayaran kita, promise.");
    }

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Lend PHP 500\n");
    printf("[2] Lend PHP 200\n");
    printf("[3] Say sorry, you need your savings\n");

    while (done == 0)
    {
        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, 500))
            {
                player->loanedToJelo = 500;
                player->friendship += 2;
                updateHappiness(player, 5);
                showDialogue("Jelo",
                             "Utang na loob ko 'to, bro. Hindi ko 'to makakalimutan.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            if (spendMoney(player, 200))
            {
                player->loanedToJelo = 200;
                player->friendship += 1;
                showDialogue("Jelo",
                             "Kahit ito lang, malaking tulong na. Salamat, bro.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else
        {
            player->friendship -= 1;
            updateHappiness(player, -5);
            showDialogue("Jelo",
                         "Ah... okay lang, bro. Intindihin ko. Hindi ka obligado.");
            showDialogue("Narrator",
                         "Umalis siyang nakangiti. Pero hindi 'yon ang ngiti ni Jelo na kilala mo.");
            done = 1;
        }
    }

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
                 "Martes. Bukas na ang presentation. Pagbukas mo ng group chat, ang huling message ay galing pa kahapon: 'Seen by 6.'");

    showDialogue("Jelo",
                 "Bro, si Renz, wala pang nagagawa sa part niya. Lowkey ako rin, pero at least ako, aaminin ko.");

    showDialogue("Narrator",
                 "Nakita mo si Renz sa hallway. Naka-headphones, chill na chill.");

    printf("\n[1] Gawin mo na ang part niya. (-15 energy)\n");
    printf("[2] Kausapin si Renz nang mahinahon.\n");
    printf("[3] I-report kay Professor.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        updateEnergy(player, -15);
        updateHappiness(player, -3);
        showDialogue(player->name,
                     "Okay. Ako na lang. Kasi ang grade, grade pa rin.");
        showDialogue("Narrator",
                     "Natapos mo ang part ni Renz. Hindi siya nagpasalamat. Hindi mo alam kung ikaw ang mabait o ikaw ang tanga.");
    }
    else if (choice == 2)
    {
        updateEnergy(player, -3);
        player->friendship += 1;
        updateHappiness(player, 2);
        showDialogue(player->name,
                     "Pare, kailangan ka namin bukas. Isang slide lang. Kaya mo 'yan.");
        showDialogue("Renz",
                     "Ay, oo nga pala. Sige, gagawin ko na. Sorry, nawala sa isip ko.");
        showDialogue("Jelo",
                     "Sheesh, bro. Hindi mo sinigawan, pero nag-work. Respect.");
    }
    else
    {
        updateHappiness(player, -5);
        showDialogue("Professor",
                     "Mr. Renz, magkakaroon ka ng individual score. Group, ituloy ninyo.");
        showDialogue("Narrator",
                     "Natapos ang problema. Pero malamig na ang tingin ng buong barkada sa'yo buong hapon.");
    }

    showDialogue("Narrator",
                 "Natutunan mo ngayon na ang oras at lakas ay pera rin. At minsan, mas mahal pa.");

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 16 COMPLETE\n");
    printf("================================\n");
}

void day17Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 17: BUSY SHIFT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Miyerkules. Pagpasok mo sa branch, may nakapaskil na bagong notice: 'Dagdag na promo. Dagdag na customer. Dagdag na stress.'");

    showDialogue("Mika",
                 "Okay, bestie. Today is a no-excuses day. Ikaw sa cashier ulit, ha.");

    showDialogue("Sir Dante",
                 "Maraming customer. Maraming pera. Maraming pwedeng magkamali.");

    if (player->energy >= MIN_SHIFT_ENERGY + 5)
    {
        cashierChallengeMedium(player);
        completeWorkShift(player);

        showDialogue("Narrator",
                     "Natapos ang shift. Paglabas mo, hinihintay ka ni Mika sa tapat ng pinto, hawak ang dalawang iced tea.");

        showDialogue("Mika",
                     "Hindi ko naman bibilhin 'to for you. Sobra lang. Sobrang... random. Hehe.");

        printf("\n[1] \"Salamat. Hindi 'sobra' 'yan, intensyon 'yan.\"\n");
        printf("[2] \"Sige, tatanggapin ko. Pero ako ang bahala sa susunod.\"\n");
        printf("[3] \"Sana all, may sobra!\"\n");

        choice = getChoice(1, 3);

        if (choice == 1)
        {
            player->mikaBond += 2;
            updateHappiness(player, 6);
            showDialogue("Mika",
                         "Ew, ang corny. Pero okay. Medyo kinilig ako. Konti lang. Parang 3 percent.");
        }
        else if (choice == 2)
        {
            player->mikaBond += 1;
            updateHappiness(player, 4);
            showDialogue("Mika",
                         "Deal! Pero hindi mo ako pwedeng ilibre sa mamahalin, ha. Tipid vibes tayo.");
        }
        else
        {
            player->mikaBond += 1;
            updateHappiness(player, 2);
            showDialogue("Mika",
                         "HAHAHA! Sana all talaga. Charot. Cheers!");
        }
    }
        else
    {
        showDialogue("Sir Dante",
                     "Umuwi ka muna. Hindi kita papayagang humawak ng pera nang ganyan kapagod.");
        showDialogue("Narrator",
                     "Umuwi kang walang sahod. Si Mika, nag-text: 'Magpahinga ka. Sa'yo pa rin ang schedule bukas.'");
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 17 COMPLETE\n");
    printf("================================\n");
}

void day18Story(struct Player *player)
{
    int choice;
    int done = 0;

    printf("\n================================\n");
    printf("       DAY 18: SCHOOL ACTIVITY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Huwebes. May class event: team-building sa labas ng campus. May shirt, may pagkain, may bayad.");

    showDialogue("Jelo",
                 "Bro, sheesh, sumali tayo! Core memory 'to. Lowkey, kailangan ko rin ng distraction.");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Join with full contribution - PHP 100\n");
    printf("[2] Join with a smaller contribution - PHP 50\n");
    printf("[3] Skip the activity - PHP 0\n");

    while (done == 0)
    {
        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, 100))
            {
                updateEnergy(player, -5);
                updateHappiness(player, 15);
                player->friendship += 1;
                printf("\nMay shirt ka, may picture ka, may tawa ka. Sulit 'to.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            if (spendMoney(player, 50))
            {
                updateEnergy(player, -5);
                updateHappiness(player, 8);
                printf("\nBaon ang kinain mo, pero kasama ka sa group photo. Panalo pa rin.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else
        {
            updateEnergy(player, 5);
            updateHappiness(player, -4);
            printf("\nNatulog ka maghapon. Tipid, pero parang may hindi kumpleto.\n");
            done = 1;
        }
    }

    showDialogue("Narrator",
                 "Pag-uwi, bukas ang laptop mo. Sa notebook, may nakasulat na 'savings: 1,200'. Dalawang bagay ang nakaharap sa'yo: proyekto at gadget.");

    financialQuizMedium(player);

    printf("\n================================\n");
    printf("          DAY 18 COMPLETE\n");
    printf("================================\n");
}
void day19Story(struct Player *player)
{
    int choice;
    int done = 0;

    printf("\n================================\n");
    printf("     DAY 19: UNEXPECTED EXPENSE\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Biyernes. Pauwi ka na nang biglang bumigay ang zipper ng bag mo. Nahulog ang notebook, ang calculator, at ang huling pandesal na ibinaon ni nanay.");

    showDialogue(player->name,
                 "Ang bag ko, nag-resign na. Walang two-weeks notice.");

    showDialogue("Jelo",
                 "Bro, RIP bag. Sheesh. Magpa-repair ka na, baka pati reviewer mo malaglag sa kalsada.");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Ipa-repair sa tailor - PHP 150 (+5 happiness)\n");
    printf("[2] I-DIY gamit ang safety pins at sinulid - PHP 20 (-3 energy)\n");
    printf("[3] Hiramin ang extra bag ni Jelo - PHP 0 (-2 happiness)\n");

    while (done == 0)
    {
        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, 150))
            {
                updateHappiness(player, 5);
                printf("\nBago ang zipper, bago ang buhay. Mahal, pero panatag ang loob mo.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            if (spendMoney(player, 20))
            {
                updateEnergy(player, -3);
                printf("\nMay safety pin na ang bag mo. Pangit, pero buhay pa. Parang ikaw.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else
        {
            player->friendship += 1;
            updateHappiness(player, -2);
            showDialogue("Jelo",
                         "Eto, bro, designer 'to. Limited edition.");
            showDialogue("Narrator",
                         "May tatak na 'Guccci'. Tatlong 'c'.");
            done = 1;
        }
    }

    showDialogue("Narrator",
                 "Gabi na. Nakahiga ka na nang mag-vibrate ang phone mo. Unknown number, may malaking message at mas malaking link.");

    showDialogue("Narrator",
                 "Sa ibaba ng message, nakasulat: 'Referred by: Jelo'.");

    showDialogue(player->name,
                 "Si Jelo? Bakit niya ako ni-refer dito?");

    scamDetectiveMedium(player);

    showDialogue("Narrator",
                 "Nag-vibrate ulit ang phone mo. Text mula kay Jelo: 'bro, wag mo muna i-open yung link. pasensya na. pag-usapan natin.'");

    printf("\n[1] \"Pare, ayos ka lang? Hindi mo kailangang harapin 'yan mag-isa.\"\n");
    printf("[2] \"Ano 'to, Jelo?! Bakit mo ako ni-refer sa ganito?!\"\n");
    printf("[3] Basahin lang. Hindi sumagot.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->friendship += 1;
        updateHappiness(player, 2);
        showDialogue("Jelo",
                     "...Salamat, bro. Hindi ko deserve 'yan. Pero salamat.");
    }
    else if (choice == 2)
    {
        player->friendship -= 1;
        updateHappiness(player, -3);
        showDialogue("Jelo",
                     "Tama ka. Sorry, bro. Sorry talaga.");
    }
    else
    {
        updateHappiness(player, -2);
        showDialogue("Narrator",
                     "Seen. Hindi ka nag-reply. Hindi ka rin nakatulog.");
    }

    printf("\n================================\n");
    printf("          DAY 19 COMPLETE\n");
    printf("================================\n");
}
void day20Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 20: SATURDAY RESET\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Sabado ng umaga. Nag-text si Mika: 'Pwede ka bang pumasok nang maaga? Hindi shift. Pang-ayos lang ng stockroom. Libre kita breakfast, promise.'");

    showDialogue(player->name,
                 "Libreng breakfast at stockroom. Parang trap, pero sige.");

    showDialogue("Narrator",
                 "Sa stockroom, may naka-frame na litrato sa dingding, kalahating natatakpan ng mga karton. Family photo. May batang babaeng naka-braces at may asul na ribbon sa buhok.");

    showDialogue("Mika",
                 "Don't look at that! Wait, may spider. Spider. Big. Dito. Oh my gosh.");

    showDialogue("Narrator",
                 "Mabilis niyang isinabit ang calendar sa ibabaw ng litrato.");

    showDialogue(player->name,
                 "Mika, wala namang spider.");

    showDialogue("Mika",
                 "It's invisible. Very exclusive spider.");

    printf("\n[1] \"Mika, kamukha mo 'yung batang may braces.\"\n");
    printf("[2] \"Sige, spider. Ako na ang magbubuhat ng karton, ikaw na sa spider.\"\n");
    printf("[3] Hindi magtanong. Tahimik na magbuhat ng karton.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        showDialogue("Mika",
                     "Everyone looks like someone, okay? Anyway. Ang laki ng mga karton, ano?");
        updateHappiness(player, -1);
    }
    else if (choice == 2)
    {
        player->mikaBond += 1;
        updateHappiness(player, 4);
        showDialogue("Mika",
                     "HAHAHA! Deal. Ikaw sa karton, ako sa spider. Teamwork!");
    }
    else
    {
        player->mikaBond += 2;
        updateHappiness(player, 5);
        showDialogue("Mika",
                     "Thank you for not asking. Seryoso. Someday sasabihin ko sa'yo. Promise. Hindi pa lang ngayon.");
    }

    updateEnergy(player, -5);

    showDialogue("Narrator",
                 "Natapos ang stockroom. Sabado pa rin, at hindi pa tapos ang desisyon mo para sa araw na 'to.");
}

void day21Story(struct Player *player)
{
    int choice;
    char message[150];

    printf("\n================================\n");
    printf("       DAY 21: SUNDAY REFLECTION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Linggo. Tatlong linggo na. Nakahiga ka, nakatitig sa kisame, at nagbibilang ng pera na hindi pa pumapasok.");

    showDialogue("Narrator",
                 "Binuksan mo ang group chat. Tahimik si Jelo mula pa kagabi. Ang huling post niya: litrato ng bagong sapatos. Binura pagkalipas ng isang oras.");

    if (player->loanedToJelo > 0)
    {
        snprintf(message, sizeof(message),
                 "Hindi ko pa nakikita ang PHP %d na hiniram niya. Pero mas inaalala ko kung okay ba siya.",
                 player->loanedToJelo);
        showDialogue(player->name, message);
    }
    else
    {
        showDialogue(player->name,
                     "Si Jelo na laging may sagot, biglang walang sagot. Hindi 'to normal.");
    }

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Puntahan si Jelo sa boarding house nila - PHP 30 pamasahe (-5 energy)\n");
    printf("[2] Mag-message: \"Pare, kumain ka na?\"\n");
    printf("[3] Hayaan muna. Mamaya na lang.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        if (spendMoney(player, 30))
        {
            updateEnergy(player, -5);
            player->friendship += 2;
            updateHappiness(player, 5);
            showDialogue("Narrator",
                         "Binuksan ni Jelo ang pinto. Pula ang mata. Walang sunglasses, walang porma. Parang ibang tao.");
            showDialogue("Jelo",
                         "Bro... hindi ko alam na pupunta ka. Okay lang ako. Ngl, hindi pa. Pero okay lang.");
            showDialogue("Jelo",
                         "May aaminin ako sa'yo. Hindi pa ngayon. Pero malapit na.");
        }
        else
        {
            player->friendship += 1;
            updateHappiness(player, 1);
            showDialogue("Narrator",
                         "Wala kang pamasahe. Nag-message ka na lang. 'Nandito lang ako, pare.' Hindi siya sumagot, pero na-seen niya agad.");
        }
    }
    else if (choice == 2)
    {
        player->friendship += 1;
        updateHappiness(player, 2);
        showDialogue("Jelo",
                     "kumain na. salamat, bro. ikaw lang nagtanong.");
    }
    else
    {
        player->friendship -= 1;
        updateHappiness(player, 2);
        showDialogue("Narrator",
                     "Natulog ka ulit. Paggising mo, walang bagong message. Hindi mo alam kung nakahinga ka o nagkamali.");
    }

    showDialogue("Narrator",
                 "Linggo pa rin. Pahinga o pera? Ikaw ang magpapasya.");
}

void day22Story(struct Player *player)
{
    int choice;
    int done = 0;
    char message[200];

    printf("\n================================\n");
    printf("       DAY 22: EXAM PREPARATION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Lunes. Anunsyo ng instructor: exam sa Biyernes. Hindi 'baka'. Hindi 'siguro'. Biyernes.");

    showDialogue("Jelo",
                 "Bro, review tayo mamaya? Lowkey kinakabahan ako. Hindi ako natulog kagabi, may inaayos lang sa app.");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\nHow will you prepare?\n");
    printf("[1] Buy a reviewer - PHP 100 (-5 energy, +5 happiness)\n");
    printf("[2] Study with Jelo using free notes (-8 energy, +6 happiness)\n");
    printf("[3] Sleep early and study tomorrow (+10 energy, -3 happiness)\n");

    while (done == 0)
    {
        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, 100))
            {
                updateEnergy(player, -5);
                updateHappiness(player, 5);
                printf("\nMay reviewer ka, may highlighter ka, may pag-asa ka.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            updateEnergy(player, -8);
            updateHappiness(player, 6);
            player->friendship += 1;

            showDialogue("Narrator",
                         "Habang nagre-review kayo, paulit-ulit tinitingnan ni Jelo ang phone niya. Nakakunot ang noo.");
            showDialogue("Jelo",
                         "Pending pa rin... pending pa rin...");
            showDialogue(player->name,
                         "Ano'ng pending?");
            showDialogue("Jelo",
                         "Wala. Withdrawal lang. Ilang araw na. Okay lang 'yan.");
            done = 1;
        }
        else
        {
            updateEnergy(player, 10);
            updateHappiness(player, -3);
            printf("\nNatulog ka nang maaga. Gising ang katawan mo, pero kinakabahan ang utak mo.\n");
            done = 1;
        }
    }

    showDialogue("Jelo",
                 "Bro, grocery run tayo. Ikaw pumili ha. Wala akong cash ngayon. Nasa app lahat.");

    budgetShoppingMedium(player);

    snprintf(message, sizeof(message),
             "Mika: 'Bukas, rush hour. Kailangan ng at least %d energy ang cashier. Matulog ka nang maaga, bestie. Seryoso.'",
             MIN_SHIFT_ENERGY + 8);
    showDialogue("Narrator", message);

    printf("\n================================\n");
    printf("          DAY 22 COMPLETE\n");
    printf("================================\n");
}

void day23Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 23: BUSY WORKDAY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Martes. Pagdating mo sa branch, nakapila na ang mga customer hanggang labas. May bus ng estudyante na kakadating.");

    showDialogue("Sir Dante",
                 "Rush hour. Lahat ng kamay, kailangan. Mika, cashier 2. Ikaw, cashier 1.");

    showDialogue(player->name,
                 "Kaya ko 'to. Malapit nang matapos ang challenge.");

    if (player->energy >= MIN_SHIFT_ENERGY + 8)
    {
        showDialogue("Mika",
                     "Dalawang customer, sunod-sunod. Compute, check, bigay. Breathe, bestie.");

        cashierChallengeHard(player);
        completeWorkShift(player);
        updateHappiness(player, 3);

        showDialogue("Narrator",
                     "Pagsara ng branch, nagpaalam ka na at lumabas. Pero naiwan ang phone mo sa locker, kaya bumalik ka.");

        if (player->drawerShort > 0)
        {
            showDialogue("Narrator",
                         "Sa counter, nakatalikod si Mika. May hawak siyang sobre. Isa-isa niyang inilalagay ang pera sa drawer. Hindi 'yon galing sa tills.");

            showDialogue("Mika",
                         "Oh my gosh! Hindi 'yan ano... like, nagbibilang lang ako. Counting. Very normal.");

            printf("\n[1] \"Hindi ko nakita 'yan. Pero salamat, Mika.\"\n");
            printf("[2] \"Mika, ako ang nagkamali. Hindi mo kailangang magbayad.\"\n");
            printf("[3] \"Sandali. Bakit ang laki ng pera sa wallet ng isang crew?\"\n");

            choice = getChoice(1, 3);

            if (choice == 1)
            {
                player->mikaBond += 2;
                updateHappiness(player, 3);
                showDialogue("Mika",
                             "...You're the first person who didn't ask questions. Okay. Utang ko 'to sa'yo. Hindi pera. Utang na kwento.");
            }
            else if (choice == 2)
            {
                player->mikaBond += 1;
                player->bossTrust += 1;
                showDialogue("Mika",
                             "Please, hayaan mo na lang. Akin 'yan. Choice ko 'yan. Hindi mo kasalanan na may nagkamali dito. Lahat naman tayo nagkakamali.");
            }
            else
            {
                player->mikaBond -= 1;
                updateHappiness(player, -2);
                showDialogue("Mika",
                             "Not everyone with money is rich, okay? Minsan utang din 'yan. Never mind. Good night.");
            }
        }
        else
        {
            showDialogue("Narrator",
                         "Papunta ka sa locker, may narinig kang boses sa stockroom. Si Mika, kausap ang phone niya. Hindi siya nakakakita sa'yo.");

            showDialogue("Mika",
                         "No, Papa. I'm not coming home. Thirty days, remember? Sabi mo kaya ko, diba? Then let me.");

            printf("\n[1] Kumatok at magkunwaring walang narinig.\n");
            printf("[2] Tahimik na umalis. Bukas na lang kayo mag-usap.\n");
            printf("[3] \"Mika, narinig ko. Okay ka lang ba?\"\n");

            choice = getChoice(1, 3);

            if (choice == 1)
            {
                player->mikaBond += 1;
                showDialogue("Mika",
                             "Oh! Hi! Kanina ka pa ba diyan? Wala akong sinabi. Wala. Wala talaga.");
            }
            else if (choice == 2)
            {
                player->mikaBond += 2;
                updateHappiness(player, 3);
                showDialogue("Narrator",
                             "Tahimik kang umalis. Kinabukasan, nakita mong may extra na kape sa locker mo. Walang note. Hindi mo kailangang magtanong.");
            }
            else
            {
                player->mikaBond += 1;
                showDialogue("Mika",
                             "Okay, fine. Narinig mo na. May deal kami ng Papa ko. Thirty days. Sasabihin ko sa'yo, pero hindi pa ngayon. Please.");
            }
        }
    }
    else
    {
        showDialogue("Sir Dante",
                     "Hindi ka pwede sa cashier ngayon. Kapag nagkamali ka, ako ang magbabayad. Umuwi ka, magpahinga, at bumalik kang buhay.");

        showDialogue("Narrator",
                     "Umuwi kang walang sahod. Sa unang pagkakataon, naramdaman mong mas mahal pala ang pagod kaysa sa PHP 610.");
    }

    showDialogue("Narrator",
                 "Hindi ka mananalo sa laban na 'to kung puro pagod ang puhunan mo. Pero kung wala kang sipag, wala ka ring pambili ng bukas.");

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 23 COMPLETE\n");
    printf("================================\n");
}

void day24Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 24: SCHOOL DEADLINE\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Miyerkules. Presentation day. 7:30 AM ang call time. 7:45 na, wala pa si Jelo.");

    showDialogue("Renz",
                 "Guys, nasaan si Jelo? Siya ang magpe-present ng last part.");

    showDialogue(player->name,
                 "Baka na-traffic. Baka nag-overthink. Baka naging ghost.");

    showDialogue("Narrator",
                 "Seen. Delivered. Walang reply. Sampung minuto na lang bago ang turn ng group ninyo.");

    printf("\n[1] Gawin mo ang part ni Jelo. (-12 energy)\n");
    printf("[2] Sabihin sa professor na absent si Jelo.\n");
    printf("[3] Tawagan si Jelo at pilitin siyang pumunta. (-3 energy)\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        updateEnergy(player, -12);
        player->friendship += 1;
        updateHappiness(player, 2);
        showDialogue("Narrator",
                     "Binasa mo nang mabilis ang slides ni Jelo, tapos nag-present ka na parang ikaw ang gumawa. Pagkatapos, nanginginig ang kamay mo, pero pasado.");
    }
    else if (choice == 2)
    {
        player->friendship -= 1;
        updateHappiness(player, -2);
        showDialogue("Professor",
                     "Absent si Mr. Jelo? Individual score na lang siya. Group, ituloy ninyo.");
        showDialogue("Narrator",
                     "Natapos ang presentation. Mabilis, malinis, at medyo malamig ang pakiramdam.");
    }
    else
    {
        updateEnergy(player, -3);

        if (player->friendship >= 3)
        {
            player->friendship += 1;
            updateHappiness(player, 4);
            showDialogue("Narrator",
                         "Sumagot si Jelo sa pangatlong ring. Makalipas ang labinlimang minuto, dumating siyang humihingal, nakasuot ng parehong damit kahapon.");
            showDialogue("Jelo",
                         "Sorry, bro! Late ako! Hindi ko alam kung paano ako nakarating dito!");
            showDialogue("Narrator",
                         "Nag-present siya. Hindi perpekto, pero nandoon siya. At 'yon ang mahalaga.");
        }
        else
        {
            updateHappiness(player, -3);
            showDialogue("Narrator",
                         "Walang sumagot. Dalawang beses kang tumawag, tatlong beses nag-text. Wala. Ikaw na lang ang nagpaliwanag sa professor.");
        }
    }

    showDialogue("Narrator",
                 "Natapos ang presentation. Naramdaman mong hindi lang pera ang pinag-uusapan sa buhay-kolehiyo. Oras din, tiwala, at mga taong nawawala kapag kailangan mo sila.");

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 24 COMPLETE\n");
    printf("================================\n");
}

void day25Story(struct Player *player)
{
    int remaining = SAVINGS_TARGET - player->money;
    int daysLeft = 30 - 25;
    int passive = daysLeft * (DAILY_ALLOWANCE - DAILY_UPKEEP);
    int stillNeeded;

    printf("\n================================\n");
    printf("       DAY 25: SAVINGS CHECK\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Huwebes. Limang araw na lang. Binuksan mo ang notebook kung saan mo isinusulat ang bawat gastos.");

    showDialogue(player->name,
                 "Limang araw na lang. Kailangan kong malaman kung malapit na ako sa goal ko.");

    printf("\n========== FINANCIAL UPDATE ==========\n");
    printf("Current Money: PHP %d\n", player->money);
    printf("Total Earnings: PHP %d\n", player->totalEarnings);
    printf("Total Expenses: PHP %d\n", player->totalExpenses);
    printf("Savings Target: PHP %d\n", SAVINGS_TARGET);

    if (remaining <= 0)
    {
        printf("\nYou have already reached your savings target!\n");
    }
    else
    {
        printf("\nRemaining amount needed: PHP %d\n", remaining);

        stillNeeded = remaining - passive;

        if (stillNeeded <= 0)
        {
            printf("Allowance minus daily costs should cover this. Just avoid big losses!\n");
        }
        else
        {
            printf("After 5 more days of allowance minus costs, you still need PHP %d.\n", stillNeeded);
            printf("That is about %d more shift(s). Weekend shifts left: Day 27 and Day 28.\n",
                   (stillNeeded + SHIFT_PAY - 1) / SHIFT_PAY);
        }
    }

    showDialogue("Narrator",
                 "Bago ka makaalis, tinawag ka ni Sir Dante sa opisina. Isinara niya ang pinto.");

    if (player->bossTrust >= 5)
    {
        showDialogue("Sir Dante",
                     "Halos isang buwan kitang minamasdan. Walang tinago. Walang dinaya. Walang palusot. Hindi ako nagbibigay ng bonus. Ngayon, nagbibigay ako.");

        updateMoney(player, 200);
        updateHappiness(player, 8);
        printf("\nPerformance bonus received: PHP 200!\n");
    }
    else if (player->bossTrust >= 2)
    {
        showDialogue("Sir Dante",
                     "Hindi ka perpekto. Pero hindi rin kita kailangang bantayan nang todo. Ituloy mo 'yan.");

        updateHappiness(player, 3);
    }
    else
    {
        showDialogue("Sir Dante",
                     "May mga nakita ako. Hindi ko pa sasabihin kung ano. Gusto ko munang makita kung paano ka magtatapos.");

        updateHappiness(player, -5);
    }

    showDialogue("Narrator",
                 "Pag-alis mo, naisip mong ang mga huling araw ay hindi na lang tungkol sa pera. Tungkol na rin ito sa kung sino ka kapag may nakatingin, at kapag wala.");

    financialQuizHard(player);

    printf("\n================================\n");
    printf("          DAY 25 COMPLETE\n");
    printf("================================\n");
}
void day26Story(struct Player *player)
{
    int choice;
    int done = 0;

    printf("\n================================\n");
    printf("       DAY 26: EXAM DAY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Biyernes. Exam day. Dalawang oras ka nang gising bago pa tumunog ang alarm, kasi nagre-review ang utak mo kahit tulog.");

    showDialogue(player->name,
                 "Sir, kung may partial credit sa kaba, perfect na ako.");

    if (player->energy >= 50)
    {
        updateHappiness(player, 8);
        showDialogue("Narrator",
                     "Malinaw ang isip mo. Alam mo ang sagot sa halos lahat. Paglabas mo ng room, parang gumaan ang buong semestre.");
    }
    else if (player->energy >= 30)
    {
        showDialogue("Narrator",
                     "Medyo malabo ang mga huling tanong, pero nairaos mo. Pasado siguro. Sana.");
    }
    else
    {
        updateHappiness(player, -6);
        showDialogue("Narrator",
                     "Dalawang beses mong binasa ang parehong tanong. Hindi pa rin pumasok. Hindi pang-exam ang pagod mo ngayon.");
    }

    showDialogue("Narrator",
                 "Pauwi ka na nang may mag-pop na ad sa phone mo: 'Wireless earbuds accessory, 50 percent OFF, today only!' Sa kabilang tab, may keychain sa Divisoria stall: PHP 100.");

    showDialogue(player->name,
                 "Deserve ko ba 'to? O naiimpluwensyahan lang ako ng algorithm?");

    printf("\nYour money: PHP %d\n", player->money);
    printf("\n[1] Buy the gadget accessory - PHP 300 (+10 happiness)\n");
    printf("[2] Save your money - PHP 0 (+3 happiness)\n");
    printf("[3] Buy a small keychain gift for Mika - PHP 100\n");

    while (done == 0)
    {
        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, 300))
            {
                updateHappiness(player, 10);
                printf("\nBago ang accessory mo. Ang saya. Hanggang sa tiningnan mo ulit ang GCash mo.\n");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
        else if (choice == 2)
        {
            updateHappiness(player, 3);
            printf("\nIsinara mo ang tab. Mahina ka sa temptation, pero mas malakas ang goal mo.\n");
            done = 1;
        }
        else
        {
            if (spendMoney(player, 100))
            {
                player->mikaBond += 2;
                updateHappiness(player, 8);
                showDialogue("Mika",
                             "Wait, this is, like, so random. And so me. Ew. I love it. Don't tell anyone na kinilig ako.");
                done = 1;
            }
            else
            {
                printf("\nNot enough money! Choose another option.\n");
            }
        }
    }

    displayStatus(*player);

    printf("\n================================\n");
    printf("          DAY 26 COMPLETE\n");
    printf("================================\n");
}

void day27Story(struct Player *player)
{
    int choice;
    char message[200];

    printf("\n================================\n");
    printf("     DAY 27: JELO'S CONFESSION\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Sabado. Nag-text si Jelo: 'bro, pwede ba tayong magkita? sa tapat ng branch. wag mo muna sabihin kay mika.'");

    showDialogue("Narrator",
                 "Nakaupo siya sa bangketa. Walang sunglasses. Walang pabango. Ang suot niya, parehong t-shirt mula Day 21.");

    showDialogue("Jelo",
                 "Bro, may aaminin ako. Yung 'PHP 5,000 daily' na app? Doon napunta ang tuition ko. Lahat. Pati 'yung pinadala ni Mama.");

    showDialogue(player->name,
                 "Pare...");

    showDialogue("Jelo",
                 "Yung 'PHP 800 kita today' na pinakita ko sa'yo noong Linggo? Fake dashboard 'yon. Numbers lang sa screen. Wala akong nawi-withdraw.");

    showDialogue("Jelo",
                 "Para ma-unlock ang withdrawal, kailangan kong mag-invite ng tatlong tao. Ikaw, si Renz, tapos isa pa. Ni-refer kita, bro. Alam kong mali. Pero desperado na ako.");

    if (player->loanedToJelo > 0)
    {
        snprintf(message, sizeof(message),
                 "At yung PHP %d na hiniram ko sa'yo? Pinang-deposit ko rin. Sorry. Sorry talaga.",
                 player->loanedToJelo);
        showDialogue("Jelo", message);
    }
    else
    {
        showDialogue("Jelo",
                     "Hindi mo ako pinautang noon, at ngayon alam ko na kung bakit. Mas matalino ka sa akin.");
    }

    showDialogue("Jelo",
                 "Yung sapatos, yung sunglasses, yung porma? Utang lahat. Tama ka noong Day 1, bro. Wala talagang laman 'tong wallet ko. Puro resibo.");

    printf("\n[1] \"Hindi mo kasalanan na naloko ka. Pero kasalanan mong hindi ka nagsabi. Tulungan kita.\"\n");
    printf("[2] \"Ni-refer mo ako sa scam, Jelo. Hindi madaling kalimutan 'yon.\"\n");
    printf("[3] Hindi sumagot. Umalis.\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->friendship += 2;
        updateHappiness(player, 3);
        showDialogue("Jelo",
                     "Bro... hindi ko 'to deserve. Pero salamat. Promise, magbabago na ako.");
    }
    else if (choice == 2)
    {
        player->friendship -= 1;
        updateHappiness(player, -2);
        showDialogue("Jelo",
                     "Tama ka. Hindi ko hinihinging kalimutan mo. Basta... huwag ka munang umalis.");
    }
    else
    {
        player->friendship -= 2;
        updateHappiness(player, -4);
        showDialogue("Narrator",
                     "Tumalikod ka. Narinig mo siyang tumawag ng 'bro' nang isang beses. Hindi ka lumingon.");
    }

    showDialogue("Narrator",
                 "Nag-vibrate ang phone mo. Parehong group, bagong mensahe: 'Recovery program! I-recover ang nawala mong pera. Kailangan lang ng bagong deposit.'");

    showDialogue("Jelo",
                 "Kita mo? Pati ang pagkalugi ko, ginagawa nilang negosyo. Tingnan mo nga kung legit.");

    scamDetectiveHard(player);

    showDialogue("Narrator",
                 "Sabado pa rin. May desisyon ka pang haharapin para sa araw na 'to.");
}

void day28Story(struct Player *player)
{
    int choice;

    printf("\n================================\n");
    printf("       DAY 28: SUNDAY RECOVERY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Linggo. Tahimik ang umaga. Nag-vibrate ang phone mo: group chat na 'BRANCH CREW'. Mula kay Sir Dante.");

    showDialogue("Sir Dante",
                 "Lunes, 8 AM. Audit ng drawer. Lahat ng crew. Walang absent.");

    showDialogue(player->name,
                 "Audit. Tatlong salitang nagpapahina ng tuhod ko.");

    showDialogue("Narrator",
                 "Ilang minuto pagkatapos, may private message mula kay Mika: 'Are you awake? Ngl, kinakabahan ako para bukas. Hindi dahil sa drawer.'");

    printf("\n[1] \"Kahit ano'ng mangyari bukas, nandito ako.\"\n");
    printf("[2] \"Mika, kung may kinalaman 'to sa mali ko sa drawer, sabihin mo na.\"\n");
    printf("[3] \"Matulog ka na, bestie. Bukas na 'yan.\"\n");

    choice = getChoice(1, 3);

    if (choice == 1)
    {
        player->mikaBond += 2;
        updateHappiness(player, 5);
        showDialogue("Mika",
                     "...Don't say that kung hindi mo ibig sabihin. Kasi baka paniwalaan ko.");
    }
    else if (choice == 2)
    {
        player->mikaBond += 1;
        player->bossTrust += 1;
        showDialogue("Mika",
                     "Bukas. Promise. Pero hindi mo kasalanan ang ginawa ko, ha. Choice ko 'yon.");
    }
    else
    {
        player->mikaBond += 1;
        updateHappiness(player, 2);
        showDialogue("Mika",
                     "Okay, okay. Goodnight. Thank you for not making it weird.");
    }

    showDialogue("Narrator",
                 "Linggo pa rin. Pahinga o pera? Dalawang araw na lang ang natitira.");
}

void day29Story(struct Player *player)
{
    int choice;
    char message[250];

    printf("\n================================\n");
    printf("       DAY 29: THE AUDIT\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Lunes. Alas-otso. Bago pa magbukas ang branch, nakahilera ang buong crew sa harap ng cashier. Nasa gitna si Sir Dante, hawak ang makapal na folder.");

    showDialogue("Sir Dante",
                 "Audit. Isang buwan ng drawer. Hindi ako magtatanong nang dalawang beses.");

    if (player->drawerShort > 0)
    {
        snprintf(message, sizeof(message),
                 "May mali sa sukli ngayong buwan. Kabuuang PHP %d. Kinaltasan na ng sahod ang nagkamali. Pero bawat error, may remake at refund. Hindi 'yon galing sa sahod. May ibang nagbayad.",
                 player->drawerShort);
        showDialogue("Sir Dante", message);

        showDialogue("Mika",
                     "Sir, ako po. Lahat po ng error, sa akin po galing. Ako po ang nagbayad.");

        showDialogue("Sir Dante",
                     "Mika. Hindi ikaw ang nasa cashier tuwing may error. Hindi ko sasabihin kung sino. Hayaan kong ang taong 'yon ang magsalita.");

        showDialogue("Narrator",
                     "Tahimik ang buong branch. Nasa'yo ang lahat ng mata. Pati mata ni Mika, na pilit nagsasabing 'huwag'.");

        printf("\nYour money: PHP %d\n", player->money);
        printf("\n[1] \"Ako po ang nagkamali, sir. Babayaran ko po kay Mika ang PHP %d.\"\n",
               player->drawerShort);
        printf("[2] \"Ako po, sir. Pero hayaan na po natin kay Mika.\"\n");
        printf("[3] Tumahimik.\n");

        choice = getChoice(1, 3);

        if (choice == 1)
        {
            if (spendMoney(player, player->drawerShort))
            {
                player->repaidMika = 1;
                player->bossTrust += 2;
                player->mikaBond += 2;
                updateHappiness(player, 5);
                showDialogue("Sir Dante",
                             "Hindi ko tinanong kung sino ang nagkamali. Gusto ko lang malaman kung sino ang magsasabi ng totoo. Ikaw 'yon.");
                showDialogue("Mika",
                             "Why would you do that? Ang corny mo. Pero... thank you. Seryoso.");
            }
            else
            {
                player->bossTrust += 1;
                player->mikaBond += 1;
                showDialogue("Narrator",
                             "Binuksan mo ang GCash. Kulang ang laman. 'Babayaran ko po, hulugan,' sabi mo. Tumango si Sir Dante. Hindi pa tapos ang usapang 'to.");
            }
        }
        else if (choice == 2)
        {
            player->bossTrust += 1;
            showDialogue("Sir Dante",
                         "Inamin mo. Pero hindi mo inayos. Tandaan mo 'yan.");
        }
        else
        {
            player->bossTrust -= 2;
            player->mikaBond -= 1;
            updateHappiness(player, -5);
            showDialogue("Mika",
                         "Okay lang. Ako na. Sanay na ako.");
            showDialogue("Narrator",
                         "Mas mabigat pala ang katahimikan kaysa sa kahit anong halaga.");
        }
    }
    else
    {
        player->repaidMika = 1;
        player->bossTrust += 1;
        player->mikaBond += 1;

        showDialogue("Sir Dante",
                     "Walang kulang kahit piso. Hindi ko pa 'yan nakikita sa buwanang audit.");

        showDialogue("Mika",
                     "Perfect drawer? Ngl, nakakainis ka. Pero, like, thank you for making my last week easy.");

        showDialogue(player->name,
                     "Last week? Anong last week?");

        showDialogue("Mika",
                     "Wala! Figure of speech. Very figurative.");
    }

    showDialogue("Sir Dante",
                 "Bukas, may bisita. Magpa-plantsa kayo ng uniporme. Lahat.");

    showDialogue("Narrator",
                 "Pag-uwi mo, may PHP 250 na natitira sa bulsa para sa araw na 'to. Kailangan ng matinong plano.");

    budgetShoppingHard(player);

    printf("\n================================\n");
    printf("          DAY 29 COMPLETE\n");
    printf("================================\n");
}

void day30Story(struct Player *player)
{
    int choice;
    int mikaStays = 1;
    char message[250];

    printf("\n================================\n");
    printf("       DAY 30: THE FINAL DAY\n");
    printf("================================\n");

    showDialogue("Narrator",
                 "Martes. Ikatatlumpung araw. Malinis ang sahig, pantay ang mga tray, at naka-plantsa ang uniporme ni Sir Dante. Pati ang hangin, parang naka-formal.");

    showDialogue("Sir Dante",
                 "Walang tanong. Tumayo ka lang nang diretso. At sabihin mo ang totoo, kahit ano'ng itanong.");

    showDialogue("Narrator",
                 "Alas-diyes. Huminto sa tapat ng branch ang itim na SUV. 'Yung nakita mo noong Day 13.");

    showDialogue("Mika",
                 "Papa.");

    showDialogue(player->name,
                 "Papa? Mika, 'yung 'wrong branch' na SUV... ito pala 'yon.");

    showDialogue("Narrator",
                 "Bumaba ang isang lalaking naka-barong, pilak na ang buhok. Yumuko nang bahagya si Sir Dante. Bihira mo 'yong makita.");

    showDialogue("Mr. Villareal",
                 "Ramon Villareal. Ako ang may-ari ng buong food group na 'to. At ito si Mika Villareal Dizon. Anak ko.");

    showDialogue("Mika",
                 "Dizon ang apelyido ni Mama. Hindi ko ginamit ang Villareal kasi, like... ayokong kilalanin ako dahil sa pera ng pamilya namin. Pamilya namin 'yon. Hindi ako.");

    showDialogue("Mr. Villareal",
                 "Tatlumpung araw. Regular na crew, walang family money, walang apelyido. Pustahan namin. Sabi niya, kaya niya.");

    showDialogue(player->name,
                 "Kaya pala ang mamahaling sapatos. Kaya pala labindalawang missed calls. Kaya pala ang 'spider'.");

    showDialogue("Mika",
                 "Sorry. Hindi kita niloko. Pinrotektahan ko lang 'yung pagiging... ako.");

    showDialogue("Sir Dante",
                 "Alam ko mula Day 2. Si Sir Ramon mismo ang nakiusap: tratuhin siya na parang kahit sino. Kaya mas mahigpit ako sa kanya. Hindi dahil galit ako. Dahil gusto kong makitang kaya niya.");

    if (player->repaidMika == 1)
    {
        showDialogue("Mr. Villareal",
                     "Chineck ko ang lahat. Walang gastos na galing sa card ng pamilya. Pasado ka, anak.");

        showDialogue("Narrator",
                     "Napasigaw nang mahina si Mika, tapos mabilis niyang tinakpan ang bibig niya. Natawa si Sir Dante. Halos hindi mo napansin, pero natawa siya.");

        showDialogue("Mr. Villareal",
                     "At ikaw, iho. Ikaw ang crew na hindi nagtanong. May iniwan akong PHP 3,000 para sa'yo. Pasasalamat.");

        printf("\n[1] \"Hindi po, sir. Hindi po ako tumulong para mabayaran.\"\n");
        printf("[2] \"Sir, malaking tulong po 'to sa goal ko. Tatanggapin ko po.\" (+PHP 3000)\n");

        choice = getChoice(1, 2);

        if (choice == 1)
        {
            player->bossTrust += 2;
            player->mikaBond += 3;
            updateHappiness(player, 10);
            showDialogue("Mr. Villareal",
                         "Sir Dante, tama ka. Genuine nga.");
            showDialogue("Sir Dante",
                         "Sinabi ko na sa inyo.");
        }
        else
        {
            updateMoney(player, 3000);
            player->bossTrust -= 2;
            player->mikaBond -= 3;
            updateHappiness(player, -8);
            showDialogue("Mika",
                         "Oh. Okay. Kailangan mo naman talaga ng pera. I get it.");
            showDialogue("Narrator",
                         "Hindi nagsalita si Sir Dante. Tumingin lang siya sa'yo nang limang segundo. Parang limang taon.");
        }
    }
    else
    {
        showDialogue("Mr. Villareal",
                     "Chineck ko rin ang mga transaction. May refund at remake na dumaan sa card ni Mika. Pera ng pamilya 'yon. Paglabag. Mika, uuwi ka na.");

        showDialogue("Mika",
                     "Papa, please. Isang araw na lang.");

        printf("\n[1] \"Sir, ako po ang may kasalanan sa drawer. Babayaran ko po ang PHP %d.\"\n",
               player->drawerShort);
        printf("[2] \"Sir, hindi po niya kasalanan. Mabait po siya sa amin.\"\n");
        printf("[3] Tumahimik.\n");

        choice = getChoice(1, 3);

        if (choice == 1)
        {
            loseMoney(player, player->drawerShort);
            player->repaidMika = 1;
            player->bossTrust += 2;
            player->mikaBond += 3;
            updateHappiness(player, 10);
            showDialogue("Mr. Villareal",
                         "Isang taong nagbalik ng pera nang walang nag-uutos. Walang family money, kung ibinalik. Pasado ka, Mika.");
        }
        else if (choice == 2)
        {
            mikaStays = 0;
            player->mikaBond += 1;
            showDialogue("Mr. Villareal",
                         "Maganda ang puso mo, iho. Pero hindi 'yon sagot sa patakaran.");
        }
        else
        {
            mikaStays = 0;
            player->mikaBond -= 3;
            updateHappiness(player, -8);
            showDialogue("Narrator",
                         "Hindi ka nagsalita. Habang isinasakay si Mika sa SUV, hindi siya lumingon.");
        }
    }

    if (mikaStays == 1)
    {
        if (player->mikaBond >= 10)
        {
            showDialogue("Mika",
                         "So, like, Mika Villareal Dizon. Pero ikaw, Mika lang. Dinner sa Sabado? Ako ang pipili ng lugar, ikaw ang pipili ng sasakyan. Split tayo. Promise, hindi kita ililibre sa mahal.");
            showDialogue(player->name,
                         "Split? Sige. Basta fishball ang pampagana.");
        }
        else if (player->mikaBond >= 5)
        {
            showDialogue("Mika",
                         "Friends muna tayo, ha? Pero seryoso, thank you. Hindi ko inakalang may makikilala akong totoong tao sa fast-food branch.");
        }
        else
        {
            showDialogue("Mika",
                         "Thank you for the thirty days. Ingat ka, ha.");
        }
    }
    else
    {
        if (player->mikaBond >= 5)
        {
            showDialogue("Narrator",
                         "Gabi, nag-text si Mika: 'Hindi ako nakapagpaalam nang maayos. Babalik ako. Hintayin mo ako, ha?'");
        }
        else
        {
            showDialogue("Narrator",
                         "Gabi, nag-text si Mika: 'Thanks for the thirty days.' Wala nang sumunod.");
        }
    }

    showDialogue("Narrator",
                 "Paglabas mo ng branch, nakaupo si Jelo sa bangketa. Walang sunglasses. Walang porma. Pero nakangiti.");

    if (player->loanedToJelo > 0 && player->friendship >= 3)
    {
        updateMoney(player, player->loanedToJelo);
        snprintf(message, sizeof(message),
                 "Bro, ito na ang PHP %d. Nag-part-time na ako sa karinderya ng kapitbahay. Pinag-ipunan ko 'to.",
                 player->loanedToJelo);
        showDialogue("Jelo", message);
        printf("\nJelo returned PHP %d to you!\n", player->loanedToJelo);
    }
    else if (player->loanedToJelo > 0)
    {
        showDialogue("Jelo",
                     "Bro, wala pa 'yung hiniram ko. Hindi ko makakalimutan 'yon. Babayaran kita, kahit tumagal pa.");
    }
    else if (player->friendship >= 3)
    {
        showDialogue("Jelo",
                     "Bro, salamat sa lahat. Hindi ako nangutang sa'yo ng pera, pero marami kang naitulong na hindi ko mababayaran.");
    }
    else
    {
        showDialogue("Jelo",
                     "Bro... sorry ulit. Sana balang araw, maayos pa tayo.");
    }

    if (player->bossTrust >= 8)
    {
        showDialogue("Sir Dante",
                     "Hindi ko sasabihing proud ako. Pero kung may bakante bukas, ikaw ang una kong tatawagan.");
    }
    else
    {
        showDialogue("Sir Dante",
                     "Matuto ka. Hindi lahat ng tama, nakikita ng iba. Pero nakikita ko.");
    }

    showDialogue(player->name,
                 "Tatlumpung araw. PHP 250 kada araw. Ang natutunan ko: ang pera, nauubos. Ang pagkatao, hindi, kung iingatan mo.");

    showDialogue("Narrator",
                 "Tapos na ang 30-day challenge. Ito ang kinalabasan.");
}

void showEnding(struct Player *player)
{
    int reachedGoal = 0;

    if (player->money >= SAVINGS_TARGET)
    {
        reachedGoal = 1;
    }

    printf("\n================================\n");
    printf("         30 DAYS COMPLETE\n");
    printf("================================\n");

    printf("Final Money: PHP %d / %d\n", player->money, SAVINGS_TARGET);
    printf("Energy: %d | Happiness: %d\n", player->energy, player->happiness);
    printf("Jelo Friendship: %d | Mika Bond: %d | Boss Trust: %d\n",
           player->friendship, player->mikaBond, player->bossTrust);

    printf("\n========== YOUR ENDING ==========\n");

    if (reachedGoal == 1 && player->happiness >= 50 && player->friendship >= 6 &&
        player->mikaBond >= 10 && player->bossTrust >= 8)
    {
        printf("ENDING: BUDGET BATTLE CHAMPION\n");
        printf("You hit your goal, kept your sanity, saved your friend,\n");
        printf("won the girl, and earned your boss's respect.\n");
        printf("Walang nawala sa'yo. Ito ang tunay na panalo.\n");
    }
    else if (reachedGoal == 1 && player->happiness >= 50)
    {
        printf("ENDING: WISE SAVER\n");
        printf("You hit your goal and stayed healthy. But you left some people behind.\n");
    }
    else if (reachedGoal == 1)
    {
        printf("ENDING: BURNED OUT\n");
        printf("You have the money, but you forgot to live.\n");
    }
    else if (player->mikaBond >= 10)
    {
        printf("ENDING: PUSONG MAMON\n");
        printf("You missed the money goal, but you gained something money can't buy.\n");
    }
    else if (player->friendship >= 6)
    {
        printf("ENDING: LOYAL FRIEND\n");
        printf("You missed the goal, but Jelo will remember who stood by him.\n");
    }
    else if (player->bossTrust >= 8)
    {
        printf("ENDING: SIR DANTE'S PRIDE\n");
        printf("You missed the goal, but you earned the respect of a very strict man.\n");
    }
    else
    {
        printf("ENDING: SURVIVOR\n");
        printf("You made it through 30 days. Next time, spend wiser, and love harder.\n");
    }

    printf("\nTry again and make different choices for a different ending!\n");
} 