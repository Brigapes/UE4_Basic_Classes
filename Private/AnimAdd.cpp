// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimAdd.h"
#include "AnimationController.h"

// Sets default values for this component's properties
UAnimAdd::UAnimAdd()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	// ...
}


// Called when the game starts
void UAnimAdd::BeginPlay()
{
	//Super::BeginPlay();

	PassAnimToActor = this->GetOwner();
	RegisterComponent();
	// ...
	
	if (AnimationController) {
		AnimationController->RecieveAnimAddComponentOnLoad(this->GetOwner());
	}

}


// Called every frame


void UAnimAdd::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	 //...
	ProcessAnims();
}



///done every frame
void UAnimAdd::ProcessAnims() {

	FTransform crr = this->PassAnimToActor->GetTransform();
	FTransform newt = this->PassAnimToActor->GetTransform();

	if (PassAnimToActor) {
		crr = PassAnimToActor->GetTransform();
		newt = PassAnimToActor->GetTransform();
	}
	else {
		crr = this->PassAnimToActor->GetTransform();
		newt = this->PassAnimToActor->GetTransform();
	}


	//staret anim1
	if (pl_1) {
		totalSteps1++;
		//finish force
		if (totalSteps1 >= AnimationTime1 && ForceFinishPosition) {
			//force all
			if (MoveLocation1) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorLocation(ToTransform1.GetLocation());
				}
				else {
					this->PassAnimToActor->SetActorLocation(ToTransform1.GetLocation());
				}
			}
			if (Rotate1) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorRotation(ToTransform1.GetRotation());
				}
				else this->PassAnimToActor->SetActorRotation(ToTransform1.GetRotation());
			}
			if (Scale1) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorScale3D(ToTransform1.GetScale3D());
				}
				else this->PassAnimToActor->SetActorScale3D(ToTransform1.GetScale3D());
			}
			if (EventToTriggerOnFinish1 != "") {
				SendEventToController(EventToTriggerOnFinish1);
			}
			StopAnim1(true, pl_1);

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
			if (PassAnimToActor) {
				PassAnimToActor->SetActorTransform(newt);
			}
			else this->PassAnimToActor->SetActorTransform(newt);

			//if not force finish
			if (totalSteps1 >= AnimationTime1) {
				if (EventToTriggerOnFinish1 != "") {
					SendEventToController(EventToTriggerOnFinish1);
				}
				StopAnim1(true, pl_1);
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
				if (PassAnimToActor) {
					PassAnimToActor->SetActorLocation(ToTransform2.GetLocation());
				}
				else this->PassAnimToActor->SetActorLocation(ToTransform2.GetLocation());
			}
			if (Rotate2) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorRotation(ToTransform2.GetRotation());
				}
				else this->PassAnimToActor->SetActorRotation(ToTransform2.GetRotation());
			}
			if (Scale2) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorScale3D(ToTransform2.GetScale3D());
				}
				else this->PassAnimToActor->SetActorScale3D(ToTransform2.GetScale3D());
			}
			if (EventToTriggerOnFinish2 != "") {
				SendEventToController(EventToTriggerOnFinish2);
			}
			StopAnim2(true, pl_2);

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
			if (PassAnimToActor) {
				PassAnimToActor->SetActorTransform(newt);
			}
			else this->PassAnimToActor->SetActorTransform(newt);

			//if not force finish
			if (totalSteps2 >= AnimationTime2) {
				if (EventToTriggerOnFinish2 != "") {
					SendEventToController(EventToTriggerOnFinish2);
				}
				StopAnim2(true, pl_2);
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
				if (PassAnimToActor) {
					PassAnimToActor->SetActorLocation(ToTransform3.GetLocation());
				}
				else this->PassAnimToActor->SetActorLocation(ToTransform3.GetLocation());
			}
			if (Rotate3) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorRotation(ToTransform3.GetRotation());
				}
				else this->PassAnimToActor->SetActorRotation(ToTransform3.GetRotation());
			}
			if (Scale3) {
				if (PassAnimToActor) {
					PassAnimToActor->SetActorScale3D(ToTransform3.GetScale3D());
				}
				else this->PassAnimToActor->SetActorScale3D(ToTransform3.GetScale3D());
			}
			if (EventToTriggerOnFinish3 != "") {
				SendEventToController(EventToTriggerOnFinish3);
			}
			StopAnim3(true, pl_3);

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
			if (PassAnimToActor) {
				PassAnimToActor->SetActorTransform(newt);
			}
			else this->PassAnimToActor->SetActorTransform(newt);

			//if not force finish
			if (totalSteps3 >= AnimationTime3) {
				if (EventToTriggerOnFinish3 != "") {
					SendEventToController(EventToTriggerOnFinish3);
				}
				StopAnim3(true, pl_3);
			}

		}
	}
	//end anim3




	//all done







	return;
}



