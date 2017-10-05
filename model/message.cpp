#include "message.h"

Message::Message() {

}


/***
 * Setters and getters
 */

void Message::setMessage(std::string msg)  {
    msg_ = msg;
}

void Message::setId(int id) {
    id_ = id;
}

std::string Message::getMessage() {
    return msg_;
}

int Message::getId() {
    return id_;
}
