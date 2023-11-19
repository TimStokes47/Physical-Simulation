#include "graphics/renderer.h"
#include "graphics/window.h"
#include "core/input.h"
#include "graphics/camera.h"
#include "physics/particle.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_stdlib.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

int main()
{
	Window window(960, 540, "Physical Simulation");
	Input::initialise(window);
	Renderer::initialise();

	int fps = 240;
	float totalTime = 0.0f;
	auto timeBetweenFrames = std::chrono::microseconds(std::chrono::seconds(1)) / fps;
	auto targetTimepoint = std::chrono::steady_clock::now();
	float dt = (float)timeBetweenFrames.count() / std::chrono::microseconds(std::chrono::seconds(1)).count();

	bool isRunning = false;

	std::vector<Particle> particles;

	while (!window.isClosed()) {
		targetTimepoint += timeBetweenFrames;
		std::this_thread::sleep_until(targetTimepoint);

		window.swapBuffers();
		Input::pollEvents();

		Renderer::getInstance()->getCamera().update(dt);

		if (isRunning) {
			for (Particle& p : particles) {
				p.applyForce({ 0.0f, -9.81f, 0.0f });
				p.update(dt);
			}
		}

		Renderer::getInstance()->clearScreen();

		for (Particle& p : particles) {
			Renderer::getInstance()->renderParticle(p);
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Simulation Manager");
		if (isRunning) {
			if (ImGui::Button("Pause Simulation")) {
				isRunning = false;
			}
		}
		else {
			if (ImGui::Button("Play Simulation")) {
				isRunning = true;
			}
		}
		if (ImGui::Button("Create Particle")) {
			particles.push_back(Particle());
		}

		for (Particle& p : particles) {
			ImGui::DragFloat3((std::string("Position ") + std::to_string(p.id)).c_str(), &p.position.x);
			ImGui::DragFloat3((std::string("Velocity ") + std::to_string(p.id)).c_str(), &p.velocity.x);
			ImGui::Separator();
		}
		
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	return 0;
}
