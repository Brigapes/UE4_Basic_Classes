// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimationActor.h"

#include "AnimationController.generated.h"


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

	UPROPERTY(EditAnywhere, Category = "Animation Actors")
		TArray<AAnimationActor*> AnimationActors = {};

};
