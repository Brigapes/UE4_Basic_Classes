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
			}
			StopAnim1();

		}
		else { //NOT FINISH

			if (MoveLocation1) {
				FVector newloc = FVector(newt.GetLocation());
				newloc.X = newloc.X + MovePerStep1.X;
				newloc.Y = newloc.Y + MovePerStep1.Y;
				newloc.Z = newloc.Z + MovePerStep1.Z;
				//SetActorLocation(newloc);
				newt.SetLocation(newloc);
			}

			if (Rotate1) {
				FRotator newrot = FRotator(newt.GetRotation());
				newrot.Pitch = newrot.Pitch + RotatePerStep1.Pitch;
				newrot.Yaw = newrot.Yaw + RotatePerStep1.Yaw;
				newrot.Roll = newrot.Roll + RotatePerStep1.Roll;
				newt.SetRotation(newrot.Quaternion());
			}

			if (Scale1) {
				FVector news = FVector(newt.GetScale3D());
				news.X = news.X + ScalePerStep1.X;
				news.Y = news.Y + ScalePerStep1.Y;
				news.Z = news.Z + ScalePerStep1.Z;
				//SetActorLocation(newloc);
				newt.SetScale3D(news);
			}

			//if all is valid apply transform

			SetActorTransform(newt);

			//if not force finish
			if (totalSteps1 >= AnimationTime1) {
				if (EventToTriggerOnFinish1 != "") {
					SendEventToController(EventToTriggerOnFinish1);
				}
				StopAnim1();
			}

		}
	}
	//end anim1

		//staret anim2
	if (pl_2) {
		totalSteps2++;
		//finish force
		if (totalSteps2 >= AnimationTime2 && ForceFinishPosition) {
			//force all
			if (MoveLocation2) {
				this->SetActorLocation(ToTransform2.GetLocation());
			}
			if (Rotate2) {
				this->SetActorRotation(ToTransform2.GetRotation());
			}
			if (Scale2) {
				this->SetActorScale3D(ToTransform2.GetScale3D());
			}
			if (EventToTriggerOnFinish2 != "") {
				SendEventToController(EventToTriggerOnFinish2);
			}
			StopAnim2();

		}
		else { //NOT FINISH

			if (MoveLocation2) {
				FVector newloc = FVector(newt.GetLocation());
				newloc.X = newloc.X + MovePerStep2.X;
				newloc.Y = newloc.Y + MovePerStep2.Y;
				newloc.Z = newloc.Z + MovePerStep2.Z;
				//SetActorLocation(newloc);
				newt.SetLocation(newloc);
			}

			if (Rotate2) {
				FRotator newrot = FRotator(newt.GetRotation());
				newrot.Pitch = newrot.Pitch + RotatePerStep2.Pitch;
				newrot.Yaw = newrot.Yaw + RotatePerStep2.Yaw;
				newrot.Roll = newrot.Roll + RotatePerStep2.Roll;
				newt.SetRotation(newrot.Quaternion());
			}

			if (Scale2) {
				FVector news = FVector(newt.GetScale3D());
				news.X = news.X + ScalePerStep2.X;
				news.Y = news.Y + ScalePerStep2.Y;
				news.Z = news.Z + ScalePerStep2.Z;
				//SetActorLocation(newloc);
				newt.SetScale3D(news);
			}

			//if all is valid apply transform

			SetActorTransform(newt);

			//if not force finish
			if (totalSteps2 >= AnimationTime2) {
				if (EventToTriggerOnFinish2 != "") {
					SendEventToController(EventToTriggerOnFinish2);	
				}
				StopAnim2();
			}

		}
	}
	//end anim2

		//staret anim3
	if (pl_3) {
		totalSteps3++;
		//finish force
		if (totalSteps3 >= AnimationTime3 && ForceFinishPosition) {
			//force all
			if (MoveLocation3) {
				this->SetActorLocation(ToTransform3.GetLocation());
			}
			if (Rotate3) {
				this->SetActorRotation(ToTransform3.GetRotation());
			}
			if (Scale3) {
				this->SetActorScale3D(ToTransform3.GetScale3D());
			}
			if (EventToTriggerOnFinish3 != "") {
				SendEventToController(EventToTriggerOnFinish3);
			}
			StopAnim3();

		}
		else { //NOT FINISH

			if (MoveLocation3) {
				FVector newloc = FVector(newt.GetLocation());
				newloc.X = newloc.X + MovePerStep3.X;
				newloc.Y = newloc.Y + MovePerStep3.Y;
				newloc.Z = newloc.Z + MovePerStep3.Z;
				//SetActorLocation(newloc);
				newt.SetLocation(newloc);
			}

			if (Rotate3) {
				FRotator newrot = FRotator(newt.GetRotation());
				newrot.Pitch = newrot.Pitch + RotatePerStep3.Pitch;
				newrot.Yaw = newrot.Yaw + RotatePerStep3.Yaw;
				newrot.Roll = newrot.Roll + RotatePerStep3.Roll;
				newt.SetRotation(newrot.Quaternion());
			}

			if (Scale3) {
				FVector news = FVector(newt.GetScale3D());
				news.X = news.X + ScalePerStep3.X;
				news.Y = news.Y + ScalePerStep3.Y;
				news.Z = news.Z + ScalePerStep3.Z;
				//SetActorLocation(newloc);
				newt.SetScale3D(news);
			}

			//if all is valid apply transform

			SetActorTransform(newt);

			//if not force finish
			if (totalSteps3 >= AnimationTime3) {
				if (EventToTriggerOnFinish3 != "") {
					SendEventToController(EventToTriggerOnFinish3);	
				}
				StopAnim3();
			}

		}
	}
	//end anim3




	//all done







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
	if (pl_1) { return; }
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
	if (pl_2) { return; }
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
	if (pl_3) { return; }
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

