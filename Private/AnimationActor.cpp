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
	FTransform newt = this->GetTransform();

	//staret anim1
	if (pl_1) {
		totalSteps1++;
		//finish force
		if (totalSteps1 >= AnimationTime1 && ForceFinishPosition) {
			//force all
			if(MoveLocation1){
				this->SetActorLocation(ToTransform1.GetLocation());
			}
			if (Rotate1) {
				this->SetActorRotation(ToTransform1.GetRotation());
			}
			if (Scale1) {
				this->SetActorScale3D(ToTransform1.GetScale3D());
			}
			if (EventToTriggerOnFinish1 != "") {
				SendEventToController(EventToTriggerOnFinish1);
				StopAnim1();
			}

		}
		else { //NOT FINISH

			if (MoveLocation1) {
				FVector newloc = FVector(newt.GetLocation());
				newloc.X = newloc.X .X;
			}





			//if not force finish
			if (totalSteps1 >= AnimationTime1) {
				if (EventToTriggerOnFinish1 != "") {
					SendEventToController(EventToTriggerOnFinish1);
					StopAnim1();
				}
			}

		}
	}
	//end anim1
















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


///simple made
void AAnimationActor::StopAllAnims() { 
	StopAnim1();
	StopAnim2();
	StopAnim3();
}


