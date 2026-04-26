#include <iostream>
#include <string>
using namespace std;

class MovieTicket
{
private:
    int bookings[10001][1001];
    int available_tickets[1001];

public:
    MovieTicket()
    {
        for (int i = 0; i < 10001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                bookings[i][j] = 0;
            }
        }

        for (int i = 0; i < 1001; i++)
        {
            available_tickets[i] = 0;
        }
    }

    bool book(int customer_id, int movie_id)
    {
        if (bookings[customer_id][movie_id] == 1)
        {
            return false;
        }

        if (available_tickets[movie_id] >= 100)
        {
            return false;
        }

        bookings[customer_id][movie_id] = 1;
        available_tickets[movie_id]++;
        return true;
    }

    bool cancel(int customer_id, int movie_id)
    {
        if (bookings[customer_id][movie_id] == 0)
        {
            return false;
        }

        bookings[customer_id][movie_id] = 0;
        available_tickets[movie_id]--;
        return true;
    }

    bool is_booked(int customer_id, int movie_id)
    {
        return bookings[customer_id][movie_id] == 1;
    }

    int available_tickets_count(int movie_id)
    {
        return 100 - available_tickets[movie_id];
    }
};

int main()
{
    int q;
    cin >> q;

    MovieTicket system;

    while (q--)
    {
        string operation;
        cin >> operation;

        if (operation == "BOOK")
        {
            int x, y;
            cin >> x >> y;
            if (system.book(x, y))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (operation == "CANCEL")
        {
            int x, y;
            cin >> x >> y;
            if (system.cancel(x, y))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (operation == "IS_BOOKED")
        {
            int x, y;
            cin >> x >> y;
            if (system.is_booked(x, y))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (operation == "AVAILABLE_TICKETS")
        {
            int y;
            cin >> y;
            cout << system.available_tickets_count(y) << endl;
        }
    }

    return 0;
}
