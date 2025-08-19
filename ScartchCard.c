#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN057 30
#define MAX_CARD_DIGITS057 21
#define admin_pass057 "admin123"

#define CARDS_FILE "cards.txt"
#define USERS_FILE "users.txt"
#define LOCKED_FILE "locked.txt"
#define HISTORY_FILE "history.txt"
#define STATS_FILE "Statistics.txt"
#define PASSWORD_FILE "password.txt"

typedef struct
{
    char card_no057[MAX_CARD_DIGITS057];
    int min057;
} Card057;

typedef struct
{
    char timestamp057[30];
    char mobile_number057[MAX_LEN057];
    char card_no057[MAX_CARD_DIGITS057];
    int min057;
} history057;

typedef struct
{
    char mobile_number057[MAX_LEN057];
    int min057;
} User057;

typedef struct
{
    char mobile_number057[MAX_LEN057];

} LockedUser057;

typedef struct
{
    char username057[100];
    char password057[100];

} PasswordManager057;

PasswordManager057 *passMange = NULL;
Card057 *cards057 = NULL;
User057 *users057 = NULL;
LockedUser057 *locked_users057 = NULL;
history057 *deleted057 = NULL;
int total_pass057 = 0;
int total_cards057 = 0;
int total_users057 = 0;
int total_locked057 = 0;
int total_delete057 = 0;
int min40_057 = 0, min60_057 = 0, min100_057 = 0;

void load_data057();
void save_data057();
void menu057();
void Display_User_Option057();

void show_banner057()
{
    printf("\n==================================\n");
    printf("||      ScratchSecure System    ||\n");
    printf("||      Developed by: SANJID    ||\n");
    printf("==================================\n\n");
}

void cleanup057()
{
    save_data057();
    free(cards057);
    free(users057);
    free(locked_users057);
    free(deleted057);
    free(passMange);
}

void post_action_menu057()
{
    int select057;
    printf("\n***Menu***\n1. Main Menu\n2. Another input\n3. Exit\nEnter your option: ");
    scanf("%d", &select057);
    if (select057 == 1)
    {
        menu057();
    }
    else if (select057 == 3)
    {
        printf("Exited Successfully\n\n");
        cleanup057();
        exit(0);
    }
}

int find_card_index057(const char *card_no057)
{
    for (int i = 0; i < total_cards057; i++)
    {
        if (strcmp(cards057[i].card_no057, card_no057) == 0)
            return i;
    }
    return -1;
}
void generate_card_number057(char *num057)
{
    do
    {
        num057[0] = '1' + rand() % 9;
        for (int i = 1; i < 20; i++)
        {
            num057[i] = '0' + rand() % 10;
        }
        num057[20] = '\0';
    } while (find_card_index057(num057) != -1);
}

int find_user_index057(const char *mobile_number057)
{
    for (int i = 0; i < total_users057; i++)
    {
        if (strcmp(users057[i].mobile_number057, mobile_number057) == 0)
            return i;
    }
    return -1;
}

int is_locked_user057(const char *mobile_number057)
{
    for (int i = 0; i < total_locked057; i++)
    {
        if (strcmp(locked_users057[i].mobile_number057, mobile_number057) == 0)
            return 1;
    }
    return 0;
}
void *safe_realloc057(void *ptr057, size_t new_size057)
{
    if (new_size057 == 0)
    {
        free(ptr057);
        return NULL;
    }
    void *temp057 = realloc(ptr057, new_size057);
    if (!temp057)
    {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        cleanup057();
        exit(EXIT_FAILURE);
    }
    return temp057;
}
void lock_user057(const char *mobile_number057)
{

    locked_users057 = safe_realloc057(locked_users057, (total_locked057 + 1) * sizeof(LockedUser057));
    strcpy(locked_users057[total_locked057++].mobile_number057, mobile_number057);
}

void delete_card057(const char *card_no057)
{
    int idx057 = find_card_index057(card_no057);
    if (idx057 == -1)
    {
        printf("Card Not Found\n");
        return;
    }
    for (int i = idx057; i < total_cards057 - 1; i++)
    {
        cards057[i] = cards057[i + 1];
    }
    total_cards057--;

    cards057 = safe_realloc057(cards057, total_cards057 * sizeof(Card057));
    printf("Card Deletion Successful\n");
}

