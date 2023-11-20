#include <SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <iostream>
#include "GameEngine.h"
#include "example.h"

int game_is_running = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int last_frame_time = 0;

float example_speed;

int initialize_window(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Erro inicializando SDL." << std::endl;
		return FALSE;
	}

	window = SDL_CreateWindow(
		GAME_NAME,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT,
		SDL_WINDOW_FOREIGN
	);

	if (!window) {
		std::cout << "Erro criando a janela." << std::endl;
		return FALSE;
	}

	renderer = SDL_CreateRenderer(window,
		-1, //driver padrao
		0);

	if (!renderer) {
		std::cout << "Erro criando o render" << std::endl;
		return FALSE;
	}

	return TRUE;
}

/*
int initialize_imgui() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	
	if (!window || !renderer) {
		std::cout << "Erro ao inicializar ImGui!" << std::endl;
		return FALSE;
	}

	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init;

	std::cout << "ImGui inicializado: Versao: " << IMGUI_VERSION << std::endl;
}

void start_frame_imgui() {
	ImGui_ImplSDL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(window);
	ImGui::NewFrame();

	ImGui::Render();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
	//SDL_GL_SwapWindow(window);
}

void shutdown_imgui() {
	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void interface_logic_imgui() {
	ImGui::Begin("Game Engine");
	ImGui::SliderFloat("Speed", &example_speed, 0.0f, 10.0f);
	ImGui::End();
}
*/

void process_input() {
	SDL_Event e;
	SDL_PollEvent(&e);
//	ImGui_ImplSDL2_ProcessEvent(&e);
	switch (e.type) {
	case SDL_QUIT:
		game_is_running = FALSE;
		break;
	case SDL_KEYDOWN:
		if (e.key.keysym.sym == SDLK_ESCAPE)
			game_is_running = FALSE;
		break;
	}
}

void destroy_window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

float getDeltaTime() {
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
	float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
	last_frame_time = SDL_GetTicks();

	return delta_time;
}

int main(int argc, char* argv[]) {
	game_is_running = initialize_window();

	//initialize_imgui();
	setup();
	while (game_is_running) {
		process_input();
		//start_frame_imgui();
		//interface_logic_imgui();
		update(getDeltaTime());
		draw(renderer);
	}


	//shutdown_imgui();
	destroy_window();

	return 0;
}