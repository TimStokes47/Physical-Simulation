#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

class EventListener {
public:
	virtual void onMouseButtonPress(int buttonCode) = 0;
};

#endif