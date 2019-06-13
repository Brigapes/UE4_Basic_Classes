// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// include draw debu helpers header file
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Engine/TriggerBox.h"
#include "TeleportBox.generated.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

/**
 *
 */
UCLASS()
class PLAYABLEDEMO_API ATeleportBox : public ATriggerBox
{
	GENERATED_BODY()


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	ATeleportBox();


	//class UBoxComponent* Box;

	// declare overlap begin function
	///UFUNCTION()
	///	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	 //Overlap
	/*UFUNCTION()
		void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);*/

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	UPROPERTY(EditAnywhere)
		AActor* parent = nullptr;
	bool hasTeleported = false;

	///UPROPERTY(EditAnywhere)
	///	ACharacter* CharacterToTransform = nullptr;

	UPROPERTY(EditAnywhere)
		bool ignoreFirstTime = false;
	UPROPERTY(EditAnywhere)
		bool ExitOnTrigger = false;

	UPROPERTY(EditAnywhere)
		bool SeeBoundBox = false;

	UPROPERTY(EditAnywhere)
		FVector LocationToTeleportCurrentOffset = FVector(0, 0, 0);

	// create trigger capsule
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* TriggerCapsule;

	// declare overlap end function
	///UFUNCTION()
		///void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
///	UPROPERTY(EditAnywhere)
///		class AActor* SpecificActor;

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};
