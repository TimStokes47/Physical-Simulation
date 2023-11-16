#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class Window {
	friend class Input;
public:
	Window(int width, int height, const std::string& title);
	void swapBuffers();

	bool isClosed();

private:
	void* _handle;
};

#endif