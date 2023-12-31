#include "Generator.h"

Generator::Generator()
{
    vector<string> genders = {"Male", "Female"};
    genderRand = Chooser(genders);
}

void Generator::generator()
{
    cout << "                                 _             " << endl;
    cout << "  __ _  ___ _ __   ___ _ __ __ _| |_ ___  _ __ " << endl;
    cout << " / _` |/ _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|" << endl;
    cout << "| (_| |  __/ | | |  __/ | | (_| | || (_) | |   " << endl;
    cout << " \\__, |\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   " << endl;
    cout << " |___/                                         " << endl;
    cout << "----------------------------------------------------" << endl;
}

void Generator::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Generator::details()
{
    cout << "     _      _        _ _     " << endl;
    cout << "  __| | ___| |_ __ _(_) |___ " << endl;
    cout << " / _` |/ _ \\ __/ _` | | / __|" << endl;
    cout << "| (_| |  __/ || (_| | | \\__ \\" << endl;
    cout << " \\__,_|\\___|\\__\\__,_|_|_|___/" << endl;
    cout << "------------------------------" << endl;
}

int Generator::seedInput()
{
    generator();
    cout << "Seed: [1] YES | [2] NO" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "Seed: ";
        int seed;
        cin >> seed;
        return seed;
    }
    return -1;
}

string Generator::genderInput()
{
    generator();
    cout << "Gender: [1] MALE | [2] FEMALE | [3] RANDOM" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        return "Male";
        break;
    case 2:
        return "Female";
        break;
    }
    return genderRand.choose();
}

void Generator::ui()
{
    clearScreen();
    seed = seedInput();
    if (seed != -1)
    {
        init(seed);
    }
    clearScreen();
    string gender = genderInput();
    clearScreen();
    map<string, string> person = generate(gender);
    details();
    cout << to_string(person);
}

map<string, string> Generator::generate(string gender)
{
    map<string, string> person;
    person["gender"] = gender;
    person["firstName"] = n.first(gender);
    person["middleName"] = n.middle();
    person["lastName"] = n.last();

    map<string, string> dob = d.ddate();
    person["dob"] = dob["Date"];
    person["month"] = dob["Month"];
    person["day"] = dob["Day"];
    person["year"] = dob["Year"];

    map<string, string> location = l.location();
    person["city"] = location["City"];
    person["state"] = location["State"];
    person["stateShort"] = location["State Short"];

    person["email"] = e.email(person["firstName"], person["middleName"], person["lastName"]);

    person["password"] = p.generate(27);

    return person;
}

string Generator::to_string(map<string, string> person)
{
    string p;
    p += "Gender: " + person["gender"] + "\n";
    p += "First Name: " + person["firstName"] + "\n";
    p += "Middle Name: " + person["middleName"] + "\n";
    p += "Last Name: " + person["lastName"] + "\n";
    p += "DOB: " + person["dob"] + "\n";
    p += "   Month: " + person["month"] + "\n";
    p += "   Day: " + person["day"] + "\n";
    p += "   Year: " + person["year"] + "\n";
    p += "City: " + person["city"] + "\n";
    p += "State: " + person["state"] + " (" + person["stateShort"] + ")" + "\n";
    p += "Email: " + person["email"] + "\n";
    p += "Password: " + person["password"] + "\n";
    return p;
}

void Generator::init(int seed)
{
    n = Name(seed);
    d = Date(1965, 2002, seed);
    l = Location(seed);
    e = Email(seed);
    p = Password(seed);
}