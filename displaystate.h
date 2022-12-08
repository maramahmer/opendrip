#ifndef WEATHERDATA_DISPLAYSTATE_H
#define WEATHERDATA_DISPLAYSTATE_H

class UserInterfacing;
class DisplayState {
protected:
    UserInterfacing* _userInterfacing;

public:
    DisplayState();
    virtual ~DisplayState() = 0;
    virtual void display() = 0;
    void setUserInterfacing(UserInterfacing *userInterfacing);
};

#endif //WEATHERDATA_DISPLAYSTATE_H
