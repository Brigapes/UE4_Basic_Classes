// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameFramework/Actor.h"
#include "NoteCam.generated.h"

/**
 * 
 */

class AAnimationController;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLAYABLEDEMO_API ANoteCam : public ACameraActor
{
	GENERATED_BODY()
	

public:
	// Sets default values for this component's properties
	ANoteCam();
	~ANoteCam();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "Camera Switching")
		AAnimationController* DaddyController;
	UPROPERTY(EditAnywhere, Category = "Camera Switching")
		TArray<FString> SwitchHereOnEvents = {};
	UPROPERTY(EditAnywhere, Category = "Camera Switching")
		TArray<FString> SwitchToPlayerOnEvents = {};
	UPROPERTY(EditAnywhere, Category = "Camera Switching")
		AActor* TestActorOverride = nullptr;
	UPROPERTY(EditAnywhere, Category = "Camera Switching")
		float TimeToBlend = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Switching")
		float TimeToBlendBackToPlayer = 0.0f;



	UPROPERTY(EditAnywhere, Category = "Locks")
		bool IgnoreAllLocks = true;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool IgnoreLocksForLoad = true;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool ShouldLock1BeTrue = false;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool ShouldLock2BeTrue = false;
	UPROPERTY(EditAnywhere, Category = "Locks")
		bool ShouldLock3BeTrue = false;

	void RecieveEvent(FString);
	void ProcessEvent(FString);

};
