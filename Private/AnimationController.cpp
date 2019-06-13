// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationController.h"

// Sets default values
AAnimationController::AAnimationController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimationController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimationController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AAnimationController::RecieveEvent(FString event) {

	for (auto& actor : AnimationActors) {
		
	}


}