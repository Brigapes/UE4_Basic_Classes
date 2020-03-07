// Fill out your copyright notice in the Description page of Project Settings.


#include "Global.h"
#include "NoteCam.h"


Global::Global()
{
	Global::AllPuzzleTriggerboxes = {};
	C_ASSERT("DON'T PLACE THIS IN THE GAME! WHAT'S WRONG WITH YOU???!!!");
}

Global::~Global()
{
}

AActor* Global::DefaultCamera = nullptr;
APlayerController* Global::OurPlayer = nullptr;
float Global::TimeToActorCam = 0.0f;
TArray<AActionOnTrigger*> Global::AllPuzzleTriggerboxes = {};

void Global::HandleInput(InputEvent inp) {

	//here add if input can even go trough

	

	switch (inp) //switch input events
	{
		case Global::LClick:
			break;//no work
		case Global::LClick_Pressed:
			SwitchToCamera((ANoteCam*)nullptr);
			break;
		case Global::LClick_Released:
			break;
		case Global::RClick:
			break;//no work
		case Global::RClick_Pressed:
			break;
		case Global::RClick_Released:
			break;
		case Global::Esc:
			Global::ExitGame();
			break;
		case Global::None:
			break;//no?
		default:
			Global::HandleNumInput(inp);
			break;
	}

}

void Global::SetDefaultCamera(AActor * cam)
{
	if (cam) { DefaultCamera = cam; }
}

void Global::SetDefaultPlayerController(APlayerController * player)
{
	if (player) {
	//	if (!OurPlayer) {
			OurPlayer = player;
			UE_LOG(LogTemp, Warning, TEXT("WE GOT OUR PLAYER!"));
	//	}
	}
	else {
		//TODO LOG ERROR
	}
}

AActor * Global::GetDefaultCamera()
{
	if (DefaultCamera) {
		return DefaultCamera;
	}


	return nullptr;
}


void Global::SwitchToCamera(ANoteCam* cam, float time) {
	if (cam == nullptr) {
		//means default camera
		if (OurPlayer) {
			OurPlayer->SetViewTargetWithBlend((GetDefaultCamera()), TimeToActorCam);
		}
	}
	else {
		if (OurPlayer){
			OurPlayer->SetViewTargetWithBlend((cam), time);
		}
	}
}

void Global::SwitchToCamera(AActor* actor) {
	if (actor == nullptr) {
		//means default camera
		if (OurPlayer) {
			OurPlayer->SetViewTargetWithBlend((GetDefaultCamera()), TimeToActorCam);
		}
	}
	else {

		if (OurPlayer) {
			OurPlayer->SetViewTargetWithBlend((actor), 0.75f);
		}
	}
}

void Global::SwitchToCameraCut(AActor* actor) {
	if (actor == nullptr) {
		//means default camera
		if (OurPlayer) {
			OurPlayer->SetViewTargetWithBlend((OurPlayer), TimeToActorCam);
		}
	}
	else {

		if (OurPlayer) {
			OurPlayer->SetViewTarget((actor));
		}
	}
}

void Global::ExitGame()
{
	//GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
	exit(0);
}

void Global::HandleNumInput(Global::InputEvent inp) {
	for (auto& tb : AllPuzzleTriggerboxes) {
		if ((tb == tb) && (tb != nullptr)) {
			FString input = "0";
			if (inp == N1) { input = "1"; }
			if (inp == N2) { input = "2"; }
			if (inp == N3) { input = "3"; }
			if (inp == N4) { input = "4"; }
			if (inp == N5) { input = "5"; }
			if (inp == N6) { input = "6"; }
			if (inp == N7) { input = "7"; }
			if (inp == N8) { input = "8"; }
			if (inp == N9) { input = "9"; }
			tb->PuzzleInput(input);
		}
	}
}

void Global::AddPuzzleTB(AActionOnTrigger* tb) {
//	mutex.Lock();
	if (tb) {
		AllPuzzleTriggerboxes.Add(tb);
	}
//	mutex.Unlock();
}