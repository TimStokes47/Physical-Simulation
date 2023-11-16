#ifndef INPUT_H
#define INPUT_H

class Window;

class Input {
public:
	Input(const Window& window);
	void pollEvents();

private:
	void* _windowHandle;
};

#endif