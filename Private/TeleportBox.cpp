// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportBox.h"
#include "Components/BoxComponent.h"

ATeleportBox::ATeleportBox() {

	//Register Events
	this->OnActorBeginOverlap.AddDynamic(this, &ATeleportBox::OnOverlapBegin);
	this->OnActorEndOverlap.AddDynamic(this, &ATeleportBox::OnOverlapEnd);


	///this->OnActorBeginOverlap.AddDynamic(this, &ATeleportBox::BeginOverlap);
	//Register Events
	//OnActorBeginOverlap.AddDynamic(this, &ATeleportBox::OnOverlapBegin);
	//OnActorEndOverlap.AddDynamic(this, &ATeleportBox::OnOverlapEnd);
}

void ATeleportBox::BeginPlay() {

	Super::BeginPlay();

	if (SeeBoundBox) {
		DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
	}
}

void ATeleportBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	//if the overlapping actor is the specific actor we identified in the editor
	//if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor)
	//{
	if (OtherActor == parent) {
		if (parent != nullptr) {
			if (ignoreFirstTime) {
				ignoreFirstTime = false;
				return;
			}

			if (ExitOnTrigger) {
				///GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
				///exit(0);
			}

			//do stuff
			auto crrLoc = parent->GetActorLocation();
			crrLoc = parent->GetTransform().GetLocation();

			const FVector newloc = FVector(
				(crrLoc.X + LocationToTeleportCurrentOffset.X),
				(crrLoc.Y + LocationToTeleportCurrentOffset.Y),
				(crrLoc.Z + LocationToTeleportCurrentOffset.Z));

			parent->SetActorLocation(newloc);

			//that's it


		}
	}

	if (OverlappedActor == parent) {
		if (parent != nullptr) {
			//do stuff
			auto crrLoc = parent->GetActorLocation();
			crrLoc = parent->GetTransform().GetLocation();

			const FVector newloc = FVector(
				(crrLoc.X + LocationToTeleportCurrentOffset.X),
				(crrLoc.Y + LocationToTeleportCurrentOffset.Y),
				(crrLoc.Z + LocationToTeleportCurrentOffset.Z));

			parent->SetActorLocation(newloc);

			//that's it


		}
	}

	///print("Overlap Begin");
	///printFString("Overlapping Actor = %s", *OtherActor->GetName());
//}
}

void ATeleportBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	//if the overlapping actor is the specific actor we identified in the editor
	///if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor)
	///{
		///print("Overlap End");
		///printFString("%s has left the Trigger Box", *OtherActor->GetName());
	///}
}



void ATeleportBox::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult) {
	// Call Custom Function here


	if (OtherActor == parent) {
		if (parent != nullptr) {
			//do stuff
			auto crrLoc = parent->GetActorLocation();
			crrLoc = parent->GetTransform().GetLocation();

			const FVector newloc = FVector(
				(crrLoc.X + LocationToTeleportCurrentOffset.X),
				(crrLoc.Y + LocationToTeleportCurrentOffset.Y),
				(crrLoc.Z + LocationToTeleportCurrentOffset.Z));

			parent->SetActorLocation(newloc);

			//that's it


		}
	}

}




/*void ATeleportBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// check if Actors do not equal nullptr and that
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
	}
}

void ATeleportBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor leaves trigger box
		print("Overlap Ended");
		printFString("%s has left the Trigger Box", *OtherActor->GetName());
	}
}*/