#include "src/router.cpp"

bool verificationValue;
int optionMenu;

Router *router = new Router();

void menu();
void authenticationSystem(const char *title);
void createNewHosting(const char *title);
void getAllListHosting(const char *title);
void registerClient(const char *title);
void hostingClient(const char *title);
void paymethod(const char *titile);
void findRegistedClient(const char *title);

int main()
{
    system("TITLE Hotel Manage System - Credits: Valdemir Valenca Jr - Engineer and Developer: github.com/valdemirjr7");

    system("CLS");
    system("COLOR 02");

    authenticationSystem("\n\t\t\tAuthentication systems");

    return 1;
};

void menu()
{
    tryMenuAgain:

    cout << "\n\n\t\t\t/===================================\\" << endl;
    cout << "\t\t\t|Welcome to hotel manage system     |" << endl;
    cout << "\t\t\t||ESC| for exit                     |" << endl;
    cout << "\t\t\t|===================================|" << endl;
    cout << "\t\t\t||C| Create new Hotel               |" << endl;
    cout << "\t\t\t||L| List all Hotel                 |" << endl;
    cout << "\t\t\t||R| Register new client            |" << endl;
    cout << "\t\t\t||K| Find for registed clients      |" << endl;
    cout << "\t\t\t||H| Register client in new hotel   |" << endl;
    cout << "\t\t\t||P| Finish hotel and pay           |" << endl;
    cout << "\t\t\t\\===================================/" << endl;
    optionMenu = getche();

    switch (optionMenu)
    {
    case 99:
        system("CLS");
        createNewHosting("\n\t\t\tCreate New Hotel");
        break;
    case 108:
        system("CLS");
        getAllListHosting("\n\t\t\tList all hotel");
        break;
    case 114:
        system("CLS");
        registerClient("\n\t\t\tRegister new client");
        break;
    case 104:
        system("CLS");
        hostingClient("\n\t\t\tRegiste client in new host");
        break;
    case 107:
        system("CLS");
        findRegistedClient("\n\t\tFind a registed client");
        break;
    case 112:
        system("CLS");
        paymethod("\n\t\t\tCheckout to payment of hosting");
        break;
    case 27:
        system("CLS");
        exit(1);
    default:
        system("CLS");
        goto tryMenuAgain;
        break;
    }
};

void authenticationSystem(const char *title)
{
    cout << title << endl;

    string username, pswd;
    
    cout << "\n\t\t\t/==================\\" << endl;
    cout << "\t\t\t|Username:";
    cin >> username;
    cout << "\t\t\t|Password:";
    cin >> pswd;
    cout << "\t\t\t\\==================/" << endl;

    verificationValue = router->authenticationMethod(username, pswd);

    if(verificationValue)
    {
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave a error for authentication...\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }
};

void createNewHosting(const char *title)
{
    cout << title << endl;

    int hostNumber = 0, hostFloor = 0;

    cout << "\n\t\t\tEnter the number of host: ";
    cin >> hostNumber;
    cout << "\n\t\t\tEnter the floor of host: ";
    cin >> hostFloor;

    numberInformation.push_back(hostNumber);
    numberInformation.push_back(hostFloor);

    verificationValue = router->createHost(numberInformation);
    
    stringInformation.clear();
    numberInformation.clear();

    if(verificationValue)
    {
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave a error for create new Host...\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }
};

void getAllListHosting(const char *title)
{
    cout << title << endl;

    verificationValue = router->checkHost();

    if(verificationValue)
    {
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave a error for list all Host...\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }
};

void registerClient(const char *title)
{
    cout << title << endl;

    string name;
    string nickname;
    string contact;
    string email;


    cout << "\n\t\t\tEnter the client first name: ";
    cin >> name;
    cout << "\n\t\t\tEnter the client nickname: ";
    cin >> nickname;
    cout << "\n\t\t\tEnter the client contact: ";
    cin >> contact;
    cout << "\n\t\t\tEnter the client email: ";
    cin >> email;

    stringInformation.push_back(name);
    stringInformation.push_back(nickname);
    stringInformation.push_back(contact);
    stringInformation.push_back(email);
    
    verificationValue = router->registerClient(stringInformation);
    
    stringInformation.clear();

    if(verificationValue)
    {
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tthere was some error to register a new client\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }
}

void hostingClient(const char *title)
{
    cout << title << endl;

    int hotelNumber=0;
    string clientName;
    string dataHosting;

    cout << "\n\t\t\tEnter the client nickname: ";
    cin >> clientName;
    cout << "\n\t\t\tEnter the hotel number: ";
    cin >> hotelNumber;
    cout << "\n\t\t\tEnter the data of today [00/00/0000]: ";
    cin >> dataHosting;

    verificationValue = router->hostingClient(hotelNumber, clientName, dataHosting);

    if(verificationValue)
    { 
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave a error for Hosting a Client...\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }
}

void paymethod(const char *titile)
{
    cout << titile << endl;

    int hostNumber = 0;
    string clientNickname;
    double priceValue = 0.0;
    int paymentMethod;

    cout << "\n\t\t\tEnter the number of host: ";
    cin >> hostNumber;
    cout << "\t\t\tEnter the clientnickname: ";
    cin >> clientNickname;

    verificationValue = router->hostingClientCheckPay(hostNumber, clientNickname);

    if(verificationValue)
    {
        againPayment:
        cout << "\n\t\t\tEnter the price value with decimals values: $";
        cin >> priceValue;
        cout << "\n\t\t\tEnter with payment method: [1] Credit Card, [2] Bank transfer " << endl;
        cin >> paymentMethod;

        switch (paymentMethod)
        {
        case 1:
            verificationValue = router->PaymentClient(priceValue, "Credit Card", clientNickname);
            break;
        case 2:
            verificationValue = router->PaymentClient(priceValue, "Bank Transfer", clientNickname);
            break;
        default:
            system("PAUSE");
            system("CLS");
            system("COLOR 02");
            goto againPayment;
            break;
        }

        if(verificationValue)
        {
            verificationValue = router->removeHostingHotel(hostNumber);

            if(verificationValue)
            {
                system("PAUSE");
                system("CLS");
                system("COLOR 02");
                menu();
            }else
            {
                system("COLOR 06");
                cout << "\n\t\t\tHave a error for Payment a Client Process...\n\t\t\t" << endl;
                system("PAUSE");
                system("CLS");
                system("COLOR 02");
                menu();
            }
        }else
        {
            system("COLOR 06");
            cout << "\n\t\t\tHave a error for Payment a Client Process...\n\t\t\t" << endl;
            system("PAUSE");
            system("CLS");
            system("COLOR 02");
            menu();
        }
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave a error for Payment a Client...\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu(); 
    }
    
}

void findRegistedClient(const char *title)
{
    cout << title << endl;

    string clientnickname;

    cout << "\n\t\tEnter with client nickname\t\t" << endl;
    cin >> clientnickname;

    verificationValue = router->findRegistedClient(clientnickname);

    if(verificationValue)
    {
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu();
    }else
    {
        system("COLOR 06");
        cout << "\n\t\t\tHave a error for find a Client...\n\t\t\t" << endl;
        system("PAUSE");
        system("CLS");
        system("COLOR 02");
        menu(); 
    }
}