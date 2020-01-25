// Fill out your copyright notice in the Description page of Project Settings.


#include "Global.h"
#include "NoteCam.h"


Global::Global()
{
	C_ASSERT("DON'T PLACE THIS IN THE GAME! WHAT'S WRONG WITH YOU???!!!");
}

Global::~Global()
{
}

AActor* Global::DefaultCamera = nullptr;
APlayerController* Global::OurPlayer = nullptr;
float Global::TimeToActorCam = 0.0f;

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
	case Global::None:
		break;//no?
	default:
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