// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionOnTrigger.h"

// Fill out your copyright notice in the Description page of Project Settings.

///#include "AnimationController.h"

#include "Components/BoxComponent.h"

AActionOnTrigger::AActionOnTrigger() {

	//Register Events
	this->OnActorBeginOverlap.AddDynamic(this, &AActionOnTrigger::OnOverlapBegin);
	this->OnActorEndOverlap.AddDynamic(this, &AActionOnTrigger::OnOverlapEnd);


	///this->OnActorBeginOverlap.AddDynamic(this, &AActionOnTrigger::BeginOverlap);
	//Register Events
	//OnActorBeginOverlap.AddDynamic(this, &AActionOnTrigger::OnOverlapBegin);
	//OnActorEndOverlap.AddDynamic(this, &AActionOnTrigger::OnOverlapEnd);
}

void AActionOnTrigger::BeginPlay() {

	Super::BeginPlay();

	if (SeeBoundBox) {
		DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
	}
}

void AActionOnTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	//if the overlapping actor is the specific actor we identified in the editor
	//if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor)
	//{
	if (OtherActor == ActorToTriggerOn) {
		if (ActorToTriggerOn != nullptr){
			if (ActorToChange != nullptr) {
				if (ignoreFirstTime) {
					ignoreFirstTime = false;
					return;
				}
				if (HideOnTrigger) {
					ActorToChange->SetActorHiddenInGame(false);
				}
				if (ShowOnTrigger) {
					ActorToChange->SetActorHiddenInGame(true);
				}

			}

			if (AnimateActors) {
				if (SendEventOnTrigger) {
					if (AnimationControllerToSendEvents) {
						AnimationControllerToSendEvents->RecieveEvent(EventName);
					}
				}



			}

		}
	}


	///print("Overlap Begin");
	///printFString("Overlapping Actor = %s", *OtherActor->GetName());
//}
}

void AActionOnTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor == ActorToTriggerOn) {
		if (ActorToTriggerOn != nullptr && ActorToChange != nullptr) {

			if (HideOnLeave) {
				ActorToChange->SetActorHiddenInGame(false);
			}
			if (ShowOnLeave) {
				ActorToChange->SetActorHiddenInGame(true);
			}


			if (AnimateActors) {
				if (SendEventOnLeave) {
					if (AnimationControllerToSendEvents) {
						AnimationControllerToSendEvents->RecieveEvent(EventName);
					}
				}
			}




		}
	}
}

