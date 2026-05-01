#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class Book
{
private:
    string Title;
    string Author;

public:
    void Set_Title()
    {
        string title;
        do
        {
            cout << "Enter the book title:";
            getline(cin >> ws, title);
        } while (title.empty());
        Title = title;
    }
    string Get_Title()
    {
        return Title;
    }
    void Set_Author()
    {
        string author;
        do
        {
            cout << "Enter the book Author:";
            getline(cin >> ws, author);
        } while (author.empty());
        Author = author;
    }
    string Get_Author()
    {
        return Author;
    }
    Book() {}
    Book(string t, string a)
    {
        Title = t;
        Author = a;
    }
};
class Management
{
private:
    vector<Book> book;
    Book b;

public:
    void Add()
    {
        b.Set_Title();
        b.Set_Author();
        book.push_back(b);
    }
    void Search()
    {
        cout << "1)Search by book name" << setw(25) << "2)Search by author" << endl;
        cout << "Enter your choice:";
        int ch;
        vector<int> hold;
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
        {
            string bn;
            cout << "Enter the book name:";
            getline(cin >> ws, bn);
            for (int i = 0; i < static_cast<int>(book.size()); i++)
            {
                if (bn == book[i].Get_Title())
                {
                    hold.push_back(i);
                }
                else
                {
                    continue;
                }
            }
            if (hold.empty())
            {
                cout << "Book doesn't exist" << endl;
            }
            else
            {
                cout << setw(20) << "i" << setw(20) << "Book Author " << endl;
                for (int i = 0; i < static_cast<int>(hold.size()); i++)
                {
                    cout << setw(18) << hold[i] + 1 << setw(20) << book[hold[i]].Get_Author() << endl;
                }
            }
            break;
        }
        case 2:
        {
            string an;
            cout << "Enter the author name:";
            getline(cin >> ws, an);
            for (int i = 0; i < static_cast<int>(book.size()); i++)
            {
                if (an == book[i].Get_Author())
                {
                    hold.push_back(i);
                }
                else
                {
                    continue;
                }
            }
            if (hold.empty())
            {
                cout << "author doesn't exist";
            }
            else
            {
                cout << setw(20) << "i" << setw(20) << "Book name" << endl;
                for (int i = 0; i < static_cast<int>(hold.size()); i++)
                {
                    cout << setw(18) << hold[i] + 1 << setw(20) << book[hold[i]].Get_Title() << endl;
                }
            }
            break;
        }
        }
    }
    void Remove()
    {
        Search();
        if (book.empty())
        {
            cout << "no books to remove " << endl;
            return;
        }
        int index;
        cout << "Enter the book index from list:";
        cin >> index;
        if (index < 1 || index > static_cast<int>(book.size()))
        {
            cout << "Invalid input ! " << endl;
            return;
        }
        book.erase(book.begin() + (index - 1));
        cout << "Book removed successfully " << endl;
    }
    void Show()
    {
        cout << setw(20) << "Book title " << setw(20) << "Book Author " << endl;
        for (int i = 0; i < static_cast<int>(book.size()); i++)
        {
            cout << i + 1 << ")" << setw(15) << book[i].Get_Title() << setw(20) << book[i].Get_Author() << endl;
        }
    }
    void Save()
    {
        string name;
        cout << "Enter the file name : ";
        getline(cin >> ws, name);
        ofstream file(name);
        if (!file)
        {
            cout << "Please try again" << endl;
            return;
        }
        file << "Book title " << "Book Author " << endl;
        for (auto &b : book)
        {
            file << b.Get_Title() << "," << b.Get_Author() << endl;
        }
        file.close();
        cout << "File saved successfully" << endl;
    }
    void Load()
    {
        cout << "Enter the file name to load:";
        string name;
        getline(cin >> ws, name);
        ifstream file(name);
        if (!file)
        {
            cout << "Cannot open this file" << endl;
            return;
        }
        book.clear();
        string line;
        getline(file, line);
        while (getline(file, line))
        {
            size_t commapos = line.find(',');
            string t, a;
            if (commapos != string ::npos)
            {
                t = line.substr(0, commapos);
                a = line.substr(commapos + 1);
                t.erase(0, t.find_first_not_of(" \t\r\n"));
                t.erase(t.find_last_not_of(" \t\r\n") + 1);
                a.erase(0, a.find_first_not_of("\t\r\n"));
                a.erase(a.find_last_not_of("\t\r\n") + 1);
                Book b(t, a);
                book.push_back(b);
            }
        }
        cout << "File loaded successfully" << endl;
        file.close();
    }
};
bool End()
{
    string input;
    cout << "Do you want to continue?" << endl;
    getline(cin >> ws, input);
    if (input == "yes" || input == "Yes")
    {
        return true;
    }
    return false;
}
int main()
{
    Management m;
    enum Menu
    {
        Add = 1,
        Search = 2,
        Remove = 3,
        Show = 4,
        Save = 5,
        Load = 6,
        Exit = 7
    };
    int o;
    while (true)
    {
        system("cls");
        cout << "1)Add" << endl
             << "2)Search" << endl
             << "3)Remove" << endl
             << "4)Show" << endl
             << "5)Save" << endl
             << "6)Load" << endl
             << "7)Exit" << endl;
        cout << string(40, '=');
        cout << endl
             << "Enter your option number:";
        cin >> o;
        switch (o)
        {
        case Add:
            system("cls");
            m.Add();
            break;
        case Search:
            system("cls");
            m.Search();
            break;
        case Remove:
            system("cls");
            m.Remove();
            break;
        case Show:
            system("cls");
            m.Show();
            break;
        case Save:
            system("cls");
            m.Save();
            break;
        case Load:
            system("cls");
            m.Load();
            break;
        case Exit:
            cout << "Exiting....." << endl;
            return 0;
        default:
            cout << "Invalid input" << endl;
        }
        if (End() == false)
        {
            cout << "Exiting....." << endl;
            return 0;
        }
    }
    getch();
    return 0;
}