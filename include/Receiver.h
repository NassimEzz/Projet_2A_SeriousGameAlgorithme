#ifndef P2A_SERIOUS_GAME_RECEIVER_H
#define P2A_SERIOUS_GAME_RECEIVER_H


#include "Window.h"
#include "DraggableRectangle.h"

class Receiver {
public :

    Receiver(const Point &position, const PictureInformer &emptyReceiverInformer,
             const std::string &wrongAnswerPicture, const std::string &lockedReceiverPicture);

    void drawMe(Window *window, bool isRCorrect) const;

    void setReceiverContent(DraggableRectangle *instruction, unsigned int x, unsigned int y);

    bool isOutOfReceiver(long dragUniqueId, unsigned int x, unsigned int y);

    bool isAvailable(long dragUniqueId, int x, int y);

    int getCurrentDragLogicID() const;

    void resetDrag();

private :
    bool isEmpty() const;

    Rectangle _rect{};
    long _uniqIDDrag = 0;
    int _logicIDDrag = 0;
    std::string _emptyReceiverPicture;
    std::string _wrongAnswerPicture;
    std::string _lockedReceiverPicture;
};

#endif
