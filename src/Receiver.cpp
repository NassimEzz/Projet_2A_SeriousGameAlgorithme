#include "Receiver.h"
#include "Utils.h"

Receiver::Receiver(const Point &position, const PictureInformer &emptyReceiverInformer,
                   const std::string &wrongAnswerPicture, const std::string &lockedReceiverPicture) {
    _emptyReceiverPicture = emptyReceiverInformer.picturePath;
    _wrongAnswerPicture = wrongAnswerPicture;
    _lockedReceiverPicture = lockedReceiverPicture;
    _rect = {position.x, position.y, emptyReceiverInformer.getPictureWidth(), emptyReceiverInformer.getPictureHeight()};
    _uniqIDDrag = 0;
}

void Receiver::drawMe(Window *window, bool isRCorrect) const {
    if (!isRCorrect) {
        window->drawPng(_rect.x, _rect.y, _wrongAnswerPicture);
    } else if (_uniqIDDrag != 0) {
        window->drawPng(_rect.x, _rect.y, _lockedReceiverPicture);
    } else {
        window->drawPng(_rect.x, _rect.y, _emptyReceiverPicture);
    }
}

bool Receiver::isAvailable(long dragUniqueId, int x, int y) {
    return ((isEmpty()) || (dragUniqueId == _uniqIDDrag)) && (_rect.isInRectangle(x, y));
}

void Receiver::setReceiverContent(DraggableRectangle *instruction, unsigned int x, unsigned int y) {
    if (_rect.isInRectangle((int) x, (int) y)) {
        instruction->setMeInReceiver(_rect.x, _rect.y);
        _uniqIDDrag = instruction->getUniqueID();
        _logicIDDrag = instruction->getLogicID();
    }
}

bool Receiver::isOutOfReceiver(long dragUniqueId, unsigned int x, unsigned int y) {
    return (!(_rect.isInRectangle((int) x, (int) y)) && (dragUniqueId == _uniqIDDrag));

}

int Receiver::getCurrentDragLogicID() const {
    return _logicIDDrag;
}

bool Receiver::isEmpty() const {
    return _uniqIDDrag == 0;
}

void Receiver::resetDrag() {
    _logicIDDrag = 0;
    _uniqIDDrag = 0;
}