void AAnimationActor::StartAnim1() { 
	FTransform crr = this->GetTransform();
	double atime = AnimationTime1;
	if (atime == 0) { atime = 1; }
	if (MoveLocation1) {
		double diff = 0.0f;
		diff = ToTransform1.GetLocation().X - crr.GetLocation().X;
		//if (diff < 0) { diff = diff * (-1); }
		MovePerStep1.X = diff / atime;
		diff = ToTransform1.GetLocation().Y - crr.GetLocation().Y;
		//if (diff < 0) { diff = diff * (-1); }
		MovePerStep1.Y = diff / atime;
		diff = ToTransform1.GetLocation().Z - crr.GetLocation().Z;
		//if (diff < 0) { diff = diff * (-1); }
		MovePerStep1.Z = diff / atime;
	}
	if (Rotate1) {
		double diff = 0.0f;
		diff = ToTransform1.GetRotation().Rotator().Roll - crr.GetRotation().Rotator().Roll;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Roll = diff / atime;
		diff = ToTransform1.GetRotation().Rotator().Yaw - crr.GetRotation().Rotator().Yaw;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Yaw = diff / atime;
		diff = ToTransform1.GetRotation().Rotator().Pitch - crr.GetRotation().Rotator().Pitch;
		//if (diff < 0) { diff = diff * (-1); }
		RotatePerStep1.Pitch = diff / atime;
	}
	if (Scale1) {
		double diff = 0.0f;
		diff = ToTransform1.GetScale3D().X - crr.GetScale3D().X;
		//if (diff < 0) { diff = diff * (-1); }
		ScalePerStep1.X = diff / atime;
		diff = ToTransform1.GetScale3D().Y - crr.GetScale3D().Y;
		//if (diff < 0) { diff = diff * (-1); }
		ScalePerStep1.Y = diff / atime;
		diff = ToTransform1.GetScale3D().Z - crr.GetScale3D().Z;
		//if (diff < 0) { diff = diff * (-1); }
		ScalePerStep1.Z = diff / atime;
	}
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_1 = true;
	totalSteps1 = 0;
}
void AAnimationActor::StartAnim2() {
	FTransform crr = this->GetTransform();
	double atime = AnimationTime2;
	if (atime == 0) { atime = 1; }
	if (MoveLocation2) {
		double diff = 0.0f;
		diff = ToTransform2.GetLocation().X - crr.GetLocation().X;
		//if (diff < 0) { diff = diff * (-2); }
		MovePerStep2.X = diff / atime;
		diff = ToTransform2.GetLocation().Y - crr.GetLocation().Y;
		//if (diff < 0) { diff = diff * (-2); }
		MovePerStep2.Y = diff / atime;
		diff = ToTransform2.GetLocation().Z - crr.GetLocation().Z;
		//if (diff < 0) { diff = diff * (-2); }
		MovePerStep2.Z = diff / atime;
	}
	if (Rotate2) {
		double diff = 0.0f;
		diff = ToTransform2.GetRotation().Rotator().Roll - crr.GetRotation().Rotator().Roll;
		//if (diff < 0) { diff = diff * (-2); }
		RotatePerStep2.Roll = diff / atime;
		diff = ToTransform2.GetRotation().Rotator().Yaw - crr.GetRotation().Rotator().Yaw;
		//if (diff < 0) { diff = diff * (-2); }
		RotatePerStep2.Yaw = diff / atime;
		diff = ToTransform2.GetRotation().Rotator().Pitch - crr.GetRotation().Rotator().Pitch;
		//if (diff < 0) { diff = diff * (-2); }
		RotatePerStep2.Pitch = diff / atime;
	}
	if (Scale2) {
		double diff = 0.0f;
		diff = ToTransform2.GetScale3D().X - crr.GetScale3D().X;
		//if (diff < 0) { diff = diff * (-2); }
		ScalePerStep2.X = diff / atime;
		diff = ToTransform2.GetScale3D().Y - crr.GetScale3D().Y;
		//if (diff < 0) { diff = diff * (-2); }
		ScalePerStep2.Y = diff / atime;
		diff = ToTransform2.GetScale3D().Z - crr.GetScale3D().Z;
		//if (diff < 0) { diff = diff * (-2); }
		ScalePerStep2.Z = diff / atime;
	}
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_2 = true;
	totalSteps2 = 0;
}
void AAnimationActor::StartAnim3() {
	FTransform crr = this->GetTransform();
	double atime = AnimationTime3;
	if (atime == 0) { atime = 1; }
	if (MoveLocation3) {
		double diff = 0.0f;
		diff = ToTransform3.GetLocation().X - crr.GetLocation().X;
		//if (diff < 0) { diff = diff * (-3); }
		MovePerStep3.X = diff / atime;
		diff = ToTransform3.GetLocation().Y - crr.GetLocation().Y;
		//if (diff < 0) { diff = diff * (-3); }
		MovePerStep3.Y = diff / atime;
		diff = ToTransform3.GetLocation().Z - crr.GetLocation().Z;
		//if (diff < 0) { diff = diff * (-3); }
		MovePerStep3.Z = diff / atime;
	}
	if (Rotate3) {
		double diff = 0.0f;
		diff = ToTransform3.GetRotation().Rotator().Roll - crr.GetRotation().Rotator().Roll;
		//if (diff < 0) { diff = diff * (-3); }
		RotatePerStep3.Roll = diff / atime;
		diff = ToTransform3.GetRotation().Rotator().Yaw - crr.GetRotation().Rotator().Yaw;
		//if (diff < 0) { diff = diff * (-3); }
		RotatePerStep3.Yaw = diff / atime;
		diff = ToTransform3.GetRotation().Rotator().Pitch - crr.GetRotation().Rotator().Pitch;
		//if (diff < 0) { diff = diff * (-3); }
		RotatePerStep3.Pitch = diff / atime;
	}
	if (Scale3) {
		double diff = 0.0f;
		diff = ToTransform3.GetScale3D().X - crr.GetScale3D().X;
		//if (diff < 0) { diff = diff * (-3); }
		ScalePerStep3.X = diff / atime;
		diff = ToTransform3.GetScale3D().Y - crr.GetScale3D().Y;
		//if (diff < 0) { diff = diff * (-3); }
		ScalePerStep3.Y = diff / atime;
		diff = ToTransform3.GetScale3D().Z - crr.GetScale3D().Z;
		//if (diff < 0) { diff = diff * (-3); }
		ScalePerStep3.Z = diff / atime;
	}
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_3 = true;
	totalSteps3 = 0;
}

void AAnimationActor::StopAnim1() {
	pl_1 = false; 
	totalSteps1 = -1;
	if (EventToTriggerOnStop1 != "") {
		processEvent(EventToTriggerOnStop1);
	}
}
void AAnimationActor::StopAnim2(){
	pl_2 = false;
	totalSteps2 = -1;
	if (EventToTriggerOnStop2 != "") {
		processEvent(EventToTriggerOnStop2);
	}
}
void AAnimationActor::StopAnim3(){
	pl_3 = false;
	totalSteps3 = -1;
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