void add_card057(int count40_057, int min057)
{

    cards057 = safe_realloc057(cards057, (total_cards057 + count40_057) * sizeof(Card057));
    for (int i = 0; i < count40_057; i++)
    {
        generate_card_number057(cards057[total_cards057].card_no057);
        cards057[total_cards057].min057 = min057;
        total_cards057++;
    }
    printf("%d Cards (%d min) Creation Successful\n", count40_057, min057);
}
void show_card057()
{
    for (int i = 0; i < total_cards057; i++)
        printf("Card: %s    Min: %d\n", cards057[i].card_no057, cards057[i].min057);
}

void Statistics057()
{
    int count40_057 = 0, count60_057 = 0, count100_057 = 0;

    for (int i = 0; i < total_cards057; i++)

    {
        if (cards057[i].min057 == 40)
            count40_057++;
        else if (cards057[i].min057 == 60)
            count60_057++;
        else if (cards057[i].min057 == 100)
            count100_057++;
    }

    printf("\n%-37s %-10s %-10s %-10s\n", "Statistics", "40 min", "60 min", "100 min");
    printf("---------------------------------------------------------------------------------\n");
    printf("%-37s %-10d %-10d %-10d\n", "Cards Sold:", min40_057, min60_057, min100_057);
    printf("%-37s %-10d %-10d %-10d\n", "Cards Remains:", count40_057, count60_057, count100_057);
    printf("%-37s %-10d %-10d %-10d\n", "Total Amounts Sold in Tk (Card-wise):", min40_057 * 40, min60_057 * 60, min100_057 * 100);
    printf("Total Amount: %d\n", min40_057 * 40 + min60_057 * 60 + min100_057 * 100);
}

void unlock_user057(const char *mobile_number057)
{
    int found057 = 0;
    for (int i = 0; i < total_locked057; i++)
    {
        if (strcmp(locked_users057[i].mobile_number057, mobile_number057) == 0)
        {
            found057 = 1;
            for (int j = i; j < total_locked057 - 1; j++)
            {
                locked_users057[j] = locked_users057[j + 1];
            }
            total_locked057--;
            locked_users057 = safe_realloc057(locked_users057, total_locked057 * sizeof(LockedUser057));
            printf("User %s unlock successful.\n", mobile_number057);
            break;
        }
    }
    if (!found057)
    {
        printf("User not found in locked list.\n");
    }
}

void deleted_data_store057(const char *mobile_number057, const char *card_no057, int card_index057)
{
    deleted057 = safe_realloc057(deleted057, (total_delete057 + 1) * sizeof(history057));
    strcpy(deleted057[total_delete057].mobile_number057, mobile_number057);
    strcpy(deleted057[total_delete057].card_no057, card_no057);
    deleted057[total_delete057].min057 = cards057[card_index057].min057;
    time_t now057 = time(NULL);
    strftime(deleted057[total_delete057].timestamp057, sizeof(deleted057[total_delete057].timestamp057), "%Y-%m-%d %H:%M:%S", localtime(&now057));
    total_delete057++;
}

void show_history057()
{
    printf("\n%-21s %-20s %-6s %-15s\n", "Card No", "Date       Time", "Minute", "Mobile No");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < total_delete057; i++)
    {
        printf("%-21s %-20s %-6d %-15s\n", deleted057[i].card_no057, deleted057[i].timestamp057, deleted057[i].min057, deleted057[i].mobile_number057);
    }
}
void search057()
{
    char mobile057[MAX_LEN057];
    printf("Enter Mobile Number: ");
    scanf("%s", mobile057);
    int count40_057 = 0;
    printf("\n%-21s %-20s %-6s\n", "Card No", "Date       Time", "Minute");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < total_delete057; i++)
    {
        if (strcmp(mobile057, deleted057[i].mobile_number057) == 0)
        {
            printf("%-21s %-20s %-6d\n", deleted057[i].card_no057, deleted057[i].timestamp057, deleted057[i].min057);
            count40_057++;
        }
    }
    if (count40_057 == 0)
        printf("No transactions found for this mobile number.\n");
    else
        printf("Total Transactions: %d\n", count40_057);
}
void Display_Admin_Option057()
{
    while (1)
    {
        int option057;
        printf("\n*****Admin Menu*****\n");
        printf("1. New Cards\n2. Delete Card\n3. Unlock Phone\n4. History\n5. Statistics\n6. Search\n7. Exit \n8. Show Cards\n9. Search A particular Card\n10.Back to Main Menu\nEnter Option: ");
        scanf("%d", &option057);

        if (option057 == 1)
        {
            int count40_057, min057;
            printf("Enter number of cards and minutes: ");
            scanf("%d %d", &count40_057, &min057);
            add_card057(count40_057, min057);
        }
        else if (option057 == 2)
        {
            char card_no057[MAX_CARD_DIGITS057];
            printf("Enter Card Number to Delete: ");
            scanf("%s", card_no057);
            delete_card057(card_no057);
        }
        else if (option057 == 3)
        {
            char mobile057[MAX_LEN057];
            printf("Enter Mobile Number to Unlock: ");
            scanf("%s", mobile057);
            unlock_user057(mobile057);
        }
        else if (option057 == 4)
        {
            show_history057();
        }
        else if (option057 == 5)
        {
            Statistics057();
        }
        else if (option057 == 6)
        {
            search057();
        }
        else if (option057 == 7)
        {
            printf("Exited Successfully\n\n");
            cleanup057();
            exit(0);
        }
        else if (option057 == 8)
        {
            show_card057();
        }
        else if (option057 == 9)
        {
            char card_no057[MAX_CARD_DIGITS057];
            printf("Enter Card No: ");
            scanf("%s", card_no057);
            int a057 = find_card_index057(card_no057);
            if (a057 != -1)

                printf("Card: %s    Min: %d\n", cards057[a057].card_no057, cards057[a057].min057);

            else
                printf("This Card is not found\n");
        }
        else if (option057 == 10)
        {
            return;
        }
        else
        {
            printf("Invalid Option\n");
        }
    }
}

