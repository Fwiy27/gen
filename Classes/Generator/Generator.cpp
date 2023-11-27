#include "Generator.h"

Generator::Generator()
{
    vector<string> v{"Male", "Female"};
    ch = Chooser(v);
    choice = -1;
}

Generator::Generator(int seed)
{
}

void Generator::clear_screen()
{
    cout << "\033[2J\033[1;1H";
}

void Generator::print_logo()
{
    cout << "  _____                           _             " << endl;
    cout << " / ____|                         | |            " << endl;
    cout << "| |  __  ___ _ __   ___ _ __ __ _| |_ ___  _ __ " << endl;
    cout << "| | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|" << endl;
    cout << "| |__| |  __/ | | |  __/ | | (_| | || (_) | |   " << endl;
    cout << " \\_____|\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|" << endl;
    cout << "----------------------------------------------------" << endl;
}

map<string, string> Generator::generate(string gender)
{
    map<string, string> m;

    // Name
    m["Gender"] = gender;
    m["First Name"] = n.first(gender);
    m["Middle Name"] = n.middle();
    m["Last Name"] = n.last();

    // Birthdate
    map<string, string> ddate = d.ddate();
    m["Birth Date"] = ddate["Date"];
    m["Month"] = ddate["Month"];
    m["Day"] = ddate["Day"];
    m["Year"] = ddate["Year"];

    // City
    map<string, string> dcity = c.pair();
    m["City"] = dcity["City"];
    m["State"] = dcity["State Long"];
    m["State Short"] = dcity["State Short"];

    // Email and Password
    m["Email"] = e.email(m["First Name"], m["Middle Name"], m["Last Name"]);
    m["Password"] = p.generate(20);

    return m;
}

void Generator::printPerson(map<string, string> person)
{
    cout << "-----------------------" << endl;
    cout << "Gender: " << person["Gender"] << endl
         << endl;
    cout << "First Name: " << person["First Name"] << endl;
    cout << "Middle Name: " << person["Middle Name"] << endl;
    cout << "Last Name: " << person["Last Name"] << endl
         << endl;
    cout << "Birth Date: " << person["Birth Date"] << endl;
    cout << "   Month: " << person["Month"] << endl;
    cout << "   Day: " << person["Day"] << endl;
    cout << "   Year: " << person["Year"] << endl
         << endl;
    cout << "City: " << person["City"] << endl;
    cout << "State: " << person["State"] << endl;
    cout << "   State Short: " << person["State Short"] << endl
         << endl;
    cout << "Email: " << person["Email"] << endl;
    cout << "Password: " << person["Password"] << endl;
    cout << "-----------------------" << endl;
}

void Generator::ui()
{
    map<string, string> person;
    clear_screen();
    while (choice < 1 || choice > 3)
    {
        print_logo();
        cout << "Enter [1] for Male, [2] for Female, [3] for Random" << endl;
        cout << "Choice: ";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        person = generate("Male");
        break;
    case 2:
        person = generate("Female");
        break;
    case 3:
        person = generate(ch.cs());
        break;
    }
    clear_screen();
    printPerson(person);
}