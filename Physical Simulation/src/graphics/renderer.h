#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
	static void initialise();
	static Renderer* getInstance();
	void clearScreen();

	void renderTriangle();

private:
	static Renderer* _instance;
};

#endif