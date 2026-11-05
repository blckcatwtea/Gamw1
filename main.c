#include <stdio.h>

struct Player
{
    char name[50];
    int gender;
    int money;
    int energy;
    int happiness;
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

void day2Story(struct Player *player); // day 2 story

void orderCheckingGame(struct Player *player);

void day3Story(struct Player *player);

void customerServiceGame(struct Player *player);

void day4Story(struct Player *player);

void multipleOrderGame(struct Player *player);

void day5Story(struct Player *player);

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
    printf("\n===== PLAYER STATUS =====\n");
    printf("Money: PHP %d\n", player.money);
    printf("Energy: %d/100\n", player.energy);
    printf("Happiness: %d/100\n", player.happiness);
}

void updateMoney(struct Player *player, int amount)
{

    player->money += amount;
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
        printf("\n========== DAY %d ==========\n", day);

        displayStatus(*player);

        if (day == 1)
        {
            day1Story(player);
        }

        if (day == 2)
        {
            day2Story(player);
        }

        if (day == 3)
        {
            day3Story(player);
        }

        if (day == 4)
        {
            day4Story(player);
        }

        if (day == 5)
        {
            day5Story(player);
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    printf("\nCongratulations! You completed 30 days!\n");
}

void day1Story(struct Player *player)
{
    char message[100];

    printf("\n================================\n");
    printf("       DAY 1: FIRST DAY\n");
    printf("================================\n");

    printf("\n[7:00 AM - TUP MANILA]\n");

    showDialogue("Narrator",
                 "You arrive at TUP Manila carrying your backpack.");

    showDialogue("Narrator",
                 "Students are walking toward their classrooms.");

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

    showDialogue("Jelo", "Busog ka na? Tara na, baka ma-late tayo sa first class!");

    showDialogue("Player", "Wait lang! First day pa lang, ayoko nang ma-late men.");

    showDialogue("Jelo", "Chill ka lang! Alam ko na mga shortcuts dito. Sundan mo 'ko!");

    showDialogue("Narrator", "You and Jelo walk toward your classroom, unaware of the challenges waiting for you.");

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
    printf("\n5s\n", speaker);
    printf("%s\n", dialogue);

    printf("\nPress Enter to continue...");
    getchar();
}

void breakfastChoice(struct Player *player)
{
    int choice;
    int completed = 0;

    printf("\n================================\n");
    printf("       BREAKFAST TIME\n");
    printf("================================\n");

    printf("\nJelo: Bro, gutom na ako. Ano'ng trip mong breakfast?\n");

    printf("\n[1] Carinderia meal - PHP 50\n");
    printf("[2] Fast-food meal - PHP 120\n");
    printf("[3] Skip breakfast - PHP 0\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 3)
        {
            printf("\nInvalid choice! Please select 1, 2, or 3.\n");
        }
        else
        {
            switch (choice)
            {
            case 1:
                if (spendMoney(player, 50))
                {
                    updateEnergy(player, 15);
                    updateHappiness(player, 5);

                    printf("\nYou bought a carinderia meal.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another meal.\n");
                }
                break;

            case 2:
                if (spendMoney(player, 120))
                {
                    updateEnergy(player, 20);
                    updateHappiness(player, 15);

                    printf("\nYou bought a fast-food meal.\n");
                    completed = 1;
                }
                else
                {
                    printf("\nNot enough money! Choose another meal.\n");
                }
                break;

            case 3:
                updateEnergy(player, -10);
                updateHappiness(player, -5);

                printf("\nYou decided to skip breakfast.\n");
                completed = 1;
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

    printf("\n================================\n");
    printf("          DAY 5 COMPLETE\n");
    printf("================================\n");
}