#include <stdio.h>
#include <stdlib.h>

#define ROOM_RATE 100.00

struct Reservation {
    int booking_id;
    char customer_name[50];
    int room_count;
    int people_count;
    int stay_duration;
    double total_cost;
};

double calculate_cost(int rooms, int stay_duration) {
    return rooms * stay_duration * ROOM_RATE;
}

void book_room() {
    struct Reservation res;
    int stay_duration;
    char check_in_date[15], check_out_date[15], check_in_time[10];

    printf("Enter your name: ");
    scanf("%s", res.customer_name);
    printf("Enter check-in date (DD/MM/YYYY): ");
    scanf("%s", check_in_date);
    printf("Enter check-out date (DD/MM/YYYY): ");
    scanf("%s", check_out_date);
    printf("Enter check-in time (HH:MM): ");
    scanf("%s", check_in_time);
    printf("Enter number of people: ");
    scanf("%d", &res.people_count);
    printf("Enter number of rooms: ");
    scanf("%d", &res.room_count);
    printf("Enter stay duration (in days): ");
    scanf("%d", &stay_duration);
    res.stay_duration = stay_duration;

    res.total_cost = calculate_cost(res.room_count, stay_duration);
    res.booking_id = rand() % 10000 + 1;

    printf("\n********** Receipt **********\n");
    printf("Customer Name: %s\n", res.customer_name);
    printf("Check-in Date: %s\n", check_in_date);
    printf("Check-out Date: %s\n", check_out_date);
    printf("Number of People: %d\n", res.people_count);
    printf("Number of Rooms: %d\n", res.room_count);
    printf("Stay Duration: %d days\n", stay_duration);
    printf("Total Cost: $%.2f\n", res.total_cost);
    printf("Booking ID: %d\n", res.booking_id);
    printf("******************************\n");
}

int main() {
    int choice;

    while(1) {
        printf("\nHotel Reservation System\n");
        printf("1. Book Room\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                book_room();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