// Called every frame
/*void UAnimAdd::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	ProcessAnims();

}*/

void UAnimAdd::SendEventToController(FString eventname) {
	if (AnimationController) {
		AnimationController->RecieveEvent(eventname);
	}
}


///simple made
void UAnimAdd::StopAllAnims() {
	auto buf1 = pl_1;
	auto buf2 = pl_2;
	auto buf3 = pl_3;


	pl_1 = false;
	totalSteps1 = -1;
	pl_2 = false;
	totalSteps2 = -1;
	pl_3 = false;
	totalSteps3 = -1;

	StopAnim1(false, buf1);
	StopAnim2(false, buf2);
	StopAnim3(false, buf3);

}


void UAnimAdd::StartAnim1() {
	if (pl_1) { return; }
	FTransform crr = this->PassAnimToActor->GetTransform();
	if (PassAnimToActor) {
		crr = PassAnimToActor->GetTransform();
	}
	double atime = AnimationTime1;
	if (atime == 0) { atime = 1; }

	/*if (UseRelative) {
		if (MoveLocation1) {
			double diff = 0.0f;


		}
	}
	else {*/
	if (MoveLocation1) {
		double diff = 0.0f;
		if (UseRelativeTransform1) {
			diff = (crr.GetLocation().X + ToTransform1.GetLocation().X) - crr.GetLocation().X;
			MovePerStep1.X = diff / atime;
			diff = (crr.GetLocation().Y + ToTransform1.GetLocation().Y) - crr.GetLocation().Y;
			MovePerStep1.Y = diff / atime;
			diff = (crr.GetLocation().Z + ToTransform1.GetLocation().Z) - crr.GetLocation().Z;
			MovePerStep1.Z = diff / atime;
		}
		else {
			diff = ToTransform1.GetLocation().X - crr.GetLocation().X;
			MovePerStep1.X = diff / atime;
			diff = ToTransform1.GetLocation().Y - crr.GetLocation().Y;
			MovePerStep1.Y = diff / atime;
			diff = ToTransform1.GetLocation().Z - crr.GetLocation().Z;
			MovePerStep1.Z = diff / atime;
		}
	}
	if (Rotate1) {
		double diff = 0.0f;
		if (UseRelativeTransform1) {
			diff = (crr.GetRotation().Rotator().Roll + ToTransform1.GetRotation().Rotator().Roll)
				- crr.GetRotation().Rotator().Roll;
			RotatePerStep1.Roll = diff / atime;
			diff = (crr.GetRotation().Rotator().Yaw + ToTransform1.GetRotation().Rotator().Yaw)
				- crr.GetRotation().Rotator().Yaw;
			RotatePerStep1.Yaw = diff / atime;
			diff = (crr.GetRotation().Rotator().Pitch + ToTransform1.GetRotation().Rotator().Pitch)
				- crr.GetRotation().Rotator().Pitch;
			RotatePerStep1.Pitch = diff / atime;
		}
		else {
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
	}
	if (Scale1) {
		double diff = 0.0f;
		if (UseRelativeTransform1) {
			diff = (crr.GetScale3D().X + ToTransform1.GetScale3D().X) - crr.GetScale3D().X;
			ScalePerStep1.X = diff / atime;
			diff = (crr.GetScale3D().Y + ToTransform1.GetScale3D().Y) - crr.GetScale3D().Y;
			ScalePerStep1.Y = diff / atime;
			diff = (crr.GetScale3D().Z + ToTransform1.GetScale3D().Z) - crr.GetScale3D().Z;
			ScalePerStep1.Z = diff / atime;
		}
		else {
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
	}
	//}

	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_1 = true;
	totalSteps1 = 0;
}
void UAnimAdd::StartAnim2() {
	if (pl_2) { return; }
	FTransform crr = this->PassAnimToActor->GetTransform();
	if (PassAnimToActor) {
		crr = PassAnimToActor->GetTransform();
	}
	double atime = AnimationTime2;
	if (atime == 0) { atime = 1; }
	if (MoveLocation2) {
		double diff = 0.0f;
		if (UseRelativeTransform2) {
			diff = (crr.GetLocation().X + ToTransform2.GetLocation().X) - crr.GetLocation().X;
			MovePerStep2.X = diff / atime;
			diff = (crr.GetLocation().Y + ToTransform2.GetLocation().Y) - crr.GetLocation().Y;
			MovePerStep2.Y = diff / atime;
			diff = (crr.GetLocation().Z + ToTransform2.GetLocation().Z) - crr.GetLocation().Z;
			MovePerStep2.Z = diff / atime;
		}
		else {
			diff = ToTransform2.GetLocation().X - crr.GetLocation().X;
			MovePerStep2.X = diff / atime;
			diff = ToTransform2.GetLocation().Y - crr.GetLocation().Y;
			MovePerStep2.Y = diff / atime;
			diff = ToTransform2.GetLocation().Z - crr.GetLocation().Z;
			MovePerStep2.Z = diff / atime;
		}
	}
	if (Rotate2) {
		double diff = 0.0f;
		if (UseRelativeTransform2) {
			diff = (crr.GetRotation().Rotator().Roll + ToTransform2.GetRotation().Rotator().Roll)
				- crr.GetRotation().Rotator().Roll;
			RotatePerStep2.Roll = diff / atime;
			diff = (crr.GetRotation().Rotator().Yaw + ToTransform2.GetRotation().Rotator().Yaw)
				- crr.GetRotation().Rotator().Yaw;
			RotatePerStep2.Yaw = diff / atime;
			diff = (crr.GetRotation().Rotator().Pitch + ToTransform2.GetRotation().Rotator().Pitch)
				- crr.GetRotation().Rotator().Pitch;
			RotatePerStep2.Pitch = diff / atime;
		}
		else {
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
	}
	if (Scale2) {
		double diff = 0.0f;
		if (UseRelativeTransform2) {
			diff = (crr.GetScale3D().X + ToTransform2.GetScale3D().X) - crr.GetScale3D().X;
			ScalePerStep2.X = diff / atime;
			diff = (crr.GetScale3D().Y + ToTransform2.GetScale3D().Y) - crr.GetScale3D().Y;
			ScalePerStep2.Y = diff / atime;
			diff = (crr.GetScale3D().Z + ToTransform2.GetScale3D().Z) - crr.GetScale3D().Z;
			ScalePerStep2.Z = diff / atime;
		}
		else {
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
	}
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_2 = true;
	totalSteps2 = 0;
}
void UAnimAdd::StartAnim3() {
	if (pl_3) { return; }
	FTransform crr = this->PassAnimToActor->GetTransform();
	if (PassAnimToActor) {
		crr = PassAnimToActor->GetTransform();
	}
	double atime = AnimationTime3;
	if (atime == 0) { atime = 1; }
	if (MoveLocation3) {
		double diff = 0.0f;
		if (UseRelativeTransform3) {
			diff = (crr.GetLocation().X + ToTransform3.GetLocation().X) - crr.GetLocation().X;
			MovePerStep3.X = diff / atime;
			diff = (crr.GetLocation().Y + ToTransform3.GetLocation().Y) - crr.GetLocation().Y;
			MovePerStep3.Y = diff / atime;
			diff = (crr.GetLocation().Z + ToTransform3.GetLocation().Z) - crr.GetLocation().Z;
			MovePerStep3.Z = diff / atime;
		}
		else {
			diff = ToTransform3.GetLocation().X - crr.GetLocation().X;
			MovePerStep3.X = diff / atime;
			diff = ToTransform3.GetLocation().Y - crr.GetLocation().Y;
			MovePerStep3.Y = diff / atime;
			diff = ToTransform3.GetLocation().Z - crr.GetLocation().Z;
			MovePerStep3.Z = diff / atime;
		}
	}
	if (Rotate3) {
		double diff = 0.0f;
		if (UseRelativeTransform3) {
			diff = (crr.GetRotation().Rotator().Roll + ToTransform3.GetRotation().Rotator().Roll)
				- crr.GetRotation().Rotator().Roll;
			RotatePerStep3.Roll = diff / atime;
			diff = (crr.GetRotation().Rotator().Yaw + ToTransform3.GetRotation().Rotator().Yaw)
				- crr.GetRotation().Rotator().Yaw;
			RotatePerStep3.Yaw = diff / atime;
			diff = (crr.GetRotation().Rotator().Pitch + ToTransform3.GetRotation().Rotator().Pitch)
				- crr.GetRotation().Rotator().Pitch;
			RotatePerStep3.Pitch = diff / atime;
		}
		else {
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
	}
	if (Scale3) {
		double diff = 0.0f;
		if (UseRelativeTransform3) {
			diff = (crr.GetScale3D().X + ToTransform3.GetScale3D().X) - crr.GetScale3D().X;
			ScalePerStep3.X = diff / atime;
			diff = (crr.GetScale3D().Y + ToTransform3.GetScale3D().Y) - crr.GetScale3D().Y;
			ScalePerStep3.Y = diff / atime;
			diff = (crr.GetScale3D().Z + ToTransform3.GetScale3D().Z) - crr.GetScale3D().Z;
			ScalePerStep3.Z = diff / atime;
		}
		else {
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
	}
	if (StopRunningAnimsOnNewStart) {
		StopAllAnims();
	}
	pl_3 = true;
	totalSteps3 = 0;
}

void UAnimAdd::StopAnim1(bool force, bool org) {
	if (force) {
		pl_1 = false;
		totalSteps1 = -1;
		if (EventToTriggerOnStop1 != "" && org == true) {
			processEvent(EventToTriggerOnStop1);
		}

	}
	else {
		if (EventToTriggerOnStop2 != "" && org == true) {
			processEvent(EventToTriggerOnStop2);
		}
	}
}
void UAnimAdd::StopAnim2(bool force, bool org) {
	if (force) {
		pl_2 = false;
		totalSteps2 = -1;
		if (EventToTriggerOnStop2 != "" && org == true) {
			processEvent(EventToTriggerOnStop2);
		}

	}
	else {
		if (EventToTriggerOnStop2 != "" && org == true) {
			processEvent(EventToTriggerOnStop2);
		}
	}
}
void UAnimAdd::StopAnim3(bool force, bool org) {
	if (force) {
		pl_3 = false;
		totalSteps2 = -1;
		if (EventToTriggerOnStop3 != "" && org == true) {
			processEvent(EventToTriggerOnStop3);
		}

	}
	else {
		if (EventToTriggerOnStop3 != "" && org == true) {
			processEvent(EventToTriggerOnStop3);
		}
	}
}




void UAnimAdd::processEvent(FString eventname) {


	bool skipLockCheck = false;

	if (!IgnoreAllLocks) {
		if (!AnimationController) {
			UE_LOG(LogTemp, Error, TEXT("ANIMATION ACTOR HAS NO ANIMATION CONTROLLER ASSIGNED!"));
			return;
		}

		if (IgnoreLocksForLoad) {
			if (eventname == "onload" || eventname == "load" || eventname == "on_load") {
				//is ok
				skipLockCheck = true;
			}
		}

		if (!skipLockCheck) {

			if (ShouldLock1BeTrue) {
				//check locks!
				if (AnimationController->lock1) {
					//ok
				}
				else {
					//is still locked
					return;
				}
			}
			if (ShouldLock2BeTrue) {
				if (AnimationController->lock2 == false) {
					//is still locked
					return;
				}
			}
			if (ShouldLock3BeTrue) {
				if (AnimationController->lock3 == false) {
					//is still locked
					return;
				}
			}

		}

	}


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
		StopAnim1(true, pl_1);
	}if (eventname == StopEvent2) {
		StopAnim2(true, pl_2);
	}if (eventname == StopEvent3) {
		StopAnim3(true, pl_3);
	}

}

