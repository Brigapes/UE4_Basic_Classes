// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationActor.h"
#include "AnimationController.h"


// Sets default values
AAnimationActor::AAnimationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimationActor::BeginPlay()
{
	Super::BeginPlay();







}

///done every frame
void AAnimationActor::ProcessAnims() {
	FTransform crr = this->GetTransform();
	if (pl_1) {
		if (MoveLocation1) {
			



		}





	}

















	return;
}



// Called every frame
void AAnimationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ProcessAnims();

}

void AAnimationActor::SendEventToController(FString eventname) {
	if (AnimationController) {
		AnimationController->RecieveEvent(eventname);
	}
}



void AAnimationActor::StopAllAnims() {
	if (pl_1) {
		if (EventToTriggerOnStop1 != "") {
			SendEventToController(EventToTriggerOnStop1);
		}
	}
	pl_1 = false;
	if (pl_2) {
		if (EventToTriggerOnStop2 != "") {
			SendEventToController(EventToTriggerOnStop2);
		}
	}
	pl_2 = false;
	if (pl_3) {
		if (EventToTriggerOnStop3 != "") {
			SendEventToController(EventToTriggerOnStop3);
		}
	}
	pl_3 = false;
}


void AAnimationActor::StartAnim1() { 
	FTransform crr = this->GetTransform();
	if (MoveLocation1) {
		double diff = 0.0f;
		diff = ToTransform1.GetLocation().X - crr.GetLocation().X;
		//if (diff < 0) { diff = diff * (-1); }
		MovePerStep1.X = diff;
		diff = ToTransform1.GetLocation().Y - crr.GetLocation().Y;
		//if (diff < 0) { diff = diff * (-1); }
		MovePerStep1.Y = diff;
		diff = ToTransform1.GetLocation().Z - crr.GetLocation().Z;
		//if (diff < 0) { diff = diff * (-1); }
		MovePerStep1.Z = diff;
	}
	if (Rotate1) {
		double diff = 0.0f;
		diff = ToTransform1.GetRotation().Rotator().Roll - crr.GetRotation().Rotator().Roll;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Roll = diff;
		diff = ToTransform1.GetRotation().Rotator().Yaw - crr.GetRotation().Rotator().Yaw;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Yaw = diff;
		diff = ToTransform1.GetRotation().Rotator().Pitch - crr.GetRotation().Rotator().Pitch;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Pitch = diff;
	}
	if (Scale1) {
		double diff = 0.0f;
		diff = ToTransform1.GetRotation().Rotator().Roll - crr.GetRotation().Rotator().Roll;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Roll = diff;
		diff = ToTransform1.GetRotation().Rotator().Yaw - crr.GetRotation().Rotator().Yaw;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Yaw = diff;
		diff = ToTransform1.GetRotation().Rotator().Pitch - crr.GetRotation().Rotator().Pitch;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Pitch = diff;
	}




	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_1 = true;
}
void AAnimationActor::StartAnim2() {
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_2 = true;
}
void AAnimationActor::StartAnim3() { 
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_3 = true; 
}

void AAnimationActor::StopAnim1() {
	pl_1 = false; 
	if (EventToTriggerOnStop1 != "") {
		processEvent(EventToTriggerOnStop1);
	}
}
void AAnimationActor::StopAnim2(){
	pl_2 = false;
	if (EventToTriggerOnStop2 != "") {
		processEvent(EventToTriggerOnStop2);
	}
}
void AAnimationActor::StopAnim3(){
	pl_3 = false;
	if (EventToTriggerOnStop3 != "") {
		processEvent(EventToTriggerOnStop3);
	}
}




void AAnimationActor::processEvent(FString eventname) {

	//anim1
	for (auto& ev : StopAllAnimationOnEvents) {
		if (eventname == ev) {
			StopAllAnims();
			break;
		}
	}

	for (auto& ev : AnimateOnEvent1) {
		if (eventname == ev) {
			StartAnim1();
			break;
		}
	}

	for (auto& ev : AnimateOnEvent2) {
		if (eventname == ev) {
			StartAnim2();
			break;
		}
	}

	for (auto& ev : AnimateOnEvent3) {
		if (eventname == ev) {
			StartAnim3();
			break;
		}
	}

	if (eventname == StopEvent1) {
		StopAnim1();
	}if (eventname == StopEvent2) {
		StopAnim2();
	}if (eventname == StopEvent3) {
		StopAnim3();
	}

}

