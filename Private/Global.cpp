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

UCameraComponent* Global::DefaultCamera = nullptr;
APlayerController* Global::OurPlayer = nullptr;

void Global::HandleInput(InputEvent inp) {

	//here add if input can even go trough



	switch (inp) //switch input events
	{
	case Global::LClick:
		break;
	case Global::LClick_Pressed:
		break;
	case Global::LClick_Released:
		break;
	case Global::RClick:
		break;
	case Global::RClick_Pressed:
		break;
	case Global::RClick_Released:
		break;
	case Global::None:
		break;
	default:
		break;
	}

}

void Global::SetDefaultCamera(UCameraComponent * cam)
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

UCameraComponent * Global::GetDefaultCamera()
{
	if (DefaultCamera) {
		return DefaultCamera;
	}


	return nullptr;
}


void Global::SwitchToCamera(ANoteCam* cam) {
	if (cam == nullptr) {
		//means default camera

	}
	else {
		
		if (OurPlayer){
			//if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne))
			//{
				//Blend smoothly to camera two.

		/*	UCameraComponent* ptr = nullptr;

			auto comps = cam->GetComponents();
			for (auto& comp : comps) {
				auto isClass = dynamic_cast<UCameraComponent*>(comp);
				if (isClass) {
					ptr = isClass;
				}
			}
			if (ptr) {
				OurPlayer->SetViewTargetWithBlend(dynamic_cast<AActor*>(ptr), 0.75f);
			}*/

			OurPlayer->SetViewTargetWithBlend((cam), 0.75f);

			


		}
	}
}

void Global::SwitchToCamera(AActor* actor) {
	if (actor == nullptr) {
		//means default camera

	}
	else {

		if (OurPlayer) {
			OurPlayer->SetViewTargetWithBlend((actor), 0.75f);
		}
	}
}