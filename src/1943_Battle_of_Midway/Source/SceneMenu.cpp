#include "SceneMenu.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "ModuleFadeToBlack.h"

SceneMenu::SceneMenu(bool startEnabled) : Module(startEnabled)
{

}

SceneMenu::~SceneMenu()
{

}

// Load assets
bool SceneMenu::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Sprites/water.png"); // Background texture (water)
	titleTexture = App->textures->Load("Assets/Sprites/1943Logo.png");
	fontTexturePath = "Assets/Fonts/rtype_font3.png";

	const char* lookUpTable = "! �,_./0123456789�;->?abcdefghijklmnopqrstuvwxyz";

	font = App->fonts->Load(fontTexturePath, lookUpTable, 2);

	// AUDIO MUTED App->audio->PlayMusic("Assets/Music/Title.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneMenu::Update()
{
	// Input
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel_1, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneMenu ::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	App->render->Blit(titleTexture, 128, 80, NULL);

	App->fonts->BlitText(10, 10, font, "hello world!"); // Font test

	return Update_Status::UPDATE_CONTINUE;
}