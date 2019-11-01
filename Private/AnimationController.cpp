// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationController.h"
#include "AnimAdd.h"
#include "LightChanger.h"

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

	if (_event == EventToUnlockLock1) {
		lock1 = true;
	}if (_event == EventToUnlockLock2) {
		lock2 = true;
	}
	if (_event == EventToUnlockLock3) {
		lock3 = true;
	}



	for (auto& actor : AnimationActors) {
		if (actor) {
			actor->processEvent(_event);
		}
	}
	//AActor* ad;
	//if (ad->GetComponentByClass(<UAnimAdd*>)){
//		ad->ProcessEvent(_event);
//	}
	

	for (auto& actor : AnimationComponents) {
		if (actor) {
			auto comps = actor->GetComponents();
			for (auto& comp : comps) {
				auto isClass = dynamic_cast<UAnimAdd*>(comp);

				if (isClass) {
					isClass->processEvent(_event);
				}

			}

		}
		//actor->GetComponentByClass(<UAnimAdd*>)->processEvent(_event);
	}

	for (auto& actor : LightActorComponents) {
		if (actor) {
			auto comps = actor->GetComponents();
			for (auto& comp : comps) {
				auto isClass = dynamic_cast<ULightChanger*>(comp);

				if (isClass) {
					isClass->ProcessEvent(_event);
				}

			}

		}
		//actor->GetComponentByClass(<UAnimAdd*>)->processEvent(_event);
	}


}

void AAnimationController::RecieveLightChangeComponent(AActor* lc) {
	if (lc) {
	//	if (lc->GetOwner()) {
			LightActorComponents.Push(lc);
	//	}
	//	else {//TODO log error
			//UELOG()
	//	}
	}
}

void  AAnimationController::RecieveAnimAddComponentOnLoad(AActor* obj) {
	//first check if you don't already have it!
	if (!obj) { return; } //TODO log error
	for (auto& exi : AnimationComponents) {
		if (exi == obj) { return; }
	}

	AnimationComponents.Push(obj);
}