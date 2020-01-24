// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Engine/TriggerBox.h"

//#include "AnimationActor.h"
#include "AnimationController.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"

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
		None
	};

//	Input event
	static void HandleInput(InputEvent);

	

	static void SetDefaultCamera(UCameraComponent*);
	static void SetDefaultPlayerController(APlayerController*);
	static UCameraComponent* GetDefaultCamera();

	static void SwitchToCamera(ANoteCam * cam);
	static void SwitchToCamera(AActor * cam);


protected:
	static UCameraComponent* DefaultCamera;
	static APlayerController* OurPlayer;
};