void SignIn_or_SignUp()
{
    int option;
    printf("\n*****User Menu*****\n");
    printf("1. Sign in\n2. Sign Up\n Select Option: ");
    scanf("%d", &option);

    getchar();

    if (option == 1)
    {
        char uname[64], pass[64];
        printf("Enter User Name (No space): ");
        if (scanf("%63s", uname) != 1)
        {
            printf("Input error!\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            return;
        }
        printf("Enter Password (No space): ");
        if (scanf("%63s", pass) != 1)
        {
            printf("Input error!\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            return;
        }

        int found = 0;
        for (int i = 0; i < total_pass057; i++)
        {
            if (strcmp(passMange[i].username057, uname) == 0 &&
                strcmp(passMange[i].password057, pass) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            printf("Login successful!\n");
            Display_User_Option057();
        }
        else
        {
            printf("Invalid username or password.\n");
            return;
        }
    }
    else if (option == 2)
    {
        char uname[64], pass[64];
        printf("Choose User Name (No space): ");
        scanf("%63s", uname);

        for (int i = 0; i < total_pass057; i++)
        {
            if (strcmp(passMange[i].username057, uname) == 0)
            {
                printf("Username already taken.\n");
                return;
            }
        }

        printf("Choose Password (No space): ");
        scanf("%63s", pass);

        passMange = safe_realloc057(passMange, (total_pass057 + 1) * sizeof(PasswordManager057));
        strcpy(passMange[total_pass057].username057, uname);
        strcpy(passMange[total_pass057].password057, pass);
        total_pass057++;

        printf("Account created successfully!\n");
        Display_User_Option057();
    }
    else
    {
        printf("Invalid option.\n");
        return;
    }
}

void Display_User_Option057()
{

    char mobile057[MAX_LEN057], card057[MAX_CARD_DIGITS057];
    int card_index057;
    int attempt057 = 0;

    while (1)
    {
        printf("\nEnter Mobile Number: ");
        scanf("%s", mobile057);

        if (is_locked_user057(mobile057))
        {
            printf("Your Phone is locked\n");
            return;
        }

        printf("Enter Card Number: ");
        scanf("%s", card057);

        card_index057 = find_card_index057(card057);
        if (card_index057 != -1)
        {
            int user_index057 = find_user_index057(mobile057);

            if (user_index057 != -1)
            {
                users057[user_index057].min057 += cards057[card_index057].min057;
                printf("Reload Successful\n");
                printf("Remaining Balance: %d\n", users057[user_index057].min057);
            }
            else
            {

                users057 = safe_realloc057(users057, (total_users057 + 1) * sizeof(User057));
                strcpy(users057[total_users057].mobile_number057, mobile057);
                users057[total_users057].min057 = cards057[card_index057].min057;
                printf("Reload Successful\n");
                printf("Remaining Balance: %d\n", users057[total_users057].min057);
                total_users057++;
            }

            if (cards057[card_index057].min057 == 40)
                min40_057++;
            else if (cards057[card_index057].min057 == 60)
                min60_057++;
            else if (cards057[card_index057].min057 == 100)
                min100_057++;

            deleted_data_store057(mobile057, card057, card_index057);
            delete_card057(card057);
            post_action_menu057();
        }
        else
        {
            attempt057++;
            printf("Invalid Card input\n");
            if (attempt057 >= 3)
            {
                printf("Your Phone is locked\n");
                lock_user057(mobile057);
                return;
            }
            else
            {
                post_action_menu057();
            }
        }
    }
}
int password_check057(int option057)
{
    char password057[MAX_CARD_DIGITS057];
    int attempts057 = 3;

    while (attempts057--)
    {
        printf("Enter Password: ");
        scanf("%s", password057);

        if ((option057 == 1 && strcmp(password057, admin_pass057) == 0))
            return 1;

        printf("Incorrect password. %d attempt(s) left.\n", attempts057);
    }

    return -1;
}

void menu057()
{
    int option057;
    while (1)
    {
        char password057[MAX_CARD_DIGITS057];
        printf("\n*****Main Menu*****\n1. Admin\n2. User\n3. Exit\nEnter Option: ");
        scanf("%d", &option057);
        if (option057 == 1)
        {
            if (password_check057(1) == 1)
                Display_Admin_Option057();
            else
                printf("Access Denied. Returning to menu...\n");
        }
        else if (option057 == 2)
        {
            SignIn_or_SignUp();
        }
        else if (option057 == 3)
        {
            printf("Exited Successfully\n\n");
            cleanup057();
            exit(0);
        }
        else
        {
            printf("Invalid Option. Try again.\n");
        }
    }
}

void save_data057()
{
    FILE *f;

    // Save cards
    f = fopen(CARDS_FILE, "w");
    if (!f)
    {
        printf("Error opening cards.txt for writing!\n");
        return;
    }

    fprintf(f, "Cards		     min\n-------------------------\n");
    for (int i = 0; i < total_cards057; i++)
        fprintf(f, "%s %d\n", cards057[i].card_no057, cards057[i].min057);

    fprintf(f, "\nTotal Cards: %d\n", total_cards057);
    fclose(f);

    // Save users
    f = fopen(USERS_FILE, "w");
    if (!f)
    {
        printf("Error opening users.txt for writing!\n");
        return;
    }

    fprintf(f, "Mobile Number min\n------------------\n");
    for (int i = 0; i < total_users057; i++)
        fprintf(f, "%s   %d\n", users057[i].mobile_number057, users057[i].min057);

    fprintf(f, "\nTotal Users: %d\n", total_users057);
    fclose(f);

    // Save locked users
    f = fopen(LOCKED_FILE, "w");
    if (!f)
    {
        printf("Error opening locked.txt for writing!\n");
        return;
    }
    fprintf(f, "Locked Phone\n------------\n");

    for (int i = 0; i < total_locked057; i++)
        fprintf(f, "%s\n", locked_users057[i].mobile_number057);

    fclose(f);

    // Save history
    f = fopen(HISTORY_FILE, "w");
    if (!f)
    {
        printf("Error opening history.txt for writing!\n");
        return;
    }
    fprintf(f, "Date       Time     Mobile      Card                 min\n--------------------------------------------------------\n");
    for (int i = 0; i < total_delete057; i++)
        fprintf(f, "%s %s %s %d\n",
                deleted057[i].timestamp057,
                deleted057[i].mobile_number057,
                deleted057[i].card_no057,
                deleted057[i].min057);

    fprintf(f, "\nTotal Purchases: %d\n", total_delete057);
    fclose(f);

    // Save Statistics
    f = fopen(STATS_FILE, "w");

    if (!f)
    {
        printf("Error opening Statistics.txt for writing!\n");
        return;
    }
    int count40_057 = 0, count60_057 = 0, count100_057 = 0;

    for (int i = 0; i < total_cards057; i++)

    {
        if (cards057[i].min057 == 40)
            count40_057++;
        else if (cards057[i].min057 == 60)
            count60_057++;
        else if (cards057[i].min057 == 100)
            count100_057++;
    }
    fprintf(f, "\n%-37s %-10s %-10s %-10s\n", "Statistics", "40 min", "60 min", "100 min");
    fprintf(f, "---------------------------------------------------------------------\n");
    fprintf(f, "%-37s %-10d %-10d %-10d\n", "Cards Sold:", min40_057, min60_057, min100_057);
    fprintf(f, "%-37s %-10d %-10d %-10d\n", "Cards Remains:", count40_057, count60_057, count100_057);
    fprintf(f, "%-37s %-10d %-10d %-10d\n", "Total Amounts Sold in Tk (Card-Wise):", min40_057 * 40, min60_057 * 60, min100_057 * 100);
    fprintf(f, "Total Amount: %d\n", min40_057 * 40 + min60_057 * 60 + min100_057 * 100);
    fclose(f);

    f = fopen(PASSWORD_FILE, "w");
    if (!f)
    {
        printf("Error opening password.txt for writing!\n");
        return;
    }
    fprintf(f, "User Name Password\n");
    fprintf(f, "---------------------\n");
    for (int i = 0; i < total_pass057; i++)

    {
        fprintf(f, "%s %s\n", passMange[i].username057, passMange[i].password057);
    }

    fclose(f);
}

void load_data057()
{
    FILE *f;
    char b1[100], b2[100], b3[100], buffer[100];
    int val;

    total_locked057 = 0;
    if (locked_users057)
    {
        free(locked_users057);
        locked_users057 = NULL;
    }
    f = fopen(CARDS_FILE, "r");
    if (!f)
    {
        printf("Error opening cards.txt for reading!\n");
        if (total_cards057 == 0)
        {
            add_card057(400, 40);
            add_card057(300, 60);
            add_card057(300, 100);
        }
        return;
    }
    else if (f)
    {

        fgets(buffer, sizeof(buffer), f);
        fgets(buffer, sizeof(buffer), f);

        while (fscanf(f, "%s %d", b1, &val) == 2)
        {
            cards057 = safe_realloc057(cards057, (total_cards057 + 1) * sizeof(Card057));
            strcpy(cards057[total_cards057].card_no057, b1);
            cards057[total_cards057].min057 = val;
            total_cards057++;
        }
        fclose(f);
    }

    f = fopen(USERS_FILE, "r");
    if (!f)
    {
        printf("Error opening users.txt for reading!\n");
        return;
    }
    else if (f)
    {
        fgets(buffer, sizeof(buffer), f);
        fgets(buffer, sizeof(buffer), f);
        while (fscanf(f, "%s %d", b1, &val) == 2)
        {
            users057 = safe_realloc057(users057, (total_users057 + 1) * sizeof(User057));
            strcpy(users057[total_users057].mobile_number057, b1);
            users057[total_users057].min057 = val;
            total_users057++;
        }
        fclose(f);
    }

    f = fopen(LOCKED_FILE, "r");
    if (!f)
    {
        printf("Error opening locked.txt for reading!\n");
        return;
    }
    else if (f)
    {
        fgets(buffer, sizeof(buffer), f);
        fgets(buffer, sizeof(buffer), f);

        while (fgets(buffer, sizeof(buffer), f))
        {

            buffer[strcspn(buffer, "\r\n")] = 0;
            locked_users057 = safe_realloc057(locked_users057, (total_locked057 + 1) * sizeof(LockedUser057));
            strcpy(locked_users057[total_locked057++].mobile_number057, buffer);
        }

        fclose(f);
    }

    f = fopen(HISTORY_FILE, "r");
    if (!f)
    {
        printf("Error opening history.txt for writing!\n");
        return;
    }
    else if (f)
    {
        fgets(buffer, sizeof(buffer), f);
        fgets(buffer, sizeof(buffer), f);
        while (fscanf(f, "%s %s %s %d", b1, b2, b3, &val) == 4)
        {
            deleted057 = safe_realloc057(deleted057, (total_delete057 + 1) * sizeof(history057));
            strcpy(deleted057[total_delete057].timestamp057, b1);
            strcpy(deleted057[total_delete057].mobile_number057, b2);
            strcpy(deleted057[total_delete057].card_no057, b3);
            deleted057[total_delete057].min057 = val;
            total_delete057++;
        }
        fclose(f);
    }
    f = fopen(PASSWORD_FILE, "r");
    if (!f)
    {
        printf("Error opening password.txt for reading!\n");
        return;
    }
    else if (f)
    {
        fgets(buffer, sizeof(buffer), f);
        fgets(buffer, sizeof(buffer), f);
        while (fscanf(f, "%s %s\n", b1, b2) == 2)
        {

            passMange = safe_realloc057(passMange, (total_pass057 + 1) * sizeof(PasswordManager057));
            strcpy(passMange[total_pass057].username057, b1);
            strcpy(passMange[total_pass057].password057, b2);
            total_pass057++;
        }
        fclose(f);
    }
}

int main()
{
    srand(time(NULL));
    load_data057();

    show_banner057();
    menu057();
    return 0;
}
