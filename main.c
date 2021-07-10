//                                      LINKED LISTS PROJECT
// Team members:-
//Name1 : Thabet hussien thabet          sec:1                BN: 49

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listnode{
    char Student_Name[30];
    int Student_ID;
    int Score_Of_Last_Year;
    int Day_Of_Birth;
    int Year_Of_Birth;
    int Month_Of_Birth;
    struct listnode* next;
}ListNode;

typedef struct dynamicarray
{
    char Student_Name[30];
    int Student_ID;
    int Score_Of_Last_Year;
    int Day_Of_Birth;
    int Year_Of_Birth;
    int Month_Of_Birth;
}DynamicArray;

typedef struct list
{
    ListNode* head;
    ListNode* tail;
    size_t size;
}List;
void initializeList(List *);
void designList(int, List *);
void printList(List *);
ListNode* enterInformationOfStudent();// enter information of a student in linked list part
void enterInformationOfStudent2(DynamicArray*);//enter information of a student in dynamic array part
void insertInTheBeginning(List *);//linked list
void insertInTheEnd(List *);//linked list
void insert_In_Nth_Position_In_The_Middle(List *);//linked list
void print_dynamic_array_elements(DynamicArray*);
void Insert_in_the_beginning_of_dynamic_array(DynamicArray*);
void Insert_in_the_middle_of_dynamic_array(DynamicArray*);
void Insert_in_the_end_of_dynamic_array(DynamicArray*);

int n;

int main()
{

    puts("Welcome to our program!");
    printf("\n");
    printf("%s", "press 1, to develop functions using dynamic memory allocation\npress 2, to develop functions using linked lists\n");
    int choice1;
    scanf("%i", &choice1);

        switch(choice1)
        {
        case 1:
            {
                puts ("Let's design your dynamic array!");
                printf("How many elements does the array initially consist of ? : ");
                scanf("%i", &n);
                bool validitySize = false;
                while (validitySize == false)
                {
                    if(n >= 1)
                    {
                        validitySize = true;
                    }
                    else
                    {
                        puts("you should enter a number which is greater than or equal to 1 !");
                        printf("Enter the new number : ");
                        scanf("%i", &n);
                    }
                }
                DynamicArray *arrayPtr = (DynamicArray* )malloc(n * sizeof(DynamicArray));
                for (int i = 0; i < n; ++i)
                {
                    printf("Now, we will enter the information of student %i\n", i + 1);
                    enterInformationOfStudent2((arrayPtr + i));
                }

            int choice4;
            bool endProgram = false;
            while (endProgram == false)
            {
                puts("To insert an element in the beginning of dynamic array, press 1!");
                puts("To insert an element in the middle of dynamic array, press 2!");
                puts("To insert an element in the end of dynamic array, press 3!");
                puts("To print the content of the dynamic array, press 4!");
                scanf("%i", &choice4);
                switch(choice4)
                {
                case 1:
                    Insert_in_the_beginning_of_dynamic_array(arrayPtr);
                    break;
                case 2:
                    Insert_in_the_middle_of_dynamic_array(arrayPtr);
                    break;
                case 3:
                    Insert_in_the_end_of_dynamic_array(arrayPtr);
                    break;
                case 4:
                    print_dynamic_array_elements(arrayPtr);
                    break;
                default:
                    puts("Invalid choice!");
                    puts("Choice should be between 1 and 4!");
                    break;
                }
                puts("If you want to end program, press -1.otherwise, The program continues!");
                int choice3;
                scanf("%i", &choice3);

                if(choice3 == -1)
                    endProgram = true;
            }
            break;
            }

        case 2:
            {
                List list1;
                initializeList(&list1);
                puts("Let's design your list!");
                printf("How many elements does the list initially consist of ? : ");
                int N;
                scanf("%i", &N);
                bool validitySize = false;
                while (validitySize == false)
                {
                    if(N >= 1)
                    {
                        designList(N, &list1);
                        validitySize = true;
                    }
                    else
                    {
                       puts("you should enter a number which is greater than or equal to 1 !");
                       scanf("%i", &N);
                    }
                }
            int choice2;
            bool endProgram = false;
            while (endProgram == false)
            {
                printf("To insert in the beginning, press 1!\nTo insert in a certain position, press 2!\n");
                printf("To insert in the end, press 3!\nTo print your list, press 4!\n");
                scanf("%i", &choice2);
                switch(choice2)
                {
                case 1:
                    insertInTheBeginning(&list1);
                    break;
                case 2:
                    insert_In_Nth_Position_In_The_Middle(&list1);
                    break;
                case 3:
                    insertInTheEnd(&list1);
                    break;
                case 4:
                    printList(&list1);
                    break;
                default:
                    puts("Invalid choice!");
                    puts("Your choice must be greater than or equal to 1 and less than or equal to 7!");
                    break;
                }
                puts("If you want to end program, press -1.otherwise, The program continues!");
                int choice3;
                scanf("%i", &choice3);
                if(choice3 == -1)
                    endProgram = true;
            }
            break;
            }
                default:
                    puts("Wrong choice!");
                    puts("You should enter either 1 or 2!");
                    break;

        }



    return 0;
}




























































































































ListNode* enterInformationOfStudent()
{

    fflush(stdin);
    ListNode* pointerToListNode = (ListNode*) malloc(sizeof(ListNode));
    printf("Enter the name of your student : ");
    fgets(pointerToListNode->Student_Name, 30, stdin);

    printf("Enter the ID of of your student : ");
    scanf("%i", &(pointerToListNode->Student_ID));

    bool validity_ID = false;
    while (!validity_ID)
    {
        if (pointerToListNode->Student_ID >= 0)
            validity_ID = true;
        else
            {
                puts("Wrong ID!");
                printf("Enter a new ID : ");
                scanf("%i", &(pointerToListNode->Student_ID));
            }
    }

    printf("Enter the score of last year of of your student : ");
    scanf("%i", &(pointerToListNode->Score_Of_Last_Year));
    bool validity_Score = false;
    while (!validity_Score)
    {
        if (pointerToListNode->Score_Of_Last_Year >= 0)
            validity_Score = true;
        else
            {
                puts("Wrong score!");
                printf("Enter a new score : ");
                scanf("%i", &(pointerToListNode->Score_Of_Last_Year));
            }
    }

    printf("Enter the date of birth of of your student!\n");
    printf("%s","Enter the day : ");
    scanf("%i", &(pointerToListNode->Day_Of_Birth));
    printf("%s", "Enter the month :");
    scanf("%i", &(pointerToListNode->Month_Of_Birth));
    printf("%s", "Enter the year : ");
    scanf("%i", &(pointerToListNode->Year_Of_Birth));
    bool validity_DateOfBirth = false;
    while (!validity_DateOfBirth)
    {
        if ((pointerToListNode->Day_Of_Birth > 0 && pointerToListNode->Day_Of_Birth <= 31) && ((pointerToListNode->Month_Of_Birth) > 0
            && (pointerToListNode->Month_Of_Birth) <=12) && ((pointerToListNode->Year_Of_Birth) >= 0))
                validity_DateOfBirth = true;
        else
            {
                puts("Wrong date of birth!");
                printf("%s","Enter the day : ");
                scanf("%i", &(pointerToListNode->Day_Of_Birth));
                printf("%s", "Enter the month :");
                scanf("%i", &(pointerToListNode->Month_Of_Birth));
                printf("%s", "Enter the year : ");
                scanf("%i", &(pointerToListNode->Year_Of_Birth));
            }
    }
    printf("\n\n");
    return pointerToListNode;
}






































