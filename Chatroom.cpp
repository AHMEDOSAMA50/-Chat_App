#include "Chatroom.h"
#include "user.h"
#include "Message.h"
#include <list>
using namespace std;
void Chatroom::list_users()
{
    if (opt == "two")
    {
        list<user>myusers[2];
            user use;
            myusers[x].push_front(use1);
        }
    }
    else if (opt == "more")
    {
        int x;
        cout << "please enter the number of users ";
        cin >> x;
        list<user>used[256];
        for (int i = 0; i < x; i++)
        {
            user use;
            used[i].push_front(use);
        }
    }
    else
    {
        cout << "please enter a valid option";
    }


}
void Chatroom::list_message()
{
    

}
void Chatroom::chatroom_typ()
{
    int choice;
    cout << "please choose the chatroomtype ";
    cout << "1- one to one";
    cout << "2-chat group";
    cin >> choice;
    if (choice == 1)
    {

    }
    else if (choice == 2)
    {

    }
    else
    {
        cout << "No Correct Option";
    }
}