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
	RecieveEvent("onload");
	RecieveEvent("on_load");
	RecieveEvent("load");
	
}

// Called every frame
void AAnimationController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AAnimationController::RecieveEvent(FString _event) {

	for (auto& actor : AnimationActors) {
		actor->processEvent(_event);
	}
	//AActor* ad;
	//if (ad->GetComponentByClass(<UAnimAdd*>)){
//		ad->ProcessEvent(_event);
//	}
	

	for (auto& actor : AnimationComponents) {
		auto comps = actor->GetComponents();
		for (auto& comp : comps) {
			auto isClass = dynamic_cast<UAnimAdd*>(comp);

			if (isClass) {
				isClass->processEvent(_event);
			}

		}

		
		//actor->GetComponentByClass(<UAnimAdd*>)->processEvent(_event);
	}


}