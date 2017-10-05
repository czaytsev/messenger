#include "messengerwindowview.h"

MessengerWindowView::MessengerWindowView(Client * client):
    client_(client) // Initializer list is invoked before the body of constructor; value of client copied into client_
{

    // Create new messenger widget
    messenger_ = new QWidget(this);
    setCentralWidget(messenger_);

    // Set layout for widget
    layout_ = new QVBoxLayout(messenger_);
    messenger_->setLayout(layout_);

    // Add a text box to the widget
    editor_ = new QTextEdit();
    layout_->addWidget(editor_);

    // Add a submit button to the widget
    submit_ = new QPushButton("Submit Message");
    layout_->addWidget(submit_);
    connect(submit_, SIGNAL(released()), this, SLOT(grabTextAndSend()));
}

MessengerWindowView::~MessengerWindowView() {
    delete submit_;
    delete editor_;
    delete layout_;
    delete messenger_;
}

/**
 * Slot function that is called when submit button is released
 */
void MessengerWindowView::grabTextAndSend() {
    // Extract text from text box
    QString str = editor_->toPlainText();
    std::string message = str.toStdString();
    client_->send(message);
}
