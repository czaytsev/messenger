#include <QApplication>
#include "model/client.h"

#include "view/messengerwindowview.h"

int main(int argc, char **argv)
{

 QApplication app(argc, argv);

 // Create instance of client
 Client client;

 // Creates a MessengerWindowView object called view, and pass pointer to client
 MessengerWindowView view(&client);

 // Shows the messenger window
 view.show();

 return app.exec();
}


