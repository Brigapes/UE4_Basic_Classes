// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimationActor.h"
//#include "AnimAdd.h"
//#include "LightChanger.h"

#include "AnimationController.generated.h"

class ULightChanger;
class UAnimAdd;
class ANoteCam;
class UCameraComponent;


UCLASS()
class PLAYABLEDEMO_API AAnimationController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimationController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RecieveEvent(FString event);
	void RecieveEvent(FString _event, ULightChanger* ptr);
	void RecieveEvent(FString _event, UAnimAdd* ptr);

	UPROPERTY(EditAnywhere, Category = "Animation Actors")
		TArray<AActor*> AnimationComponents = {};
	UPROPERTY(EditAnywhere, Category = "Animation Actors")
		TArray<AActor*> LightActorComponents = {};
		//TArray<UAnimAdd*> AnimationComponents = {};
	UPROPERTY(EditAnywhere, Category = "Animation Actors")
		TArray<AAnimationActor*> AnimationActors = {};

	
	
	//UPROPERTY(EditAnywhere, Category = "Lock 1")
	//	bool ShouldLock1BeTrue = false;
	UPROPERTY(EditAnywhere, Category = "Lock 1")
		FString EventToUnlockLock1 = "";
	bool lock1 = false;

	UPROPERTY(EditAnywhere, Category = "Lock 2")
		FString EventToUnlockLock2 = "";
	bool lock2 = false;

	UPROPERTY(EditAnywhere, Category = "Lock 3")
		FString EventToUnlockLock3 = "";
	bool lock3 = false;

	UPROPERTY(EditAnywhere, Category = "Exit")
		bool ExitUsingEscape = true;
	UPROPERTY(EditAnywhere, Category = "Exit")
		FString ExitEventName = "";


	void RecieveLightChangeComponent(AActor*);

	void RecieveAnimAddComponentOnLoad(AActor*);
//	void RecieveAnimAddComponentOnLoad(UObject*);

	void RecieveNoteCam(ANoteCam*);
	TArray<ANoteCam*> AllNoteCams = {};
	UCameraComponent* DefCam = nullptr;
};
