// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Engine/TriggerBox.h"

//#include "AnimationActor.h"
#include "AnimationController.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "ActionOnTrigger.h"

/**
 * 
 */

class UCameraComponent;
class ANoteCam;

class PLAYABLEDEMO_API Global
{
public:
	Global();
	~Global();

	

	enum InputEvent {
		LClick,
		LClick_Pressed,
		LClick_Released,
		RClick,
		RClick_Pressed,
		RClick_Released,
		N0,
		N1,
		N2,
		N3,
		N4,
		N5,
		N6,
		N7,
		N8,
		N9,
		Esc,
		None
	};

//	Input event
	static void HandleInput(InputEvent);

	

	static void SetDefaultCamera(AActor*);
	static void SetDefaultPlayerController(APlayerController*);
	static AActor* GetDefaultCamera();

	static void SwitchToCamera(ANoteCam * cam, float);
	static void SwitchToCamera(AActor * cam);
	static void SwitchToCameraCut(AActor * cam);

	static float TimeToActorCam;// = 0.0f;

	static void ExitGame();
	static void AddPuzzleTB(AActionOnTrigger*);

protected:
	static AActor* DefaultCamera;
	static APlayerController* OurPlayer;
	static void HandleNumInput(Global::InputEvent);
	//static FCriticalSection mutex;
	static TArray<AActionOnTrigger*> AllPuzzleTriggerboxes;
};


